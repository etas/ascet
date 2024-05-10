package VehicleModel.VehicelDynamicModel;

import SystemLib.Math.MathLib;
import SystemLib.Miscellaneous.EdgeRising;
import SystemLib.Transferfunction.Integrator.IntegratorK;

class VehicleDynamicModelClass {

	real SlopeAcceleration = 0.0;
	boolean hold = false;
	MathLib MathLib_instance;
	characteristic real c_SlopePlus = 32.0;
	real BrakeForce = 0.0;
	real velocity = 0.0;
	real velocity_old = 0.0;
	characteristic BrakeForceCurve BrakeForceCurve_instance[11] = {
		{ 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 },
		{ 0.0, 18000.0, 35000.0, 53000.0, 68000.0, 80.0E3, 88000.0, 92000.0, 95000.0, 98000.0, 100.0E3 }
	};
	EdgeRising EdgeRising_instance;
	real EngineForce = 0.0;
	characteristic EngineForceCurve EngineForceCurve_instance[11] = {
		{ 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 },
		{ 0.0, 100.0, 1500.0, 5000.0, 8500.0, 12000.0, 16000.0, 18000.0, 18600.0, 18800.0, 19000.0 }
	};
	characteristic real roh = 1.34;
	characteristic real cw = 0.31;
	characteristic real A = 1.45;
	real AirResistance = 0.0;
	characteristic real vehicle_mass = 1700.0;
	IntegratorK IntegratorK_instance;
	characteristic real K = 1.0;

	@generated("blockdiagram", "e26b548a")
	public real calc(real in CtrlVal_accel, real in WindSpeed, real in RoadSlope, real in CtrlVal_brake) {
		boolean ZeroCross;
		if (CtrlVal_brake < 0.05) {
			hold = false; // Main/calc 1/if-then 1
		} // Main/calc 1
		if (EdgeRising_instance.value() && (CtrlVal_accel <= 0.01)) {
			hold = true; // Main/calc 2/if-then 1
		} // Main/calc 2
		if (hold) {
			IntegratorK_instance.reset(0.0); // Main/calc 3/if-then 1
		} else {
			IntegratorK_instance.compute(((((EngineForce - AirResistance) - BrakeForce) / vehicle_mass) + SlopeAcceleration), K); // Main/calc 3/if-else 1
		} // Main/calc 3
		SlopeAcceleration = (MathLib_instance.sqrt((if(abs(RoadSlope) <= 0.0001) then 0.0 else(c_SlopePlus / (((1.0 / RoadSlope) * (1.0 / RoadSlope)) + 1.0)))) * 9.81 * (if(RoadSlope < 0.0) then 1.0 else -1.0)); // Main/calc 4
		velocity_old = velocity; // Main/calc 5
		ZeroCross = ((velocity_old * velocity) <= 0.0); // Main/calc 6
		BrakeForce = (BrakeForceCurve_instance.getAt(CtrlVal_brake) * (if ZeroCross then 0.0 else(if(velocity < 0.0) then -1.0 else 1.0))); // Main/calc 7
		EdgeRising_instance.compute(ZeroCross); // Main/calc 8
		EngineForce = EngineForceCurve_instance.getAt(CtrlVal_accel); // Main/calc 9
		AirResistance = ((WindSpeed + velocity) * (WindSpeed + velocity) * A * cw * 0.5 * roh * (if((WindSpeed + velocity) < 0.0) then -1.0 else 1.0)); // Main/calc 10
		velocity = IntegratorK_instance.value(); // Main/calc 11
		return velocity; // Main/calc 12
	}
}