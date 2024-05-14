package ascet.Lib;
import enumerations.LB_RiseFall;

class LIB_RiseFall {
	boolean LIB_Prev = false;
	LB_RiseFall LIB_RiseFallLocal = LB_RiseFall.LB_Unchanged;

	@generated("blockdiagram", "cc448690")
	public LB_RiseFall LIB_RiseFall(boolean in LIB_Input) {
		LIB_RiseFallLocal = (if(LIB_Input && (!LIB_Prev)) then LB_RiseFall.LB_Rise else(if((!LIB_Input) && LIB_Prev) then LB_RiseFall.LB_Fall else LB_RiseFall.LB_Unchanged)); // Main/LIB_RiseFall 1
		LIB_Prev = LIB_Input; // Main/LIB_RiseFall 2
		return LIB_RiseFallLocal; // Main/LIB_RiseFall 3
	}
}