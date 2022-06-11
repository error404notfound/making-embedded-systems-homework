/*
 * meditation_breathing_mode.c
 *
 *  Created on: 3 Jun. 2022
 *      Author: jennie.stenhouse
 */


#include "util.h"
#include "meditation_breathing_mode.h"
// state tabel for the mode.
modeState_t currentModeState;
int timeOut = 8000;


int meditationBreathingInit(){
	currentModeState = BREATHING_START;
	return 0;
}
int meditationBreathingProcess(){


}
int meditationBreathingOnEnd(){

}
int meditationGetTimeOut()
{

}
