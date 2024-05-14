#include "HA_Types.h"
#include "OS_Scheduler.h"
#include "OS_Task.h"
#include "S32K144.h"

void OS_Init(void);
void OS_Scheduler(void);
void OS_RequestStop(void);
void OS_Shutdown(void);

#define SOSCDIV_SETTING     0x00000101     /* DIV1 and DIV2 = 1 - divide by 1 */
#define SOSCCFG_SETTING     0x00000034     /* Range = 3 - High - 8-40MHz, High gain, External XTAL */
#define SCG_CSR_LOCK_MASK   0x00800000     /* LK bit of CSR register */
#define SCG_CSR_VALID_MASK  0x01000000     /* Valid bit of CSR register */
#define SOSCCSR_SETTING     0x00000001     /* Enable the oscillator */

#define PLLCSR_LK_MASK      0x00800000     /* LK bit of PLLCSR register */
#define PLLCSR_VALID_MASK   0x01000000     /* Valid bit of PLLCSR register */
#define PLLDIV_SETTING      0x00000302     /* DIV1 = /2, DIV2 = /4 */
#define PLLCFG_SETTING      0x00180000     /* PREDIV = 0 -> Divide by 0 + 1 = 1, MULT = 24 -> Multiply SYSPLL by 24 + 16 = 40 */
                                           /* SPLL_CLK is VCO_CLK /2, so overall Multiplier is (EXTCLK / 1) * (40 / 2) = 160MHz for 8MHz XTAL */
#define PLL_EN_SETTING      0x00000001     /* Enables PLL */

#define SYSCLK_SOURCE       (U32)((U32)0x06 << 24)   /* PLL clock as clock source */
#define CORECLK_SOURCE      (U32)((U32)0x01 << 16)   /* Core CLK divider = /2 = 80MHz */
#define BUSCLK_SOURCE       (U32)((U32)0x01 << 4)    /* Bus CLK divider = /2 = 40MHz */
#define SLOWCLK_SOURCE      0x00000002     /* Slow CLK (Flash Clock) divider = /3 = 26.6MHz */
#define CSRSCS_MASK         0x0F000000     /* Mask for SCS section of Clock status register */

#define PCC_CGC_BIT         0x40000000     /* Clock Gate control field in PCC */
#define PCC_CLKOPTION6      0xC6000000     /* Enables gated clock option 6 */
#define PCC_SOSCDIV2        0xC1000000     /* Enables gated clock with External oscillator / 2 as source */


static U16 os1mscount;
static U16 os5mscount;
static U16 os10mscount;
static U16 os100mscount;
static U16 os1scount;

static U8 os1mssched;
static U8 os5mssched;
static U8 os10mssched;
static U8 os100mssched;
static U8 os1ssched;
static U8 osRun;


void HA_NVICInit (void)
{
	S32_NVIC->ICPR[1] = 1 << (48 % 32);  /* IRQ48-LPIT0 ch0: clr any pending IRQ*/
	S32_NVIC->ISER[1] = 1 << (48 % 32);  /* IRQ48-LPIT0 ch0: enable IRQ */
	S32_NVIC->IP[48] = 0xA;              /* IRQ48-LPIT0 ch0: priority 10 of 0-15*/
}

void HA_LPIT0Init (void)
{
  PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6);
  PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK;
  LPIT0->MCR |= LPIT_MCR_M_CEN_MASK;
  LPIT0->MIER = LPIT_MIER_TIE0_MASK;
  LPIT0->TMR[0].TVAL = 4000;
  LPIT0->TMR[0].TCTRL |= LPIT_TMR_TCTRL_T_EN_MASK;
}

void HA_DisableWatchdog (void)
{
  WDOG->CNT=0xD928C520;     /* Unlock watchdog 		*/
  WDOG->TOVAL=0x0000FFFF;   /* Maximum timeout value 	*/
  WDOG->CS = 0x00002100;    /* Disable watchdog 		*/
}

