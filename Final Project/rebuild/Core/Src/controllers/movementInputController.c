/*
 * movementInputController.c
 *
 *  Created on: May 31, 2022
 *      Author: jennie.stenhouse
 */




#include <movementInputController.h>
#include "accel_LIS3DH_driver.h"
#include "gyro_I3G450D_driver.h"


gesture_t  lastGesture;
extern movementData_t lastGyro;
extern movementData_t lastAccel;

#define DEG_TO_RAD(angleInDegrees)      ((double)(angleInDegrees) * M_PI / 180.0f)
#define RAD_TO_DEG(angleInRadians)      ((double)(angleInRadians) * 180.0f / M_PI)
#define ACC_TO_G(acceleration)          (((double)(acceleration) / 100.0f) / 9.80665f) // convert acceleration m/s² to gravity 9,80665 m/s²

// From adafruit magic wand detection -
// flick detection
#define FLICKTRIG 17000 // lower = more senstive

// Wrist twist
#define WRISTDIFF 13000 // lower = more senstive
#define WRISTGY  25000 // higher = more senstive

typedef enum {horiz,vertical,mid}orientation;


int wristTwist = 0;
int flick = 0;
orientation orient = horiz;

// running average buffer
// thresholds for basic gestures.

void MovementControllerInit(I2C_HandleTypeDef *I2Cxhandle,SPI_HandleTypeDef *SPIxHandle) {
	// Accelrometor Init
	Lis3dhInit(I2Cxhandle);

	I3G450D_Init(SPIxHandle);



}
int MovementControllerProcess(){

	// Process the Acellerometor
	 Lis3dhGetAcc();
	int16_t acelX,acelY,acelZ;
	AccelGetData(&acelX, &acelY, &acelZ);


	// Process the gyro.
	int16_t gX,gY,gZ;
	I3G450D_loop();
	GyroGetData(&gX, &gY, &gZ);


	HAL_Delay(100);

	return 0;
}
gesture_t GetInterruptType( sensor_t sensor ){

	gesture_t interruptType;

	if(ACCELEROMETER == sensor)
	{
		AccelGetInerrrupt(&interruptType);
	}
	if(GYROSCOPE == sensor)
	{
		GyroGetInerrrupt(&interruptType);
	}
}
gesture_t GetLastGesture(){
	return lastGesture;
}

void GetLast( sensor_t sensor,  movementData_t * data)
{
	if(ACCELEROMETER == sensor)
	{
		int16_t acelX,acelY,acelZ;
		AccelGetData(&acelX, &acelY, &acelZ);
		data->x = acelX;
		data->y = acelY;
		data->z = acelZ;

	}
	if(GYROSCOPE == sensor)
		{
			int16_t gyroX,gyroY,gyroZ;
			GyroGetData(&gyroX, &gyroY, &gyroZ);
			data->x = gyroX;
			data->y = gyroY;
			data->z = gyroZ;

		}

}

