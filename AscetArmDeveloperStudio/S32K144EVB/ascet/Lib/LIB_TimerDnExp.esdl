package ascet.Lib;
import types.T_Time;

class LIB_TimerDnExp {
	T_Time LIB_CurrentTime = 0.0;

	@generated("blockdiagram", "440e44f7")
	public boolean LIB_Expired(T_Time in LIB_DT, boolean in LIB_Run) {
		LIB_CurrentTime = (if LIB_Run then max((LIB_CurrentTime - LIB_DT), 0.0) else LIB_CurrentTime); // Main/LIB_Expired 1
		return(LIB_CurrentTime == 0.0); // Main/LIB_Expired 2
	}

	@generated("blockdiagram", "6d001aa9")
	public void LIB_Init(T_Time in LIB_TimeIn) {
		LIB_CurrentTime = LIB_TimeIn; // Main/LIB_Init 1
	}

	@generated("blockdiagram", "17b21c23")
	public T_Time LIB_Time() {
		return LIB_CurrentTime; // Main/LIB_Time 1
	}
}