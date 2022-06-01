/*
 * sessionController.h
 *
 *  Created on: May 31, 2022
 *      Author: jennie.stenhouse
 */

#ifndef INC_CONTROLLERS_SESSIONCONTROLLER_H_
#define INC_CONTROLLERS_SESSIONCONTROLLER_H_

#include "stm32f4xx_hal.h"

void SessionControllerInit(I2C_HandleTypeDef *I2Cxhandle,SPI_HandleTypeDef *SPIxHandle,UART_HandleTypeDef * HUARTxHandler);
void SessionControllerProcess();



#endif /* INC_CONTROLLERS_SESSIONCONTROLLER_H_ */
