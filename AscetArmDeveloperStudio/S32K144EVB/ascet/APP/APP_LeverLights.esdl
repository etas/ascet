package ascet.APP;
import types.T_LeverIn;
import ascet.Lib.LIB_TimerUp;
import types.SY_10ms;
import types.T_Time;
import types.T_DutyPercent;
import enumerations.H_Status;

class APP_LeverLights {
	LIB_TimerUp APP_FlashCounter;
	T_Time APP_FlashTime = 0.0;
	characteristic T_Time APP_FLASHTOGGLETIME = 0.75;
	boolean APP_FlashState = false;
	characteristic T_DutyPercent APP_FLASHOFFDUTY = 5.0;
	characteristic T_DutyPercent APP_FLASHONDUTY = 95.0;
	T_DutyPercent APP_FlashDuty = 0.0;
	boolean APP_TCMLinkOkay = false;
	APP_LightDutySwitch APP_LightDuty;
	boolean APP_Backlight = false;
	@get
	T_DutyPercent APP_ReverseDuty = 0.0;
	@get
	T_DutyPercent APP_ParkDuty = 0.0;
	@get
	T_DutyPercent APP_NeutralDuty = 0.0;
	@get
	T_DutyPercent APP_DriveDuty = 0.0;
	@get
	T_DutyPercent APP_SportDuty = 0.0;
	@get
	T_DutyPercent APP_ManualDuty = 0.0;

	@generated("blockdiagram", "fc4a0334")
	public void APP_LightCtrl(T_LeverIn in IN_LeverLights, boolean in IN_Backlight) {
		{
			APP_FlashTime = APP_FlashCounter.LIB_Time((APP_FlashTime >= APP_FLASHTOGGLETIME), SY_10ms); // Main/APP_LightCtrl 1/APP_FlashGenerator 1
			APP_FlashState = (if(APP_FlashTime == 0.0) then(!APP_FlashState) else APP_FlashState); // Main/APP_LightCtrl 1/APP_FlashGenerator 2
			APP_FlashDuty = (if APP_FlashState then APP_FLASHONDUTY else APP_FLASHOFFDUTY); // Main/APP_LightCtrl 1/APP_FlashGenerator 3
		} // Main/APP_LightCtrl 1
		{
			APP_TCMLinkOkay = (IN_LeverLights.TCM_Status == H_Status.H_Okay); // Main/APP_LightCtrl 2/APP_TCMStatus 1
			APP_Backlight = (if(IN_LeverLights.TCM_BackLight == 3) then IN_Backlight else(!(IN_LeverLights.TCM_BackLight == 1))); // Main/APP_LightCtrl 2/APP_TCMStatus 2
		} // Main/APP_LightCtrl 2
		{
			APP_ParkDuty = APP_LightDuty.APP_LightDuty(IN_LeverLights.TCM_ParkLight, APP_FlashDuty, APP_Backlight, APP_TCMLinkOkay); // Main/APP_LightCtrl 3/APP_LightDuty 1
			APP_NeutralDuty = APP_LightDuty.APP_LightDuty(IN_LeverLights.TCM_NeutralLight, APP_FlashDuty, APP_Backlight, APP_TCMLinkOkay); // Main/APP_LightCtrl 3/APP_LightDuty 2
			APP_ReverseDuty = APP_LightDuty.APP_LightDuty(IN_LeverLights.TCM_ReverseLight, APP_FlashDuty, APP_Backlight, APP_TCMLinkOkay); // Main/APP_LightCtrl 3/APP_LightDuty 3
			APP_DriveDuty = APP_LightDuty.APP_LightDuty(IN_LeverLights.TCM_DriveLight, APP_FlashDuty, APP_Backlight, APP_TCMLinkOkay); // Main/APP_LightCtrl 3/APP_LightDuty 4
			APP_SportDuty = APP_LightDuty.APP_LightDuty(IN_LeverLights.TCM_SportLight, APP_FlashDuty, APP_Backlight, APP_TCMLinkOkay); // Main/APP_LightCtrl 3/APP_LightDuty 5
			APP_ManualDuty = APP_LightDuty.APP_LightDuty(IN_LeverLights.TCM_ManualLight, APP_FlashDuty, APP_Backlight, APP_TCMLinkOkay); // Main/APP_LightCtrl 3/APP_LightDuty 6
		} // Main/APP_LightCtrl 3
	}
}