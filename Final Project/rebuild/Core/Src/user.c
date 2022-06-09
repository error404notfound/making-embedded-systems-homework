/*
 * user.c
 *
 *  Created on: Jun 9, 2022
 *      Author: jennie.stenhouse
 */

uint8_t userID = 12345;

// change which userID is used in saving activity & usage data.
void ChangeUser(uint8_t newUserID ){
	userID = newUserID;
}
uint8_t GetUserID()
{
	return userID;
}
