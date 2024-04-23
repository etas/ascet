/*
 * LED.cpp
 *
 *  Created on: 15.10.2018
 *      Author: BFR9FE
 */

#include "Arduino.h"

const int RPin = A0; //RGB LED Pin R
const int GPin = A1; //RGB LED Pin G
const int BPin = A2; //RGB LED Pin B

void setupLEDs() {
	pinMode(RPin, OUTPUT);   // set RPin to output mode
	pinMode(GPin, OUTPUT);   // set GPin to output mode
	pinMode(BPin, OUTPUT);   // set BPin to output mode
}



void setLEDsOff() {
	digitalWrite(RPin, HIGH);
	digitalWrite(GPin, HIGH);
	digitalWrite(BPin, HIGH);
}

void setLEDsRed() {
	digitalWrite(RPin, LOW);
	digitalWrite(GPin, HIGH);
	digitalWrite(BPin, HIGH);
}

void setLEDsGreen() {
	digitalWrite(RPin, HIGH);
	digitalWrite(GPin, LOW);
	digitalWrite(BPin, HIGH);
}

void setLEDsBlue() {
	digitalWrite(RPin, HIGH);
	digitalWrite(GPin, HIGH);
	digitalWrite(BPin, LOW);
}

void setLEDsYellow() {
	digitalWrite(RPin, LOW);
	digitalWrite(GPin, LOW);
	digitalWrite(BPin, HIGH);
}

void setLEDsColor(int colorCode) {
	switch (colorCode) {
		case 0 : setLEDsOff(); break;
		case 1 : setLEDsRed(); break;
		case 2 : setLEDsGreen(); break;
		case 3 : setLEDsBlue(); break;
		case 4 : setLEDsYellow(); break;
		default : setLEDsOff();
	}
}
