package control;

import SystemLib.CounterTimer.Timer;
import classes.Balance2WD;

@generated("statemachine", "000000")
type RemoteCommandsStatemachineStates is enum {
	StopBalancing,
	GoForward,
	GoBackward,
	TurnLeft,
	TurnRight,
	Parked,
	StartBalancing,
	AvoidObstacles,
	ManualDrive,
	Dispatch,
	OpenLab,
	StopTurning,
	Stop,
	Stabilizing,
	MovingForward,
	FarObstacleDetected,
	NearObstacleDetected,
	Starting,
	Driving
};

class RemoteCommands {

	@set
	private EModes mode;
	integer counter;
	Timer localTimer;

	private boolean IsStopMode() {
		return mode == EModes.STOP;
	}

	private boolean IsStopBalancingMode() {
		return mode == EModes.STOP_BALANCING;
	}

	private boolean IsGoForwardMode() {
		return mode == EModes.GO_FORWARD;
	}

	private boolean IsGoBackwardMode() {
		return mode == EModes.GO_BACKWARD;
	}

	private boolean IsTurnLeftMode() {
		return mode == EModes.TURN_LEFT;
	}

	private boolean IsTurnRightMode() {
		return mode == EModes.TURN_RIGHT;
	}

	private boolean IsStopTurningMode() {
		return mode == EModes.STOP_TURNING;
	}

	private boolean IsManualDriveMode() {
		return IsStopMode() || IsStopBalancingMode() || IsGoForwardMode() || IsGoBackwardMode() || IsTurnLeftMode() || IsTurnRightMode() || IsStopTurningMode();
	}

	private boolean IsOpenLabMode() {
		return mode == EModes.OPENLAB_MODE;
	}

	private boolean IsObstacleAvoidanceMode() {
		return mode == EModes.OBSTACLE_AVOIDANCE;
	}

	@generated("statemachine", "000000")
	public void trig() triggers RemoteCommandsStatemachine;

	@generated("statemachine", "1ad8fcc3")
	statemachine RemoteCommandsStatemachine using RemoteCommandsStatemachineStates {
		start Dispatch;

		state AvoidObstacles {
			transition !IsObstacleAvoidanceMode() to Dispatch;
			start Stabilizing;

			state Stabilizing {
				entry {
					RemoteCommandsMain.Balance2WD.stop();
					RemoteCommandsMain.Balance2WD.setLEDsYellow();
					localTimer.begin(1.0);
				}
				static {
					localTimer.compute();
				}
				transition localTimer.isElapsed() to MovingForward;
			}

			state MovingForward {
				entry {
					RemoteCommandsMain.Balance2WD.goForward();
				}
				transition RemoteCommandsMain.Balance2WD.getFrontDistance() <= 30.0 to NearObstacleDetected;
				transition RemoteCommandsMain.Balance2WD.getFrontDistance() <= 50.0 to FarObstacleDetected;
			}

			state FarObstacleDetected {
				entry {
					RemoteCommandsMain.Balance2WD.turnLeft();
					localTimer.begin(0.2);
				}
				static {
					localTimer.compute();
				}
				exit {
					RemoteCommandsMain.Balance2WD.stopTurning();
				}
				transition localTimer.isElapsed() to MovingForward;
			}

			state NearObstacleDetected {
				entry {
					RemoteCommandsMain.Balance2WD.stop();
					RemoteCommandsMain.Balance2WD.goBackward();
					localTimer.begin(2.0);
				}
				static {
					localTimer.compute();
				}
				exit {
					RemoteCommandsMain.Balance2WD.stop();
				}
				transition localTimer.isElapsed() to FarObstacleDetected;
			}
		}

		state ManualDrive {
			transition !IsManualDriveMode() to Dispatch;
			start StartBalancing;

			state StopBalancing {
				entry {
					RemoteCommandsMain.Balance2WD.setLEDsRed();
					RemoteCommandsMain.Balance2WD.moveServoToParkingPosition();
					localTimer.begin(0.8);
					RemoteCommandsMain.Balance2WD.goBackward();
				}
				static {
					localTimer.compute();
				}
				transition localTimer.isElapsed() to Parked;
			}

			state GoForward {
				entry {
					RemoteCommandsMain.Balance2WD.goForward();
					RemoteCommandsMain.Balance2WD.setLEDsGreen();
				}
				transition !IsGoForwardMode() to junction0;
			}

			state GoBackward {
				entry {
					RemoteCommandsMain.Balance2WD.goBackward();
					RemoteCommandsMain.Balance2WD.setLEDsBlue();
				}
				transition !IsGoBackwardMode() to junction0;
			}

			state TurnLeft {
				entry {
					RemoteCommandsMain.Balance2WD.turnLeft();
				}
				exit {
					RemoteCommandsMain.Balance2WD.stopTurning();
				}
				transition !IsTurnLeftMode() to junction0;
			}

			state TurnRight {
				entry {
					RemoteCommandsMain.Balance2WD.turnRight();
				}
				exit {
					RemoteCommandsMain.Balance2WD.stopTurning();
				}
				transition !IsTurnRightMode() to junction0;
			}

			state Parked {
				entry {
					RemoteCommandsMain.Balance2WD.stop();
					RemoteCommandsMain.Balance2WD.setEnginesOff();
					RemoteCommandsMain.Balance2WD.resetBalancerCounters();
				}
				transition !IsStopBalancingMode() to StartBalancing;
			}

			state StartBalancing {
				entry {
					if (!IsStopBalancingMode()) {
						RemoteCommandsMain.Balance2WD.setEnginesOn();
						RemoteCommandsMain.Balance2WD.moveServoToBalancingPosition();
					}
				}
				transition true to junction0;
			}

			state StopTurning {
				entry {
					RemoteCommandsMain.Balance2WD.stopTurning();
				}
				transition !IsStopTurningMode() to junction0;
			}

			state Stop {
				entry {
					RemoteCommandsMain.Balance2WD.setLEDsRed();
					RemoteCommandsMain.Balance2WD.stop();
				}
				transition !IsStopMode() to junction0;
			}
			junction junction0 {
				transition IsTurnLeftMode() to TurnLeft;
				transition IsGoForwardMode() to GoForward;
				transition IsTurnRightMode() to TurnRight;
				transition IsGoBackwardMode() to GoBackward;
				transition IsStopBalancingMode() to StopBalancing;
				transition IsStopTurningMode() to StopTurning;
				transition IsStopMode() to Stop;
			}
		}

		state Dispatch {
			transition IsManualDriveMode() to ManualDrive;
			transition IsObstacleAvoidanceMode() to AvoidObstacles;
			transition IsOpenLabMode() to OpenLab;
		}

		state OpenLab {
			transition !IsOpenLabMode() to Dispatch;
			start Starting;

			state Starting {
				entry {
					RemoteCommandsMain.Balance2WD.stop();
					RemoteCommandsMain.Balance2WD.setLEDsYellow();
					localTimer.begin(1.0);
				}
				static {
					localTimer.compute();
				}
				transition localTimer.isElapsed() to Driving;
			}

			state Driving {
			}
		}
	}
}