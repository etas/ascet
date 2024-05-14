
#include "HA_Types.h"
#include "HA_FTM.h"
#include "S32K144.h"

/* Function prototypes */
void HA_FTMInit(void);
void HA_FTM0Init(void);
void HA_FTM1Init(void);
void HA_FTM2Init(void);
void HA_FTM3Init(void);
void HA_FTMStart(void);
void HA_SetPWM(U8 port, U16 freq, U16 duty);
U32 HA_GetFTMHigh(U8 port);
U32 HA_GetFTMPeriod(U8 port);
S16 HA_GetFTMFreq(U8 port, U8 ppr, U32 timeout);
U16 HA_GetFTMDuty(U8 port, U32 timeout);

static U16 HA_Capture1[HA_FREQCHANNELS];
static U16 HA_Capture2[HA_FREQCHANNELS];
static U32 HA_Period[HA_FREQCHANNELS];
static U32 HA_PeriodMin[HA_FREQCHANNELS];
static U32 HA_RiseLast[HA_FREQCHANNELS];
static U32 HA_HighTime[HA_FREQCHANNELS];
static U32 HA_FallLast[HA_FREQCHANNELS];
static U32 HA_Timeout[HA_FREQCHANNELS];
static U32 HA_FTM3HighResTmr;

/* Function to initialise all used FTM modules */
void HA_FTMInit(void)
{
	HA_FTM0Init();
	HA_FTM1Init();
	HA_FTM2Init();
	HA_FTM3Init();
}

/* Function to start timers on PWM modules */
void HA_FTMStart(void)
{
	FTM0->SC |= FTM_SC_CLKS(1); 	/* Start FTM0 counter with clk source = internal clock*/
	FTM1->SC |= FTM_SC_CLKS(1); 	/* Start FTM1 counter with clk source = internal clock*/
	FTM2->SC |= FTM_SC_CLKS(1); 	/* Start FTM2 counter with clk source = internal clock*/
}

/* Initialise FTM0 with channels set to PWM outputs */
void HA_FTM0Init(void)
{
	PCC->PCCn[PCC_FTM0_INDEX] &= ~PCC_PCCn_CGC_MASK;
	PCC->PCCn[PCC_FTM0_INDEX] |= PCC_PCCn_PCS(0b010) |  PCC_PCCn_CGC_MASK;
	FTM0->MODE |= FTM_MODE_WPDIS_MASK;
	FTM0->SC = FTM_SC_PWMEN0_MASK | FTM_SC_PWMEN1_MASK | FTM_SC_PWMEN2_MASK | FTM_SC_PWMEN4_MASK | FTM_SC_PWMEN5_MASK | FTM_SC_PS(3);
	FTM0->COMBINE = 0x00000000;
	FTM0->POL = 0x00000000;
	FTM0->MOD = (10000 - 1);
	FTM0->CONTROLS[0].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	FTM0->CONTROLS[0].CnV =  (10000 - 1);
	FTM0->CONTROLS[1].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	FTM0->CONTROLS[1].CnV =  (10000 - 1);
	FTM0->CONTROLS[2].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	FTM0->CONTROLS[2].CnV =  (10000 - 1);
	FTM0->CONTROLS[4].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	FTM0->CONTROLS[4].CnV =  (10000 - 1);
	FTM0->CONTROLS[5].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	FTM0->CONTROLS[5].CnV =  (10000 - 1);
}

/* Initialise FTM1 with channels set to PWM outputs */
void HA_FTM1Init(void)
{
	PCC->PCCn[PCC_FTM1_INDEX] &= ~PCC_PCCn_CGC_MASK;
	PCC->PCCn[PCC_FTM1_INDEX] |= PCC_PCCn_PCS(0b010) |  PCC_PCCn_CGC_MASK;
	FTM1->MODE |= FTM_MODE_WPDIS_MASK;
	FTM1->SC = FTM_SC_PWMEN0_MASK | FTM_SC_PWMEN1_MASK | FTM_SC_PS(3);
	FTM1->COMBINE = 0x00000000;
	FTM1->POL = 0x00000000;
	FTM1->MOD = (10000 - 1);
	FTM1->CONTROLS[0].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	FTM1->CONTROLS[0].CnV =  (10000 - 1);
	FTM1->CONTROLS[1].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	FTM1->CONTROLS[1].CnV =  (10000 - 1);
}

