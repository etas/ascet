application {
	class classes.VehicleSpeedController
	class classes.AngleSpeedController
	class classes.TurnSpeedController
	class SystemLib.Miscellaneous.DeltaTimeService
	class control.RemoteCommandsMain
}
schedule {
	startup {
	}
	shutdown {
	}
	task Task_5ms priority 0 period 5ms delay 0ms {
		process control.RemoteCommandsMain.calc
		process classes.Balance2WD.calculatePulseCount
		process classes.AngleSpeedController.calculateInclinationAngle
		process classes.AngleSpeedController.calculateAngleSpeed
		process classes.Balance2WD.calculateMotorPower
	}
	task Task_10ms priority 0 period 10ms delay 0ms {
		process classes.TurnSpeedController.calculateTurnSpeed
	}
	task Task_50ms priority 0 period 50ms delay 0ms {
		process classes.VehicleSpeedController.calculateVehicleSpeed
		process classes.Balance2WD.calculateFrontDistance
	}
}