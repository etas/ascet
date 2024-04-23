/*
 * Engines.cpp
 *
 *  Created on: 15.10.2018
 *      Author: BFR9FE
 */
#define LIBCALL_PINCHANGEINT
#include "Arduino.h"
#include "PinChangeInterrupt.h"
#include "Engines.h"

#include "interfaces_IBalance2WD_Automatic.h"

//TB6612FNG Drive module control signal
#define IN1M 7
#define IN2M 6
#define IN3M 13
#define IN4M 12
#define PWMA 9
#define PWMB 10
#define STBY 8
//Speed PID control is realized by using speed code counting
#define PinA_left 2  //Interrupt 0
#define PinA_right 4 //Interrupt 1

void Code_left() {
	CountLeft++;
}

void Code_right() {
	CountRight++;
}

void resetBalancerData() {
//	CountLeft = 0;
//	CountRight = 0;
//	Forward = 0.0;
//	Backward = 0.0;
//	TurnLeftFlag = 0;
//	TurnRightFlag = 0;
}

void setupEngines() {
	// TB6612FNGN drive module control signal initialization
	pinMode(IN1M, OUTPUT);//Control the direction of the motor 1, 01 for the forward rotation, 10 for the reverse
	pinMode(IN2M, OUTPUT);
	pinMode(IN3M, OUTPUT);//Control the direction of the motor 2, 01 for the forward rotation, 10 for the reverse
	pinMode(IN4M, OUTPUT);
	pinMode(PWMA, OUTPUT);//Left motor PWM
	pinMode(PWMB, OUTPUT);//Right motor PWM
	pinMode(STBY, OUTPUT);//TB6612FNG enabled

	//Initialize the motor drive module
	digitalWrite(IN1M, 0);
	digitalWrite(IN2M, 1);
	digitalWrite(IN3M, 1);
	digitalWrite(IN4M, 0);
	digitalWrite(STBY, 1);
	analogWrite(PWMA, 0);
	analogWrite(PWMB, 0);

	pinMode(PinA_left, INPUT);  //Speed code A input
	pinMode(PinA_right, INPUT); //Speed code B input

	//The main function of the cycle of detection and superposition of pulse, the determination of car speed.
	//Use the level change both into the pulse superposition, increase the number of motor pulses to ensure
	//the accuracy of the car.
	attachPinChangeInterrupt(digitalPinToPCINT(PinA_left), Code_left, CHANGE);
	attachPinChangeInterrupt(digitalPinToPCINT(PinA_right), Code_right, CHANGE);
}

void stopEngines() {
	PWM1 = 0.0;
	PWM2 = 0.0;
}

void setEnginePower() {
	//Serial.print("PWM1 = "); Serial.print(PWM1); Serial.print(", PWM2 = "); Serial.println(PWM2);
	//Positive and negative output judgment of motor (left motor judgment)
	if (PWM1 >= 0) {
		digitalWrite(IN1M, 0);
		digitalWrite(IN2M, 1);
	} else {
		digitalWrite(IN1M, 1);
		digitalWrite(IN2M, 0);
	}
	analogWrite(PWMA, abs(PWM1));

	//Positive and negative output judgment of motor (right motor judgment)
	if (PWM2 >= 0) {
		digitalWrite(IN3M, 0);
		digitalWrite(IN4M, 1);
	} else {
		digitalWrite(IN3M, 1);
		digitalWrite(IN4M, 0);
	}
	analogWrite(PWMB, abs(PWM2));

}

