/*
 * Servos.cpp
 *
 *  Created on: 15.10.2018
 *      Author: BFR9FE
 */

#include "Arduino.h"
#include "Servo.h"
#include <ServoTimer2.h>

const int ServoPin = 11;  //define pin for supporting servo
const int ServoParkingAngle = 20;
const int ServoBalancingAngle = 80;

ServoTimer2 servo1;

void setupServo() {
	//Attach the supporting servo
	servo1.attach(ServoPin);
}

void moveServoToAngle(int angle) {
	servo1.write(map(angle, 0, 180, 550, 2400));
}

void moveServoToBalancingPosition() {
	moveServoToAngle(ServoBalancingAngle);
}

void moveServoToParkingPosition() {
	moveServoToAngle(ServoParkingAngle);
}
