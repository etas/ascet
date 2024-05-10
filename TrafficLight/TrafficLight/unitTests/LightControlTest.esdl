package unitTests;
import SystemLib.CounterTimer.StopWatch;
import SystemLib.Miscellaneous.DeltaTimeService;
import time.DeltaTimeAccess;

import controller.LightControl;
import controller.LightsStatemachineStates;
import assert.Assert;

singleton class LightControlTest {

	LightControl testee;
	Assert Assert;
	LightsStatemachineStates currentState_return;
	DeltaTimeService t;
	DeltaTimeAccess dtAccess;
	StopWatch sw;
	
	@Before
	public void init() {
		dtAccess.setDeltaTime(0.01);
	}

	
	@Test
	public void testNormalMode() {
		
		// first time state machine wakes up check if it is off
		testee.lightsTrigger();
		currentState_return = testee.currentState(); 

		Assert.expectIntEqual(currentState_return.value(), 
			LightsStatemachineStates.AllOff.value()
		);
		
		// check for yellow state
		testee.lightsTrigger();
		currentState_return = testee.currentState(); 

		Assert.expectIntEqual(currentState_return.value(), 
			LightsStatemachineStates.Yellow.value()
		);
		
		// Check for red state which is reached after 2.33 seconds
		while(sw.value()< 2.34) {
			sw.compute();
			testee.lightsTrigger();
		}
		sw.reset();
		currentState_return = testee.currentState();
		Assert.expectIntEqual(currentState_return.value(), 
			LightsStatemachineStates.Red.value()
		); 
		
		// Check for red yellow state which is reached after 14 seconds
		while(sw.value()< 14.01) {
			sw.compute();
			testee.lightsTrigger();
		}
		sw.reset();
		currentState_return = testee.currentState();
		Assert.expectIntEqual(currentState_return.value(), 
			LightsStatemachineStates.RedYellow.value()
		); 
		
		// Check for green state which is reached after 2.33 seconds
		while(sw.value()< 2.34) {
			sw.compute();
			testee.lightsTrigger();
		}
		sw.reset();
		currentState_return = testee.currentState();
		Assert.expectIntEqual(currentState_return.value(), 
			LightsStatemachineStates.Green.value()
		); 
		
		// Check for yellow state which is reached after 7 seconds
		while(sw.value()< 7.01) {
			sw.compute();
			testee.lightsTrigger();
		}
		sw.reset();
		currentState_return = testee.currentState();
		Assert.expectIntEqual(currentState_return.value(), 
			LightsStatemachineStates.Yellow.value()
		); 
	}

	@Test
	public void testErrorMode() {
		// run the state machine in normal mode for some time
		while(sw.value()< 14) {
			sw.compute();
			testee.lightsTrigger();
		}
		sw.reset();
		
		// now when error signal is enabled it should abort and go to error mode
		testee.error = true;
		while(sw.value()< 0.78) {
			sw.compute();
			testee.lightsTrigger();
		}
		currentState_return = testee.currentState();
		// check of yellow off state
		Assert.expectIntEqual(currentState_return.value(), 
			LightsStatemachineStates.YellowOff.value()
		); 
		
		while(sw.value()< 1) {
			sw.compute();
			testee.lightsTrigger();
		}
		currentState_return = testee.currentState();
		// check of yellow on state
		Assert.expectIntEqual(currentState_return.value(), 
			LightsStatemachineStates.YellowOn.value()
		);
		
	}
}