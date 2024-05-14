package ascet.Lib;

class LIB_Fall {
	boolean LIB_Prev = false;
	boolean LIB_FallLocal = false;

	@generated("blockdiagram", "ac2084ec")
	public boolean LIB_Falling(boolean in LIB_Input) {
		LIB_FallLocal = ((!LIB_Input) && LIB_Prev); // Main/LIB_Falling 1
		LIB_Prev = LIB_Input; // Main/LIB_Falling 2
		return LIB_FallLocal; // Main/LIB_Falling 3
	}
}