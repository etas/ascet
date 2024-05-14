package ascet.Lib;
import types.T_Time;

class LIB_TimerUp {
	T_Time LIB_TimeInternal = 0.0;

	@generated("blockdiagram", "93f7ddae")
	public T_Time LIB_Time(boolean in LIB_Reset, T_Time in LIB_DT) {
		LIB_TimeInternal = (if LIB_Reset then 0.0 else(LIB_TimeInternal + LIB_DT)); // Main/LIB_Time 1
		return LIB_TimeInternal; // Main/LIB_Time 2
	}
}