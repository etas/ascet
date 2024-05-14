package ascet.Lib;

class LIB_Rise {
	boolean LIB_Prev = false;
	boolean LIB_RiseLocal = false;

	@generated("blockdiagram", "26e028ee")
	public boolean LIB_Rising(boolean in LIB_Input) {
		LIB_RiseLocal = (LIB_Input && (!LIB_Prev)); // Main/LIB_Rising 1
		LIB_Prev = LIB_Input; // Main/LIB_Rising 2
		return LIB_RiseLocal; // Main/LIB_Rising 3
	}
}