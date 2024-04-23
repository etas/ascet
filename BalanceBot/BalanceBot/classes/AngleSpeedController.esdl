package classes;

import SystemLib.Math.MathLib;
import interfaces.IParameters;
import SystemLib.Miscellaneous.DeltaTimeService;
import SystemLib.Nonlinears.Limiter;
import interfaces.IBalance2WD;
import SystemLib.Transferfunction.Integrator.IntegratorKLimited;
import control.RAD_TO_DEG;

singleton class AngleSpeedController
reads IBalance2WD.AccelerationY, IBalance2WD.AccelerationZ, IBalance2WD.GyroX, IParameters.TargetAngle, IParameters.KpAngle, IParameters.KiAngle
writes IBalance2WD.AngleOutput {
	MathLib mathlib_;
	real currentAngle;
	real errorAngleSum;
	Limiter limiter_;
	IntegratorKLimited IntegratorKLimited_instance;
	real prevAngle;

	@thread
	@generated("blockdiagram", "7555b112")
	public void calculateInclinationAngle() {
		real accAngle;
		real gyroRate;
		real gyroAngle;
		accAngle = (mathlib_.atan2(real(IBalance2WD.AccelerationY), real(IBalance2WD.AccelerationZ)) * RAD_TO_DEG); // Main/calculateInclinationAngle 1
		gyroRate = real((IBalance2WD.GyroX / 131)); // Main/calculateInclinationAngle 2
		gyroAngle = (DeltaTimeService.deltaT * gyroRate); // Main/calculateInclinationAngle 3
		currentAngle = ((0.9934 * (prevAngle + gyroAngle)) + (0.0066 * accAngle)); // Main/calculateInclinationAngle 4
		prevAngle = currentAngle; // Main/calculateInclinationAngle 5
	}

	@thread
	@generated("blockdiagram", "204dab65")
	public void calculateAngleSpeed() {
		real errorAngle;
		errorAngle = (currentAngle - IParameters.TargetAngle); // Main/calculateAngleSpeed 1
		IntegratorKLimited_instance.compute(errorAngle, 1.0, -1.5, 1.5); // Main/calculateAngleSpeed 2
		errorAngleSum = IntegratorKLimited_instance.value(); // Main/calculateAngleSpeed 3
		IBalance2WD.AngleOutput = ((IParameters.KpAngle * errorAngle) + (errorAngleSum * IParameters.KiAngle)); // Main/calculateAngleSpeed 4
	}
}