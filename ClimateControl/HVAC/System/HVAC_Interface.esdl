package System;

data interface HVAC_Interface {
	real T_Environment = 20.0;
	real T_Setpoint = 20.0;
	OnOffSwitch VentilationSetpoint = OnOffSwitch.Off;
	Rate R_Ventilation = 0.0;
	boolean b_Cooler = false;
	boolean b_Heater = false;	
}

type Rate is real 0.0 .. 1.0;

type OnOffSwitch is enum  {
	Off = 0,
	On = 1,
	Automatic = 2,
	Manual = 3
};