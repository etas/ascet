package ascet.Lib;
import types.T_Counter;

class LIB_CounterUp {
	T_Counter LIB_TimeInternal = 0;

	@generated("blockdiagram", "351d1b83")
	public T_Counter LIB_Count(boolean in LIB_Reset) {
		LIB_TimeInternal = (if LIB_Reset then 0 else(LIB_TimeInternal + 1)); // Main/LIB_Count 1
		return LIB_TimeInternal; // Main/LIB_Count 2
	}
}