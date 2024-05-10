package controller;


singleton class LightControlTest {
	LightControl tester;
	LightsStatemachineStates currentState_return;
	characteristic boolean Sti_error = false;
	@thread
	public void currentState() {
		currentState_return = tester.currentState();
	}
	@thread
	public void lightsTrigger() {
		tester.error = Sti_error;
		tester.lightsTrigger();
	}

}