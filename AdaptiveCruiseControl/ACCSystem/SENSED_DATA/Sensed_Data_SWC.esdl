package SENSED_DATA;
import interfaces.messages;

singleton class Sensed_Data_SWC
reads messages.Actual_Position_LC, messages.Actual_Position_EC, messages.Actual_Velocity_LC, messages.Actual_Velocity_EC

writes messages.Relative_Distance, messages.Relative_Velocity {
	@thread
	@generated("blockdiagram", "ffec7430")
	public void proc_10ms() {
		messages.Relative_Distance = (messages.Actual_Position_LC - messages.Actual_Position_EC); // Main/proc_10ms 1
		messages.Relative_Velocity = (messages.Actual_Velocity_LC - messages.Actual_Velocity_EC); // Main/proc_10ms 2
	}

	@thread
	@generated("blockdiagram", "a5099f66")
	public void proc_ini() {
		messages.Relative_Velocity = 0.0; // Ini/proc_ini 1
		messages.Relative_Distance = 0.0; // Ini/proc_ini 2
	}
}