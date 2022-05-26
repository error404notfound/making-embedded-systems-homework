/*
 * sessionController.h
 *
 *  Created on: May 19, 2022
 *  The session Controller holds the current state and makes the state change descions.
 *  It also communicates to the outputController and the inputsController.
 *
 *      Author: jennie.stenhouse
 */

#ifndef INC_SESSIONCONTROLLER_H_
#define INC_SESSIONCONTROLLER_H_

#include "stm32f4xx_hal.h"

void SessionControllerInit(I2C_HandleTypeDef *I2Cxhandle,TIM_HandleTypeDef *timer,SPI_HandleTypeDef *SPIxHandle);
void SessionProcess();

#endif /* INC_SESSIONCONTROLLER_H_ */
