/*
 * Distance.cpp
 *
 *  Created on: 10.12.2018
 *      Author: BFR9FE
 */

#include "interfaces_IBalance2WD_Automatic.h"
#include "Arduino.h"
#include "PinChangeInterrupt.h"
#include "Distance.h"

/*
 * Define trigger and echo pins for the ultrasonic sensors
 */
//Front Sensor Middle
#define TRIG_FRONTMID 3
#define ECHO_FRONTMID 5

volatile long echo_start;                         // Records start of echo pulse
volatile long echo_end;                           // Records end of echo pulse
volatile long signalRuntime;					  // Records runtime of signal
volatile int trigger_time_count = 0;                  // Count down counter to trigger pulse time

void echo_interrupt(int echoPin);
void echo_interrupt_frontmid();

void setupDistanceMeasurement() {
	pinMode(TRIG_FRONTMID, OUTPUT);
	pinMode(ECHO_FRONTMID, INPUT);

	attachPinChangeInterrupt(digitalPinToPCINT(ECHO_FRONTMID), echo_interrupt_frontmid, CHANGE);  // Attach interrupt to the sensor echo input
}

void triggerDistanceMeasurement()
{
	digitalWrite(TRIG_FRONTMID, HIGH);              // Set the trigger output high

	delayMicroseconds(10);			// Minimum trigger pulse width for the HC-SR04 is 10 us.

	digitalWrite(TRIG_FRONTMID, LOW);              // Set the trigger output low
}


void echo_interrupt_frontmid()
{
	echo_interrupt(ECHO_FRONTMID);
}

// --------------------------
// echo_interrupt() External interrupt from HC-SR04 echo signal.
// Called every time the echo signal changes state.
//
// Note: this routine does not handle the case where the timer
//       counter overflows which will result in the occasional error.
// --------------------------
void echo_interrupt(int echoPin)
{
  switch (digitalRead(echoPin))                     // Test to see if the signal is high or low
  {
    case HIGH:                                      // High so must be the start of the echo pulse
      echo_end = 0;                        // Clear the end time
      echo_start = micros();               // Save the start time
      break;

    case LOW:                                       // Low so must be the end of the echo pulse
      echo_end = micros();                          // Save the end time
      UltraSonicSignalRuntimeInMicroSeconds = echo_end - echo_start;        // Calculate the pulse duration
      break;
  }
}



