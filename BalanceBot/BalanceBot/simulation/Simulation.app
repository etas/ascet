application {
	class control.RemoteCommandsMain
	class SystemLib.Miscellaneous.DeltaTimeService
	class simulation.Stimulator
}
schedule {
	startup {
	}
	shutdown {
	}
	task Task0 priority 0 period 10ms delay 0ms {
		process simulation.Stimulator.stimulate
		process classes.Balance2WD.calculateFrontDistance
		process control.RemoteCommandsMain.calc
	}
}