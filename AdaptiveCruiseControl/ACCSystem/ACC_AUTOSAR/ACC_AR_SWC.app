application {
	class ACC_AUTOSAR.ACC_AR
}
schedule {
	startup {
	}
	shutdown {
	}
	task Task0 priority 0 period 10ms delay 0ms {
		process ACC.ACC_SWC.proc_10ms
		process ACC.ACC_SWC.proc_ini
	}
}