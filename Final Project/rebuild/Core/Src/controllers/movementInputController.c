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

// running average buffer
// thresholds for basic gestures.

void MovementControllerInit(I2C_HandleTypeDef *I2Cxhandle,SPI_HandleTypeDef *SPIxHandle) {
	// Accelrometor Init
	Lis3dhInit(I2Cxhandle);

	I3G450D_Init(SPIxHandle);



}
int MovementControllerProcess(){
	// Gets for the gyroscope.
	 I3G450D_loop();
	 Lis3dhGetAcc();
	int16_t acelX,acelY,acelZ;
	AccelGetData(&acelX, &acelY, &acelZ);
	//printf("%d,%d,%d \n",acelX,acelY,acelZ);
	int interrupt = PollInterrupt();

	return 0;
}
gesture_t GetInterruptType( sensor_t sensor ){


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
