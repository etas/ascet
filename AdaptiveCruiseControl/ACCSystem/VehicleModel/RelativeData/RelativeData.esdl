package VehicleModel.RelativeData;

import interfaces.messages;
import SystemLib.Transferfunction.Integrator.IntegratorK;

singleton class RelativeData
reads messages.Actual_Velocity_LC, messages.Actual_Velocity_EC
writes messages.Relative_Distance, messages.Relative_Velocity, messages.Actual_Position_LC, messages.Actual_Position_EC {

	IntegratorK Position_EC;
	IntegratorK Position_LC;
	real v;

	@thread
	@generated("blockdiagram", "bd05f8c6")
	public void proc_10ms() {
		messages.Relative_Distance = (Position_LC.value() - Position_EC.value()); // Main/proc_10ms 1
		messages.Relative_Velocity = (messages.Actual_Velocity_LC - messages.Actual_Velocity_EC); // Main/proc_10ms 2
		Position_LC.compute(messages.Actual_Velocity_LC, 0.27778); // Main/proc_10ms 3
		Position_EC.compute(messages.Actual_Velocity_EC, 0.27778); // Main/proc_10ms 4
		messages.Actual_Position_LC = Position_LC.value(); // Main/proc_10ms 5
		messages.Actual_Position_EC = Position_EC.value(); // Main/proc_10ms 6
	}

	@thread
	@generated("blockdiagram", "08657fd8")
	public void proc_ini() {
		messages.Relative_Velocity = 0.0; // Ini/proc_ini 1
		messages.Relative_Distance = 0.0; // Ini/proc_ini 2
	}

	@thread
	@generated("blockdiagram", "898e258f")
	public void SetDistance100() {
		Position_LC.reset(100.0); // Main/SetDistance100 1
		Position_EC.reset(0.0); // Main/SetDistance100 2
	}

	@thread
	@generated("blockdiagram", "e6c1ab1b")
	public void AntiOverFlow_10ms() {
		if ((Position_EC.value() > 2000.0) || (Position_LC.value() > 2000.0)) {
			Position_EC.reset((Position_EC.value() - 2000.0)); // OwervlowReset/AntiOverFlow_10ms 1/if-then 1
			Position_LC.reset((Position_LC.value() - 2000.0)); // OwervlowReset/AntiOverFlow_10ms 1/if-then 2
		} // OwervlowReset/AntiOverFlow_10ms 1
	}
}