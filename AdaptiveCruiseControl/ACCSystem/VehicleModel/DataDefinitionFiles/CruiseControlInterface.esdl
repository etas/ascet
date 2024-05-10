package VehicleModel.DataDefinitionFiles;

type CruiseControlMainStates is enum {Error, Off, SpeedControl, SpeedLimit};

data interface CruiseControlInterface {
	
	boolean CC_SetPlus;
	boolean CC_SetMinus;
	boolean CC_Resume;
	boolean CC_Cancel;
	real Accelerator_pedal;
	real Brake_pedal;
	real CurrentSpeed;
	real CC_ControlValue_acc = 0.0;
	real CC_ControlValue_brake;
	real RoadSlopeSet;
	real WindSpeed;
	CruiseControlMainStates MainSwitch = CruiseControlMainStates.Off;
}