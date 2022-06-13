/*
 * usbcontroller.h
 *
 *  Created on: Jun 2, 2022
 *      Author: jennie.stenhouse
 *      code from https://controllerstech.com/stm32-usb-host-msc/
 *      Modified from the free RTOS file handling code.
 */



#include <fileController.h>
#include <stdio.h>
#include <inttypes.h>

#include "stm32f4xx_hal.h"
#include "file_USB_driver.h"
#include "usb_host.h"
#include "user.h"
#include 	"util.h"
#include "movementInputController.h"


int logMovement = 0;

stoneError_t FileControllerInit(){
	stoneError_t ret = NO_ERROR;
	// wait for the USB to be ready to mount.
	while (GetUSBState()!=APPLICATION_READY){
		   MX_USB_HOST_Process();

	}
	Mount_USB();
	// check to see if a dir for this user already exists.

	int userID = GetUserID();
	char *path = malloc(20*sizeof(char));
	sprintf(path,"/%d/prefs.txt\n",userID);
	FRESULT res = Check_File( path );
	// if there is no existing folder creat one and the files that the program uses.
	if(FR_NO_PATH == res)
	{

		sprintf(path,"/%d",userID);
		res = Create_Dir(path);
		sprintf(path,"/%d/prefs.txt",userID);
		res = Create_File(path);// User settings
		sprintf(path,"/%d/MOVELOG.txt",userID);
		res = Create_File(path);// Movement Log
		sprintf(path,"/%d/SESSION.txt",userID);
		res = Create_File(path);// Movement Log


	}
	free(path);


	return ret;
}
stoneError_t FileControllerProcess(){
	MX_USB_HOST_Process();

	if (1 == GetMovementUSBLogging())
	{

		int userID = GetUserID();
		// get the movement data and barf it out to file along with Haltick. which isn't entirely accurate at this point.
		// todo: change this to using ping pong buffers.
		uint32_t tick  = HAL_GetTick();
		// get gyro
		movementData_t gyroData;
		GetLast( GYROSCOPE,  & gyroData);
		// get accel
		movementData_t accelData;
		GetLast( ACCELEROMETER,  & accelData);
		//write it to a buffer.
		char *pathBuf = malloc(16*sizeof(char));
		sprintf(pathBuf,"/%d/MOVELOG.txt",userID);
		char *buf = malloc(80*sizeof(char));
		sprintf(buf,"%lu :%d,%d,%d,%d,%d,%d \n",tick,accelData.x,accelData.y,accelData.z,gyroData.x,gyroData.y,gyroData.z);
		Update_File(pathBuf, buf);
		free(buf);
		free(pathBuf);






	}

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
stoneError_t checkUSBConnected(){
	 MX_USB_HOST_Process();
	char path[40] = {0};
	int userID = GetUserID();
	sprintf(path,"/%d/prefs.txt\n",userID,userID);
	FRESULT res = Check_File( path );
	if(res!=FR_OK)
	{
		return NO_USB;
	}
	else return NO_ERROR;
	free(path);
}





