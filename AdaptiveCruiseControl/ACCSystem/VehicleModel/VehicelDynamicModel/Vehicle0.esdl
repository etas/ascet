package VehicleModel.VehicelDynamicModel;

import VehicleModel.DataDefinitionFiles.CruiseControlInterface;
import SystemLib.Transferfunction.Integrator.IntegratorK;
import SystemLib.Nonlinears.Hysteresis_Delta_RSP;
import SystemLib.Math.MathLib;
import SystemLib.Miscellaneous.EdgeRising;
import interfaces.messages;
import SystemLib.Comparators.ClosedInterval;
import SystemLib.Nonlinears.Limiter;

singleton class Vehicle0

reads CruiseControlInterface.RoadSlopeSet, CruiseControlInterface.WindSpeed, messages.Acceleration_EC
writes messages.Actual_Velocity_EC {

	real velocity = 0.0;
	characteristic real A = 1.45;
	characteristic real cw = 0.31;
	characteristic real vehicle_mass = 1700.0;
	characteristic real roh = 1.34;
	real AirResistance = 0.0;
	characteristic EngineForceCurve EngineForceCurve_instance[11] = {
		{ 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 },
		{ 0.0, 100.0, 1500.0, 5000.0, 8500.0, 12000.0, 16000.0, 18000.0, 18600.0, 18800.0, 19000.0 }
	};
	characteristic BrakeForceCurve BrakeForceCurve_instance[11] = {
		{ 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 },
		{ 0.0, 18000.0, 35000.0, 53000.0, 68000.0, 80.0E3, 88000.0, 92000.0, 95000.0, 98000.0, 100.0E3 }
	};
	real EngineForce = 0.0;
	real BrakeForce = 0.0;
	IntegratorK IntegratorK_instance;
	characteristic real K = 1.0;
	Hysteresis_Delta_RSP Hysteresis_Delta_RSP_instance;
	real velocity_old = 0.0;
	MathLib MathLib_instance;
	real SlopeAcceleration = 0.0;
	boolean hold = false;
	EdgeRising EdgeRising_instance;
	characteristic real c_SlopePlus = 32.0;
	VehicleDynamicModelClass VehicleDynamicModelClass_instance;
	VehicleDynamicModelClass VehicleDynamicModelClass_instance_2;
	ClosedInterval ClosedInterval_instance;
	Limiter Limiter_instance;

	@thread
	@generated("blockdiagram", "f94a0286")
	public void calc() {
		boolean ZeroCross;
		messages.Actual_Velocity_EC = VehicleDynamicModelClass_instance_2.calc(Limiter_instance.value(0.0, messages.Acceleration_EC, 2.0), CruiseControlInterface.WindSpeed, CruiseControlInterface.RoadSlopeSet, (-Limiter_instance.value(-3.0, messages.Acceleration_EC, 0.0))); // Main/calc 1
	}
}