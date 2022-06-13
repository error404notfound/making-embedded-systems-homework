/*
 * fileController.h
 *
 *  Created on: Jun 8, 2022
 *      Author: jennie.stenhouse
 */

#ifndef INC_CONTROLLERS_USBCONTROLLER_H_
#define INC_CONTROLLERS_USBCONTROLLER_H_
#include "util.h"


stoneError_t FileControllerInit();

stoneError_t LoadUser(uint8_t userID);
stoneError_t SaveUser(uint8_t userID);

stoneError_t LogSessionData();
stoneError_t SaveSessionData();


stoneError_t SaveDebugPinData(GPIO_TypeDef * port, uint16_t pin, uint16_t timeperiod );


stoneError_t LogMovementData(uint16_t x, uint16_t y, uint16_t z , sensor_t sensor);
stoneError_t SaveMovementData();

stoneError_t checkUSBConnected();


#endif /* INC_CONTROLLERS_USBCONTROLLER_H_ */
