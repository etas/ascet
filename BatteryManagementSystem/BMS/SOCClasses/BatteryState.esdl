package SOCClasses;

@generated("statemachine", "000000")
type BatteryState1StatemachineStates is enum {
	idle,
	discharge,
	recharge,
	SOC_check,
	initState
};

class BatteryState {

	@set
	private real current_measure;
	@set
	private real SOC_in;
	@get
	private boolean SOC_request;
	@get
	private real SOC_value;
	characteristic real P_SOCCheckPeriod = 0.5;
	characteristic real dT_Par = 0.01;
	characteristic real P_SOCCheckStop = 0.2;
	real SOC_buffer;
	real time_counter;
	characteristic real C_SOC_Coeff = 0.014;

	@generated("statemachine", "000000")
	public void batteryState1StatemachineTrigger() triggers BatteryState1Statemachine;

	@generated("statemachine", "865e3002")
	statemachine BatteryState1Statemachine using BatteryState1StatemachineStates {
		start initState;

		state idle {
			entry {
				time_counter = 0.0;
				SOC_value = SOC_buffer;
			}
			static {
				time_counter = time_counter + dT_Par;
			}
			transition time_counter > P_SOCCheckPeriod to SOC_check;
			transition current_measure > 0.0 && SOC_buffer < 100.0 to recharge;
			transition current_measure < 0.0 && SOC_buffer > 0.0 to discharge {
				SOC_in = 0.0;
			};
		}

		state discharge {
			static {
				if (SOC_buffer > 0.0) {
					SOC_buffer = SOC_buffer + dT_Par * C_SOC_Coeff * current_measure;
				}
				SOC_value = SOC_buffer;
			}
			transition current_measure >= 0.0 to idle;
		}

		state recharge {
			static {
				if (SOC_buffer < 100.0) {
					SOC_buffer = SOC_buffer + dT_Par * C_SOC_Coeff * current_measure;
				}
				SOC_value = SOC_buffer;
			}
			transition current_measure <= 0.0 to idle;
		}

		state SOC_check {
			entry {
				time_counter = 0.0;
				SOC_request = true;
			}
			static {
				time_counter = time_counter + dT_Par;
			}
			exit {
				SOC_buffer = SOC_in;
				SOC_request = false;
			}
			transition time_counter > P_SOCCheckStop to idle;
		}

		state initState {
			transition true to SOC_check;
		}
	}
}