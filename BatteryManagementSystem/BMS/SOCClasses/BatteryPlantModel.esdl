package SOCClasses;

import SystemLib.Transferfunction.Integrator.IntegratorK;
import SystemLib.Math.MathLib;
import Interfaces.akku_messages;
import SystemLib.Transferfunction.Integrator.IntegratorKLimited;

singleton class BatteryPlantModel
reads akku_messages.T_ambient, akku_messages.current
writes akku_messages.T_Cell, akku_messages.voltage, akku_messages.SOC_model {

	real PW;
	sysconst real C_ThermoConst = -1.5;
	IntegratorK IntegratorK_instance_T_Cell;
	characteristic real C_ThermicDampCoeff = 1.7;
	characteristic real C_Bat = 2.73;
	characteristic real T0 = 290.0;
	/** Nominal voltage [V] */
	characteristic real UN = 1.5;
	/** cell constant [V] */
	characteristic real K1 = 0.05;
	/** Nominal temperature [°K] */
	characteristic real TN = 400.0;
	/** Temperature Constant [°K] */
	characteristic real K2 = 6000.0;
	/** leakage current [A] */
	characteristic real I0 = 0.0000005;
	/** initial charge value [%] */
	characteristic real P0 = 41.653;
	/** nominal capacity [As] */
	characteristic real KN = 25.0;
	/** leakage current [A] */
	real IV;
	/** Base voltage [V] */
	characteristic real U_0 = 1.55;
	/** Internal resistance [Ohm] */
	characteristic real R_V_0 = 1200.0;
	/** Polarisation resistance [Ohm] */
	characteristic real R_P = 0.08;
	/** Leakage resistance [Ohm] */
	real R_V;
	MathLib MathLib_instance;
	IntegratorK IntegratorK_instance_SOC;
	characteristic T_2D_REAL T_SOC_2_RV[12][8] = {
		{ -40.0, -25.0, -5.0, 0.0, 5.0, 15.0, 40.0, 58.0, 75.0, 95.0, 110.0, 120.0 },
		{ 0.0, 10.0, 20.0, 40.0, 60.0, 90.0, 95.0, 100.0 },
		{
			{ 2.4335, 2.141, 1.8935, 1.691, 1.5335, 1.421, 1.3535, 1.331 },
			{ 2.1025, 1.81, 1.5625, 1.36, 1.2025, 1.09, 1.0225, 1.0 },
			{ 1.8315, 1.539, 1.2915, 1.089, 0.9315, 0.819, 0.7515, 0.729 },
			{ 1.6145, 1.322, 1.0745, 0.872, 0.7145, 0.602, 0.5345, 0.512 },
			{ 1.4455, 1.153, 0.9055, 0.703, 0.5455, 0.433, 0.3655, 0.343 },
			{ 1.3185, 1.026, 0.7785, 0.576, 0.4185, 0.306, 0.2385, 0.216 },
			{ 1.2275, 0.935, 0.6875, 0.485, 0.3275, 0.215, 0.1475, 0.125 },
			{ 1.1665, 0.874, 0.6265, 0.424, 0.2665, 0.154, 0.0865, 0.064 },
			{ 1.1295, 0.837, 0.5895, 0.387, 0.2295, 0.117, 0.0495, 0.027 },
			{ 1.1105, 0.818, 0.5705, 0.368, 0.2105, 0.098, 0.0305, 0.008 },
			{ 1.1035, 0.811, 0.5635, 0.361, 0.2035, 0.091, 0.0235, 0.001 },
			{ 1.1025, 0.81, 0.5625, 0.36, 0.2025, 0.09, 0.0225, 0.0 }
		}
	};
	IntegratorKLimited IntegratorKLimited_instance;

	@thread
	@generated("blockdiagram", "1e2d75a8")
	public void calc() {
		{
			PW = (akku_messages.current * C_ThermoConst); // Main/calc 1/ThermoModel 1
			IntegratorK_instance_T_Cell.compute((PW + (C_ThermicDampCoeff * (akku_messages.T_ambient - ((IntegratorK_instance_T_Cell.value() / C_Bat) + T0)))), 1.0); // Main/calc 1/ThermoModel 2
		} // Main/calc 1
		akku_messages.T_Cell = ((IntegratorK_instance_T_Cell.value() / C_Bat) + T0); // Main/calc 2
		{
			R_V = ((T_SOC_2_RV.getAt(((IntegratorK_instance_T_Cell.value() / C_Bat) + T0), (P0 + (IntegratorKLimited_instance.value() / KN))) * R_V_0) + R_V_0); // Main/calc 3/VoltageModel 1
		} // Main/calc 3
		akku_messages.voltage = ((U_0 - (akku_messages.current * R_P)) * (R_V / (R_P + R_V))); // Main/calc 4
		{
			IV = (MathLib_instance.exp((((((U_0 - (akku_messages.current * R_P)) * (R_V / (R_P + R_V))) - UN) / K1) + (((((IntegratorK_instance_T_Cell.value() / C_Bat) + T0) - TN) * K2) / (TN * ((IntegratorK_instance_T_Cell.value() / C_Bat) + T0))))) * I0); // Main/calc 5/ChargeModel 1
			IntegratorKLimited_instance.compute(((akku_messages.current - IV) * (1.0 - ((P0 + (IntegratorKLimited_instance.value() / KN)) / 100.0))), 1.0, -1041.325, 1458.675); // Main/calc 5/ChargeModel 2
		} // Main/calc 5
		akku_messages.SOC_model = (P0 + (IntegratorKLimited_instance.value() / KN)); // Main/calc 6
	}

	@thread
	@generated("blockdiagram", "42203e8b")
	public void init() {
		IntegratorK_instance_T_Cell.reset(akku_messages.T_ambient); // Init/init 1
		IntegratorK_instance_SOC.reset(0.0); // Init/init 2
	}
}