/*
 * colour_change_mode.h
 *
 *  Created on: Jun 1, 2022
 *      Author: jennie.stenhouse
 */



#include "colour_change_mode.h"

// private functions.

int breathingIn();
int breathHold();
int breathingOut();

void breathingInProcess();
void breathHoldProcess();
void breathingOutProcess();

void breathingInOutput();
void breathHoldOutput();
void breaingOutOutput();

// internal state table
//static stateTableEntry_t  stateTabel[]={};
int colourChangeInit(){

	return 0;
}
int colourChangeProcess(){
	return 0;
}
int colourChangeOnEnd(){
	return 0;
}

int colourChangeGetTimeOut(){
	return 0;
}
