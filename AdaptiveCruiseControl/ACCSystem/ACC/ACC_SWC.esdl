package ACC;

import common_esdl.c;
import interfaces.messages;
import SystemLib.Nonlinears.Limiter;

singleton class ACC_SWC
reads messages.Set_Velocity, messages.Actual_Velocity_EC, messages.Relative_Distance, messages.Relative_Velocity
writes messages.Safe_Distance, messages.Acceleration_EC {

	Limiter Limiter;
	characteristic c Time_Gap = 1.4;
	characteristic c Velocity_Error_Gain = 0.5;
	characteristic c Spacing_Error_Gain = 0.2;
	characteristic c Relative_Velocity_Gain = 0.4;
	characteristic c Default_Distance = 10.0;

	@thread
	@generated("blockdiagram", "7a02b152")
	public void proc_10ms() {
		messages.Safe_Distance = (Default_Distance + (Time_Gap * messages.Actual_Velocity_EC)); // Main/proc_10ms 1
		messages.Acceleration_EC = Limiter.value(-3.0, (if(((Default_Distance + (Time_Gap * messages.Actual_Velocity_EC)) - messages.Relative_Distance) > 0.0) then((messages.Relative_Velocity * Relative_Velocity_Gain) - (((Default_Distance + (Time_Gap * messages.Actual_Velocity_EC)) - messages.Relative_Distance) * Spacing_Error_Gain)) else min(((messages.Set_Velocity - messages.Actual_Velocity_EC) * Velocity_Error_Gain), ((messages.Relative_Velocity * Relative_Velocity_Gain) - (((Default_Distance + (Time_Gap * messages.Actual_Velocity_EC)) - messages.Relative_Distance) * Spacing_Error_Gain)))), 2.0); // Main/proc_10ms 2
	}

	@thread
	@generated("blockdiagram", "abd2bf81")
	public void proc_ini() {
		messages.Safe_Distance = 0.0; // Ini/proc_ini 1
		messages.Acceleration_EC = 0.0; // Ini/proc_ini 2
	}
}