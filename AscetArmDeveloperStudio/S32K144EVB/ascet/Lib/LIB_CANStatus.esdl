package ascet.Lib;
import enumerations.H_Status;
import types.T_Time;

class LIB_CANStatus {
	T_Time LIB_TimeSinceLast = 0.0;

	@generated("blockdiagram", "b0ab963e")
	public H_Status LIB_Status(boolean in LIB_NewData, boolean in LIB_Plausible, T_Time in LIB_Timeout, T_Time in LIB_dT) {
		LIB_TimeSinceLast = (if LIB_NewData then 0.0 else(LIB_TimeSinceLast + LIB_dT)); // Main/LIB_Status 1
		return(if(LIB_TimeSinceLast >= LIB_Timeout) then H_Status.H_Timeout else(if(!LIB_Plausible) then H_Status.H_Implausible else H_Status.H_Okay)); // Main/LIB_Status 2
	}
}