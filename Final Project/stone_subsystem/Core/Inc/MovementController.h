/*
 * MovementController.h
 *
 *  Created on: May 19, 2022
 *      Author: jennie.stenhouse
 */

#ifndef INC_MOVEMENTCONTROLLER_H_
#define INC_MOVEMENTCONTROLLER_H_

#include "stm32f4xx_hal.h"



void MovementControllerInit(I2C_HandleTypeDef *I2Cxhandle,SPI_HandleTypeDef *SPIxHandle) ;
int MovementControllerProcess();


#endif /* INC_MOVEMENTCONTROLLER_H_ */