/* Initialise FTM2 with channels set to PWM outputs */
void HA_FTM2Init(void)
{
	PCC->PCCn[PCC_FTM2_INDEX] &= ~PCC_PCCn_CGC_MASK;
	PCC->PCCn[PCC_FTM2_INDEX] |= PCC_PCCn_PCS(0b010) |  PCC_PCCn_CGC_MASK;
	FTM2->MODE |= FTM_MODE_WPDIS_MASK;
	FTM2->SC = FTM_SC_PWMEN0_MASK |  FTM_SC_PWMEN4_MASK | FTM_SC_PWMEN5_MASK | FTM_SC_PS(3);
	FTM2->COMBINE = 0x00000000;
	FTM2->POL = 0x00000000;
	FTM2->MOD = (10000 - 1);
	FTM2->CONTROLS[4].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	FTM2->CONTROLS[4].CnV =  (10000 - 1);
	FTM2->CONTROLS[5].CnSC = FTM_CnSC_MSB_MASK | FTM_CnSC_ELSB_MASK;
	FTM2->CONTROLS[5].CnV =  (10000 - 1);
}

/* Initialise FTM3 with channels set to IC inputs */
void HA_FTM3Init(void)
{
	FTM3->MODE |= FTM_MODE_WPDIS_MASK;     /* Disable write protection on registers */

	S32_NVIC->ISER[FTM3_Ch0_Ch1_IRQn / 32] |= (1 << (FTM3_Ch0_Ch1_IRQn % 32));   /* Enables CH0/Ch1 ISR */
	S32_NVIC->ISER[FTM3_Ch2_Ch3_IRQn / 32] |= (1 << (FTM3_Ch2_Ch3_IRQn % 32));   /* Enables CH2/Ch3 ISR */
	S32_NVIC->ISER[FTM3_Ch4_Ch5_IRQn / 32] |= (1 << (FTM3_Ch4_Ch5_IRQn % 32));   /* Enables CH4/Ch5 ISR */
	S32_NVIC->ISER[FTM3_Ch6_Ch7_IRQn / 32] |= (1 << (FTM3_Ch6_Ch7_IRQn % 32));   /* Enables CH6/Ch7 ISR */
	S32_NVIC->ISER[FTM3_Ovf_Reload_IRQn / 32] |= (1 << (FTM3_Ovf_Reload_IRQn % 32));   /* Enables Overflow ISR */

	/* Combination functions not required */
	FTM3->COMBINE = 0;

	/* Define edge sensitivity for each channel */
	FTM3->CONTROLS[0].CnSC = FTM_BIDIEDGE_INT;
	FTM3->CONTROLS[1].CnSC = FTM_BIDIEDGE_INT;
	FTM3->CONTROLS[2].CnSC = FTM_BIDIEDGE_INT;
	FTM3->CONTROLS[3].CnSC = FTM_BIDIEDGE_INT;
	FTM3->CONTROLS[4].CnSC = FTM_BIDIEDGE_INT;
	FTM3->CONTROLS[5].CnSC = FTM_BIDIEDGE_INT;
	FTM3->CONTROLS[6].CnSC = FTM_BIDIEDGE_INT;
	FTM3->CONTROLS[7].CnSC = FTM_BIDIEDGE_INT;

	/* Must set up initial count value and modulo counter otherwise overflow interrupt will not work */
	FTM3->CNTIN = 0;
	FTM3->MOD = 0xFFFF;

	FTM3->CNT = 0;
	HA_FTM3HighResTmr = 0;

	FTM3->SC = (U32)( FTM_TOIESEL | FTM_CLKSOURCE | FTM_PS_FACTOR );   /* Control and Status set */
}

