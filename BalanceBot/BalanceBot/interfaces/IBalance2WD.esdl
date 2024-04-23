package interfaces;
data interface IBalance2WD {
	
	@symbol("PWM1")
	real PWM1 = 0.0;
	
	@symbol("PWM2")
	real PWM2 = 0.0;	
	
	@symbol("ServoAngle")
	integer ServoAngle = 80;
	
	@symbol("AngleOutput")
	real AngleOutput = 0.0;
	
	@symbol("SpeedOutput")
	real SpeedOutput = 0.0;
	
	@symbol("TurnOutput")
	real TurnOutput = 0.0;	
	
	@symbol("PulseLeft")
	integer PulseLeft = 0;
	
	@symbol("PulseRight")
	integer PulseRight = 0;
	
	@symbol("LEDColor")
	integer LEDColor = 0;  // 0 = off, 1= red, 2 = green, 3 = blue, 4 = yellow
	
	@symbol("CurrentAngle")
	real CurrentAngle = 0.0;
	
	@symbol("TurnLeftRightFlag")
	integer TurnLeftRightFlag = 0;
	
	@symbol("CountLeft") 
	integer CountLeft = 0;
	
	@symbol("CountRight")
	integer CountRight = 0;
	
	// DistanceSensor
	@symbol("UltraSonicSignalRuntimeInMicroSeconds")
	integer UltraSonicSignalRuntimeInMicroSeconds = 0;
	
	//Motion Sensors
	@symbol("AccelerationX")
	integer AccelerationX = 0;
	
	@symbol("AccelerationY")
	integer AccelerationY = 0;

	@symbol("AccelerationZ")
	integer AccelerationZ = 0;
	
	@symbol("GyroX")
	integer GyroX = 0;
	
	@symbol("GyroY")
	integer GyroY = 0;

	@symbol("GyroZ")
	integer GyroZ = 0;
	
	@symbol("BuzzerOn")
	integer BuzzerOn = 0;

}
