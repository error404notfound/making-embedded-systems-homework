/*
 * movementInputController.h
 *
 *  Created on: May 31, 2022
 *      Author: jennie.stenhouse
 */

#ifndef INC_CONTROLLERS_MOVEMENTINPUTCONTROLLER_H_
#define INC_CONTROLLERS_MOVEMENTINPUTCONTROLLER_H_


#include "stm32f4xx_hal.h"

typedef enum { WRIST_FLICK, FULL_CIRCLE, DOUBLE_TAP, TWIST_Y } gesture_t;
typedef enum { ACCELEROMETER,GYROSCOPE }sensor_t;


void MovementControllerInit(I2C_HandleTypeDef *I2Cxhandle,SPI_HandleTypeDef *SPIxHandle) ;
int MovementControllerProcess();
gesture_t getInterruptType( sensor_t sensor );


#endif /* INC_CONTROLLERS_MOVEMENTINPUTCONTROLLER_H_ */