/* Function to allow update of PWM duty */
void HA_SetPWM(U8 port, U16 freq, U16 duty)
{
U16 period;
U16 hightime;

period = HA_PWMCOUNTERFREQ / freq;

if (FTM0->MOD != (period - (U8)1))
	{
		FTM0->MOD = (period - (U8)1);
	}
hightime = (U16)(((U32)period * duty) / (U16)10000);

switch (port)
	{
   		case 54:		/* FTM0 CH2 - PTD0 */
   			FTM0->CONTROLS[2].CnV =  hightime;
   		break;
   		case 69:		/* FTM0 CH0 - PTD15 */
   			FTM0->CONTROLS[0].CnV =  hightime;
   		break;
   		case 70:		/* FTM0 CH1 - PTD16 */
   			FTM0->CONTROLS[1].CnV =  hightime;
   		break;
  		case 67:		/* FTM2 CH4 - PTD13 */
   			FTM2->CONTROLS[4].CnV =  hightime;
   		break;
  		case 68:		/* FTM2 CH5 - PTD14 */
   			FTM2->CONTROLS[5].CnV =  hightime;
   		break;
  		case 23:		/* FTM0 CH5 - PTB5 */
   			FTM0->CONTROLS[5].CnV =  hightime;
   		break;
  		case 22:		/* FTM0 CH4 - PTB4 */
   			FTM0->CONTROLS[4].CnV =  hightime;
   		break;
  		case 21:		/* FTM1 CH1 - PTB3 */
   			FTM1->CONTROLS[1].CnV =  hightime;
   		break;
  		case 20:		/* FTM1 CH0 - PTB2 */
   			FTM1->CONTROLS[0].CnV =  hightime;
   		break;
   		default:
   		break;
   }
}

