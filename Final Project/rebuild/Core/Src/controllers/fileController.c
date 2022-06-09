/*
 * usbcontroller.h
 *
 *  Created on: Jun 2, 2022
 *      Author: jennie.stenhouse
 *      code from https://controllerstech.com/stm32-usb-host-msc/
 *      Modified from the free RTOS file handling code.
 */



#include <fileController.h>
#include "stm32f4xx_hal.h"
#include "file_USB_driver.h"
#include "usb_host.h"


stoneError_t FileControllerInit(){
	stoneError_t ret = NO_ERROR;
	// wait for the USB to be ready to mount.
	while (getUSBState()!=APPLICATION_READY){
		   MX_USB_HOST_Process();

	}
	Mount_USB();
	// check to see if a dir for this user already exists.

	// if not make a directory for that user

	return ret;
}
stoneError_t loadUser(uint8_t userID){
	stoneError_t ret = NO_ERROR;
		return ret;
}
stoneError_t saveUser(uint8_t userID){
	stoneError_t ret = NO_ERROR;
		return ret;
}
stoneError_t logSessionData(){
	stoneError_t ret = NO_ERROR;
		return ret;
}
stoneError_t saveSessionData(){
	stoneError_t ret = NO_ERROR;
		return ret;
}
stoneError_t logMovementData(){
	stoneError_t ret = NO_ERROR;
		return ret;
}
stoneError_t saveMovementData(){
	stoneError_t ret = NO_ERROR;
		return ret;
}
stoneError_t saveDebugPinData(GPIO_TypeDef * port, uint16_t pin,uint16_t timeperiod){
	stoneError_t ret = NO_ERROR;
		return ret;
}






