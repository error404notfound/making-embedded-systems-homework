/*
 * movementInputController.h
 *
 *  Created on: May 31, 2022
 *      Author: jennie.stenhouse
 */

#ifndef INC_CONTROLLERS_MOVEMENTINPUTCONTROLLER_H_
#define INC_CONTROLLERS_MOVEMENTINPUTCONTROLLER_H_


#include "stm32f4xx_hal.h"
#include "util.h"

typedef enum { SUDDEN_UP, FULL_CIRCLE, DOUBLE_TAP, TWIST_Y, TWIST_Z, TWIST_X, NO_GESTURE } gesture_t;

typedef struct{
	int16_t x;
	int16_t y;
	int16_t z;
} movementData_t;

void MovementControllerInit(I2C_HandleTypeDef *I2Cxhandle,SPI_HandleTypeDef *SPIxHandle) ;
int MovementControllerProcess();
gesture_t GetInterruptType( sensor_t sensor );
gesture_t GetLastGesture();
void GetLast( sensor_t sensor,  movementData_t * data);


#endif /* INC_CONTROLLERS_MOVEMENTINPUTCONTROLLER_H_ */
