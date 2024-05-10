application {
	class SENSED_DATA_AUTOSAR.Sensed_Data_AR
}
schedule {
	startup {
	}
	shutdown {
	}
	task Task0 priority 0 period 10ms delay 0ms {
		process SENSED_DATA.Sensed_Data_SWC.proc_10ms
		process SENSED_DATA.Sensed_Data_SWC.proc_ini
	}
}