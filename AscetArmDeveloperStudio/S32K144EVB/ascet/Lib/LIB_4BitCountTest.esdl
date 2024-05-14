package ascet.Lib;
import types.T_CANMsgCtr;

class LIB_4BitCountTest {
	boolean LIB_OkayThisCycle = false;
	T_CANMsgCtr LIB_CounterPrevious = 0;
	characteristic T_CANMsgCtr LIB_PASSCYCLESOKAY = 3;
	T_CANMsgCtr LIB_Counter = 0;
	boolean LIB_CheckOk = false;
	characteristic T_CANMsgCtr LIB_PASSCYCLESFAIL = 2;

	@generated("blockdiagram", "1cde4b1e")
	public boolean LIB_CheckOkay(T_CANMsgCtr in LIB_CountIn) {
		LIB_OkayThisCycle = (if(LIB_CountIn == 0) then(LIB_CounterPrevious == 15) else(LIB_CountIn == (LIB_CounterPrevious + 1))); // Main/LIB_CheckOkay 1
		LIB_Counter = (if LIB_OkayThisCycle then max((LIB_Counter - 1), 0) else min((LIB_Counter + 1), LIB_PASSCYCLESOKAY)); // Main/LIB_CheckOkay 2
		LIB_CheckOk = (if(LIB_Counter >= LIB_PASSCYCLESFAIL) then false else(if(LIB_Counter == 0) then true else LIB_CheckOk)); // Main/LIB_CheckOkay 3
		LIB_CounterPrevious = LIB_CountIn; // Main/LIB_CheckOkay 4
		return LIB_CheckOk; // Main/LIB_CheckOkay 5
	}
}