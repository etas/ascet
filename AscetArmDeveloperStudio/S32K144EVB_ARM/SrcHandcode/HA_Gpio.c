
#include "HA_Types.h"
#include "HA_Gpio.h"
#include "S32K144.h"

void HA_GPIOInit (void);
void HA_SetGPIOOut(U8 chan, U8 stat);
U8 HA_GetGPIOIn(U8 chan);
void HA_ToggleGPIOOut(U32 port, U8 chan);

void HA_GPIOInit (void)
{
	  PCC->PCCn[PCC_PORTA_INDEX ]|= PCC_PCCn_CGC_MASK;  /* Enable clock for PORTA */
	  PCC->PCCn[PCC_PORTB_INDEX ]|= PCC_PCCn_CGC_MASK;  /* Enable clock for PORTB */
	  PCC->PCCn[PCC_PORTC_INDEX ]|= PCC_PCCn_CGC_MASK;  /* Enable clock for PORTC */
	  PCC->PCCn[PCC_PORTD_INDEX ]|= PCC_PCCn_CGC_MASK;  /* Enable clock for PORTD */
	  PCC->PCCn[PCC_PORTE_INDEX ]|= PCC_PCCn_CGC_MASK;	/* Enable clock for PORTE */

	  PORTA->PCR[0]   = PORT_PCR_MUX(0);		/* ADC0_SE0 */
	  PORTA->PCR[1]   = PORT_PCR_MUX(0);		/* ADC0_SE1 */
	  PORTA->PCR[2]   = PORT_PCR_MUX(2);		/* FTM3_CH0 */
	  PORTA->PCR[3]   = PORT_PCR_MUX(2);		/* FTM3_CH1 */
	  PORTA->PCR[6]   = PORT_PCR_MUX(0);		/* ADC0_SE2 */
	  PORTA->PCR[7]   = PORT_PCR_MUX(0);		/* ADC0_SE3 */
	  PORTA->PCR[8]   = PORT_PCR_MUX(1);
	  PORTA->PCR[9]   = PORT_PCR_MUX(1);
	  PORTA->PCR[15]  = PORT_PCR_MUX(0);		/* ADC1_SE12 */
	  PORTA->PCR[16]  = PORT_PCR_MUX(0);		/* ADC1_SE13 */
	  PTA->PDDR = 1 << 8 |1 << 9;			/* Set Data Direction Register */

	  PORTB->PCR[0]   = PORT_PCR_MUX(0);		/* ADC1_SE14 / ADC0_SE4 */
	  PORTB->PCR[1]   = PORT_PCR_MUX(0);		/* ADC1_SE15 / ADC0_SE5 */
	  PORTB->PCR[2]   = PORT_PCR_MUX(2);
	  PORTB->PCR[3]   = PORT_PCR_MUX(2);
	  PORTB->PCR[4]   = PORT_PCR_MUX(2);
	  PORTB->PCR[5]   = PORT_PCR_MUX(2);
	  PORTB->PCR[8]   = PORT_PCR_MUX(1) | PORT_PCR_PFE_MASK;
	  PORTB->PCR[9]   = PORT_PCR_MUX(1) | PORT_PCR_PFE_MASK;
	  PORTB->PCR[10]  = PORT_PCR_MUX(2);		/* FTM3_CH2 */
	  PORTB->PCR[11]  = PORT_PCR_MUX(2);		/* FTM3_CH3 */
	  PORTB->PCR[12]  = PORT_PCR_MUX(0);		/* ADC1_SE7 */
	  PORTB->PCR[13]  = PORT_PCR_MUX(0);		/* ADC1_SE8 */
	  PTB->PDDR = 1 << 5 | 1 << 4 | 1 << 3 | 1 << 2;			/* Set Data Direction Register */

	  PORTC->PCR[0]   = PORT_PCR_MUX(0);		/* ADC0_SE8 */
	  PORTC->PCR[1]   = PORT_PCR_MUX(0);		/* ADC0_SE9 */
	  PORTC->PCR[2]   = PORT_PCR_MUX(0);		/* ADC0_SE10 */
	  PORTC->PCR[8]   = PORT_PCR_MUX(1);
	  PORTC->PCR[9]   = PORT_PCR_MUX(1);
	  PORTC->PCR[10]  = PORT_PCR_MUX(2);		/* FTM3_CH4 */
	  PORTC->PCR[11]  = PORT_PCR_MUX(2);		/* FTM3_CH5 */
	  PORTC->PCR[12]  = PORT_PCR_MUX(2);		/* FTM3_CH6 */
	  PORTC->PCR[13]  = PORT_PCR_MUX(2);		/* FTM3_CH7 */
	  PORTC->PCR[14]  = PORT_PCR_MUX(0);		/* ADC0_SE12 */
	  PTC->PDDR = 1 << 8 |1 << 9;			/* Set Data Direction Register */

	  PORTD->PCR[0]   = PORT_PCR_MUX(2);
	  PORTD->PCR[1]   = PORT_PCR_MUX(0);
	  PORTD->PCR[2]   = PORT_PCR_MUX(1);
	  PORTD->PCR[3]   = PORT_PCR_MUX(0);
	  PORTD->PCR[4]   = PORT_PCR_MUX(0);		/* ADC1_SE6 */
	  PORTD->PCR[5]   = PORT_PCR_MUX(0);
	  PORTD->PCR[6]   = PORT_PCR_MUX(0);
	  PORTD->PCR[7]   = PORT_PCR_MUX(0);
	  PORTD->PCR[8]   = PORT_PCR_MUX(1);
	  PORTD->PCR[9]   = PORT_PCR_MUX(1);
	  PORTD->PCR[10]  = PORT_PCR_MUX(0);
	  PORTD->PCR[11]  = PORT_PCR_MUX(0);
	  PORTD->PCR[12]  = PORT_PCR_MUX(0);
	  PORTD->PCR[13]  = PORT_PCR_MUX(2);
	  PORTD->PCR[14]  = PORT_PCR_MUX(2);
	  PORTD->PCR[15]  = PORT_PCR_MUX(2);
	  PORTD->PCR[16]  = PORT_PCR_MUX(2);
	  PORTD->PCR[17]  = PORT_PCR_MUX(1);
	  PTD->PDDR = 1 << 0 |1 << 15 |1 << 13 |1 << 14 |1 << 16 |1 << 8 |1 << 9 |1 << 17 |1 << 2;			/* Set Data Direction Register */

	  PORTE->PCR[0]   = PORT_PCR_MUX(0);
	  PORTE->PCR[1]   = PORT_PCR_MUX(0);
	  PORTE->PCR[2]   = PORT_PCR_MUX(0);				/* ADC1_SE10 */
	  PORTE->PCR[3]   = PORT_PCR_MUX(0);
	  PORTE->PCR[4]  |= PORT_PCR_MUX(5);				/* Port E4: MUX = ALT5, CAN0_RX */
	  PORTE->PCR[5]  |= PORT_PCR_MUX(5); 				/* Port E5: MUX = ALT5, CAN0_TX */
	  PORTE->PCR[6]   = PORT_PCR_MUX(0);				/* ADC1_SE11 */
	  PORTE->PCR[7]   = PORT_PCR_MUX(0);
	  PORTE->PCR[8]   = PORT_PCR_MUX(0);
	  PORTE->PCR[9]   = PORT_PCR_MUX(0);
	  PORTE->PCR[10]  = PORT_PCR_MUX(0);
	  PORTE->PCR[11]  = PORT_PCR_MUX(0);
	  PORTE->PCR[12]  = PORT_PCR_MUX(1);
	  PORTE->PCR[13]  = PORT_PCR_MUX(0);
	  PORTE->PCR[14]  = PORT_PCR_MUX(0);
	  PORTE->PCR[15]  = PORT_PCR_MUX(0);
	  PORTE->PCR[16]  = PORT_PCR_MUX(0);
	  PTE->PDDR = 1 << 12;			/* Set Data Direction Register */
}


