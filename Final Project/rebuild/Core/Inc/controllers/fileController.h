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
stoneError_t loadUser(uint8_t userID);
stoneError_t saveUser(uint8_t userID);
stoneError_t logSessionData();
stoneError_t saveSessionData();
stoneError_t logMovementData();
stoneError_t saveMovementData();
stoneError_t saveDebugPinData(GPIO_TypeDef * port, uint16_t pin, uint16_t timeperiod );




#endif /* INC_CONTROLLERS_USBCONTROLLER_H_ */