void HA_SetupClocks(void)
{
	/* Initialise external crystal as reference clock */
	SCG->SOSCDIV = SOSCDIV_SETTING;
	SCG->SOSCCFG = SOSCCFG_SETTING;
	while (SCG->SOSCCSR & SCG_CSR_LOCK_MASK);   /* Wait for unlock */
	SCG->SOSCCSR = SOSCCSR_SETTING;
	while(!(SCG->SOSCCSR & SCG_CSR_VALID_MASK)); /* Wait for valid */

	/* PLL setup for 160MHz */
	while(SCG->SPLLCSR & PLLCSR_LK_MASK);   /*Ensure PLLCSR is unlocked */
	SCG->SPLLCSR = 0x00000000;    /* PLL disabled */
	SCG->SPLLDIV = PLLDIV_SETTING;
	SCG->SPLLCFG = PLLCFG_SETTING;
	while(SCG->SPLLCSR & PLLCSR_LK_MASK);   /*Ensure PLLCSR is unlocked */
	SCG->SPLLCSR = PLL_EN_SETTING;               /* Enable PLL */
	while(!(SCG->SPLLCSR & PLLCSR_VALID_MASK));  /* Wait until it is valid */

	/* Run mode setup at 80MHz */
	SCG->RCCR = (SYSCLK_SOURCE | CORECLK_SOURCE | BUSCLK_SOURCE | SLOWCLK_SOURCE );
	while ((SCG->CSR & CSRSCS_MASK) != SYSCLK_SOURCE); /* Wait until set */

	/* Peripheral Clock distribution */
	/* Ports A - E and GPIO */
	PCC->PCCn[PCC_PORTA_INDEX] |= PCC_CGC_BIT;
	PCC->PCCn[PCC_PORTB_INDEX] |= PCC_CGC_BIT;
	PCC->PCCn[PCC_PORTC_INDEX] |= PCC_CGC_BIT;
	PCC->PCCn[PCC_PORTD_INDEX] |= PCC_CGC_BIT;
	PCC->PCCn[PCC_PORTE_INDEX] |= PCC_CGC_BIT;

	/* FlexCAN 0 - 2 */
	PCC->PCCn[PCC_FlexCAN0_INDEX] |= PCC_CGC_BIT;
	PCC->PCCn[PCC_FlexCAN1_INDEX] |= PCC_CGC_BIT;
	PCC->PCCn[PCC_FlexCAN2_INDEX] |= PCC_CGC_BIT;

	/* DMAMUX */
	PCC->PCCn[PCC_DMAMUX_INDEX] |= PCC_CGC_BIT;

	/* LPIT */
	PCC->PCCn[PCC_LPIT_INDEX] = 0; /* Disable clock to configure it */
	PCC->PCCn[PCC_LPIT_INDEX] = PCC_SOSCDIV2;

	/* LPSPI0 */
	PCC->PCCn[PCC_LPSPI0_INDEX] = 0x00000000;   /* Disable clock to configure it */
	PCC->PCCn[PCC_LPSPI0_INDEX] = PCC_CLKOPTION6;   /* SPLL DIV 2 */

	/* FTM0, 2 and 3*/
	PCC->PCCn[PCC_FTM0_INDEX] = 0x00000000;   /* Disable clock to configure it */
	PCC->PCCn[PCC_FTM0_INDEX] = PCC_CLKOPTION6;   /* SPLL DIV 1 */
	PCC->PCCn[PCC_FTM2_INDEX] = 0x00000000;   /* Disable clock to configure it */
	PCC->PCCn[PCC_FTM2_INDEX] = PCC_CLKOPTION6;   /* SPLL DIV 1 */
	PCC->PCCn[PCC_FTM3_INDEX] = 0x00000000;   /* Disable clock to configure it */
	PCC->PCCn[PCC_FTM3_INDEX] = PCC_CLKOPTION6;   /* SPLL DIV 1 */

	/* PDB0, PDB1 and TRGMUX */
	PCC->PCCn[PCC_PDB0_INDEX] = 0x00000000;   /* Disable clock to configure it */
	PCC->PCCn[PCC_PDB0_INDEX] = PCC_PCCn_CGC_MASK;   /* Enable the clock */
	PCC->PCCn[PCC_PDB1_INDEX] = 0x00000000;   /* Disable clock to configure it */
	PCC->PCCn[PCC_PDB1_INDEX] = PCC_PCCn_CGC_MASK;   /* Enable the clock */

	/* ADC0 - 1 */
	PCC->PCCn[PCC_ADC0_INDEX] = 0x00000000;   /* Disable clock to configure it */
	PCC->PCCn[PCC_ADC0_INDEX] = PCC_CLKOPTION6;    /* SPLL DIV 2 */
	PCC->PCCn[PCC_ADC1_INDEX] = 0x00000000;   /* Disable clock to configure it */
	PCC->PCCn[PCC_ADC1_INDEX] = PCC_CLKOPTION6;    /* SPLL DIV 2 */

	SMC->PMCTRL  = SMC_PMCTRL_RUNM(0b00);     /* Set RUN mode */
}


