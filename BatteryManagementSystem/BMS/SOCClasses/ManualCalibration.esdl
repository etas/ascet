package SOCClasses;

import Interfaces.akku_messages;

singleton class ManualCalibration
writes akku_messages.current, akku_messages.T_ambient {

	characteristic real c_Current = 0.0;
	characteristic real c_T_ambient = 293.0;
	characteristic boolean ManualCalibration_ = false;

	@thread
	@generated("blockdiagram", "e81677b7")
	public void calc() {
		if (ManualCalibration_) {
			akku_messages.current = c_Current; // Main/calc 1/if-then 1
			akku_messages.T_ambient = c_T_ambient; // Main/calc 1/if-then 2
		} // Main/calc 1
	}
}