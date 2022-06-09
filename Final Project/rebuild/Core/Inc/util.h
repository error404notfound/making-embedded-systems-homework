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
typedef enum { SENSOR_INIT_ERROR,SENSOR_READ_ERROR, CONSOLE_BASED_ERROR, HAL_BASED_ERROR,NO_ERROR, FILE_ERROR } stoneError_t;


void debugPrint(char * buffer);
void setUserDebugLogging ( int set );
void resumeDebugLogging();
void pauseDebugLogging();
void errorHandling(stoneError_t);
#endif /* INC_UTIL_H_ */
