package interfaces;
import common_esdl.c;

data interface messages {
	@symbol("Actual_Velocity_LC")
	c Actual_Velocity_LC = 0.0;
	@symbol("Actual_Velocity_EC")
	c Actual_Velocity_EC = 0.0;
	@symbol("Actual_Position_LC")
	c Actual_Position_LC = 0.0;
	@symbol("Actual_Position_EC")
	c Actual_Position_EC = 0.0;
	
	@symbol("Relative_Distance")
	c Relative_Distance = 0.0;
	@symbol("Relative_Velocity")
	c Relative_Velocity = 0.0;
	
	@symbol("Set_Velocity")
	c Set_Velocity = 0.0;
	
	@symbol("Acceleration_EC")
	c Acceleration_EC = 0.0;
	@symbol("Safe_Distance")
	c Safe_Distance = 0.0;
	
}