/* Function to read the high time of an IC channel */
U32 HA_GetFTMHigh(U8 port)
{
    U32 retval;
    U8 chan;

    switch (port)
    	{
    		case 2:		/* PTA2 */
    			chan = (U8)0;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_HighTime[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
    			break;
    		case 3:		/* PTA3 */
    			chan = (U8)1;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_HighTime[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
    			break;
    		case 28:	/* PTB10 */
    			chan = (U8)2;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_HighTime[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
    			break;
    		case 29:	/* PTB11 */
    			chan = (U8)3;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_HighTime[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
    			break;
    		case 46:	/* PTC10 */
    			chan = (U8)4;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_HighTime[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
    			break;
    		case 47:	/* PTC11 */
    			chan = (U8)5;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_HighTime[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
    			break;
    		case 48:	/* PTC12 */
    			chan = (U8)6;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_HighTime[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
    			break;
    		case 49:	/* PTC13 */
    			chan = (U8)7;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_HighTime[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
    			break;
    		default:
    			retval = (U32)0xFFFFFFFF;
    		break;
    	}

	return (retval);
}

/* Function to read the period of an IC channel */
U32 HA_GetFTMPeriod(U8 port)
{
    U32 retval;
    U8 chan;

    switch (port)
    	{
    		case 2:		/* PTA2 */
    			chan = (U8)0;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_Period[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
    		break;
    		case 3:		/* PTA3 */
    			chan = (U8)1;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_Period[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
    			break;
    		case 28:	/* PTB10 */
    			chan = (U8)2;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_Period[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
       		break;
    		case 29:	/* PTB11 */
    			chan = (U8)3;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_Period[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
       		break;
    		case 46:	/* PTC10 */
    			chan = (U8)4;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_Period[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
       		break;
    		case 47:	/* PTC11 */
    			chan = (U8)5;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_Period[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
       		break;
    		case 48:	/* PTC12 */
    			chan = (U8)6;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_Period[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
       		break;
    		case 49:	/* PTC13 */
    			chan = (U8)7;
    			retval = (HA_PeriodMin[chan] < HA_Timeout[chan])?(HA_Period[chan] / HA_COUNTSTOUS):(U32)0xFFFFFFFF;
       		break;
    		default:
    			retval = (U32)0xFFFFFFFF;
    		break;
    	}

	return (retval);
}

/* Function to read the freqency of an IC channel with a given number of pulses per revolution (set to 60 for freq. in Hz) */
S16 HA_GetFTMFreq(U8 port, U8 ppr, U32 timeout)
{
	S16 retval;
	U32 kspeed;
	U8 chan;

    switch (port)
    	{
    		case 2:		/* PTA2 */
    			chan = 0;
    			kspeed = (HA_SPEEDPRESCALERPM / ppr) ;
    			HA_Timeout[chan] = timeout * HA_COUNTSTOUS;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?(kspeed / HA_Period[chan]):(U32)0;
    		break;
    		case 3:		/* PTA3 */
    			chan = 1;
    			kspeed = (HA_SPEEDPRESCALERPM / ppr) ;
    			HA_Timeout[chan] = timeout * HA_COUNTSTOUS;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?(kspeed / HA_Period[chan]):(U32)0;
       		break;
    		case 28:	/* PTB10 */
    			chan = 2;
    			kspeed = (HA_SPEEDPRESCALERPM / ppr) ;
    			HA_Timeout[chan] = timeout * HA_COUNTSTOUS;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?(kspeed / HA_Period[chan]):(U32)0;
       		break;
    		case 29:	/* PTB11 */
    			chan = 3;
    			kspeed = (HA_SPEEDPRESCALERPM / ppr) ;
    			HA_Timeout[chan] = timeout * HA_COUNTSTOUS;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?(kspeed / HA_Period[chan]):(U32)0;
       		break;
    		case 46:	/* PTC10 */
    			chan = 4;
    			kspeed = (HA_SPEEDPRESCALERPM / ppr) ;
    			HA_Timeout[chan] = timeout * HA_COUNTSTOUS;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?(kspeed / HA_Period[chan]):(U32)0;
       		break;
    		case 47:	/* PTC11 */
    			chan = 5;
    			kspeed = (HA_SPEEDPRESCALERPM / ppr) ;
    			HA_Timeout[chan] = timeout * HA_COUNTSTOUS;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?(kspeed / HA_Period[chan]):(U32)0;
       		break;
    		case 48:	/* PTC12 */
    			chan = 6;
    			kspeed = (HA_SPEEDPRESCALERPM / ppr) ;
    			HA_Timeout[chan] = timeout * HA_COUNTSTOUS;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?(kspeed / HA_Period[chan]):(U32)0;
       		break;
    		case 49:	/* PTC13 */
    			chan = 7;
    			kspeed = (HA_SPEEDPRESCALERPM / ppr) ;
    			HA_Timeout[chan] = timeout * HA_COUNTSTOUS;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?(kspeed / HA_Period[chan]):(U32)0;
       		break;
    		default:
    			retval = (S16)0;
    		break;
    	}

	return (retval);
}

/* Function to read the duty cycle of an IC channel */
U16 HA_GetFTMDuty(U8 port, U32 timeout)
{
	U8 chan;
	U16 retval;
    switch (port)
    	{
    		case 2:		/* PTA2 */
    			chan = 0;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?((HA_HighTime[chan] * HA_PERCENTSCALING) / HA_Period[chan]):(U16)0;
    		break;
    		case 3:		/* PTA3 */
    			chan = 1;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?((HA_HighTime[chan] * HA_PERCENTSCALING) / HA_Period[chan]):(U16)0;
       		break;
    		case 28:	/* PTB10 */
    			chan = 2;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?((HA_HighTime[chan] * HA_PERCENTSCALING) / HA_Period[chan]):(U16)0;
       		break;
    		case 29:	/* PTB11 */
    			chan = 3;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?((HA_HighTime[chan] * HA_PERCENTSCALING) / HA_Period[chan]):(U16)0;
       		break;
    		case 46:	/* PTC10 */
    			chan = 4;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?((HA_HighTime[chan] * HA_PERCENTSCALING) / HA_Period[chan]):(U16)0;
       		break;
    		case 47:	/* PTC11 */
    			chan = 5;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?((HA_HighTime[chan] * HA_PERCENTSCALING) / HA_Period[chan]):(U16)0;
       		break;
    		case 48:	/* PTC12 */
    			chan = 6;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?((HA_HighTime[chan] * HA_PERCENTSCALING) / HA_Period[chan]):(U16)0;
       		break;
    		case 49:	/* PTC13 */
    			chan = 7;
    			retval = ((HA_Period[chan] > 0) && (HA_PeriodMin[chan] < HA_Timeout[chan]))?((HA_HighTime[chan] * HA_PERCENTSCALING) / HA_Period[chan]):(U16)0;
       		break;
    		default:
    			retval = (U16)0;
    		break;
    	}
	return (retval);
}


/* Interrupt functions - names here are from exceptions file */
void FTM3_Ch0_Ch1_IRQHandler (void)
{
	U32 last;

	if (FTM3->CONTROLS[0].CnSC & FTM_CHF_MASK)
		{
			if (FTM3->CONTROLS[0].CnSC & FTM_CHIS_MASK)
				{
					/* This is a rising edge */
					/* Grab the rising edge time */
					HA_Capture1[0] = (U16)(FTM3->CONTROLS[0].CnV);
					/* Get total time including overflows since the last rising edge */
					last = HA_Capture1[0] + HA_FTM3HighResTmr;
					/* Period = Current time minus last rising edge time */
					HA_Period[0] = last - HA_RiseLast[0];
					/* Min period = present period */
					HA_PeriodMin[0] = HA_Period[0];
					/* Store current rising edge time for next period calculation */
					HA_RiseLast[0] = last;
				}
			else
				{
					/* This is a falling edge */

					/* Grab the falling edge time */
					HA_Capture2[0] = (U16)(FTM3->CONTROLS[0].CnV);
					/* Get total time including overflows since the last falling edge */
					last =  HA_Capture2[0] + HA_FTM3HighResTmr;
					/* High time = Present time minus rising edge time */
					HA_HighTime[0] = last - HA_RiseLast[0];
					/* Store current falling time for next high time calculation */
					HA_FallLast[0] = last;
				}
			/* Clear the interrupt flag */
			FTM3->CONTROLS[0].CnSC &= FTM_CHF_CLEAR;
		}
	if (FTM3->CONTROLS[1].CnSC & FTM_CHF_MASK)
		{
			if (FTM3->CONTROLS[1].CnSC & FTM_CHIS_MASK)
				{
					/* This is a rising edge */
					/* Grab the rising edge time */
					HA_Capture1[1] = (U16)(FTM3->CONTROLS[1].CnV);
					/* Get total time including overflows since the last rising edge */
					last = HA_Capture1[1] + HA_FTM3HighResTmr;
					/* Period = Current time minus last rising edge time */
					HA_Period[1] = last - HA_RiseLast[1];
					/* Min period = present period */
					HA_PeriodMin[1] = HA_Period[1];
					/* Store current rising edge time for next period calculation */
					HA_RiseLast[1] = last;
				}
			else
				{
					/* This is a falling edge */

					/* Grab the falling edge time */
					HA_Capture2[1] = (U16)(FTM3->CONTROLS[1].CnV);
					/* Get total time including overflows since the last falling edge */
					last =  HA_Capture2[1] + HA_FTM3HighResTmr;
					/* High time = Present time minus rising edge time */
					HA_HighTime[1] = last - HA_RiseLast[1];
					/* Store current falling time for next high time calculation */
					HA_FallLast[1] = last;
				}
			/* Clear the interrupt flag */
			FTM3->CONTROLS[1].CnSC &= FTM_CHF_CLEAR;
		}
}

/* Interrupt functions - names here are from exceptions file */
void FTM3_Ch2_Ch3_IRQHandler (void)
{
	U32 last;

	if (FTM3->CONTROLS[2].CnSC & FTM_CHF_MASK)
		{
			if (FTM3->CONTROLS[2].CnSC & FTM_CHIS_MASK)
				{
					/* This is a rising edge */
					/* Grab the rising edge time */
					HA_Capture1[2] = (U16)(FTM3->CONTROLS[2].CnV);
					/* Get total time including overflows since the last rising edge */
					last = HA_Capture1[2] + HA_FTM3HighResTmr;
					/* Period = Current time minus last rising edge time */
					HA_Period[2] = last - HA_RiseLast[2];
					/* Min period = present period */
					HA_PeriodMin[2] = HA_Period[2];
					/* Store current rising edge time for next period calculation */
					HA_RiseLast[2] = last;
				}
			else
				{
					/* This is a falling edge */

					/* Grab the falling edge time */
					HA_Capture2[2] = (U16)(FTM3->CONTROLS[2].CnV);
					/* Get total time including overflows since the last falling edge */
					last =  HA_Capture2[2] + HA_FTM3HighResTmr;
					/* High time = Present time minus rising edge time */
					HA_HighTime[2] = last - HA_RiseLast[2];
					/* Store current falling time for next high time calculation */
					HA_FallLast[2] = last;
				}
			/* Clear the interrupt flag */
			FTM3->CONTROLS[2].CnSC &= FTM_CHF_CLEAR;
		}
	if (FTM3->CONTROLS[3].CnSC & FTM_CHF_MASK)
		{
			if (FTM3->CONTROLS[3].CnSC & FTM_CHIS_MASK)
				{
					/* This is a rising edge */
					/* Grab the rising edge time */
					HA_Capture1[3] = (U16)(FTM3->CONTROLS[3].CnV);
					/* Get total time including overflows since the last rising edge */
					last = HA_Capture1[3] + HA_FTM3HighResTmr;
					/* Period = Current time minus last rising edge time */
					HA_Period[3] = last - HA_RiseLast[3];
					/* Min period = present period */
					HA_PeriodMin[3] = HA_Period[3];
					/* Store current rising edge time for next period calculation */
					HA_RiseLast[3] = last;
				}
			else
				{
					/* This is a falling edge */

					/* Grab the falling edge time */
					HA_Capture2[3] = (U16)(FTM3->CONTROLS[3].CnV);
					/* Get total time including overflows since the last falling edge */
					last =  HA_Capture2[3] + HA_FTM3HighResTmr;
					/* High time = Present time minus rising edge time */
					HA_HighTime[3] = last - HA_RiseLast[3];
					/* Store current falling time for next high time calculation */
					HA_FallLast[3] = last;
				}
			/* Clear the interrupt flag */
			FTM3->CONTROLS[3].CnSC &= FTM_CHF_CLEAR;
		}
}

/* Interrupt functions - names here are from exceptions file */
void FTM3_Ch4_Ch5_IRQHandler (void)
{
	U32 last;

	if (FTM3->CONTROLS[4].CnSC & FTM_CHF_MASK)
		{
			if (FTM3->CONTROLS[4].CnSC & FTM_CHIS_MASK)
				{
					/* This is a rising edge */
					/* Grab the rising edge time */
					HA_Capture1[4] = (U16)(FTM3->CONTROLS[4].CnV);
					/* Get total time including overflows since the last rising edge */
					last = HA_Capture1[4] + HA_FTM3HighResTmr;
					/* Period = Current time minus last rising edge time */
					HA_Period[4] = last - HA_RiseLast[4];
					/* Min period = present period */
					HA_PeriodMin[4] = HA_Period[4];
					/* Store current rising edge time for next period calculation */
					HA_RiseLast[4] = last;
				}
			else
				{
					/* This is a falling edge */

					/* Grab the falling edge time */
					HA_Capture2[4] = (U16)(FTM3->CONTROLS[4].CnV);
					/* Get total time including overflows since the last falling edge */
					last =  HA_Capture2[4] + HA_FTM3HighResTmr;
					/* High time = Present time minus rising edge time */
					HA_HighTime[4] = last - HA_RiseLast[4];
					/* Store current falling time for next high time calculation */
					HA_FallLast[4] = last;
				}
			/* Clear the interrupt flag */
			FTM3->CONTROLS[4].CnSC &= FTM_CHF_CLEAR;
		}
	if (FTM3->CONTROLS[5].CnSC & FTM_CHF_MASK)
		{
			if (FTM3->CONTROLS[5].CnSC & FTM_CHIS_MASK)
				{
					/* This is a rising edge */
					/* Grab the rising edge time */
					HA_Capture1[5] = (U16)(FTM3->CONTROLS[5].CnV);
					/* Get total time including overflows since the last rising edge */
					last = HA_Capture1[5] + HA_FTM3HighResTmr;
					/* Period = Current time minus last rising edge time */
					HA_Period[5] = last - HA_RiseLast[5];
					/* Min period = present period */
					HA_PeriodMin[5] = HA_Period[5];
					/* Store current rising edge time for next period calculation */
					HA_RiseLast[5] = last;
				}
			else
				{
					/* This is a falling edge */

					/* Grab the falling edge time */
					HA_Capture2[5] = (U16)(FTM3->CONTROLS[5].CnV);
					/* Get total time including overflows since the last falling edge */
					last =  HA_Capture2[5] + HA_FTM3HighResTmr;
					/* High time = Present time minus rising edge time */
					HA_HighTime[5] = last - HA_RiseLast[5];
					/* Store current falling time for next high time calculation */
					HA_FallLast[5] = last;
				}
			/* Clear the interrupt flag */
			FTM3->CONTROLS[5].CnSC &= FTM_CHF_CLEAR;
		}
}


/* Interrupt functions - names here are from exceptions file */
void FTM3_Ch6_Ch7_IRQHandler (void)
{
	U32 last;

	if (FTM3->CONTROLS[6].CnSC & FTM_CHF_MASK)
		{
			if (FTM3->CONTROLS[6].CnSC & FTM_CHIS_MASK)
				{
					/* This is a rising edge */
					/* Grab the rising edge time */
					HA_Capture1[6] = (U16)(FTM3->CONTROLS[6].CnV);
					/* Get total time including overflows since the last rising edge */
					last = HA_Capture1[6] + HA_FTM3HighResTmr;
					/* Period = Current time minus last rising edge time */
					HA_Period[6] = last - HA_RiseLast[6];
					/* Min period = present period */
					HA_PeriodMin[6] = HA_Period[6];
					/* Store current rising edge time for next period calculation */
					HA_RiseLast[6] = last;
				}
			else
				{
					/* This is a falling edge */

					/* Grab the falling edge time */
					HA_Capture2[6] = (U16)(FTM3->CONTROLS[6].CnV);
					/* Get total time including overflows since the last falling edge */
					last =  HA_Capture2[6] + HA_FTM3HighResTmr;
					/* High time = Present time minus rising edge time */
					HA_HighTime[6] = last - HA_RiseLast[6];
					/* Store current falling time for next high time calculation */
					HA_FallLast[6] = last;
				}
			/* Clear the interrupt flag */
			FTM3->CONTROLS[6].CnSC &= FTM_CHF_CLEAR;
		}
	if (FTM3->CONTROLS[7].CnSC & FTM_CHF_MASK)
		{
			if (FTM3->CONTROLS[7].CnSC & FTM_CHIS_MASK)
				{
					/* This is a rising edge */
					/* Grab the rising edge time */
					HA_Capture1[7] = (U16)(FTM3->CONTROLS[7].CnV);
					/* Get total time including overflows since the last rising edge */
					last = HA_Capture1[7] + HA_FTM3HighResTmr;
					/* Period = Current time minus last rising edge time */
					HA_Period[7] = last - HA_RiseLast[7];
					/* Min period = present period */
					HA_PeriodMin[7] = HA_Period[7];
					/* Store current rising edge time for next period calculation */
					HA_RiseLast[7] = last;
				}
			else
				{
					/* This is a falling edge */

					/* Grab the falling edge time */
					HA_Capture2[7] = (U16)(FTM3->CONTROLS[7].CnV);
					/* Get total time including overflows since the last falling edge */
					last =  HA_Capture2[7] + HA_FTM3HighResTmr;
					/* High time = Present time minus rising edge time */
					HA_HighTime[7] = last - HA_RiseLast[7];
					/* Store current falling time for next high time calculation */
					HA_FallLast[7] = last;
				}
			/* Clear the interrupt flag */
			FTM3->CONTROLS[7].CnSC &= FTM_CHF_CLEAR;
		}
}

/* Interrupt functions - overflow to allow > 16 bit captures. Name here is from exceptions file */
void FTM3_Ovf_Reload_IRQHandler (void)
{
	U32 last;
	U8 chan;
	/* FTM3 timer has overflowed - add full count to 32 bit counter */
	HA_FTM3HighResTmr += FTM_MAXCOUNT;

	for (chan = 0;chan < HA_FREQCHANNELS;chan++)
		{
			if(HA_PeriodMin[chan] < HA_Timeout[chan])
				{
					last = HA_FTM3HighResTmr - HA_RiseLast[chan];
					if ((last > HA_Timeout[chan]) && (last < HA_PERIODUNDERFLOW))
						{
							HA_PeriodMin[chan] = HA_Timeout[chan];
						}
					else if((last > HA_Period[chan]) && (last < HA_PERIODUNDERFLOW))
						{
							HA_PeriodMin[chan] = last;
						}
				}
			/* Else not needed */
		}

	/* Clear the flag */
	FTM3->SC &= FTM_TOFCLEAR;
}
