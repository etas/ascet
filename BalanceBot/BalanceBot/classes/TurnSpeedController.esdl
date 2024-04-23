package classes;

import interfaces.IParameters;
import interfaces.IBalance2WD;
import SystemLib.Nonlinears.Limiter;

singleton class TurnSpeedController
reads IParameters.KpTurn, IBalance2WD.TurnLeftRightFlag, IBalance2WD.PulseLeft, IBalance2WD.PulseRight
writes IBalance2WD.TurnOutput {
	real turnOut = 0.0;
	Limiter Limit_TurnOut;
	real rotationRatio = 0.0;
	real currentSpeed = 0.0;
	Limiter Limit_RotationRatio;
	integer spinOnce = 0;

	@thread
	@generated("blockdiagram", "cc672214")
	public void calculateTurnSpeed() {
		if (IBalance2WD.TurnLeftRightFlag == 0) {
			spinOnce = 0; // Main/calculateTurnSpeed 1/if-then 1
			turnOut = 0.0; // Main/calculateTurnSpeed 1/if-then 2
		} else {
			if (spinOnce == 0) {
				spinOnce = 1; // Main/calculateTurnSpeed 1/if-else 1/if-then 1
				currentSpeed = abs(real((IBalance2WD.PulseLeft + IBalance2WD.PulseRight))); // Main/calculateTurnSpeed 1/if-else 1/if-then 2
				rotationRatio = Limit_RotationRatio.value(0.5, (55.0 / currentSpeed), 5.0); // Main/calculateTurnSpeed 1/if-else 1/if-then 3
			} // Main/calculateTurnSpeed 1/if-else 1
			turnOut = Limit_TurnOut.value(-5.0, (turnOut + (if(IBalance2WD.TurnLeftRightFlag == 1) then(-rotationRatio) else rotationRatio)), 5.0); // Main/calculateTurnSpeed 1/if-else 2
		} // Main/calculateTurnSpeed 1
		IBalance2WD.TurnOutput = (IParameters.KpTurn * turnOut); // Main/calculateTurnSpeed 2
	}
}