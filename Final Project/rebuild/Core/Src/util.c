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

void debugPrint(char * buffer)
{
	if(debugLogging&!paused)
	{
		printf(buffer);
		printf("\n");
	}
}
void setUserDebugLogging ( int set )
{
	debugLogging = set;
}
int getDebugLogging( )
{
	return debugLogging;
}
void pauseDebugLogging(){paused = 1;}
void resumeDebugLogging(){paused = 0;}