void HA_SetGPIOOut(U8 chan, U8 stat)
{
	U32 mask;

	if (chan < PORTB_MINCHANNEL)
	{
		mask = (U32)1 << chan;
		/* Port A channel selected */
		if (stat == TRUE_U8)
		{
			PTA->PSOR |= mask;
		}
		else
		{
			PTA->PCOR |= mask;
		}
	}
	else if (chan < PORTC_MINCHANNEL)
	{
		mask = (U32)1 << ((U8)(chan - PORTB_MINCHANNEL));
		/* Port B channel selected */
		if (stat == TRUE_U8)
		{
			PTB->PSOR |= mask;
		}
		else
		{
			PTB->PCOR |= mask;
		}
	}
	else if (chan < PORTD_MINCHANNEL)
	{
		mask = (U32)1 << ((U8)(chan - PORTC_MINCHANNEL));
		/* Port C channel selected */
		if (stat == TRUE_U8)
		{
			PTC->PSOR |= mask;
		}
		else
		{
			PTC->PCOR |= mask;
		}
	}
	else if (chan < PORTE_MINCHANNEL)
	{
		mask = (U32)1 << ((U8)(chan - PORTD_MINCHANNEL));
		/* Port D channel selected */
		if (stat == TRUE_U8)
		{
			PTD->PSOR |= mask;
		}
		else
		{
			PTD->PCOR |= mask;
		}
	}
	else if (chan <= PORTE_MAXCHANNEL)
	{
		mask = (U32)1 << ((U8)(chan - PORTE_MINCHANNEL));
		/* Port E channel selected */
		if (stat == TRUE_U8)
		{
			PTE->PSOR |= mask;
		}
		else
		{
			PTE->PCOR |= mask;
		}
	}
}

U8 HA_GetGPIOIn(U8 chan)
{
	U8 retval;
	U32 mask;


	mask = (U32)0;
	if (chan < PORTB_MINCHANNEL)
	{
		mask = (U32)1 << chan;
		/* Port A channel selected */
		mask &= PTA->PDIR;
	}
	else if (chan < PORTC_MINCHANNEL)
	{
		mask = (U32)1 << ((U8)(chan - PORTB_MINCHANNEL));
		/* Port B channel selected */
		mask &= PTB->PDIR;
	}
	else if (chan < PORTD_MINCHANNEL)
	{
		mask = (U32)1 << ((U8)(chan - PORTC_MINCHANNEL));
		/* Port C channel selected */
		mask &= PTC->PDIR;
	}
	else if (chan < PORTE_MINCHANNEL)
	{
		mask = (U32)1 << ((U8)(chan - PORTD_MINCHANNEL));
		/* Port D channel selected */
		mask &= PTD->PDIR;
	}
	else if (chan <= PORTE_MAXCHANNEL)
	{
		mask = (U32)1 << ((U8)(chan - PORTE_MINCHANNEL));
		/* Port E channel selected */
		mask &= PTE->PDIR;
	}

	retval = (U8)(mask != 0);

	return(retval);
}


void HA_ToggleGPIOOut(U32 port, U8 chan)
{
	GPIO_Type * GPIOPort;
	U32 mask;

	GPIOPort = (void *)port;
	mask = (U32)1 << chan;

	GPIOPort->PTOR |= mask;
}

