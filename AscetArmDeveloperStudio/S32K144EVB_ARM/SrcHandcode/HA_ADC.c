#include "HA_Types.h"
#include "S32K144.h"
#include "HA_ADC.h"

/* Function prototypes */
U16 HA_getAdc (U8 chan);
void HA_InitADC(void);
void HA_CalibrateADC(U32 HA_BaseAddr);
void HA_SetupADC(U32 HA_BaseAddr);

volatile U16 HA_ADCResults[HA_ANALLENGTH];

/* ADC result access function from ASCET */
U16 HA_getAdc (U8 chan)
{

U16 retval;
	switch (chan)
		{
			case 0:
				retval = HA_ADCResults[HA_ANAA0];
			break;
			case 1:
				retval = HA_ADCResults[HA_ANAA1];
			break;
			case 6:
				retval = HA_ADCResults[HA_ANAA6];
			break;
			case 7:
				retval = HA_ADCResults[HA_ANAA7];
			break;
			case 36:
				retval = HA_ADCResults[HA_ANAC0];
			break;
			case 37:
				retval = HA_ADCResults[HA_ANAC1];
			break;
			case 38:
				retval = HA_ADCResults[HA_ANAC2];
			break;
			case 50:
				retval = HA_ADCResults[HA_ANAC14];
			break;
			case 58:
				retval = HA_ADCResults[HA_ANAD4];
			break;
			case 30:
				retval = HA_ADCResults[HA_ANAB12];
			break;
			case 31:
				retval = HA_ADCResults[HA_ANAB13];
			break;
			case 74:
				retval = HA_ADCResults[HA_ANAE2];
			break;
			case 78:
				retval = HA_ADCResults[HA_ANAE6];
			break;
			case 15:
				retval = HA_ADCResults[HA_ANAA15];
			break;
			case 16:
				retval = HA_ADCResults[HA_ANAA16];
			break;
			case 18:
				retval = HA_ADCResults[HA_ANAB0];
			break;
			case 19:
				retval = HA_ADCResults[HA_ANAB1];
			break;
			default:
				retval = (U16)0;
			break;
		}
	return (retval);
}


void HA_AdcStart(void)
{
static U8 channeltoggle = FALSE_U8;
	if(((ADC0->SC1[7] & ADC_SC1_COCO_MASK)>>ADC_SC1_COCO_SHIFT) != 0)
	{
		HA_ADCResults[HA_ANAA0]  = HA_ANAA0RESULT;
		HA_ADCResults[HA_ANAA1]  = HA_ANAA1RESULT;
		HA_ADCResults[HA_ANAA6]  = HA_ANAA6RESULT;
		HA_ADCResults[HA_ANAA7]  = HA_ANAA7RESULT;
		HA_ADCResults[HA_ANAC0]  = HA_ANAC0RESULT;
		HA_ADCResults[HA_ANAC1]  = HA_ANAC1RESULT;
		HA_ADCResults[HA_ANAC2]  = HA_ANAC2RESULT;
		HA_ADCResults[HA_ANAC14] = HA_ANAC14RESULT;
	}

	if(((ADC1->SC1[7] & ADC_SC1_COCO_MASK)>>ADC_SC1_COCO_SHIFT) != 0)
	{
		HA_ADCResults[HA_ANAD4]  = HA_ANAD4RESULT;
		HA_ADCResults[HA_ANAB12] = HA_ANAB12RESULT;
		HA_ADCResults[HA_ANAB13] = HA_ANAB13RESULT;
		HA_ADCResults[HA_ANAE2]  = HA_ANAE2RESULT;
		HA_ADCResults[HA_ANAE6]  = HA_ANAE6RESULT;
		HA_ADCResults[HA_ANAA15] = HA_ANAA15RESULT;
		HA_ADCResults[HA_ANAA16] = HA_ANAA16RESULT;

		if (channeltoggle == FALSE_U8)
			{
				HA_ADCResults[HA_ANAB0]  = HA_ANAB0RESULT;
				ADC1->SC1[7] = ADC_SC1_ADCH(15);     					/* B1 */
				channeltoggle = TRUE_U8;
			}
		else
			{
				HA_ADCResults[HA_ANAB1]  = HA_ANAB1RESULT;
				ADC1->SC1[7] = ADC_SC1_ADCH(14);                        /* B0 */
				channeltoggle = FALSE_U8;
			}


	}
}



