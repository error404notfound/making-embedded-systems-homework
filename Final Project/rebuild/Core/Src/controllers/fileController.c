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
#include "user.h"

int logMovement = 0;

stoneError_t FileControllerInit(){
	stoneError_t ret = NO_ERROR;
	// wait for the USB to be ready to mount.
	while (GetUSBState()!=APPLICATION_READY){
		   MX_USB_HOST_Process();

	}
	Mount_USB();
	// check to see if a dir for this user already exists.
	char path[80]={0};
	int userID = GetUserID();
	sprintf(path,"/%d/%user_prefs.txt\n",userID,userID);
	FRESULT res = Check_File( path );

	if(FR_NO_PATH == res)
	{
		sprintf(path,"/%d",userID);
		res = Create_Dir(path);
		sprintf(path,"/%d/prefs.txt",userID);
		res = Create_File(path);

	}

	// if not make a directory for that user

	return ret;
}
stoneError_t FileControllerProcess(){


}
stoneError_t LoadUser(uint8_t userID){
	stoneError_t ret = NO_ERROR;
		return ret;
}
stoneError_t SaveUser(uint8_t userID){
	stoneError_t ret = NO_ERROR;
		return ret;
}
stoneError_t LogSessionData(){
	stoneError_t ret = NO_ERROR;
		return ret;
}
stoneError_t SaveSessionData(){
	stoneError_t ret = NO_ERROR;
		return ret;
}
stoneError_t LogMovementData(uint16_t x, uint16_t y, uint16_t z , sensor_t sensor){
	stoneError_t ret = NO_ERROR;
		return ret;
}
stoneError_t SaveMovementData(){
	stoneError_t ret = NO_ERROR;
		return ret;
}
stoneError_t SaveDebugPinData(GPIO_TypeDef * port, uint16_t pin,uint16_t timeperiod){
	stoneError_t ret = NO_ERROR;
		return ret;
}






