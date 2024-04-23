package interfaces;

data interface IParameters {
	@symbol("KpAngle")
	real KpAngle = 25.0;
	
	@symbol("KiAngle")
	real KiAngle = 21.21;
	
	@symbol("KpSpeed")
	real KpSpeed = 3.8;
	
	@symbol("KiSpeed")
	real KiSpeed = 2.76;
	
	@symbol("KpTurn")
	real KpTurn = 18.0;		
		
	@symbol("TargetAngle")
	real TargetAngle= 3.0;  // > 0 is forward angle, < 0 is backward angle
	
	@symbol("TargetSpeed")
	real TargetSpeed = 0.0; // < 0.0 is backward, > 0.0 is forward

}