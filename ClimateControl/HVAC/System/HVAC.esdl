package System;

import System.Congra.InteriorModel_c_AC;
import System.Congra.InteriorModel_c_Heat;
import System.Scode.ET_Request_TemperatureEnum;
import System.Scode.ET_Request_VentilationEnum;
import System.Scode.modeSelector;
import System.Scode.ModesEnum;

/**
 * This class implements a heating, ventilation and air conditioning controller.
 * <ul>
 * <li>input <b>T_Environment</b>: environment temperature</li>
 * <li>input <b>T_Setpoint</b>: desire temperature inside the vehicle</li>
 * <li>input <b>VentilationSetpoint</b>: climate control mode - off, manual, auto</li>
 * <li>output <b>b_Cooler</b>: status heating</li>
 * <li>output <b>b_Heater</b>: status cooling</li>
 * <li>output <b>R_Ventilation</b>: ventilation rate</li>
 * </ul>
 */
singleton class HVAC
writes HVAC_Interface.b_Cooler, HVAC_Interface.b_Heater, HVAC_Interface.R_Ventilation
reads HVAC_Interface.T_Environment, HVAC_Interface.T_Setpoint, HVAC_Interface.VentilationSetpoint {

	ET_Request_TemperatureEnum temperatureRequest;
	ET_Request_VentilationEnum ventilationRequest;
	modeSelector modeSelector_instance;
	ModesEnum mode = ModesEnum.ET_System_Off;
	real rateVentilationCooler = 0.0;
	real rateVentilationHeater = 3.0;
	InteriorModel_c_AC InteriorModel_c_AC_instance;
	InteriorModel_c_Heat InteriorModel_c_Heat_instance;

	@thread
	@generated("blockdiagram", "69ca10cf")
	public void calc() {
		{
			if (HVAC_Interface.T_Environment > HVAC_Interface.T_Setpoint) {
				temperatureRequest = ET_Request_TemperatureEnum.ET_Below_Outside; // Main/calc 1/01_Input_Selection 1/if-then 1
			} else {
				temperatureRequest = ET_Request_TemperatureEnum.ET_Above_Outside; // Main/calc 1/01_Input_Selection 1/if-else 1
			} // Main/calc 1/01_Input_Selection 1
			if (HVAC_Interface.VentilationSetpoint == OnOffSwitch.Off) {
				ventilationRequest = ET_Request_VentilationEnum.ET_Off; // Main/calc 1/01_Input_Selection 2/if-then 1
			} else {
				if (HVAC_Interface.VentilationSetpoint == OnOffSwitch.Manual) {
					ventilationRequest = ET_Request_VentilationEnum.ET_Max; // Main/calc 1/01_Input_Selection 2/if-else 1/if-then 1
				} else {
					ventilationRequest = ET_Request_VentilationEnum.ET_Automatic; // Main/calc 1/01_Input_Selection 2/if-else 1/if-else 1
				} // Main/calc 1/01_Input_Selection 2/if-else 1
			} // Main/calc 1/01_Input_Selection 2
		} // Main/calc 1
		{
			modeSelector_instance.execute(ventilationRequest, temperatureRequest); // Main/calc 2/02_Mode_Selection 1
			mode = modeSelector_instance.getCurrentMode(); // Main/calc 2/02_Mode_Selection 2
		} // Main/calc 2
		switch (mode) {
			case ModesEnum.ET_System_Off : {
				{
					HVAC_Interface.b_Cooler = false; // Main/calc 3/case(ET_System_Off) 1/off 1
					HVAC_Interface.b_Heater = false; // Main/calc 3/case(ET_System_Off) 1/off 2
					HVAC_Interface.R_Ventilation = 0.0; // Main/calc 3/case(ET_System_Off) 1/off 3
				} // Main/calc 3/case(ET_System_Off) 1
			}
			case ModesEnum.ET_Uncontrolled : {
				{
					HVAC_Interface.b_Cooler = false; // Main/calc 3/case(ET_Uncontrolled) 1/Manual 1
					HVAC_Interface.b_Heater = false; // Main/calc 3/case(ET_Uncontrolled) 1/Manual 2
					HVAC_Interface.R_Ventilation = 0.0; // Main/calc 3/case(ET_Uncontrolled) 1/Manual 3
				} // Main/calc 3/case(ET_Uncontrolled) 1
			}
			case ModesEnum.ET_Controlled_Heating : {
				{
					InteriorModel_c_Heat_instance.setT_env(HVAC_Interface.T_Environment); // Main/calc 3/case(ET_Controlled_Heating) 1/Heating 1
					InteriorModel_c_Heat_instance.setT_set(HVAC_Interface.T_Setpoint); // Main/calc 3/case(ET_Controlled_Heating) 1/Heating 2
					InteriorModel_c_Heat_instance.c_Heat__Initial(); // Main/calc 3/case(ET_Controlled_Heating) 1/Heating 3
					InteriorModel_c_Heat_instance.c_Heat_integrate(); // Main/calc 3/case(ET_Controlled_Heating) 1/Heating 4
					HVAC_Interface.b_Heater = true; // Main/calc 3/case(ET_Controlled_Heating) 1/Heating 5
					HVAC_Interface.b_Cooler = (!true); // Main/calc 3/case(ET_Controlled_Heating) 1/Heating 6
					HVAC_Interface.R_Ventilation = InteriorModel_c_Heat_instance.getRate_heater(); // Main/calc 3/case(ET_Controlled_Heating) 1/Heating 7
				} // Main/calc 3/case(ET_Controlled_Heating) 1
			}
			case ModesEnum.ET_Controlled_Cooling : {
				{
					InteriorModel_c_AC_instance.setT_env(HVAC_Interface.T_Environment); // Main/calc 3/case(ET_Controlled_Cooling) 1/Cooling 1
					InteriorModel_c_AC_instance.setT_set(HVAC_Interface.T_Setpoint); // Main/calc 3/case(ET_Controlled_Cooling) 1/Cooling 2
					InteriorModel_c_AC_instance.c_AC__Initial(); // Main/calc 3/case(ET_Controlled_Cooling) 1/Cooling 3
					InteriorModel_c_AC_instance.c_AC_integrate(); // Main/calc 3/case(ET_Controlled_Cooling) 1/Cooling 4
					HVAC_Interface.b_Cooler = true; // Main/calc 3/case(ET_Controlled_Cooling) 1/Cooling 5
					HVAC_Interface.b_Heater = (!true); // Main/calc 3/case(ET_Controlled_Cooling) 1/Cooling 6
					HVAC_Interface.R_Ventilation = InteriorModel_c_AC_instance.getRate_cooler(); // Main/calc 3/case(ET_Controlled_Cooling) 1/Cooling 7
				} // Main/calc 3/case(ET_Controlled_Cooling) 1
			}
		} // Main/calc 3
	}
}