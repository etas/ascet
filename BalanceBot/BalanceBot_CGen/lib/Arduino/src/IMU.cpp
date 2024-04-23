/*
 * IMU.cpp
 *
 *  Created on: 15.10.2018
 *      Author: BFR9FE
 */

#include <MPU6050_6Axis_MotionApps20.h>
#include <I2Cdev.h>
#include "Wire.h"

#include "interfaces_IBalance2WD_Automatic.h"


int16_t ax, ay, az, gx, gy, gz;
MPU6050 mpu; //Instantiate an MPU6050 object with the object name mpu

void setupIMU() {
	Wire.begin();
	mpu.initialize();
	delay(2);
}

void loopIMU() {
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);     //IIC gets MPU6050 six axis data ax ay az gx gy gz
    AccelerationX = ax;
    AccelerationY = ay;
    AccelerationZ = az;
    GyroX = gx;
    GyroY = gy;
    GyroZ = gz;
}
