/*
 * USBController.c
 *
 *  Created on: 28 May 2022
 *      Author: jennie.stenhouse
 */
#include "USBController.h"
#include "stm32f4xx_hal.h"
#include "fatfs.h"
#include "usb_host.h"



char * curretBuffer;
char bufferA[512];

FATFS USBDISKFatFs;           /* File system object for USB disk logical drive */
FIL MyFile;                   /* File object */
char USBDISKPath[4];          /* USB Host logical drive path */
USBH_HandleTypeDef hUSB_HostHandle; /* USB Host handle */


ApplicationTypeDef currentAplicaitonState = APPLICATION_IDLE;


