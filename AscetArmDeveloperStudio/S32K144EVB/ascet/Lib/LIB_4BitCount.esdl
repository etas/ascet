package ascet.Lib;
import types.T_Bitfield4;

class LIB_4BitCount {
	T_Bitfield4 LIB_Counter = 0;

	@generated("blockdiagram", "2d8423a3")
	public T_Bitfield4 LIB_4BitCount(boolean in LIB_Reset) {
		LIB_Counter = (if((LIB_Counter == 15) || LIB_Reset) then 0 else(LIB_Counter + 1)); // Main/LIB_4BitCount 1
		return LIB_Counter; // Main/LIB_4BitCount 2
	}
}