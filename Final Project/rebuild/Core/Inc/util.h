/*
 * util.h
 *
 *  Created on: May 31, 2022
 *      Author: jennie.stenhouse
 */

#ifndef INC_UTIL_H_
#define INC_UTIL_H_


#define VERSION_STRING "StoneCode 0.0.0.1"
typedef enum { INIT_ERROR } stoneError_t;
void debugPrint(char * buffer);
void setUserDebugLogging ( int set );
void resumeDebugLogging();
void pauseDebugLogging();
#endif /* INC_UTIL_H_ */
