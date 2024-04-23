package classes;

import SystemLib.Transferfunction.Integrator.IntegratorKLimited;
import SystemLib.Transferfunction.Lowpass.DigitalLowpass;
import interfaces.IBalance2WD;
import interfaces.IParameters;

singleton class VehicleSpeedController
reads interfaces.IParameters.KiSpeed, interfaces.IParameters.KpSpeed, interfaces.IBalance2WD.PulseLeft, interfaces.IBalance2WD.PulseRight, interfaces.IParameters.TargetSpeed
writes interfaces.IBalance2WD.SpeedOutput, interfaces.IBalance2WD.PulseLeft, interfaces.IBalance2WD.PulseRight {
	real errorSpeedSum = 0.0;
	IntegratorKLimited Integrator_Speed;
	DigitalLowpass DigitalLowpass_Speed;
	DigitalLowpass DigitalLowpass_TargetSpeed;

	@thread
	@generated("blockdiagram", "0176fe66")
	public void calculateVehicleSpeed() {
		integer measuredSpeed = 0;
		real currentSpeed = 0.0;
		real errorSpeed = 0.0;
		measuredSpeed = (IBalance2WD.PulseLeft + IBalance2WD.PulseRight); // Main/calculateVehicleSpeed 1
		DigitalLowpass_Speed.compute(real(measuredSpeed), 0.3); // Main/calculateVehicleSpeed 2
		currentSpeed = DigitalLowpass_Speed.value(); // Main/calculateVehicleSpeed 3
		DigitalLowpass_TargetSpeed.compute(IParameters.TargetSpeed, 0.05); // Main/calculateVehicleSpeed 4
		IBalance2WD.PulseLeft = 0; // Main/calculateVehicleSpeed 5
		IBalance2WD.PulseRight = 0; // Main/calculateVehicleSpeed 6
		errorSpeed = (currentSpeed - DigitalLowpass_TargetSpeed.value()); // Main/calculateVehicleSpeed 7
		Integrator_Speed.compute(errorSpeed, 1.0, -227.5, 227.5); // Main/calculateVehicleSpeed 8
		errorSpeedSum = Integrator_Speed.value(); // Main/calculateVehicleSpeed 9
		IBalance2WD.SpeedOutput = ((IParameters.KpSpeed * errorSpeed) + (errorSpeedSum * IParameters.KiSpeed)); // Main/calculateVehicleSpeed 10
	}

	@generated("blockdiagram", "29d63079")
	public void init() {
		Integrator_Speed.reset(0.0); // Main/init 1
	}
}