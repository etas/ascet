package classes;

import interfaces.IParameters;
import interfaces.IBalance2WD;
import SystemLib.Nonlinears.Limiter;

singleton class Balance2WD
reads IBalance2WD.PWM1, IBalance2WD.PWM2, IBalance2WD.AngleOutput, IBalance2WD.SpeedOutput, IBalance2WD.CountLeft, IBalance2WD.CountRight, IBalance2WD.PulseLeft, IBalance2WD.PulseRight, IBalance2WD.TurnOutput, IBalance2WD.CurrentAngle, IBalance2WD.UltraSonicSignalRuntimeInMicroSeconds
writes IBalance2WD.PWM1, IBalance2WD.PWM2, IBalance2WD.CountLeft, IBalance2WD.CountRight, IBalance2WD.ServoAngle, IBalance2WD.PulseLeft, IBalance2WD.PulseRight, IBalance2WD.LEDColor, IParameters.TargetSpeed, IBalance2WD.TurnLeftRightFlag, IBalance2WD.BuzzerOn {

	Limiter limiter_;
	integer enginesOn = 0;
	real frontDistance = 0.0;

	@thread
	public void calculateFrontDistance() {
		frontDistance = real(IBalance2WD.UltraSonicSignalRuntimeInMicroSeconds) * 0.017;
	}

	@no_side_effect
	public real getFrontDistance() {
		return frontDistance;
	}

	public void setLEDsOff() {
		IBalance2WD.LEDColor = 0;
	}

	public void setLEDsRed() {
		IBalance2WD.LEDColor = 1;
	}

	public void setLEDsGreen() {
		IBalance2WD.LEDColor = 2;
	}

	public void setLEDsBlue() {
		IBalance2WD.LEDColor = 3;
	}

	public void setLEDsYellow() {
		IBalance2WD.LEDColor = 4;
	}

	// Pulse calculation
	@thread
	public void calculatePulseCount() {

		integer leftPulse = IBalance2WD.CountLeft;
		integer rightPulse = IBalance2WD.CountRight;

		IBalance2WD.CountLeft = 0;
		IBalance2WD.CountRight = 0;

		if (IBalance2WD.PWM1 < 0.0) { // left engine rotates backwards
			leftPulse = -1 * leftPulse;
		}
		if (IBalance2WD.PWM2 < 0.0) { // right engine rotates backwards
			rightPulse = -1 * rightPulse;
		}
		// Every 5ms the number of pulses superimposed
		IBalance2WD.PulseLeft += leftPulse;
		IBalance2WD.PulseRight += rightPulse;
	}

	@thread
	public void calculateMotorPower() {
		real pwm = 0.0;

		// //The angle is too large so stop the motor.
		if (abs(IBalance2WD.CurrentAngle) > 40.0) {
			setEnginesOff();
		}

		if (enginesOn == 0) {
			IBalance2WD.PWM1 = 0.0;
			IBalance2WD.PWM2 = 0.0;
			return;
		}

		pwm = IBalance2WD.AngleOutput + IBalance2WD.SpeedOutput;

		IBalance2WD.PWM1 = pwm - IBalance2WD.TurnOutput; // Left motor PWM output value
		IBalance2WD.PWM2 = pwm + IBalance2WD.TurnOutput; // Right motor PWM output value

		// Amplitude limit
		IBalance2WD.PWM1 = limiter_.value(-255.0, IBalance2WD.PWM1, 255.0);
		IBalance2WD.PWM2 = limiter_.value(-255.0, IBalance2WD.PWM2, 255.0);
	}

	// Methods to control the balancer movement	
	public void setTargetSpeed(real targetSpeed) {
		// VehicleSpeedController.init();
		IParameters.TargetSpeed = targetSpeed;
	}

	public void stop() {
		setTargetSpeed(0.0);
		IBalance2WD.TurnLeftRightFlag = 0;
	}

	public void setEnginesOn() {
		enginesOn = 1;
	}

	public void setEnginesOff() {
		enginesOn = 0;
	}

	public void moveServoToParkingPosition() {
		IBalance2WD.ServoAngle = 20;
	}

	public void moveServoToBalancingPosition() {
		IBalance2WD.ServoAngle = 80;
	}

	public void resetBalancerCounters() {
		IBalance2WD.CountLeft = 0;
		IBalance2WD.CountRight = 0;
		IBalance2WD.PulseLeft = 0;
		IBalance2WD.PulseRight = 0;
	}

	public void goForward() {
		setTargetSpeed(50.0);
	}

	public void goBackward() {
		setTargetSpeed(-50.0);
	}

	public void turnLeft() {
		IBalance2WD.TurnLeftRightFlag = -1;
	}

	public void turnRight() {
		IBalance2WD.TurnLeftRightFlag = 1;
	}

	public void stopTurning() {
		IBalance2WD.TurnLeftRightFlag = 0;
	}

	public void buzzerOn() {
		IBalance2WD.BuzzerOn = 1;
	}

	public void buzzerOff() {
		IBalance2WD.BuzzerOn = 0;
	}
}