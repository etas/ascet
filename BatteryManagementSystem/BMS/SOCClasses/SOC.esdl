package SOCClasses;

import Interfaces.akku_messages;
import Interfaces.S32;

singleton class SOC
reads akku_messages.voltage, akku_messages.T_Cell, akku_messages.current
writes akku_messages.SOC_estimated, akku_messages.SOC_low, akku_messages.SOC_symbol {

	AccuCharacteristic accu = AccuCharacteristic.NewBattery();
	BatteryState battState;

	@thread
	@generated("blockdiagram", "33df354d")
	public void method_100ms() {
		battState.current_measure = akku_messages.current; // Main/method_100ms 1
		battState.batteryState1StatemachineTrigger(); // Main/method_100ms 2
		if (battState.SOC_request) {
			battState.SOC_in = accu.calc(akku_messages.voltage, akku_messages.T_Cell); // Main/method_100ms 3/if-then 1
		} // Main/method_100ms 3
		akku_messages.SOC_estimated = battState.SOC_value; // Main/method_100ms 4
		akku_messages.SOC_low = (battState.SOC_value < 12.0); // Main/method_100ms 5
		akku_messages.SOC_symbol = (S32((battState.SOC_value / 12.5)) + 1); // Main/method_100ms 6
	}
	representation SOC1 {
		represent accu using SOC1;
	}
	representation SOC2 {
		represent accu using SOC2;
	}
}