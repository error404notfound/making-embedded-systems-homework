/*
 * user.c
 *
 *  Created on: Jun 9, 2022
 *      Author: jennie.stenhouse
 */
#include "user.h"
#include <stdio.h>
int userID = 123501;

// change which userID is used in saving activity & usage data.
void ChangeUser(uint8_t newUserID ){
	userID = newUserID;
}
int GetUserID()
{
	return userID;
}
void SetUserMainColour(int Red, int Green, int Blue)
{}
