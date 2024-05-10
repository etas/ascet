package VehicleModel.CalibrationMapping;

import VehicleModel.DataDefinitionFiles.CruiseControlInterface;
import interfaces.messages;

singleton class CalibrationInterfaceModel

writes CruiseControlInterface.RoadSlopeSet, CruiseControlInterface.CC_ControlValue_acc, CruiseControlInterface.CC_ControlValue_brake, CruiseControlInterface.WindSpeed, messages.Set_Velocity, messages.Actual_Velocity_LC {

	characteristic real c_CC_ControlValue_acc = 0.0;
	characteristic real c_CC_ControlValue_brake = 0.0;
	characteristic real c_RoadSlopeSet = 0.0;
	characteristic real c_WindSpeed = 0.0;
	characteristic real Set_ACC_Velocity = 0.0;
	characteristic real Set_Velocity_LC = 0.0;

	@thread
	@generated("blockdiagram", "afe90475")
	public void calc() {
		CruiseControlInterface.CC_ControlValue_acc = c_CC_ControlValue_acc; // Main/calc 1
		CruiseControlInterface.CC_ControlValue_brake = c_CC_ControlValue_brake; // Main/calc 2
		CruiseControlInterface.RoadSlopeSet = c_RoadSlopeSet; // Main/calc 3
		CruiseControlInterface.WindSpeed = c_WindSpeed; // Main/calc 4
		messages.Set_Velocity = Set_ACC_Velocity; // Main/calc 5
		messages.Actual_Velocity_LC = Set_Velocity_LC; // Main/calc 6
	}
}