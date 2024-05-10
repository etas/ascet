package controller;

import SystemLib.CounterTimer.Timer;

@generated("statemachine", "000000")
type LightsStatemachineStates is enum {
	ErrorMode,
	YellowOff,
	YellowOn,
	NormalMode,
	Red,
	AllOff,
	Yellow,
	Green,
	RedYellow
};

class LightControl {

	Timer localTimer;
	Timer errorTimer;
	@set
	private boolean error;
	@get
	private boolean green;
	@get
	private boolean red;
	@get
	private boolean yellow;
	characteristic real GreenTime = 7.0;
	characteristic real RedTime <- "2.0 * green", green = GreenTime;
	characteristic real YellowTime <- "green / 3.0", green = GreenTime;
	characteristic real BlinkTime <- "yellow / 3.0", yellow = YellowTime;

	public LightsStatemachineStates currentState() {
		return LightsStatemachine.getState();
	}

	private void setYellow() {
		yellow = true;
		red = false;
		green = false;
	}

	private void setRed() {
		yellow = false;
		red = true;
		green = false;
	}

	private void setGreen() {
		yellow = false;
		red = false;
		green = true;
	}

	private void turnAllOff() {
		yellow = false;
		red = false;
		green = false;
	}
 
	@generated("statemachine", "000000")
	public void lightsTrigger() triggers LightsStatemachine;

	@generated("statemachine", "49378926")
	statemachine LightsStatemachine using LightsStatemachineStates {
		start ErrorMode;

		state ErrorMode {
			transition !error to NormalMode;
			start YellowOff;

			state YellowOff {
				entry {
					turnAllOff();
					errorTimer.begin(BlinkTime);
				}
				static {
					errorTimer.compute();
				}
				transition errorTimer.isElapsed() to YellowOn;
			}

			state YellowOn {
				entry {
					setYellow();
					errorTimer.begin(BlinkTime);
				}
				static {
					errorTimer.compute();
				}
				transition errorTimer.isElapsed() to YellowOff;
			}
		}

		state NormalMode {
			transition error to ErrorMode;
			start AllOff;

			state Red {
				entry {
					localTimer.begin(RedTime);
				}
				static {
					localTimer.compute();
				}
				transition localTimer.isElapsed() to RedYellow {
					setYellow();
				};
			}

			state AllOff {
				exit {
					turnAllOff();
				}
				transition true to Yellow {
					setYellow();
				};
			}

			state Yellow {
				entry {
					localTimer.begin(YellowTime);
				}
				static {
					localTimer.compute();
				}
				transition localTimer.isElapsed() to Red {
					setRed();
				};
			}

			state Green {
				entry {
					localTimer.begin(GreenTime);
				}
				static {
					localTimer.compute();
				}
				transition localTimer.isElapsed() to Yellow {
					setYellow();
				};
			}

			state RedYellow {
				entry {
					localTimer.begin(YellowTime);
				}
				static {
					localTimer.compute();
				}
				transition localTimer.isElapsed() to Green {
					setGreen();
				};
			}
		}
	}
}