package interfaces;
import enumerations.H_Status;

import types.T_LeverOut;
import types.T_DutyPercent;

data interface APPInterface
{
	T_DutyPercent APP_RedLED = 0.0;
	T_DutyPercent APP_GreenLED = 0.0;
	T_DutyPercent APP_BlueLED = 0.0;
	
	/* J2 - Arduino */
	T_DutyPercent APP_D8_PTD13 = 0.0;
	T_DutyPercent APP_D9_PTD14 = 0.0;
	T_DutyPercent APP_D10_PTB5 = 0.0;
	T_DutyPercent APP_D11_PTB4 = 0.0;
	T_DutyPercent APP_D12_PTB3 = 0.0;
	T_DutyPercent APP_D13_PTB2 = 0.0;
	/* J6 - Arduino */	
	boolean APP_D14_PTA9 = false;
	boolean APP_D15_PTA8 = false;
	boolean APP_D16_PTE12 = false;
	boolean APP_D17_PTD17 = false;
	boolean APP_D18_PTC9 = false;
	boolean APP_D19_PTC8 = false;
	boolean APP_D20_PTD8 = false;
	boolean APP_D21_PTD9 = false;
	boolean APP_GPIOPTD2 = false;
	boolean APP_GPIOPTD0 = false;

	/* Application specific */
	T_LeverOut APP_LeverOut = {0,0,0,0,0,0,0,0,0,H_Status.H_Init};
}