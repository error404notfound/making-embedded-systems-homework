/*
 * util.c
 *
 *  Created on: Jun 1, 2022
 *      Author: jennie.stenhouse
 */

#include <util.h>
#include <stdio.h>


int debugLogging = 0;
int paused = 0;
// system and user debugging need to be on to actually print.
void debugPrint(char * buffer)
{
	if(debugLogging&!paused)
	{
		printf(buffer);
		printf("\n");
	}
}
// user debugging
void setUserDebugLogging ( int set )
{
	debugLogging = set;
}
int getDebugLogging( )
{
	return debugLogging;
}
//  system debugging.
void pauseDebugLogging(){paused = 1;}
void resumeDebugLogging(){paused = 0;}

void errorHandling(stoneError_t error ){
// Uses Red pin with different flashing rates for errors.
//SENSOR_INIT_ERROR, CONSOLE_BASED_ERROR, HAL_BASED_ERROR
	int delay = 0;
	switch(error)
	{
	case(SENSOR_INIT_ERROR):
		delay = 100;
		 break;
	case (SENSOR_READ_ERROR):
			delay = 500;
	break;
	case(CONSOLE_BASED_ERROR):
			delay = 1000;
			 break;
	case(HAL_BASED_ERROR):
			delay = 10000;
			 break;
	default:
			 delay = 1;
			 break;

	}
	while(1){
			HAL_GPIO_WritePin(GPIOG,GPIO_PIN_14, GPIO_PIN_SET);
			HAL_Delay(delay);
			// rest to turn it off.
			HAL_GPIO_WritePin(GPIOG,GPIO_PIN_14, GPIO_PIN_RESET);
			HAL_Delay(delay);
	}
}


