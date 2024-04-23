package control;

type EModes is enum {
	STOP_BALANCING = 0,			// serial command 'j'  APIs: moveServoToParkingPosition(), stop(), setEnginesOff()
	GO_FORWARD = 1,				// serial command 'a'  APIs: goForward()
	TURN_RIGHT = 2,				// serial command 'b'  APIs: turnRight()
	TURN_LEFT = 3,				// serial command 'c'  APIs: turnLeft()
	GO_BACKWARD = 4,			// serial command 'd'  APIs: goBackward()
	STOP = 5,					// serial command 'e'  APIs: stop()
	BUZZER_ON = 6,				// serial command 'h'  APIs: C++ only: Buzzer.cpp buzzerOn()
	BUZZER_OFF = 7,				// serial command 'i'  APIs: C++ only: Buzzer.cpp buzzerOff()
	STOP_TURNING = 8,			// serial command 'q'  APIs: stopTurning()
	INC_KPSPEED = 9,			// serial command 'k'  APIs: IParameters.KpSpeed += 0.2
	DEC_KPSPEED = 10,			// serial command 'l'  APIs: IParameters.KpSpeed -= 0.2
	INC_KPANGLE = 11,			// serial command 'm'  APIs: IParameters.KpAngle += 1.0
	DEC_KPANGLE = 12,			// serial command 'n'  APIs: IParameters.KpAngle -= 1.0
	INC_KISPEED = 13,			// serial command 'o'  APIs: IParameters.KiSpeed += 0.2
	DEC_KISPEED = 14,			// serial command 'p'  APIs: IParameters.KpSpeed -= 0.2
	INC_ZEROANGLE = 15,			// serial command 'r'  APIs: IParameters.Angle0 += 1
	DEC_ZEROANGLE = 16,			// serial command 's'  APIs: IParameters.Angle0 -= 1
	OBSTACLE_AVOIDANCE = 17,	// serial command 'f'  APIs: See hierarchical state machine �ObstacleAvoidance�
	OPENLAB_MODE = 18,			// serial command 'g'  APIs: See hierarchical state machine �OpenLab2019"
	INC_KIANGLE = 19,			// serial command 't'  APIs: IParameters.KiAngle += 0.03
	DEC_KIANGLE = 20			// serial command 'u'  APIs: IParameters.KiAngle -= 0.03
}; 

const real RAD_TO_DEG = 57.3;
