/*
 * MovementController.c
 *
 *  Created on: May 19, 2022
 *      Author: jennie.stenhouse
 */


#include <movementController.h>
#include "lis3dh_driver.h"
#include "gyroI3G450D.h"

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
	int16_t x,y,z;

	I3G450D_loop();
	GyroGetData(&x,&y, &z );


	// Gets for the acceleromentor .
	Lis3dhGetAcc();
	AccelGetData(&x,&y, &z );
	return 0;
}
