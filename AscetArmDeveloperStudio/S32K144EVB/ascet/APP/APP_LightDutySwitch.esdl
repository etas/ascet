package ascet.APP;
import types.T_DutyPercent;
import types.T_Bitfield2;

class APP_LightDutySwitch {
	characteristic T_DutyPercent APP_LIGHTOFFNOBACKDUTY = 5.0;
	characteristic T_DutyPercent APP_LIGHTOFFWITHBACKDUTY = 25.0;
	characteristic T_DutyPercent APP_LIGHTONNOBACKDUTY = 85.0;
	characteristic T_DutyPercent APP_LIGHTONWITHBACKDUTY = 95.0;
	characteristic boolean APP_INVERTDUTY = false;

	@generated("blockdiagram", "5a62ffba")
	public T_DutyPercent APP_LightDuty(T_Bitfield2 in APP_SwitchState, T_DutyPercent in APP_FlashDuty, boolean in APP_Backlight, boolean in APP_TCMOkay) {
		return(if APP_INVERTDUTY then(100.0 - (if(APP_SwitchState == 3) then 1.0 else(if(APP_TCMOkay && (APP_SwitchState != 0)) then(if APP_Backlight then(if(APP_SwitchState == 1) then APP_LIGHTOFFWITHBACKDUTY else APP_LIGHTONWITHBACKDUTY) else(if(APP_SwitchState == 1) then APP_LIGHTOFFNOBACKDUTY else APP_LIGHTONNOBACKDUTY)) else APP_FlashDuty))) else(if(APP_SwitchState == 3) then 1.0 else(if(APP_TCMOkay && (APP_SwitchState != 0)) then(if APP_Backlight then(if(APP_SwitchState == 1) then APP_LIGHTOFFWITHBACKDUTY else APP_LIGHTONWITHBACKDUTY) else(if(APP_SwitchState == 1) then APP_LIGHTOFFNOBACKDUTY else APP_LIGHTONNOBACKDUTY)) else APP_FlashDuty))); // Main/APP_LightDuty 1
	}
}