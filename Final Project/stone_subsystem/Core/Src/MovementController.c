/*
 * MovementController.c
 *
 *  Created on: May 19, 2022
 *      Author: jennie.stenhouse
 */


#include <movementController.h>
#include "lis3dh_driver.h"
#include "gyroI3G450D.h"

// running average buffer
// thresholds for basic gestures.

void MovementControllerInit(I2C_HandleTypeDef *I2Cxhandle,SPI_HandleTypeDef *SPIxHandle) {
	// Accelrometor Init
	Lis3dhInit(I2Cxhandle);
	I3G450D_Init(SPIxHandle);
	// Gyroscope init.
	// GPIO for accelerometor interrupt.

}
int MovementControllerProcess(){
	// run the gets for data from the gyroscope and the
	return 0;
}
