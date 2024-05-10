application {
	class ACC.ACC_SWC
}
schedule {
	startup {
		process ACC.ACC_SWC.proc_ini
	}
	shutdown {
	}
	task Task_10ms priority 0 period 10ms delay 0ms {
		process ACC.ACC_SWC.proc_10ms
	}
}