application {
	class VehicleModel.VehicelDynamicModel.Vehicle0
	class ACC.ACC_SWC
	class SystemLib.Miscellaneous.DeltaTimeService
	class VehicleModel.CalibrationMapping.CalibrationInterfaceModel
	class VehicleModel.RelativeData.RelativeData
}
schedule {
	startup {
		process VehicleModel.RelativeData.RelativeData.proc_ini
		process ACC.ACC_SWC.proc_ini
		process VehicleModel.RelativeData.RelativeData.SetDistance100
	}
	shutdown {
	}
	task Task0 priority 0 period 10ms delay 0ms {
		process VehicleModel.CalibrationMapping.CalibrationInterfaceModel.calc
		process VehicleModel.VehicelDynamicModel.Vehicle0.calc
		process ACC.ACC_SWC.proc_10ms
		process VehicleModel.RelativeData.RelativeData.proc_10ms
		process VehicleModel.RelativeData.RelativeData.AntiOverFlow_10ms
	}
}