application {
	class System.HVACTest
	class System.HVAC
	class System.Congra.C_T_int
}
schedule {
	startup {
	}
	shutdown {
	}
	task Task0 priority 0 period 10ms delay 0ms {
		process System.HVACTest.calc
		process System.HVAC.calc
	}
}