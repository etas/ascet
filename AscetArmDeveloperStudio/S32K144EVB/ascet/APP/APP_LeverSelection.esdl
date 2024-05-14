package ascet.APP;
import types.T_LeverOut;
import types.T_Analogue;

class APP_LeverSelection {
	T_LeverOut APP_LeverSwitch;
	characteristic T_Analogue APP_MINUSSWITCHMIN = 0.5;
	characteristic T_Analogue APP_MINUSSWITCHMAX = 1.5;
	boolean APP_AnalogueMinus;
	boolean APP_AnaloguePlus;
	characteristic T_Analogue APP_PLUSSWITCHMIN = 3.0;
	characteristic T_Analogue APP_PLUSSWITCHMAX = 4.0;
	APP_SwitchInterpretation APP_ParkSwitchInterp;
	characteristic boolean APP_PARKSWFITTED = false;
	characteristic boolean APP_REVERSESWFITTED = true;
	APP_SwitchInterpretation APP_ReverseSwitchInterp;
	APP_SwitchInterpretation APP_NeutralSwitchInterp;
	APP_SwitchInterpretation APP_DriveSwitchInterp;
	APP_SwitchInterpretation APP_SportSwitchInterp;
	APP_SwitchInterpretation APP_ManualSwitchInterp;
	APP_SwitchInterpretation APP_PlusSwitchInterp;
	APP_SwitchInterpretation APP_MinusSwitchInterp;
	characteristic boolean APP_ANALOGUEPLUSMINUS = true;
	characteristic boolean APP_NEUTRALSWFITTED = true;
	characteristic boolean APP_DRIVESWFITTED = true;
	characteristic boolean APP_SPORTSWFITTED = true;
	characteristic boolean APP_MANUALSWFITTED = true;
	characteristic boolean APP_PLUSSWFITTED = true;
	characteristic boolean APP_MINUSSWFITTED = true;

	@generated("blockdiagram", "df5c3c06")
	public T_LeverOut APP_LeverSelect(boolean in IN_ParkSwitch, boolean in IN_ReverseSwitch, boolean in IN_NeutralSwitch, boolean in IN_DriveSwitch, boolean in IN_SportSwitch, boolean in IN_ManualSwitch, boolean in IN_PlusSwitch, boolean in IN_MinusSwitch, T_Analogue in IN_SteeringWheel) {
		{
			APP_AnalogueMinus = between(IN_SteeringWheel, APP_MINUSSWITCHMIN, APP_MINUSSWITCHMAX); // Main/APP_LeverSelect 1/APP_PaddleAnalogue 1
			APP_AnaloguePlus = between(IN_SteeringWheel, APP_PLUSSWITCHMIN, APP_PLUSSWITCHMAX); // Main/APP_LeverSelect 1/APP_PaddleAnalogue 2
		} // Main/APP_LeverSelect 1
		{
			APP_LeverSwitch.LVR_ParkSwitch = APP_ParkSwitchInterp.APP_SwitchState(IN_ParkSwitch, APP_PARKSWFITTED); // Main/APP_LeverSelect 2/APP_Switches 1
			APP_LeverSwitch.LVR_ReverseSwitch = APP_ReverseSwitchInterp.APP_SwitchState(IN_ReverseSwitch, APP_REVERSESWFITTED); // Main/APP_LeverSelect 2/APP_Switches 2
			APP_LeverSwitch.LVR_NeutralSwitch = APP_NeutralSwitchInterp.APP_SwitchState(IN_NeutralSwitch, APP_NEUTRALSWFITTED); // Main/APP_LeverSelect 2/APP_Switches 3
			APP_LeverSwitch.LVR_DriveSwitch = APP_DriveSwitchInterp.APP_SwitchState(IN_DriveSwitch, APP_DRIVESWFITTED); // Main/APP_LeverSelect 2/APP_Switches 4
			APP_LeverSwitch.LVR_SportSwitch = APP_SportSwitchInterp.APP_SwitchState(IN_SportSwitch, APP_SPORTSWFITTED); // Main/APP_LeverSelect 2/APP_Switches 5
			APP_LeverSwitch.LVR_ManualSwitch = APP_ManualSwitchInterp.APP_SwitchState(IN_ManualSwitch, APP_MANUALSWFITTED); // Main/APP_LeverSelect 2/APP_Switches 6
			APP_LeverSwitch.LVR_PlusSwitch = APP_PlusSwitchInterp.APP_SwitchState((if APP_ANALOGUEPLUSMINUS then APP_AnaloguePlus else IN_PlusSwitch), APP_PLUSSWFITTED); // Main/APP_LeverSelect 2/APP_Switches 7
			APP_LeverSwitch.LVR_MinusSwitch = APP_MinusSwitchInterp.APP_SwitchState((if APP_ANALOGUEPLUSMINUS then APP_AnalogueMinus else IN_MinusSwitch), APP_MINUSSWFITTED); // Main/APP_LeverSelect 2/APP_Switches 8
		} // Main/APP_LeverSelect 2
		return APP_LeverSwitch; // Main/APP_LeverSelect 3
	}
}