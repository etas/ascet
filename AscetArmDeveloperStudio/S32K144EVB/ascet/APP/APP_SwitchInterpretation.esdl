package ascet.APP;
import types.T_Bitfield2;
import types.logic;
import ascet.Lib.LIB_TimerUp;
import types.SY_10ms;
import types.T_Time;

class APP_SwitchInterpretation {
	LIB_TimerUp APP_SwitchTimer;
	characteristic T_Time APP_MAXSWITCHPRESSTIME = 10.0;

	@generated("blockdiagram", "686fa015")
	public T_Bitfield2 APP_SwitchState(logic in APP_SwitchIn, boolean in APP_SwitchFitted) {
		return(if(!APP_SwitchFitted) then 3 else(if(APP_SwitchTimer.LIB_Time((!APP_SwitchIn), SY_10ms) >= APP_MAXSWITCHPRESSTIME) then 0 else(if APP_SwitchIn then 2 else 1))); // Main/APP_SwitchState 1
	}
}