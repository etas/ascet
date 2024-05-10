application {
	class ACC.ACC_SWC
	class SENSED_DATA.Sensed_Data_SWC
}
schedule {
	startup {
		process ACC.ACC_SWC.proc_ini
		process SENSED_DATA.Sensed_Data_SWC.proc_ini
	}
	shutdown {
	}
	task Task0 priority 0 period 10ms delay 0ms {
		process ACC.ACC_SWC.proc_10ms
		process SENSED_DATA.Sensed_Data_SWC.proc_10ms
	}
}