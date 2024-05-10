application {
	class SENSED_DATA.Sensed_Data_SWC
}
schedule {
	startup {
		process SENSED_DATA.Sensed_Data_SWC.proc_ini
	}
	shutdown {
	}
	task Task_10ms priority 0 period 10ms delay 0ms {
		process SENSED_DATA.Sensed_Data_SWC.proc_10ms
	}
}