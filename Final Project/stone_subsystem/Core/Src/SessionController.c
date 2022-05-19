/*
 * SessionController.c
 *
 *  Created on: May 19, 2022
 *      Author: jennie.stenhouse
 */




#include "sessionController.h"
#include <stdio.h>
// private varaibles.

uint8_t userID = 1;

// states Startup


// change which userID is used in saving activity & usage data.
void ChangeUser(uint8_t newUserID ){
	userID = newUserID;
}

void SessionControllerInit()
{
	// Pass down all the interface handles to there controllers
	// Make sure that they return okay.
	// Ff there are error enter error state
	// trigger startup output
	// change state to idle

}
void SessionControllerProcess()
{


// run movement input loop.
// check to see if console has been triggerd
//





}

void IdleState()
{

}
// common timer ends
// go to next function state.
//