/* Default LPIT Interrupt handler - run at each OS tick */
void LPIT0_Ch0_IRQHandler(void)
{
	/* Function is called by system tick to update scheduler */

	/* Update scheduler counters */
	os1mscount = (os1mscount >= (HA_OS1MSTHRESH - (U8)1))?(U16)0:(os1mscount+(U16)1);
	os5mscount = (os5mscount >= (HA_OS5MSTHRESH - (U8)1))?(U16)0:(os5mscount+(U16)1);
	os10mscount = (os10mscount >= (HA_OS10MSTHRESH - (U8)1))?(U16)0:(os10mscount+(U16)1);
	os100mscount = (os100mscount >= (HA_OS100MSTHRESH - (U8)1))?(U16)0:(os100mscount+(U16)1);
	os1scount = (os1scount >= (HA_OS1STHRESH - (U8)1))?(U16)0:(os1scount+(U16)1);

	/* Update call schedulers */
	os1mssched = (os1mscount == (U16)0)?(os1mssched + (U8)1):os1mssched;
	os5mssched = (os5mscount == (U16)0)?(os5mssched + (U8)1):os5mssched;
	os10mssched = (os10mscount == (U16)0)?(os10mssched + (U8)1):os10mssched;
	os100mssched = (os100mscount == (U16)0)?(os100mssched + (U8)1):os100mssched;
	os1ssched = (os1scount == (U16)0)?(os1ssched + (U8)1):os1ssched;

	LPIT0->MSR |= 0x01;    /* Write 1 to clear TIF0 */

}

void OS_Init(void)
{
	/* Initialise counters (including phase offsets) */
	os1mscount = HA_OS1MSPHASE;
	os5mscount= HA_OS5MSPHASE;
	os10mscount= HA_OS10MSPHASE;
	os100mscount= HA_OS100MSPHASE;
	os1scount = HA_OS1SPHASE;

	/* Reset scheduler requests */
	os1mssched = 0;
	os5mssched = 0;
	os10mssched = 0;
	os100mssched = 0;
	os1ssched = 0;

	/* Call initialisation of application */
	OS_TaskInit();

	/* Start OS requests */
	osRun = TRUE_U8;
}


void OS_Scheduler(void)
{
	/* Os background handler. Calls tasks as scheduled by ISR */
	while (osRun == TRUE_U8)
	{
		/* Call task containers when scheduler flags them as ready */
		if(os1mssched != (U8)0)
			{
				OS_Task1ms();
				os1mssched--;
			}
		/* Else not needed */
		if(os5mssched != (U8)0)
			{
				OS_Task5ms();
				os5mssched--;
			}
		/* Else not needed */
		if(os10mssched != (U8)0)
			{
				OS_Task10ms();
				os10mssched--;
			}
		/* Else not needed */
		if(os100mssched != (U8)0)
			{
				OS_Task100ms();
				os100mssched--;
			}
		/* Else not needed */
		if(os1ssched != (U8)0)
			{
				OS_Task1s();
				os1ssched--;
			}
		/* Else not needed */
	}

	/* OS has been told to stop */
	OS_Shutdown();
}

void OS_RequestStop(void)
{
	/* Allows an external function to request the OS to shutdown in a controlled fashion */

	osRun = FALSE_U8;
}

void OS_Shutdown(void)
{
	/* Disable interrupts */
	__asm("cpsid i");

	while(1)
	{}
}


void WDOG_EWM_IRQHandler(void)
{
	while(1)
	{}
}

