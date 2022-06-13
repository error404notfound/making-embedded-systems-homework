/*
 * util.h
 *
 *  Created on: May 31, 2022
 *      Author: jennie.stenhouse
 *      Usefull stuff used across the project that either needs global access or dosn't really fit
 *      Anywhere else. These should be kept to a minimum not just a place to dump stuff.
 */

#ifndef INC_UTIL_H_
#define INC_UTIL_H_

#include "stm32f4xx_hal.h"



#define VERSION_STRING "StoneCode 0.0.0.1"
typedef enum { SENSOR_INIT_ERROR,SENSOR_READ_ERROR, CONSOLE_BASED_ERROR, HAL_BASED_ERROR,NO_ERROR, FILE_ERROR, HARD_FAULT, NO_USB } stoneError_t;
typedef enum { ACCELEROMETER,GYROSCOPE }sensor_t;

void DebugPrint(char * buffer);
void SetUserDebugLogging ( int set );
void ResumeDebugLogging();
void PauseDebugLogging();
void StoneErrorHandling(stoneError_t);
stoneError_t SetMovementUSBLogging(int flag);
int GetMovementUSBLogging();
#endif /* INC_UTIL_H_ */
