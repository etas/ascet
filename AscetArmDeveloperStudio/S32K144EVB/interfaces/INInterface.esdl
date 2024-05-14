package interfaces;
import enumerations.H_Status;
import types.T_LeverIn;
import types.T_Analogue;
import types.T_InputCapture;

data interface INInterface
{	
	/* User Inputs */
	boolean IN_SW2_PTC12 = false;
	boolean IN_SW3_PTC13 = false;
	T_Analogue IN_Potentiometer_PTC14 = 0.0;
	/* J3 */
	boolean IN_GPIOPTB6 = false;
	boolean IN_GPIOPTB7 = false;
	boolean IN_GPIOPTE0 = false;
	boolean IN_GPIOPTE9 = false;
	boolean IN_GPIOPTC5 = false;
	boolean IN_GPIOPTC4 = false;
	boolean IN_GPIOPTA10 = false;
	boolean IN_GPIOPTA4 = false;
	/* J4 */
	boolean IN_GPIOPTC7 = false;
	boolean IN_GPIOPTC6 = false;
	boolean IN_GPIOPTB17 = false;
	boolean IN_GPIOPTB14 = false;
	boolean IN_GPIOPTB15 = false;
	boolean IN_GPIOPTB16 = false;
	boolean IN_GPIOPTC14 = false;
	boolean IN_GPIOPTC3 = false;
	/* J5 */
	boolean IN_GPIOPTE16 = false;
	boolean IN_GPIOPTE15 = false;
	boolean IN_GPIOPTE14 = false;
	boolean IN_GPIOPTE13 = false;
	boolean IN_GPIOPTE1 = false;
	boolean IN_GPIOPTD7 = false;
	boolean IN_GPIOPTD6 = false;
	boolean IN_GPIOPTC15 = false;
	/* J4 - Arduino */	
	T_Analogue IN_ADC0_PTD4 = 0.0;
	T_Analogue IN_ADC1_PTB12 = 0.0;
	T_Analogue IN_ADC2_PTB0 = 0.0;
	T_Analogue IN_ADC3_PTB1 = 0.0;
	T_Analogue IN_ADC4_PTA6 = 0.0;
	T_Analogue IN_ADC5_PTC0 = 0.0;
	T_Analogue IN_ADC6_PTE2 = 0.0;
	T_Analogue IN_ADC7_PTE6 = 0.0;
	/* J5 - Arduino */	
	T_Analogue IN_ADC8_PTA15 = 0.0;
	T_Analogue IN_ADC9_PTA16 = 0.0;
	T_Analogue IN_ADC10_PTA1 = 0.0;
	T_Analogue IN_ADC11_PTA0 = 0.0;
	T_Analogue IN_ADC12_PTA7 = 0.0;
	T_Analogue IN_ADC13_PTB13 = 0.0;
	T_Analogue IN_ADC14_PTC1 = 0.0;
	T_Analogue IN_ADC15_PTC2 = 0.0;
	/* J2 */
	boolean IN_GPIOPTA14 = false;
	boolean IN_GPIOPTE7 = false;
	boolean IN_GPIOPTC13 = false;
	boolean IN_GPIOPTC12 = false;
	boolean IN_GPIOPTE8 = false;
	boolean IN_GPIOPTD0 = false;
	boolean IN_GPIOPTD16 = false;
	boolean IN_GPIOPTD15 = false;
	/* J1 */
	boolean IN_GPIOPTE3 = false;
	boolean IN_GPIOPTD3 = false;
	boolean IN_GPIOPTD5 = false;
	boolean IN_GPIOPTD12 = false;
	boolean IN_GPIOPTD11 = false;
	boolean IN_GPIOPTD10 = false;
	boolean IN_GPIOPTA17 = false;
	boolean IN_GPIOPTA11 = false;
	/* J6 */
	boolean IN_GPIOPTE4 = false;
	boolean IN_GPIOPTE5 = false;
	boolean IN_GPIOPTA12 = false;
	boolean IN_GPIOPTA13 = false;
	boolean IN_GPIOPTC16 = false;
	boolean IN_GPIOPTC17 = false;
	boolean IN_GPIOPTD3_ = false;
	boolean IN_GPIOPTD1 = false;
	/* J2 - Arduino */
	boolean IN_D15_PTE10 = false;
	boolean IN_D14_PTE11 = false;
	boolean IN_D13_PTB2 = false;
	boolean IN_D12_PTB3 = false;
	boolean IN_D11_PTB4 = false;
	boolean IN_D10_PTB5 = false;
	boolean IN_D9_PTD14 = false;
	boolean IN_D8_PTD13 = false;
	/* J1 - Arduino */
	boolean IN_D7_PTC11 = false;
	boolean IN_D6_PTC10 = false;
	boolean IN_D5_PTB11 = false;
	boolean IN_D4_PTB10 = false;
	boolean IN_D3_PTB9 = false;
	boolean IN_D2_PTB8 = false;
	boolean IN_D1_PTA3 = false;
	boolean IN_D0_PTA2 = false;
	/* J6 - Arduino (part) */
	boolean IN_D14_PTA9 = false;
	boolean IN_D15_PTA8 = false;
	boolean IN_D16_PTE12 = false;
	boolean IN_D17_PTD17 = false;
	boolean IN_D18_PTC9 = false;
	boolean IN_D19_PTC8 = false;
	boolean IN_D20_PTD8_ = false;
	boolean IN_D21_PTD9 = false;
	boolean IN_GPIOPTD2 = false;
	boolean IN_GPIOPTD0_ = false;
	/* J1 - Arduino */
	T_InputCapture IN_D0_IC_PTA2 = {false,0.0,0.0,0.0,0.0};
	T_InputCapture IN_D1_IC_PTA3 = {false,0.0,0.0,0.0,0.0};
	T_InputCapture IN_D2_IC_PTB10 = {false,0.0,0.0,0.0,0.0};
	T_InputCapture IN_D3_IC_PTB11 = {false,0.0,0.0,0.0,0.0};
	T_InputCapture IN_D4_IC_PTC10 = {false,0.0,0.0,0.0,0.0};
	T_InputCapture IN_D5_IC_PTC11 = {false,0.0,0.0,0.0,0.0};
	T_InputCapture IN_D6_IC_PTC12 = {false,0.0,0.0,0.0,0.0};
	T_InputCapture IN_D7_IC_PTC13 = {false,0.0,0.0,0.0,0.0};
	
	/* Application specific */
	T_LeverIn IN_LeverIn = {0,0,0,0,0,0,0,0,0,0,0,0,H_Status.H_Init};
}