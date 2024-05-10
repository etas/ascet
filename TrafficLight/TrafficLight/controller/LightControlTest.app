application {
	class controller.LightControlTest
	class SystemLib.Miscellaneous.DeltaTimeService
}
schedule {
	startup {
	}
	shutdown {
	}
	task Task0 priority 0 period 10ms delay 0ms {
		process controller.LightControlTest.currentState
		process controller.LightControlTest.lightsTrigger
	}
}