application {
	class ascet.OUT.OUT_Main
	class ascet.IN.IN_Main
	class ascet.APP.APP
}
schedule {
	startup {
		process ascet.IN.IN_Main.IN_Init
		process ascet.OUT.OUT_Main.OUT_Init
	}
	shutdown {
	}
	task ASCTask1ms priority 0 scheduling none period 1ms delay 0ms {
		process ascet.IN.IN_Main.IN_dT
		process ascet.APP.APP.APP_1ms
		process ascet.OUT.OUT_Main.OUT_1ms
	}
	task ASCTask5ms priority 1 scheduling none period 5ms delay 0ms {
	}
	task ASCTask10ms priority 2 scheduling none period 10ms delay 0ms {
		process ascet.APP.APP.APP_10ms
		process ascet.OUT.OUT_Main.OUT_10ms
	}
	task ASCTask100ms priority 3 scheduling none period 100ms delay 0ms {
		process ascet.OUT.OUT_Main.OUT_100ms
	}
}