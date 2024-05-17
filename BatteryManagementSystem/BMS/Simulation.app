application {
	class SOCClasses.BatteryPlantModel
	class SOCClasses.SOC
	class SystemLib.Miscellaneous.DeltaTimeService
	class SOCClasses.ManualCalibration
}
schedule {
	startup {
		process SOCClasses.BatteryPlantModel.init
	}
	shutdown {
	}
	task Task_10ms priority 0 period 10ms delay 0ms {
		process SOCClasses.ManualCalibration.calc
		process SOCClasses.BatteryPlantModel.calc
		process SOCClasses.SOC.method_100ms
	}
}