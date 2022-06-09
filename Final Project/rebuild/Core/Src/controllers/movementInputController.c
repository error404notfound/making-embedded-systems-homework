/*
 * movementInputController.c
 *
 *  Created on: May 31, 2022
 *      Author: jennie.stenhouse
 */




#include <movementInputController.h>
#include "accel_LIS3DH_driver.h"
#include "gyro_I3G450D_driver.h"

typedef struct{
	int16_t x;
	int16_t y;
	int16_t z;
} movementData_t;
extern movementData_t lastGyro;
extern movementData_t lastAccel;

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

	return 0;
}
gesture_t getInterruptType( sensor_t sensor ){


}
