package ascet.OUT;
import types.T_CANHandle;
import enumerations.H_Status;
import types.T_CANID;
import types.T_CANChannel;
import types.T_CANTxSpeeds;
import enumerations.S32K144_Gpio;
import interfaces.APPInterface;
import interfaces.INInterface;
import types.T_CANTxAnalogue;
import types.T_Bitfield4;
import types.T_CANLeverTCM;
import types.T_LeverOut;
import ascet.IN.IN_CANMessageInit;
import ascet.Lib.LIB_4BitCount;

singleton class OUT_Main
reads APPInterface.APP_RedLED, APPInterface.APP_GreenLED, APPInterface.APP_BlueLED, INInterface.IN_ADC0_PTD4, INInterface.IN_ADC1_PTB12, INInterface.IN_ADC2_PTB0, INInterface.IN_ADC3_PTB1, INInterface.IN_ADC4_PTA6, INInterface.IN_ADC5_PTC0, INInterface.IN_ADC6_PTE2, INInterface.IN_ADC7_PTE6, INInterface.IN_ADC8_PTA15, INInterface.IN_ADC9_PTA16, INInterface.IN_ADC10_PTA1, INInterface.IN_ADC11_PTA0, INInterface.IN_ADC12_PTA7, INInterface.IN_ADC13_PTB13, INInterface.IN_ADC14_PTC1, INInterface.IN_ADC15_PTC2, INInterface.IN_D0_IC_PTA2, INInterface.IN_D1_IC_PTA3, INInterface.IN_D2_IC_PTB10, INInterface.IN_D3_IC_PTB11, INInterface.IN_D4_IC_PTC10, INInterface.IN_D5_IC_PTC11, INInterface.IN_D6_IC_PTC12, INInterface.IN_D7_IC_PTC13, APPInterface.APP_D14_PTA9, APPInterface.APP_D15_PTA8, APPInterface.APP_D16_PTE12, APPInterface.APP_D17_PTD17, APPInterface.APP_D18_PTC9, APPInterface.APP_D19_PTC8, APPInterface.APP_D20_PTD8, APPInterface.APP_D21_PTD9, APPInterface.APP_GPIOPTD2, APPInterface.APP_GPIOPTD0, APPInterface.APP_D8_PTD13, APPInterface.APP_D9_PTD14, APPInterface.APP_D10_PTB5, APPInterface.APP_D11_PTB4, APPInterface.APP_D12_PTB3, APPInterface.APP_D13_PTB2, INInterface.IN_Potentiometer_PTC14, APPInterface.APP_LeverOut {
	OUT_CANTxIC OUT_CANTxIC1;
	T_CANHandle OUT_IC1Handle = -1;
	H_Status OUT_IC1Status = H_Status.H_Init;
	characteristic T_CANID OUT_IC1ID = 277;
	characteristic T_CANChannel OUT_IC1CHANNEL = 0;
	T_CANTxSpeeds OUT_CANTxSpeedsData;
	OUT_DigitalOutput OUT_DigitalOut;
	OUT_PWMOutput OUT_PWMOut;
	T_CANTxAnalogue OUT_CANTxAna1Data;
	OUT_CANTxAnalogue OUT_TxAna1;
	T_CANHandle OUT_Ana1Handle = -1;
	H_Status OUT_Ana1Status = H_Status.H_Init;
	characteristic T_CANID OUT_ANA1ID = 273;
	characteristic T_CANChannel OUT_ANA1CHANNEL = 0;
	T_CANTxAnalogue OUT_CANTxAna2Data;
	characteristic T_CANChannel OUT_ANA2CHANNEL = 0;
	characteristic T_CANID OUT_ANA2ID = 274;
	H_Status OUT_Ana2Status = H_Status.H_Init;
	T_CANHandle OUT_Ana2Handle = -1;
	OUT_CANTxAnalogue OUT_TxAna2;
	T_CANTxAnalogue OUT_CANTxAna3Data;
	T_CANTxAnalogue OUT_CANTxAna4Data;
	OUT_CANTxAnalogue OUT_TxAna3;
	OUT_CANTxAnalogue OUT_TxAna4;
	characteristic T_CANChannel OUT_ANA3CHANNEL = 0;
	characteristic T_CANID OUT_ANA3ID = 275;
	T_CANHandle OUT_Ana3Handle = -1;
	characteristic T_CANChannel OUT_ANA4CHANNEL = 0;
	characteristic T_CANID OUT_ANA4ID = 276;
	T_CANHandle OUT_Ana4Handle = -1;
	H_Status OUT_Ana3Status = H_Status.H_Init;
	H_Status OUT_Ana4Status = H_Status.H_Init;
	T_Bitfield4 OUT_AnaSched = 0;
	T_Bitfield4 OUT_ICSched = 0;
	OUT_CANTxIC OUT_CANTxIC2;
	OUT_CANTxIC OUT_CANTxIC3;
	OUT_CANTxIC OUT_CANTxIC4;
	T_CANHandle OUT_IC2Handle = -1;
	H_Status OUT_IC2Status = H_Status.H_Init;
	characteristic T_CANID OUT_IC2ID = 278;
	characteristic T_CANChannel OUT_IC2CHANNEL = 0;
	T_CANHandle OUT_IC3Handle = -1;
	H_Status OUT_IC3Status = H_Status.H_Init;
	characteristic T_CANID OUT_IC3ID = 279;
	characteristic T_CANChannel OUT_IC3CHANNEL = 0;
	T_CANHandle OUT_IC4Handle = -1;
	H_Status OUT_IC4Status = H_Status.H_Init;
	characteristic T_CANID OUT_IC4ID = 280;
	characteristic T_CANChannel OUT_IC4CHANNEL = 0;
	OUT_CANTxIC OUT_CANTxIC5;
	OUT_CANTxIC OUT_CANTxIC6;
	OUT_CANTxIC OUT_CANTxIC7;
	OUT_CANTxIC OUT_CANTxIC8;
	T_CANHandle OUT_IC5Handle = -1;
	H_Status OUT_IC5Status = H_Status.H_Init;
	characteristic T_CANID OUT_IC5ID = 281;
	characteristic T_CANChannel OUT_IC5CHANNEL = 0;
	T_CANHandle OUT_IC6Handle = -1;
	H_Status OUT_IC6Status = H_Status.H_Init;
	characteristic T_CANID OUT_IC6ID = 282;
	characteristic T_CANChannel OUT_IC6CHANNEL = 0;
	T_CANHandle OUT_IC7Handle = -1;
	H_Status OUT_IC7Status = H_Status.H_Init;
	characteristic T_CANID OUT_IC7ID = 283;
	characteristic T_CANChannel OUT_IC7CHANNEL = 0;
	T_CANHandle OUT_IC8Handle = -1;
	H_Status OUT_IC8Status = H_Status.H_Init;
	characteristic T_CANID OUT_IC8ID = 284;
	characteristic T_CANChannel OUT_IC8CHANNEL = 0;
	boolean OUT_ICMux = false;
	OUT_CANTxLever OUT_CANTx_Lever;
	T_CANHandle OUT_LeverHandle = -1;
	H_Status OUT_LeverStatus = H_Status.H_Init;
	characteristic T_CANID OUT_LEVERID = 1040;
	characteristic T_CANChannel OUT_LEVERCHANNEL = 0;
	T_CANLeverTCM OUT_CANTxLeverData;
	T_LeverOut T_LeverOut_instance;
	IN_CANMessageInit OUT_CANMsgInit;
	LIB_4BitCount OUT_CANCount;
	characteristic boolean OUT_SENDPOT = true;

	@thread
	@generated("blockdiagram", "c056f830")
	public void OUT_1ms() {
		{
			{
				OUT_PWMOut.setPWMOut(S32K144_Gpio.PortD_15, APPInterface.APP_RedLED, 1000.0); // Main/OUT_1ms 1/OUT_DirectOutputs 1/OUT_RGBLeds 1
				OUT_PWMOut.setPWMOut(S32K144_Gpio.PortD_16, APPInterface.APP_GreenLED, 1000.0); // Main/OUT_1ms 1/OUT_DirectOutputs 1/OUT_RGBLeds 2
				OUT_PWMOut.setPWMOut(S32K144_Gpio.PortD_0, APPInterface.APP_BlueLED, 1000.0); // Main/OUT_1ms 1/OUT_DirectOutputs 1/OUT_RGBLeds 3
			} // Main/OUT_1ms 1/OUT_DirectOutputs 1
			{
				OUT_DigitalOut.setDigOut(S32K144_Gpio.PortA_9, APPInterface.APP_D14_PTA9); // Main/OUT_1ms 1/OUT_DirectOutputs 2/OUT_Digital_J6_Arduino 1
				OUT_DigitalOut.setDigOut(S32K144_Gpio.PortA_8, APPInterface.APP_D15_PTA8); // Main/OUT_1ms 1/OUT_DirectOutputs 2/OUT_Digital_J6_Arduino 2
				OUT_DigitalOut.setDigOut(S32K144_Gpio.PortE_12, APPInterface.APP_D16_PTE12); // Main/OUT_1ms 1/OUT_DirectOutputs 2/OUT_Digital_J6_Arduino 3
				OUT_DigitalOut.setDigOut(S32K144_Gpio.PortD_17, APPInterface.APP_D17_PTD17); // Main/OUT_1ms 1/OUT_DirectOutputs 2/OUT_Digital_J6_Arduino 4
				OUT_DigitalOut.setDigOut(S32K144_Gpio.PortC_9, APPInterface.APP_D18_PTC9); // Main/OUT_1ms 1/OUT_DirectOutputs 2/OUT_Digital_J6_Arduino 5
				OUT_DigitalOut.setDigOut(S32K144_Gpio.PortC_8, APPInterface.APP_D19_PTC8); // Main/OUT_1ms 1/OUT_DirectOutputs 2/OUT_Digital_J6_Arduino 6
				OUT_DigitalOut.setDigOut(S32K144_Gpio.PortD_8, APPInterface.APP_D20_PTD8); // Main/OUT_1ms 1/OUT_DirectOutputs 2/OUT_Digital_J6_Arduino 7
				OUT_DigitalOut.setDigOut(S32K144_Gpio.PortD_9, APPInterface.APP_D21_PTD9); // Main/OUT_1ms 1/OUT_DirectOutputs 2/OUT_Digital_J6_Arduino 8
				OUT_DigitalOut.setDigOut(S32K144_Gpio.PortD_2, APPInterface.APP_GPIOPTD2); // Main/OUT_1ms 1/OUT_DirectOutputs 2/OUT_Digital_J6_Arduino 9
				OUT_DigitalOut.setDigOut(S32K144_Gpio.PortD_0, APPInterface.APP_GPIOPTD0); // Main/OUT_1ms 1/OUT_DirectOutputs 2/OUT_Digital_J6_Arduino 10
			} // Main/OUT_1ms 1/OUT_DirectOutputs 2
			{
				OUT_PWMOut.setPWMOut(S32K144_Gpio.PortD_13, APPInterface.APP_D8_PTD13, 1000.0); // Main/OUT_1ms 1/OUT_DirectOutputs 3/OUT_PWM_J2_Arduino 1
				OUT_PWMOut.setPWMOut(S32K144_Gpio.PortD_14, APPInterface.APP_D9_PTD14, 1000.0); // Main/OUT_1ms 1/OUT_DirectOutputs 3/OUT_PWM_J2_Arduino 2
				OUT_PWMOut.setPWMOut(S32K144_Gpio.PortB_5, APPInterface.APP_D10_PTB5, 1000.0); // Main/OUT_1ms 1/OUT_DirectOutputs 3/OUT_PWM_J2_Arduino 3
				OUT_PWMOut.setPWMOut(S32K144_Gpio.PortB_4, APPInterface.APP_D11_PTB4, 1000.0); // Main/OUT_1ms 1/OUT_DirectOutputs 3/OUT_PWM_J2_Arduino 4
				OUT_PWMOut.setPWMOut(S32K144_Gpio.PortB_3, APPInterface.APP_D12_PTB3, 1000.0); // Main/OUT_1ms 1/OUT_DirectOutputs 3/OUT_PWM_J2_Arduino 5
				OUT_PWMOut.setPWMOut(S32K144_Gpio.PortB_2, APPInterface.APP_D13_PTB2, 1000.0); // Main/OUT_1ms 1/OUT_DirectOutputs 3/OUT_PWM_J2_Arduino 6
			} // Main/OUT_1ms 1/OUT_DirectOutputs 3
		} // Main/OUT_1ms 1
		{
			OUT_AnaSched = (if(OUT_AnaSched == 4) then 0 else(OUT_AnaSched + 1)); // Main/OUT_1ms 2/OUT_CANSchedule 1
			OUT_ICSched = (if(OUT_ICSched == 9) then 0 else(OUT_ICSched + 1)); // Main/OUT_1ms 2/OUT_CANSchedule 2
			OUT_ICMux = (if(OUT_ICSched == 9) then(!OUT_ICMux) else OUT_ICMux); // Main/OUT_1ms 2/OUT_CANSchedule 3
		} // Main/OUT_1ms 2
		{
			if (OUT_ICSched == 0) {
				OUT_IC1Status = OUT_CANTxIC1.txCANMsg(OUT_IC1Handle, INInterface.IN_D0_IC_PTA2, OUT_ICMux); // Main/OUT_1ms 3/OUT_CANTxIC 1/if-then 1
			} // Main/OUT_1ms 3/OUT_CANTxIC 1
			if (OUT_ICSched == 1) {
				OUT_IC2Status = OUT_CANTxIC2.txCANMsg(OUT_IC2Handle, INInterface.IN_D1_IC_PTA3, OUT_ICMux); // Main/OUT_1ms 3/OUT_CANTxIC 2/if-then 1
			} // Main/OUT_1ms 3/OUT_CANTxIC 2
			if (OUT_ICSched == 2) {
				OUT_IC3Status = OUT_CANTxIC3.txCANMsg(OUT_IC3Handle, INInterface.IN_D2_IC_PTB10, OUT_ICMux); // Main/OUT_1ms 3/OUT_CANTxIC 3/if-then 1
			} // Main/OUT_1ms 3/OUT_CANTxIC 3
			if (OUT_ICSched == 3) {
				OUT_IC4Status = OUT_CANTxIC4.txCANMsg(OUT_IC4Handle, INInterface.IN_D3_IC_PTB11, OUT_ICMux); // Main/OUT_1ms 3/OUT_CANTxIC 4/if-then 1
			} // Main/OUT_1ms 3/OUT_CANTxIC 4
			if (OUT_ICSched == 4) {
				OUT_IC5Status = OUT_CANTxIC5.txCANMsg(OUT_IC5Handle, INInterface.IN_D4_IC_PTC10, OUT_ICMux); // Main/OUT_1ms 3/OUT_CANTxIC 5/if-then 1
			} // Main/OUT_1ms 3/OUT_CANTxIC 5
			if (OUT_ICSched == 5) {
				OUT_IC6Status = OUT_CANTxIC6.txCANMsg(OUT_IC6Handle, INInterface.IN_D5_IC_PTC11, OUT_ICMux); // Main/OUT_1ms 3/OUT_CANTxIC 6/if-then 1
			} // Main/OUT_1ms 3/OUT_CANTxIC 6
			if (OUT_ICSched == 6) {
				OUT_IC7Status = OUT_CANTxIC7.txCANMsg(OUT_IC7Handle, INInterface.IN_D6_IC_PTC12, OUT_ICMux); // Main/OUT_1ms 3/OUT_CANTxIC 7/if-then 1
			} // Main/OUT_1ms 3/OUT_CANTxIC 7
			if (OUT_ICSched == 7) {
				OUT_IC8Status = OUT_CANTxIC8.txCANMsg(OUT_IC8Handle, INInterface.IN_D7_IC_PTC13, OUT_ICMux); // Main/OUT_1ms 3/OUT_CANTxIC 8/if-then 1
			} // Main/OUT_1ms 3/OUT_CANTxIC 8
		} // Main/OUT_1ms 3
		{
			OUT_CANTxAna1Data.OUT_Analogue1 = INInterface.IN_ADC0_PTD4; // Main/OUT_1ms 4/OUT_CANTxAnalog 1
			OUT_CANTxAna1Data.OUT_Analogue2 = INInterface.IN_ADC1_PTB12; // Main/OUT_1ms 4/OUT_CANTxAnalog 2
			OUT_CANTxAna1Data.OUT_Analogue3 = INInterface.IN_ADC2_PTB0; // Main/OUT_1ms 4/OUT_CANTxAnalog 3
			OUT_CANTxAna1Data.OUT_Analogue4 = INInterface.IN_ADC3_PTB1; // Main/OUT_1ms 4/OUT_CANTxAnalog 4
			OUT_CANTxAna2Data.OUT_Analogue1 = INInterface.IN_ADC4_PTA6; // Main/OUT_1ms 4/OUT_CANTxAnalog 5
			OUT_CANTxAna2Data.OUT_Analogue2 = INInterface.IN_ADC5_PTC0; // Main/OUT_1ms 4/OUT_CANTxAnalog 6
			OUT_CANTxAna2Data.OUT_Analogue3 = INInterface.IN_ADC6_PTE2; // Main/OUT_1ms 4/OUT_CANTxAnalog 7
			OUT_CANTxAna2Data.OUT_Analogue4 = INInterface.IN_ADC7_PTE6; // Main/OUT_1ms 4/OUT_CANTxAnalog 8
			OUT_CANTxAna3Data.OUT_Analogue1 = INInterface.IN_ADC8_PTA15; // Main/OUT_1ms 4/OUT_CANTxAnalog 9
			OUT_CANTxAna3Data.OUT_Analogue2 = INInterface.IN_ADC9_PTA16; // Main/OUT_1ms 4/OUT_CANTxAnalog 10
			OUT_CANTxAna3Data.OUT_Analogue3 = INInterface.IN_ADC10_PTA1; // Main/OUT_1ms 4/OUT_CANTxAnalog 11
			OUT_CANTxAna3Data.OUT_Analogue4 = INInterface.IN_ADC11_PTA0; // Main/OUT_1ms 4/OUT_CANTxAnalog 12
			OUT_CANTxAna4Data.OUT_Analogue1 = INInterface.IN_ADC12_PTA7; // Main/OUT_1ms 4/OUT_CANTxAnalog 13
			OUT_CANTxAna4Data.OUT_Analogue2 = INInterface.IN_ADC13_PTB13; // Main/OUT_1ms 4/OUT_CANTxAnalog 14
			OUT_CANTxAna4Data.OUT_Analogue3 = INInterface.IN_ADC14_PTC1; // Main/OUT_1ms 4/OUT_CANTxAnalog 15
			OUT_CANTxAna4Data.OUT_Analogue4 = (if OUT_SENDPOT then INInterface.IN_Potentiometer_PTC14 else INInterface.IN_ADC15_PTC2); // Main/OUT_1ms 4/OUT_CANTxAnalog 16
			if (OUT_AnaSched == 0) {
				OUT_Ana1Status = OUT_TxAna1.txCANMsg(OUT_Ana1Handle, OUT_CANTxAna1Data); // Main/OUT_1ms 4/OUT_CANTxAnalog 17/if-then 1
			} // Main/OUT_1ms 4/OUT_CANTxAnalog 17
			if (OUT_AnaSched == 1) {
				OUT_Ana2Status = OUT_TxAna2.txCANMsg(OUT_Ana2Handle, OUT_CANTxAna2Data); // Main/OUT_1ms 4/OUT_CANTxAnalog 18/if-then 1
			} // Main/OUT_1ms 4/OUT_CANTxAnalog 18
			if (OUT_AnaSched == 2) {
				OUT_Ana3Status = OUT_TxAna3.txCANMsg(OUT_Ana3Handle, OUT_CANTxAna3Data); // Main/OUT_1ms 4/OUT_CANTxAnalog 19/if-then 1
			} // Main/OUT_1ms 4/OUT_CANTxAnalog 19
			if (OUT_AnaSched == 3) {
				OUT_Ana4Status = OUT_TxAna4.txCANMsg(OUT_Ana4Handle, OUT_CANTxAna4Data); // Main/OUT_1ms 4/OUT_CANTxAnalog 20/if-then 1
			} // Main/OUT_1ms 4/OUT_CANTxAnalog 20
		} // Main/OUT_1ms 4
	}

	@thread
	@generated("blockdiagram", "f438e076")
	public void OUT_Init() {
		{
			OUT_IC1Handle = OUT_CANMsgInit.initCANMsg(OUT_IC1CHANNEL, OUT_IC1ID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 1
			OUT_IC2Handle = OUT_CANMsgInit.initCANMsg(OUT_IC2CHANNEL, OUT_IC2ID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 2
			OUT_IC3Handle = OUT_CANMsgInit.initCANMsg(OUT_IC3CHANNEL, OUT_IC3ID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 3
			OUT_IC4Handle = OUT_CANMsgInit.initCANMsg(OUT_IC4CHANNEL, OUT_IC4ID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 4
			OUT_IC5Handle = OUT_CANMsgInit.initCANMsg(OUT_IC5CHANNEL, OUT_IC5ID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 5
			OUT_IC6Handle = OUT_CANMsgInit.initCANMsg(OUT_IC6CHANNEL, OUT_IC6ID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 6
			OUT_IC7Handle = OUT_CANMsgInit.initCANMsg(OUT_IC7CHANNEL, OUT_IC7ID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 7
			OUT_IC8Handle = OUT_CANMsgInit.initCANMsg(OUT_IC8CHANNEL, OUT_IC8ID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 8
			OUT_LeverHandle = OUT_CANMsgInit.initCANMsg(OUT_LEVERCHANNEL, OUT_LEVERID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 9
			OUT_Ana1Handle = OUT_CANMsgInit.initCANMsg(OUT_ANA1CHANNEL, OUT_ANA1ID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 10
			OUT_Ana2Handle = OUT_CANMsgInit.initCANMsg(OUT_ANA2CHANNEL, OUT_ANA2ID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 11
			OUT_Ana3Handle = OUT_CANMsgInit.initCANMsg(OUT_ANA3CHANNEL, OUT_ANA3ID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 12
			OUT_Ana4Handle = OUT_CANMsgInit.initCANMsg(OUT_ANA4CHANNEL, OUT_ANA4ID, true, false, 8); // Main/OUT_Init 1/OUT_CANInitMsgs 13
		} // Main/OUT_Init 1
	}

	@thread
	@generated("blockdiagram", "0feac339")
	public void OUT_100ms() {
	}

	@thread
	@generated("blockdiagram", "0969c4de")
	public void OUT_10ms() {
		{
			OUT_CANTxLeverData.LVR_Counter = OUT_CANCount.LIB_4BitCount(false); // Main/OUT_10ms 1/OUT_CANTxLever 1
			OUT_LeverStatus = OUT_CANTx_Lever.txCANMsg(OUT_LeverHandle, OUT_CANTxLeverData); // Main/OUT_10ms 1/OUT_CANTxLever 2
			OUT_CANTxLeverData.LVR_ParkSwitch = APPInterface.APP_LeverOut.LVR_ParkSwitch; // Main/OUT_10ms 1/OUT_CANTxLever 3
			OUT_CANTxLeverData.LVR_ReverseSwitch = APPInterface.APP_LeverOut.LVR_ReverseSwitch; // Main/OUT_10ms 1/OUT_CANTxLever 4
			OUT_CANTxLeverData.LVR_NeutralSwitch = APPInterface.APP_LeverOut.LVR_NeutralSwitch; // Main/OUT_10ms 1/OUT_CANTxLever 5
			OUT_CANTxLeverData.LVR_DriveSwitch = APPInterface.APP_LeverOut.LVR_DriveSwitch; // Main/OUT_10ms 1/OUT_CANTxLever 6
			OUT_CANTxLeverData.LVR_ManualSwitch = APPInterface.APP_LeverOut.LVR_ManualSwitch; // Main/OUT_10ms 1/OUT_CANTxLever 7
			OUT_CANTxLeverData.LVR_PlusSwitch = APPInterface.APP_LeverOut.LVR_PlusSwitch; // Main/OUT_10ms 1/OUT_CANTxLever 8
			OUT_CANTxLeverData.LVR_MinusSwitch = APPInterface.APP_LeverOut.LVR_MinusSwitch; // Main/OUT_10ms 1/OUT_CANTxLever 9
			OUT_CANTxLeverData.LVR_SportSwitch = APPInterface.APP_LeverOut.LVR_SportSwitch; // Main/OUT_10ms 1/OUT_CANTxLever 10
			OUT_CANTxLeverData.LVR_TestResponse = APPInterface.APP_LeverOut.LVR_TestResponse; // Main/OUT_10ms 1/OUT_CANTxLever 11
		} // Main/OUT_10ms 1
	}
}