#include "Arduino.h"
#include "Wire.h"
#include "Engines.h"
#include "IMU.h"
#include "LED.h"
#include "Servo.h"
#include "Buzzer.h"
#include "Distance.h"
#include "interfaces_IBalance2WD_Automatic.h"
#include "interfaces_IRemoteCommands_Automatic.h"
#include "interfaces_IParameters_Automatic.h"

extern "C" {
	extern void Task_5ms();
	extern void Task_10ms();
	extern void Task_50ms();
}


int mode = 3;
int motorRun = 0;
int backwardCounter = 0;

const int cyclePeriod = 5; //Filter method sampling time interval milliseconds
static unsigned long cycle_count = 0L;
static unsigned long last_cycle_time = 0L;

void logger();

void readSerialInput() {
  if (Serial.available() > 0){ //Receive serial data
   switch(Serial.read()){ //Save the serial data received
	  case 'a': Mode = 1; break;//go ahead
	  case 'b': Mode = 2; break;//turn right
	  case 'c': Mode = 3; break;//turn left
	  case 'd': Mode = 4; break;//go backwards
	  case 'e': Mode = 5; break;//stop
	  case 'f': Mode = 17; break;//obstacle avoidance
	  case 'g': Mode = 18; break;//follow mode
	  case 'h': buzzerOn(); break;//buzzer on
	  case 'i': buzzerOff(); break;//buzzer off
	  case 'j': Mode = 0; break;//stop balancing
	  case 'k': /*Mode = 9;*/ KpSpeed += 0.2; break;//increment kpSpeed
	  case 'l': /*Mode = 10;*/ KpSpeed -= 0.2; break;//decrement kpSpeed
	  case 'm': /*Mode = 11;*/ KpAngle += 1.0; break;//increment kpAngle
	  case 'n': /*Mode = 12;*/ KpAngle -= 1.0; break;//decrement kpAngle
	  case 'o': /*Mode = 13;*/ KiSpeed += 0.03; break;//increment kiSpeed
	  case 'p': /*Mode = 14;*/ KiSpeed -= 0.03; break;//decrement kiSpeed
	  case 'q': Mode = 8; break;//stop turning
	  case 'r': /*Mode = 15;*/ TargetAngle -= 1; break;//decrement zero angle (tilt backward)
	  case 's': /*Mode = 16;*/ TargetAngle += 1; break;//increment zero angle (tilt forward)
	  case 't': /*Mode = 19;*/ KiAngle += 0.03; break;//increment kiAngle
	  case 'u': /*Mode = 20;*/ KiAngle -= 0.03; break;//decrement kiAngle
   }
  }
}

void setup() {

	Mode = 0;
	Wire.begin();  //I2C Controller
	setupIMU();
	setupEngines();
	setupLEDs();
	setupServo();
	setupBuzzer();
	setupDistanceMeasurement();

	moveServoToParkingPosition();
	setLEDsRed();
	buzzerOn();
	delay(100);
	buzzerOff();

	//Turn on the serial port and set the baud rate to 115200
	//Communicate with the Bluetooth module
	Serial.begin(115200);
	delay(150);
	//Serial.println("getForwardBackward, PulseLeft, PulseRight, SetP0, KpSpeed, KiSpeed, SpeedOutput");
}

void loop() {
	unsigned long current_millies = millis();

	// we do not use the builtin timers because they are already used for other things
	if ( cycle_count == 0L || (current_millies >= last_cycle_time + cyclePeriod) ) {
		last_cycle_time = current_millies;

		// read sensor data
		loopIMU();
		// calculate actions every 5ms
		Task_5ms();
		moveServoToAngle(ServoAngle);

		setEnginePower();

		if (cycle_count % 2 == 0) { // every 10ms
			Task_10ms();
		}
		if (cycle_count % 4 == 0) { // every 20ms
			triggerDistanceMeasurement();
		}
		if (cycle_count % 10 == 0) { // every 50ms
//			logger();
			Task_50ms();
			setLEDsColor(LEDColor);
			setBuzzer(BuzzerOn);
			readSerialInput();
		}
		if (cycle_count % 100 == 0) { // every 500ms
			logger();
		}
		cycle_count++;
	}
}

void logger() {
//	Serial.print(ForwardBackward); Serial.print(", "); Serial.print(PulseLeft); Serial.print(", "); Serial.print(PulseRight); Serial.print(", ");
//	Serial.print(SetP0); Serial.print(", "); Serial.print(KpSpeed); Serial.print(", "); Serial.print(KiSpeed); Serial.print(", "); Serial.println(SpeedOutput);
//	Serial.print("TargetSpeed = "); Serial.println(TargetSpeed);
//	Serial.print("SpeedOutput = "); Serial.println(SpeedOutput);
//	Serial.print("PWM = "); Serial.print(PWM); Serial.print(", PWM1 = "); Serial.print(PWM1); Serial.print(", PWM2 = "); Serial.println(PWM2);
//	Serial.print("KpSpeed = "); Serial.print(KpSpeed); Serial.print(", KiSpeed = "); Serial.print(KiSpeed);//Serial.print(", KpAngle = "); Serial.print(KpAngle); Serial.print(", KiAngle = "); Serial.println(KiAngle);
//	Serial.print("SensorSignalRuntime = "); Serial.print(SensorSignalRuntime / 1000); Serial.print("ms");
	Serial.print("TargetAngle = "); Serial.print(TargetAngle); Serial.print(", Front Distance = "); Serial.print(UltraSonicSignalRuntimeInMicroSeconds * 0.017); Serial.println("cm");
//	Serial.print("AngleOutput = "); Serial.println(AngleOutput);
//	Serial.print("AccX = "); Serial.print(AccelerationX);
//	Serial.print(", AccY = "); Serial.print(AccelerationY);
//	Serial.print(", AccZ = "); Serial.println(AccelerationZ);
//	Serial.print("GyroX = "); Serial.print(GyroX);
//	Serial.print(", GyroY = "); Serial.print(GyroY);
//	Serial.print(", GyroZ = "); Serial.println(GyroZ);
}