void HA_InitADC(void)
{
	U32 clk_reg;

	HA_SetupADC(ADC0_BASE);
	/* Get the present state of the gated clock to the ADC */
	clk_reg = PCC->PCCn[PCC_ADC0_INDEX];
	PCC->PCCn[PCC_ADC0_INDEX] = 0x00000000;      /* Disable clock to configure it */
	PCC->PCCn[PCC_ADC0_INDEX] = ADC_SLOWPCCCLK;  /* Clock is set slow */
	HA_CalibrateADC(ADC0_BASE);
	PCC->PCCn[PCC_ADC0_INDEX] = 0x00000000;      /* Disable clock to configure it */
	PCC->PCCn[PCC_ADC0_INDEX] = clk_reg;         /* Clock is set fast */

	/* Same procedure for ADC1 */
	HA_SetupADC(ADC1_BASE);
	clk_reg = PCC->PCCn[PCC_ADC1_INDEX];
	PCC->PCCn[PCC_ADC1_INDEX] = 0x00000000;   /* Disable clock to configure it */
	PCC->PCCn[PCC_ADC1_INDEX] = ADC_SLOWPCCCLK;
	HA_CalibrateADC(ADC1_BASE);
	PCC->PCCn[PCC_ADC1_INDEX] = 0x00000000;      /* Disable clock to configure it */
	PCC->PCCn[PCC_ADC1_INDEX] = clk_reg;         /* Clock is set fast */

	/* Set up Queues */
	ADC0->SC1[0] = ADC_SC1_ADCH(0);                         /* A0 */
	ADC0->SC1[1] = ADC_SC1_ADCH(1);                         /* A1 */
	ADC0->SC1[2] = ADC_SC1_ADCH(2);                         /* A6 */
	ADC0->SC1[3] = ADC_SC1_ADCH(3);     					/* A7 */
	ADC0->SC1[4] = ADC_SC1_ADCH(8);     					/* C0 */
	ADC0->SC1[5] = ADC_SC1_ADCH(9);     					/* C1 */
	ADC0->SC1[6] = ADC_SC1_ADCH(10);     					/* C2 */
	ADC0->SC1[7] = ADC_SC1_ADCH(12);     					/* C14 */

	ADC1->SC1[0] = ADC_SC1_ADCH(6);                         /* D4 */
	ADC1->SC1[1] = ADC_SC1_ADCH(7);                         /* B12 */
	ADC1->SC1[2] = ADC_SC1_ADCH(8);                         /* B13 */
	ADC1->SC1[3] = ADC_SC1_ADCH(10);                        /* E2 */
	ADC1->SC1[4] = ADC_SC1_ADCH(11);                        /* E6 */
	ADC1->SC1[5] = ADC_SC1_ADCH(12);                        /* A15 */
	ADC1->SC1[6] = ADC_SC1_ADCH(13);                        /* A16 */
	ADC1->SC1[7] = ADC_SC1_ADCH(14);                        /* B0 */
	//ADC1->SC1[8] = ADC_SC1_ADCH(15);     					/* B1 */

	PCC->PCCn[PCC_PDB0_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable bus clock in PDB */
	PDB0->SC = PDB_SC_PRESCALER(1) | PDB_SC_TRGSEL(15) | PDB_SC_MULT(3) | PDB_SC_CONT_MASK;
	PDB0->MOD = 1200;
	PDB0->CH[0].C1 = (PDB_C1_BB(0xFE) | PDB_C1_TOS(0x01) | PDB_C1_EN(0xFF));
	PDB0->CH[0].DLY[0] = 10;
	PDB0->SC |= PDB_SC_PDBEN_MASK | PDB_SC_LDOK_MASK;
	PDB0->SC |= PDB_SC_SWTRIG_MASK; /* Single trigger */

	PCC->PCCn[PCC_PDB1_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable bus clock in PDB */
	PDB1->SC = PDB_SC_PRESCALER(1) | PDB_SC_TRGSEL(15) | PDB_SC_MULT(3) | PDB_SC_CONT_MASK;
	PDB1->MOD = 1200;
	PDB1->CH[0].C1 = (PDB_C1_BB(0xFE) | PDB_C1_TOS(0x01) | PDB_C1_EN(0xFF));
	PDB1->CH[0].DLY[0] = 10;
	PDB1->SC |= PDB_SC_PDBEN_MASK | PDB_SC_LDOK_MASK;
	PDB1->SC |= PDB_SC_SWTRIG_MASK; /* Single trigger */

}


void HA_SetupADC(U32 HA_BaseAddr)
{
	ADC_Type * ADConv;

	ADConv = (void *)HA_BaseAddr;
	ADConv->SC3 = 0;                               /* One conversion, no averaging enabled, 4 samples, but disabled  */
	ADConv->SC2 = ADC_SC2_ADTRG_MASK;              /* Hardware triggered, No DMA, Reference voltage VREFH/VREFL */
	ADConv->CFG1 = (ADC_CLOCK_DIV1 | ADC_CONV12);  /* Clock divided by 1, 12 bit precision */
	ADConv->CFG2 = ADC_RESET_SAMPLETIME;           /* Sample time  = 12 + 1 clocks (default) */
}


void HA_CalibrateADC(U32 HA_BaseAddr)
{
	ADC_Type * ADConv;
	U32 SC3_State;
	U32 SC2_State;
	U32 CFG2_State;
	U32 CFG1_State;
	U32 RegTemp;

	/* All registers are 32-bit write only. Read-modify-write must be used to adjust peripheral */

	/* Save current state of ADC setup */
	ADConv = (void *)HA_BaseAddr;
	SC3_State = ADConv->SC3;
	SC2_State = ADConv->SC2;
	CFG2_State = ADConv->CFG2;
	CFG1_State = ADConv->CFG1;

	/* Set up ADC for calibration - averaging enabled, 32 samples*/
	RegTemp = SC3_State;
	RegTemp &= ~(ADC_SC3_AVGS_MASK | ADC_SC3_AVGE_MASK);
	RegTemp |= (ADC_SC3_AVGE_MASK | ADC_AV_32_SAMPLES);
	ADConv->SC3 = RegTemp;

	/* Set up trigger by software */
	RegTemp = SC2_State;
	RegTemp &= ~(ADC_SC2_ADTRG_MASK);
	ADConv->SC2 = RegTemp;

	/* Set the sample time value at the MCU reset value */
	ADConv->CFG2 = ADC_RESET_SAMPLETIME;

	/* Reset the calibration values */
    ADConv->CLPS = 0x00u;
	ADConv->CLP3 = 0x00u;
	ADConv->CLP2 = 0x00u;
	ADConv->CLP1 = 0x00u;
	ADConv->CLP0 = 0x00u;
	ADConv->CLPX = 0x00u;
	ADConv->CLP9 = 0x00u;

	/* Setup ADC Clock */
	RegTemp = CFG1_State;
	RegTemp &= ~(ADC_CFG1_ADIV_MASK);
	RegTemp |= ADC_CLOCK_DIV4;
	ADConv->CFG1 = RegTemp;

	/* Set Calibration to start */
	RegTemp = ADConv->SC3;
	RegTemp |= ADC_SC3_CAL_MASK;
	ADConv->SC3 = RegTemp;

	/* Wait for it to finish */
	while((ADConv->SC1[0] & ADC_SC1_COCO_MASK) != ADC_SC1_COCO_MASK)
	{;}

	/* Restore the configuration */
	ADConv->CFG1 = CFG1_State;
	ADConv->SC3 = SC3_State;
	ADConv->SC2 = SC2_State;
	ADConv->CFG2 = CFG2_State;
}




