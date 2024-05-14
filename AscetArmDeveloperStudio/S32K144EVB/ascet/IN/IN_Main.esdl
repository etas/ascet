package ascet.IN;
import types.T_CANHandle;
import types.T_Timeus;
import types.T_SpeedPpr;
import types.T_CANID;
import types.T_CANChannel;
import interfaces.INInterface;
import enumerations.S32K144_Gpio;
import ascet.Lib.LIB_4BitCountTest;
import types.T_Bitfield4;
import types.T_Time;
import enumerations.H_Status;
import types.SY_1ms;
import ascet.Lib.LIB_CANStatus;
import types.T_CANLength;
import types.T_CANTCMLever;

singleton class IN_Main
writes INInterface.IN_GPIOPTB6, INInterface.IN_GPIOPTB7, INInterface.IN_GPIOPTE0, INInterface.IN_GPIOPTE9, INInterface.IN_GPIOPTC5, INInterface.IN_GPIOPTC4, INInterface.IN_GPIOPTA10, INInterface.IN_GPIOPTA4, INInterface.IN_GPIOPTC7, INInterface.IN_GPIOPTC6, INInterface.IN_GPIOPTB17, INInterface.IN_GPIOPTB14, INInterface.IN_GPIOPTB15, INInterface.IN_GPIOPTB16, INInterface.IN_GPIOPTC14, INInterface.IN_GPIOPTC3, INInterface.IN_GPIOPTE16, INInterface.IN_GPIOPTE15, INInterface.IN_GPIOPTE14, INInterface.IN_GPIOPTE13, INInterface.IN_GPIOPTE1, INInterface.IN_GPIOPTD7, INInterface.IN_GPIOPTD6, INInterface.IN_GPIOPTC15, INInterface.IN_ADC0_PTD4, INInterface.IN_ADC1_PTB12, INInterface.IN_ADC2_PTB0, INInterface.IN_ADC3_PTB1, INInterface.IN_ADC4_PTA6, INInterface.IN_ADC5_PTC0, INInterface.IN_ADC6_PTE2, INInterface.IN_ADC7_PTE6, INInterface.IN_ADC8_PTA15, INInterface.IN_ADC9_PTA16, INInterface.IN_ADC10_PTA1, INInterface.IN_ADC11_PTA0, INInterface.IN_ADC12_PTA7, INInterface.IN_ADC13_PTB13, INInterface.IN_ADC14_PTC1, INInterface.IN_ADC15_PTC2, INInterface.IN_GPIOPTA14, INInterface.IN_GPIOPTE7, INInterface.IN_GPIOPTC13, INInterface.IN_GPIOPTC12, INInterface.IN_GPIOPTE8, INInterface.IN_GPIOPTD0, INInterface.IN_GPIOPTD16, INInterface.IN_GPIOPTD15, INInterface.IN_GPIOPTE3, INInterface.IN_GPIOPTD3, INInterface.IN_GPIOPTD5, INInterface.IN_GPIOPTD12, INInterface.IN_GPIOPTD11, INInterface.IN_GPIOPTD10, INInterface.IN_GPIOPTA17, INInterface.IN_GPIOPTA11, INInterface.IN_GPIOPTE4, INInterface.IN_GPIOPTE5, INInterface.IN_GPIOPTA12, INInterface.IN_GPIOPTA13, INInterface.IN_GPIOPTC16, INInterface.IN_GPIOPTC17, INInterface.IN_GPIOPTD3_, INInterface.IN_GPIOPTD1, INInterface.IN_D15_PTE10, INInterface.IN_D14_PTE11, INInterface.IN_D13_PTB2, INInterface.IN_D12_PTB3, INInterface.IN_D11_PTB4, INInterface.IN_D10_PTB5, INInterface.IN_D9_PTD14, INInterface.IN_D8_PTD13, INInterface.IN_D7_PTC11, INInterface.IN_D6_PTC10, INInterface.IN_D5_PTB11, INInterface.IN_D4_PTB10, INInterface.IN_D3_PTB9, INInterface.IN_D2_PTB8, INInterface.IN_D1_PTA3, INInterface.IN_D0_PTA2, INInterface.IN_D14_PTA9, INInterface.IN_D15_PTA8, INInterface.IN_D16_PTE12, INInterface.IN_D17_PTD17, INInterface.IN_D18_PTC9, INInterface.IN_D19_PTC8, INInterface.IN_D20_PTD8_, INInterface.IN_D21_PTD9, INInterface.IN_GPIOPTD2, INInterface.IN_GPIOPTD0_, INInterface.IN_SW2_PTC12, INInterface.IN_SW3_PTC13, INInterface.IN_Potentiometer_PTC14, INInterface.IN_D0_IC_PTA2, INInterface.IN_D1_IC_PTA3, INInterface.IN_D2_IC_PTB10, INInterface.IN_D3_IC_PTB11, INInterface.IN_D4_IC_PTC10, INInterface.IN_D5_IC_PTC11, INInterface.IN_D6_IC_PTC12, INInterface.IN_D7_IC_PTC13, INInterface.IN_LeverIn {
	T_CANHandle IN_RxTCMHandle = -1;
	IN_AnaIn IN_GetAnalog;
	IN_DigitalIn IN_DigitalInput;
	characteristic T_Timeus IN_D0_IC_PTA2_TIMEOUT = 1.0E6;
	characteristic T_SpeedPpr IN_D0_IC_PTA2_PPR = 60;
	IN_InputCaptureIn IN_InputCapture;
	IN_CANRxTCM IN_CAN_RxTCM;
	IN_CANConfig IN_CAN1Config;
	characteristic T_CANChannel IN_CANRXTCMCHAN = 0;
	characteristic T_CANID IN_CANRXTCMID = 1041;
	boolean IN_CANRxNewData = false;
	characteristic T_Timeus IN_D1_IC_PTA3_TIMEOUT = 1.0E6;
	characteristic T_SpeedPpr IN_D1_IC_PTA3_PPR = 60;
	characteristic T_Timeus IN_D2_IC_PTB10_TIMEOUT = 1.0E6;
	characteristic T_SpeedPpr IN_D2_IC_PTB10_PPR = 60;
	characteristic T_Timeus IN_D3_IC_PTB11_TIMEOUT = 1.0E6;
	characteristic T_SpeedPpr IN_D3_IC_PTB11_PPR = 60;
	characteristic T_Timeus IN_D4_IC_PTC10_TIMEOUT = 1.0E6;
	characteristic T_SpeedPpr IN_D4_IC_PTC10_PPR = 60;
	characteristic T_Timeus IN_D5_IC_PTC11_TIMEOUT = 1.0E6;
	characteristic T_SpeedPpr IN_D5_IC_PTC11_PPR = 60;
	characteristic T_Timeus IN_D6_IC_PTC12_TIMEOUT = 1.0E6;
	characteristic T_SpeedPpr IN_D6_IC_PTC12_PPR = 60;
	characteristic T_Timeus IN_D7_IC_PTC13_TIMEOUT = 1.0E6;
	characteristic T_SpeedPpr IN_D7_IC_PTC13_PPR = 60;
	boolean IN_RxTCMChkOkay = false;
	LIB_4BitCountTest IN_CANTxTCMCountTest;
	T_Bitfield4 IN_RxTCMCounter = 0;
	boolean IN_RxTCMCounterOkay = false;
	LIB_CANStatus IN_CANRxTCMStatCheck;
	characteristic T_Time IN_CANRXTCMTIMEOUT = 0.25;
	H_Status IN_CANRxTCMStatus = H_Status.H_Init;
	IN_CANMessageInit IN_CANMsgInit;
	characteristic T_CANLength IN_CANRXTCMLEN = 8;
	T_CANTCMLever IN_CANTCMData;

	@thread
	@generated("blockdiagram", "d9e4d292")
	public void IN_dT() {
		IN_CAN1Config.startCANChannel(0); // Main/IN_dT 1
		{
			{
				INInterface.IN_ADC0_PTD4 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortD_4); // Main/IN_dT 2/IN_Analogues 1/IN_Analogue_J4_Arduino 1
				INInterface.IN_ADC1_PTB12 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortB_12); // Main/IN_dT 2/IN_Analogues 1/IN_Analogue_J4_Arduino 2
				INInterface.IN_ADC2_PTB0 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortB_0); // Main/IN_dT 2/IN_Analogues 1/IN_Analogue_J4_Arduino 3
				INInterface.IN_ADC3_PTB1 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortB_1); // Main/IN_dT 2/IN_Analogues 1/IN_Analogue_J4_Arduino 4
				INInterface.IN_ADC4_PTA6 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortA_6); // Main/IN_dT 2/IN_Analogues 1/IN_Analogue_J4_Arduino 5
				INInterface.IN_ADC5_PTC0 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortC_0); // Main/IN_dT 2/IN_Analogues 1/IN_Analogue_J4_Arduino 6
				INInterface.IN_ADC6_PTE2 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortE_2); // Main/IN_dT 2/IN_Analogues 1/IN_Analogue_J4_Arduino 7
				INInterface.IN_ADC7_PTE6 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortE_6); // Main/IN_dT 2/IN_Analogues 1/IN_Analogue_J4_Arduino 8
			} // Main/IN_dT 2/IN_Analogues 1
			{
				INInterface.IN_ADC8_PTA15 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortA_15); // Main/IN_dT 2/IN_Analogues 2/IN_Analogue_J5_Arduino 1
				INInterface.IN_ADC9_PTA16 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortA_16); // Main/IN_dT 2/IN_Analogues 2/IN_Analogue_J5_Arduino 2
				INInterface.IN_ADC10_PTA1 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortA_1); // Main/IN_dT 2/IN_Analogues 2/IN_Analogue_J5_Arduino 3
				INInterface.IN_ADC11_PTA0 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortA_0); // Main/IN_dT 2/IN_Analogues 2/IN_Analogue_J5_Arduino 4
				INInterface.IN_ADC12_PTA7 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortA_7); // Main/IN_dT 2/IN_Analogues 2/IN_Analogue_J5_Arduino 5
				INInterface.IN_ADC13_PTB13 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortB_13); // Main/IN_dT 2/IN_Analogues 2/IN_Analogue_J5_Arduino 6
				INInterface.IN_ADC14_PTC1 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortC_1); // Main/IN_dT 2/IN_Analogues 2/IN_Analogue_J5_Arduino 7
				INInterface.IN_ADC15_PTC2 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortC_2); // Main/IN_dT 2/IN_Analogues 2/IN_Analogue_J5_Arduino 8
			} // Main/IN_dT 2/IN_Analogues 2
			{
				INInterface.IN_Potentiometer_PTC14 = IN_GetAnalog.getADCIn(S32K144_Gpio.PortC_14); // Main/IN_dT 2/IN_Analogues 3/IN_Analogue_Potentiometer 1
			} // Main/IN_dT 2/IN_Analogues 3
		} // Main/IN_dT 2
		{
			INInterface.IN_D0_IC_PTA2 = IN_InputCapture.getSpeedIn(S32K144_Gpio.PortA_2, IN_D0_IC_PTA2_TIMEOUT, IN_D0_IC_PTA2_PPR); // Main/IN_dT 3/IN_InputCapture 1
			INInterface.IN_D1_IC_PTA3 = IN_InputCapture.getSpeedIn(S32K144_Gpio.PortA_3, IN_D1_IC_PTA3_TIMEOUT, IN_D1_IC_PTA3_PPR); // Main/IN_dT 3/IN_InputCapture 2
			INInterface.IN_D2_IC_PTB10 = IN_InputCapture.getSpeedIn(S32K144_Gpio.PortB_10, IN_D2_IC_PTB10_TIMEOUT, IN_D2_IC_PTB10_PPR); // Main/IN_dT 3/IN_InputCapture 3
			INInterface.IN_D3_IC_PTB11 = IN_InputCapture.getSpeedIn(S32K144_Gpio.PortB_11, IN_D3_IC_PTB11_TIMEOUT, IN_D3_IC_PTB11_PPR); // Main/IN_dT 3/IN_InputCapture 4
			INInterface.IN_D4_IC_PTC10 = IN_InputCapture.getSpeedIn(S32K144_Gpio.PortC_10, IN_D4_IC_PTC10_TIMEOUT, IN_D4_IC_PTC10_PPR); // Main/IN_dT 3/IN_InputCapture 5
			INInterface.IN_D5_IC_PTC11 = IN_InputCapture.getSpeedIn(S32K144_Gpio.PortC_11, IN_D5_IC_PTC11_TIMEOUT, IN_D5_IC_PTC11_PPR); // Main/IN_dT 3/IN_InputCapture 6
			INInterface.IN_D6_IC_PTC12 = IN_InputCapture.getSpeedIn(S32K144_Gpio.PortC_12, IN_D6_IC_PTC12_TIMEOUT, IN_D6_IC_PTC12_PPR); // Main/IN_dT 3/IN_InputCapture 7
			INInterface.IN_D7_IC_PTC13 = IN_InputCapture.getSpeedIn(S32K144_Gpio.PortC_13, IN_D7_IC_PTC13_TIMEOUT, IN_D7_IC_PTC13_PPR); // Main/IN_dT 3/IN_InputCapture 8
		} // Main/IN_dT 3
		{
			{
				INInterface.IN_GPIOPTB6 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_6); // Main/IN_dT 4/IN_Digitals 1/IN_Digitals_J3 1
				INInterface.IN_GPIOPTB7 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_7); // Main/IN_dT 4/IN_Digitals 1/IN_Digitals_J3 2
				INInterface.IN_GPIOPTE0 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_0); // Main/IN_dT 4/IN_Digitals 1/IN_Digitals_J3 3
				INInterface.IN_GPIOPTE9 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_9); // Main/IN_dT 4/IN_Digitals 1/IN_Digitals_J3 4
				INInterface.IN_GPIOPTC5 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_5); // Main/IN_dT 4/IN_Digitals 1/IN_Digitals_J3 5
				INInterface.IN_GPIOPTC4 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_4); // Main/IN_dT 4/IN_Digitals 1/IN_Digitals_J3 6
				INInterface.IN_GPIOPTA10 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortA_10); // Main/IN_dT 4/IN_Digitals 1/IN_Digitals_J3 7
				INInterface.IN_GPIOPTA4 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortA_4); // Main/IN_dT 4/IN_Digitals 1/IN_Digitals_J3 8
			} // Main/IN_dT 4/IN_Digitals 1
			{
				INInterface.IN_GPIOPTC7 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_7); // Main/IN_dT 4/IN_Digitals 2/IN_Digitals_J4 1
				INInterface.IN_GPIOPTC6 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_6); // Main/IN_dT 4/IN_Digitals 2/IN_Digitals_J4 2
				INInterface.IN_GPIOPTB17 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_17); // Main/IN_dT 4/IN_Digitals 2/IN_Digitals_J4 3
				INInterface.IN_GPIOPTB14 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_14); // Main/IN_dT 4/IN_Digitals 2/IN_Digitals_J4 4
				INInterface.IN_GPIOPTB15 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_15); // Main/IN_dT 4/IN_Digitals 2/IN_Digitals_J4 5
				INInterface.IN_GPIOPTB16 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_16); // Main/IN_dT 4/IN_Digitals 2/IN_Digitals_J4 6
				INInterface.IN_GPIOPTC14 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_14); // Main/IN_dT 4/IN_Digitals 2/IN_Digitals_J4 7
				INInterface.IN_GPIOPTC3 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_3); // Main/IN_dT 4/IN_Digitals 2/IN_Digitals_J4 8
			} // Main/IN_dT 4/IN_Digitals 2
			{
				INInterface.IN_GPIOPTE16 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_16); // Main/IN_dT 4/IN_Digitals 3/IN_Digitals_J5 1
				INInterface.IN_GPIOPTE15 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_15); // Main/IN_dT 4/IN_Digitals 3/IN_Digitals_J5 2
				INInterface.IN_GPIOPTE14 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_14); // Main/IN_dT 4/IN_Digitals 3/IN_Digitals_J5 3
				INInterface.IN_GPIOPTE13 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_13); // Main/IN_dT 4/IN_Digitals 3/IN_Digitals_J5 4
				INInterface.IN_GPIOPTE1 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_1); // Main/IN_dT 4/IN_Digitals 3/IN_Digitals_J5 5
				INInterface.IN_GPIOPTD7 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_7); // Main/IN_dT 4/IN_Digitals 3/IN_Digitals_J5 6
				INInterface.IN_GPIOPTD6 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_6); // Main/IN_dT 4/IN_Digitals 3/IN_Digitals_J5 7
				INInterface.IN_GPIOPTC15 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_15); // Main/IN_dT 4/IN_Digitals 3/IN_Digitals_J5 8
			} // Main/IN_dT 4/IN_Digitals 3
			{
				INInterface.IN_D15_PTE10 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_10); // Main/IN_dT 4/IN_Digitals 4/IN_Digitals_J2_Arduino 1
				INInterface.IN_D14_PTE11 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_11); // Main/IN_dT 4/IN_Digitals 4/IN_Digitals_J2_Arduino 2
				INInterface.IN_D13_PTB2 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_2); // Main/IN_dT 4/IN_Digitals 4/IN_Digitals_J2_Arduino 3
				INInterface.IN_D12_PTB3 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_3); // Main/IN_dT 4/IN_Digitals 4/IN_Digitals_J2_Arduino 4
				INInterface.IN_D11_PTB4 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_4); // Main/IN_dT 4/IN_Digitals 4/IN_Digitals_J2_Arduino 5
				INInterface.IN_D10_PTB5 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_5); // Main/IN_dT 4/IN_Digitals 4/IN_Digitals_J2_Arduino 6
				INInterface.IN_D9_PTD14 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_14); // Main/IN_dT 4/IN_Digitals 4/IN_Digitals_J2_Arduino 7
				INInterface.IN_D8_PTD13 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_13); // Main/IN_dT 4/IN_Digitals 4/IN_Digitals_J2_Arduino 8
			} // Main/IN_dT 4/IN_Digitals 4
			{
				INInterface.IN_D7_PTC11 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_11); // Main/IN_dT 4/IN_Digitals 5/IN_Digitals_J1_Arduino 1
				INInterface.IN_D6_PTC10 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_10); // Main/IN_dT 4/IN_Digitals 5/IN_Digitals_J1_Arduino 2
				INInterface.IN_D5_PTB11 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_11); // Main/IN_dT 4/IN_Digitals 5/IN_Digitals_J1_Arduino 3
				INInterface.IN_D4_PTB10 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_10); // Main/IN_dT 4/IN_Digitals 5/IN_Digitals_J1_Arduino 4
				INInterface.IN_D3_PTB9 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_9); // Main/IN_dT 4/IN_Digitals 5/IN_Digitals_J1_Arduino 5
				INInterface.IN_D2_PTB8 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortB_8); // Main/IN_dT 4/IN_Digitals 5/IN_Digitals_J1_Arduino 6
				INInterface.IN_D1_PTA3 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortA_3); // Main/IN_dT 4/IN_Digitals 5/IN_Digitals_J1_Arduino 7
				INInterface.IN_D0_PTA2 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortA_2); // Main/IN_dT 4/IN_Digitals 5/IN_Digitals_J1_Arduino 8
			} // Main/IN_dT 4/IN_Digitals 5
			{
				INInterface.IN_D14_PTA9 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortA_9); // Main/IN_dT 4/IN_Digitals 6/IN_Digitals_J6_Arduino 1
				INInterface.IN_D15_PTA8 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortA_8); // Main/IN_dT 4/IN_Digitals 6/IN_Digitals_J6_Arduino 2
				INInterface.IN_D16_PTE12 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_12); // Main/IN_dT 4/IN_Digitals 6/IN_Digitals_J6_Arduino 3
				INInterface.IN_D17_PTD17 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_17); // Main/IN_dT 4/IN_Digitals 6/IN_Digitals_J6_Arduino 4
				INInterface.IN_D18_PTC9 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_9); // Main/IN_dT 4/IN_Digitals 6/IN_Digitals_J6_Arduino 5
				INInterface.IN_D19_PTC8 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_8); // Main/IN_dT 4/IN_Digitals 6/IN_Digitals_J6_Arduino 6
				INInterface.IN_D20_PTD8_ = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_8); // Main/IN_dT 4/IN_Digitals 6/IN_Digitals_J6_Arduino 7
				INInterface.IN_D21_PTD9 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_9); // Main/IN_dT 4/IN_Digitals 6/IN_Digitals_J6_Arduino 8
				INInterface.IN_GPIOPTD2 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_2); // Main/IN_dT 4/IN_Digitals 6/IN_Digitals_J6_Arduino 9
				INInterface.IN_GPIOPTD0_ = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_0); // Main/IN_dT 4/IN_Digitals 6/IN_Digitals_J6_Arduino 10
			} // Main/IN_dT 4/IN_Digitals 6
			{
				INInterface.IN_GPIOPTA14 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortA_14); // Main/IN_dT 4/IN_Digitals 7/IN_Digitals_J2 1
				INInterface.IN_GPIOPTE7 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_7); // Main/IN_dT 4/IN_Digitals 7/IN_Digitals_J2 2
				INInterface.IN_GPIOPTC13 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_13); // Main/IN_dT 4/IN_Digitals 7/IN_Digitals_J2 3
				INInterface.IN_GPIOPTC12 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_12); // Main/IN_dT 4/IN_Digitals 7/IN_Digitals_J2 4
				INInterface.IN_GPIOPTE8 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_8); // Main/IN_dT 4/IN_Digitals 7/IN_Digitals_J2 5
				INInterface.IN_GPIOPTD0 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_0); // Main/IN_dT 4/IN_Digitals 7/IN_Digitals_J2 6
				INInterface.IN_GPIOPTD16 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_16); // Main/IN_dT 4/IN_Digitals 7/IN_Digitals_J2 7
				INInterface.IN_GPIOPTD15 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_15); // Main/IN_dT 4/IN_Digitals 7/IN_Digitals_J2 8
			} // Main/IN_dT 4/IN_Digitals 7
			{
				INInterface.IN_GPIOPTE3 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_3); // Main/IN_dT 4/IN_Digitals 8/IN_Digitals_J1 1
				INInterface.IN_GPIOPTD3 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_3); // Main/IN_dT 4/IN_Digitals 8/IN_Digitals_J1 2
				INInterface.IN_GPIOPTD5 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_5); // Main/IN_dT 4/IN_Digitals 8/IN_Digitals_J1 3
				INInterface.IN_GPIOPTD12 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_12); // Main/IN_dT 4/IN_Digitals 8/IN_Digitals_J1 4
				INInterface.IN_GPIOPTD11 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_11); // Main/IN_dT 4/IN_Digitals 8/IN_Digitals_J1 5
				INInterface.IN_GPIOPTD10 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_10); // Main/IN_dT 4/IN_Digitals 8/IN_Digitals_J1 6
				INInterface.IN_GPIOPTA17 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortA_17); // Main/IN_dT 4/IN_Digitals 8/IN_Digitals_J1 7
				INInterface.IN_GPIOPTA11 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortA_11); // Main/IN_dT 4/IN_Digitals 8/IN_Digitals_J1 8
			} // Main/IN_dT 4/IN_Digitals 8
			{
				INInterface.IN_GPIOPTE4 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_4); // Main/IN_dT 4/IN_Digitals 9/IN_Digitals_J6 1
				INInterface.IN_GPIOPTE5 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortE_5); // Main/IN_dT 4/IN_Digitals 9/IN_Digitals_J6 2
				INInterface.IN_GPIOPTA12 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortA_12); // Main/IN_dT 4/IN_Digitals 9/IN_Digitals_J6 3
				INInterface.IN_GPIOPTA13 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortA_13); // Main/IN_dT 4/IN_Digitals 9/IN_Digitals_J6 4
				INInterface.IN_GPIOPTC16 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_16); // Main/IN_dT 4/IN_Digitals 9/IN_Digitals_J6 5
				INInterface.IN_GPIOPTC17 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_17); // Main/IN_dT 4/IN_Digitals 9/IN_Digitals_J6 6
				INInterface.IN_GPIOPTD3_ = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_3); // Main/IN_dT 4/IN_Digitals 9/IN_Digitals_J6 7
				INInterface.IN_GPIOPTD1 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortD_1); // Main/IN_dT 4/IN_Digitals 9/IN_Digitals_J6 8
			} // Main/IN_dT 4/IN_Digitals 9
			{
				INInterface.IN_SW2_PTC12 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_12); // Main/IN_dT 4/IN_Digitals 10/IN_DigitalSW2SW3 1
				INInterface.IN_SW3_PTC13 = IN_DigitalInput.getDigitalIn(S32K144_Gpio.PortC_13); // Main/IN_dT 4/IN_Digitals 10/IN_DigitalSW2SW3 2
			} // Main/IN_dT 4/IN_Digitals 10
		} // Main/IN_dT 4
		{
			IN_CANRxNewData = IN_CAN_RxTCM.rxCANNewData(IN_RxTCMHandle); // Main/IN_dT 5/IN_CANRxLever 1
			if (IN_CANRxNewData) {
				IN_CANTCMData = IN_CAN_RxTCM.rxCANMsg(); // Main/IN_dT 5/IN_CANRxLever 2/if-then 1
				IN_RxTCMChkOkay = IN_CANTCMData.TCM_ChecksumOkay; // Main/IN_dT 5/IN_CANRxLever 2/if-then 2
				IN_RxTCMCounter = IN_CANTCMData.TCM_Counter; // Main/IN_dT 5/IN_CANRxLever 2/if-then 3
				IN_RxTCMCounterOkay = IN_CANTxTCMCountTest.LIB_CheckOkay(IN_RxTCMCounter); // Main/IN_dT 5/IN_CANRxLever 2/if-then 4
			} // Main/IN_dT 5/IN_CANRxLever 2
			IN_CANRxTCMStatus = IN_CANRxTCMStatCheck.LIB_Status(IN_CANRxNewData, IN_RxTCMCounterOkay, IN_CANRXTCMTIMEOUT, SY_1ms); // Main/IN_dT 5/IN_CANRxLever 3
			if (IN_RxTCMCounterOkay && IN_CANRxNewData) {
				INInterface.IN_LeverIn.TCM_ParkLight = IN_CANTCMData.TCM_ParkLight; // Main/IN_dT 5/IN_CANRxLever 4/if-then 1
				INInterface.IN_LeverIn.TCM_ReverseLight = IN_CANTCMData.TCM_ReverseLight; // Main/IN_dT 5/IN_CANRxLever 4/if-then 2
				INInterface.IN_LeverIn.TCM_NeutralLight = IN_CANTCMData.TCM_NeutralLight; // Main/IN_dT 5/IN_CANRxLever 4/if-then 3
				INInterface.IN_LeverIn.TCM_DriveLight = IN_CANTCMData.TCM_DriveLight; // Main/IN_dT 5/IN_CANRxLever 4/if-then 4
				INInterface.IN_LeverIn.TCM_ManualLight = IN_CANTCMData.TCM_ManualLight; // Main/IN_dT 5/IN_CANRxLever 4/if-then 5
				INInterface.IN_LeverIn.TCM_SportLight = IN_CANTCMData.TCM_SportLight; // Main/IN_dT 5/IN_CANRxLever 4/if-then 6
				INInterface.IN_LeverIn.TCM_ShiftLock = IN_CANTCMData.TCM_ShiftLock; // Main/IN_dT 5/IN_CANRxLever 4/if-then 7
				INInterface.IN_LeverIn.TCM_BackLight = IN_CANTCMData.TCM_BackLight; // Main/IN_dT 5/IN_CANRxLever 4/if-then 8
				INInterface.IN_LeverIn.TCM_ActualGear = IN_CANTCMData.TCM_ActualGear; // Main/IN_dT 5/IN_CANRxLever 4/if-then 9
				INInterface.IN_LeverIn.TCM_TargetGear = IN_CANTCMData.TCM_TargetGear; // Main/IN_dT 5/IN_CANRxLever 4/if-then 10
				INInterface.IN_LeverIn.TCM_TestData1 = IN_CANTCMData.TCM_TestData1; // Main/IN_dT 5/IN_CANRxLever 4/if-then 11
				INInterface.IN_LeverIn.TCM_TestData2 = IN_CANTCMData.TCM_TestData2; // Main/IN_dT 5/IN_CANRxLever 4/if-then 12
			} // Main/IN_dT 5/IN_CANRxLever 4
			INInterface.IN_LeverIn.TCM_Status = IN_CANRxTCMStatus; // Main/IN_dT 5/IN_CANRxLever 5
		} // Main/IN_dT 5
	}

	@thread
	@generated("blockdiagram", "84a08c2a")
	public void IN_Init() {
		IN_CAN1Config.initCANChannel(0, 500); // Main/IN_Init 1
		{
			IN_RxTCMHandle = IN_CANMsgInit.initCANMsg(IN_CANRXTCMCHAN, IN_CANRXTCMID, false, false, IN_CANRXTCMLEN); // Main/IN_Init 2/IN_CANMsgInitialise 1
		} // Main/IN_Init 2
	}
}