package System;

singleton class HVACTest
writes HVAC_Interface.T_Environment
writes HVAC_Interface.T_Setpoint
writes HVAC_Interface.VentilationSetpoint {
	characteristic real Sti_T_Environment = 20.0;
	characteristic real Sti_T_Setpoint = 20.0;
	characteristic OnOffSwitch Sti_VentilationSetpoint = OnOffSwitch.Off;
	@thread
	public void calc() {
		HVAC_Interface.T_Environment = Sti_T_Environment;
		HVAC_Interface.T_Setpoint = Sti_T_Setpoint;
		HVAC_Interface.VentilationSetpoint = Sti_VentilationSetpoint;
	}

}