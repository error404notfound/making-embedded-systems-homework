/*
 * sessionController.c
 *
 *  Created on: May 31, 2022
 *      Author: jennie.stenhouse
 */






#include <sessionController.h>
#include "movementInputController.h"
#include "visualOutputController.h"
#include <stdio.h>
#include "console.h"
#include "retarget.h"

// private varaibles.

int userID = 12345678;

typedef int (*stateInit )(void);
typedef int (*ledOutput)(void);
typedef int (*stateProcess)(void);
typedef enum { START, IDLE_AWAKE, DEEP_SLEEP, WAITING_FOR_SELECTION, LOAD_MODE, IN_MODE,CLI_MODE } state_t;
typedef enum { IDEL_AWAKE_OUTPUT, SLEEP_OUTPUT, WAITING_FOR_INPUT, CLI_MODE_OUTPUT, LOADING_MODE_OUTPUT} output_t;


typedef struct {
	/*Button press Response */ stateInit onButtonPress;
	/*Gesture recon response */ stateInit onGestureRecognize;
	/*Shake to wake */ stateInit onShakeToWake;
	/*LED output */ ledOutput LedOutput;
	/*OnEnd */stateInit onEnd;
	/* timeout */ int timeout;
	/* stateProcess */ stateProcess stateProcess;
}stateTableEntry_t;

// set up functions for each state.
int Start();
int IdleAwake();
int DeepSleep();
int WaitingForSelection();
int LoadMode();
int CliMode();
int StartPreviouseMode();
int InMode();
// Process for each state
int StartProcess();
int IdleAwakeProcess();
int DeepSleepProcess();
int WaitingForSelectionProcess();
int LoadModeProcess();
int CliModeProcess();
int StartPreviouseModeProcess();
int InModeProcess();

// output for each function.
int IdelAwakeOutput();
int SleepOutput();
int WaitingForInputOutput();
int CliModeOutput();
int ModeLoading();

//Cli mode needs to go back to previouse state if it gets togled out of handled with in the cliMode

// state table
static stateTableEntry_t  stateTabel[]={
				// Button Press, Gesture Recognized, Shake to wake, Led output, Timeout/completion , timeout length in milliseconds stateprocces
/*START*/		{ NULL,				NULL, 				NULL,		NULL, 		&IdleAwake, 		800,&StartProcess },
/*IDEL AWAKE */	{ &CliMode,			NULL, 				NULL,		NULL, 		&WaitingForSelection, 800, &IdleAwakeProcess },
/*DEEP SLEEP */	{ &CliMode,			NULL, 				IdleAwake,	NULL, 		&DeepSleep, 800, &DeepSleepProcess },
/* WAITING */	{ &CliMode,			LoadMode, 			NULL,		NULL, 		&DeepSleep, 800 , &WaitingForSelectionProcess},
/* LOAD_MODE */	{ &CliMode,			NULL, 				NULL,		NULL, 		&InMode, 800 , &LoadModeProcess},
/* IN_MODE */	{ &CliMode,			NULL, 				NULL,		NULL, 		&IdleAwake, 800, &InModeProcess },
/* CLI_MODE */	{ &StartPreviouseMode,NULL, 				NULL,		NULL, 		&IdleAwake, 800, &CliModeProcess },


};
state_t currentState;
state_t previouseState;
uint32_t timeStateStarted;
uint8_t buttonPressed =0;
uint8_t shakeToWakeTriggered;
uint8_t gestureRecognized;
uint8_t loggingToUsbEnabled;
uint8_t inMode;
uint8_t cliMode =0;
// struct for loggin
// mode, time in mode
TIM_HandleTypeDef * timerHandle;

// change which userID is used in saving activity & usage data.
void ChangeUser(uint8_t newUserID ){
	userID = newUserID;
}

void SessionControllerInit(I2C_HandleTypeDef *I2Cxhandle,TIM_HandleTypeDef *timer,SPI_HandleTypeDef *SPIxHandle)
{
	// Pass down all the interface handles to there controllers




	// Make sure that they return okay.
	// There are error enter error state
	// start general timer;

	currentState = START;
	timeStateStarted = HAL_GetTick();
	MovementControllerInit(I2Cxhandle,SPIxHandle);


}
void SessionControllerProcess()
{


// check to see if current state has reached it time out.
	stateTableEntry_t current = stateTabel[currentState];
	uint32_t timeout = current.timeout;
	uint32_t currentTime = HAL_GetTick();
	uint32_t timeSinceStarted = currentTime -timeStateStarted;


	MovementControllerProcess();

	if ( HAL_GetTick() - timeStateStarted > timeout )
	{
		previouseState = currentState;
		current.onEnd();

	}
	if ( 1 == buttonPressed )
	{
		current.onButtonPress();
	}
	if( 1 == gestureRecognized ){
		// gesture recognized response.
		// get the gesture tag from MovementController.

	}
	if( 1 == shakeToWakeTriggered)
	{
		// shake to wake response.
	}
	// in mode
	if( 1 == inMode )
	{
		// pass movement data to mode

	}
	else{
		// run out put for current state
		// run proccess for current state.
		current.stateProcess();
	}


}

// set up functions for each state.
int Start(){
	timeStateStarted = HAL_GetTick();
	ConsoleSendLine(" State = starting");
	return 0;
}
int IdleAwake(){
	currentState = IDLE_AWAKE;
	timeStateStarted = HAL_GetTick();
	ConsoleSendLine(" State = IdleAwake");
	return 0;
}
int DeepSleep(){
	currentState = DEEP_SLEEP;
	timeStateStarted = HAL_GetTick();
	ConsoleSendLine(" State = DeepSleep");
	return 0;
}
int WaitingForSelection(){
	currentState = WAITING_FOR_SELECTION;
	timeStateStarted = HAL_GetTick();
	ConsoleSendLine(" State = WaitingForSelection");
	return 0;
}
int LoadMode(){
	currentState = WAITING_FOR_SELECTION;
	timeStateStarted = HAL_GetTick();
	ConsoleSendLine(" State = LoadMode");
	return 0;
}
int CliMode(){
	currentState = CLI_MODE;
	// clear the button press
	buttonPressed = 0;
	timeStateStarted = HAL_GetTick();
	ConsoleSendLine(" State = CliMode");

	return 0;
}
int StartPreviouseMode(){
	currentState = previouseState;

	timeStateStarted = HAL_GetTick();
	ConsoleSendLine(" State = StartPreviouseMode");
	return 0;
}
int InMode()
{
	currentState = IN_MODE;
	timeStateStarted = HAL_GetTick();
	ConsoleSendLine(" State = InMode");
	return 0;

}

// output for each function.
int IdelAwakeOutput(){}
int SleepOutput(){}
int WaitingForInputOutput(){}
int CliModeOutput(){}
int ModeLoading(){}

int StartProcess(){return 0;}
int IdleAwakeProcess(){return 0;}
int DeepSleepProcess(){return 0;}
int WaitingForSelectionProcess(){return 0;}
int LoadModeProcess(){return 0;}
int CliModeProcess(){return 0;}
int StartPreviouseModeProcess(){return 0;}
int InModeProcess(){return 0;}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	uint16_t userButtonPin = GPIO_PIN_0;
	GPIO_TypeDef *userButtonPort = GPIOA;

	// make sure we are  using the right pin for the user button.



	if(HAL_GPIO_ReadPin (userButtonPort, userButtonPin)==GPIO_PIN_SET){

		buttonPressed = 1;
	}

}
