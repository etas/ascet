package ascet.APP;
import interfaces.APPInterface;
import interfaces.INInterface;
import types.T_Speed;

singleton class APP
writes APPInterface.APP_RedLED, APPInterface.APP_GreenLED, APPInterface.APP_BlueLED, APPInterface.APP_D8_PTD13, APPInterface.APP_D9_PTD14, APPInterface.APP_D10_PTB5, APPInterface.APP_D11_PTB4, APPInterface.APP_D12_PTB3, APPInterface.APP_D13_PTB2, APPInterface.APP_D14_PTA9, APPInterface.APP_D15_PTA8, APPInterface.APP_D16_PTE12, APPInterface.APP_D17_PTD17, APPInterface.APP_D18_PTC9, APPInterface.APP_D19_PTC8, APPInterface.APP_D20_PTD8, APPInterface.APP_D21_PTD9, APPInterface.APP_GPIOPTD2, APPInterface.APP_GPIOPTD0, APPInterface.APP_LeverOut
reads APPInterface.APP_RedLED, INInterface.IN_Potentiometer_PTC14, INInterface.IN_SW2_PTC12, INInterface.IN_SW3_PTC13, INInterface.IN_GPIOPTB6, INInterface.IN_GPIOPTB7, INInterface.IN_LeverIn, INInterface.IN_GPIOPTE0, INInterface.IN_GPIOPTE9, INInterface.IN_GPIOPTC5, INInterface.IN_GPIOPTC4, INInterface.IN_GPIOPTA10, INInterface.IN_D6_IC_PTC12, INInterface.IN_D7_IC_PTC13 {

	boolean APP_Toggle = false;
	APP_LeverLights APP_LeverLightControl;
	APP_LeverSelection APP_LeverSelect;
	APP_Sanity APP_SanityCheck;
	APP_RGBControl APP_RGBSM;
	T_Speed APP_SpeedSum = 0.0;
	T_Speed APP_SpeedOperand1 = 0.0;
	T_Speed APP_SpeedOperand2 = 0.0;
	T_Speed APP_SpeedSubtraction = 0.0;

	@thread
	@generated("blockdiagram", "8fbfe19c")
	public void APP_1ms() {
		{
			APP_RGBSM.APP_Sw2 = INInterface.IN_SW2_PTC12; // Main/APP_1ms 1/APP_UpdateLED 1
			APP_RGBSM.APP_Sw3 = INInterface.IN_SW3_PTC13; // Main/APP_1ms 1/APP_UpdateLED 2
			APP_RGBSM.APP_Pot = INInterface.IN_Potentiometer_PTC14; // Main/APP_1ms 1/APP_UpdateLED 3
			APP_RGBSM.APP_RGBStateMachineTrig(); // Main/APP_1ms 1/APP_UpdateLED 4
			APPInterface.APP_RedLED = (100.0 - APP_RGBSM.APP_RedDuty); // Main/APP_1ms 1/APP_UpdateLED 5
			APPInterface.APP_GreenLED = (100.0 - APP_RGBSM.APP_GreenDuty); // Main/APP_1ms 1/APP_UpdateLED 6
			APPInterface.APP_BlueLED = (100.0 - APP_RGBSM.APP_BlueDuty); // Main/APP_1ms 1/APP_UpdateLED 7
		} // Main/APP_1ms 1
		{
			APP_Toggle = (!APP_Toggle); // Main/APP_1ms 2/APP_StimDig 1
			APPInterface.APP_D14_PTA9 = APP_Toggle; // Main/APP_1ms 2/APP_StimDig 2
			APPInterface.APP_D15_PTA8 = APP_Toggle; // Main/APP_1ms 2/APP_StimDig 3
			APPInterface.APP_D16_PTE12 = APP_Toggle; // Main/APP_1ms 2/APP_StimDig 4
			APPInterface.APP_D17_PTD17 = APP_Toggle; // Main/APP_1ms 2/APP_StimDig 5
			APPInterface.APP_D18_PTC9 = APP_Toggle; // Main/APP_1ms 2/APP_StimDig 6
			APPInterface.APP_D19_PTC8 = APP_Toggle; // Main/APP_1ms 2/APP_StimDig 7
			APPInterface.APP_D20_PTD8 = APP_Toggle; // Main/APP_1ms 2/APP_StimDig 8
			APPInterface.APP_D21_PTD9 = APP_Toggle; // Main/APP_1ms 2/APP_StimDig 9
			APPInterface.APP_GPIOPTD2 = APP_Toggle; // Main/APP_1ms 2/APP_StimDig 10
			APPInterface.APP_GPIOPTD0 = APP_Toggle; // Main/APP_1ms 2/APP_StimDig 11
		} // Main/APP_1ms 2
		{
			APP_SpeedOperand1 = INInterface.IN_D6_IC_PTC12.IN_Speed; // Main/APP_1ms 3/APP_ArithmeticExample 1
			APP_SpeedOperand2 = INInterface.IN_D7_IC_PTC13.IN_Speed; // Main/APP_1ms 3/APP_ArithmeticExample 2
			APP_SpeedSum = (APP_SpeedOperand1 + APP_SpeedOperand2); // Main/APP_1ms 3/APP_ArithmeticExample 3
			APP_SpeedSubtraction = (APP_SpeedOperand1 - APP_SpeedOperand2); // Main/APP_1ms 3/APP_ArithmeticExample 4
		} // Main/APP_1ms 3
	}

	@thread
	@generated("blockdiagram", "44b9aefc")
	public void APP_10ms() {
		{
			APPInterface.APP_LeverOut = APP_LeverSelect.APP_LeverSelect(INInterface.IN_GPIOPTB6, INInterface.IN_GPIOPTB7, INInterface.IN_SW2_PTC12, INInterface.IN_SW3_PTC13, INInterface.IN_GPIOPTE0, INInterface.IN_GPIOPTE9, INInterface.IN_GPIOPTC5, INInterface.IN_GPIOPTC4, INInterface.IN_Potentiometer_PTC14); // Main/APP_10ms 1/APP_Lever 1
			APPInterface.APP_LeverOut.LVR_TestResponse = APP_SanityCheck.SanityReturn(INInterface.IN_LeverIn.TCM_TestData1, INInterface.IN_LeverIn.TCM_TestData2); // Main/APP_10ms 1/APP_Lever 2
			APP_LeverLightControl.APP_LightCtrl(INInterface.IN_LeverIn, INInterface.IN_GPIOPTA10); // Main/APP_10ms 1/APP_Lever 3
			APPInterface.APP_D8_PTD13 = APP_LeverLightControl.APP_ParkDuty; // Main/APP_10ms 1/APP_Lever 4
			APPInterface.APP_D9_PTD14 = APP_LeverLightControl.APP_ReverseDuty; // Main/APP_10ms 1/APP_Lever 5
			APPInterface.APP_D10_PTB5 = APP_LeverLightControl.APP_NeutralDuty; // Main/APP_10ms 1/APP_Lever 6
			APPInterface.APP_D11_PTB4 = APP_LeverLightControl.APP_DriveDuty; // Main/APP_10ms 1/APP_Lever 7
			APPInterface.APP_D12_PTB3 = APP_LeverLightControl.APP_SportDuty; // Main/APP_10ms 1/APP_Lever 8
			APPInterface.APP_D13_PTB2 = APP_LeverLightControl.APP_ManualDuty; // Main/APP_10ms 1/APP_Lever 9
		} // Main/APP_10ms 1
	}
}