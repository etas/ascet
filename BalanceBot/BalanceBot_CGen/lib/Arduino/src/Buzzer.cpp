/*
 * Buzzer.cpp
 *
 *  Created on: 16.10.2018
 *      Author: BFR9FE
 */
#include "Arduino.h"

const int buzzerPin = A3;  // define pin for buzzer

void setupBuzzer() {
	pinMode(buzzerPin, OUTPUT);
}

void buzzerOn() {
	digitalWrite(buzzerPin, HIGH);
}

void buzzerOff() {
	digitalWrite(buzzerPin, LOW);
}

void setBuzzer(int buzzerOnFlag) {
	if (buzzerOnFlag == 1)
		buzzerOn();
	else
		buzzerOff();
}


