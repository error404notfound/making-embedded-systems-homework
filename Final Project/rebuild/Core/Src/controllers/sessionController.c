/*
 * sessionController.c
 *
 *  Created on: May 31, 2022
 *      Author: jennie.stenhouse
 *      Session controller is the main state machine for the system.
 *      It handles the incoming interrupts and also runs the movementControllerProcess
 *      It passing output to the output controller.
 *      Modes have there own state machines including timeouts which are detalied in there indvidual .c
 *      I have tried to keep this as generic as possible so that new modes ( or states ) can be added with out having to change the way
 *      the system runs. It also allows for the addition of other sensors and outputs  - ie if we wanted to have haptics added or captive touch
 *      or to swap out sensors this section of the system could remain unchanged.
 *
 */

#include <stdio.h>

// controllers.
#include <sessionController.h>
#include "movementInputController.h"
#include "visualOutputController.h"
#include "fileController.h"
// modes
#include "mode_template.h"
#include "colour_change_mode.h"
#include "meditation_breathing_mode.h"

// utilities
#include "console.h"
#include "retarget.h"
#include "util.h"

// user
#include "user.h"


// private varaibles.
#define MAX_STATE_TIMEOUT 120000



typedef int (*stateFunc )(void);
typedef int (*ledOutput)(void);


typedef enum { START, IDLE_AWAKE, DEEP_SLEEP, WAITING_FOR_SELECTION, LOAD_MODE, IN_MODE,CLI_MODE } state_t;
typedef enum { IDEL_AWAKE_OUTPUT, SLEEP_OUTPUT, WAITING_FOR_INPUT, CLI_MODE_OUTPUT, LOADING_MODE_OUTPUT} output_t;



typedef struct {
	/*Button press Response */ stateFunc onButtonPress;
	/*Gesture recon response */ stateFunc onGestureRecognize;
	/*Shake to wake */ stateFunc onShakeToWake;
	/*LED output */ ledOutput LedOutput;
	/*OnEnd */stateFunc onEnd;
	/* timeout */ int timeout;
	/* stateProcess */ stateFunc stateProcess;
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



// state table
static stateTableEntry_t  stateTabel[]={
				// Button Press, Gesture Recognized, Shake to wake, Led output, Timeout/completion , timeout length in milliseconds stateprocces
/*START*/		{ &CliMode,				NULL, 				NULL,		NULL, 		&IdleAwake, 		1000,&StartProcess },
/*IDEL AWAKE */	{ &CliMode,			NULL, 				NULL,		NULL, 		&WaitingForSelection, MAX_STATE_TIMEOUT, &IdleAwakeProcess },
/*DEEP SLEEP */	{ &CliMode,			NULL, 				IdleAwake,	NULL, 		&DeepSleep, MAX_STATE_TIMEOUT, &DeepSleepProcess },
/* WAITING */	{ &CliMode,			LoadMode, 			NULL,		NULL, 		&DeepSleep, MAX_STATE_TIMEOUT , &WaitingForSelectionProcess},
/* LOAD_MODE */	{ &CliMode,			NULL, 				NULL,		NULL, 		&InMode, MAX_STATE_TIMEOUT , &LoadModeProcess},
/* IN_MODE */	{ &CliMode,			NULL, 				NULL,		NULL, 		&IdleAwake, MAX_STATE_TIMEOUT, &InModeProcess },
/* CLI_MODE */	{ &StartPreviouseMode,NULL, 			NULL,		NULL, 	&StartPreviouseMode, MAX_STATE_TIMEOUT, &CliModeProcess },

};
// these methods are defined in the modes headers. for all the modes the timeout is adjusted if there is still activity.
static modeTableEntry_t modeTable[]={
	{ &colourChangeInit,&colourChangeProcess,&colourChangeOnEnd,colourChangeGetTimeOut},
	{ &meditationBreathingInit,&meditationBreathingProcess,&meditationBreathingOnEnd,meditationGetTimeOut}
};
// Basic state managment
state_t currentState;
stateTableEntry_t current;
state_t previouseState = START;
//
modeSelection_t currentMode;
modeTableEntry_t selectedMode;
uint32_t timeStateStarted;


uint8_t buttonPressed =0;
uint8_t shakeToWakeTriggered;
uint8_t gestureRecognized;
uint8_t loggingToUsbEnabled;

uint8_t cliMode =0;
int currentDebugMode=0;
int accelerometorInterrupt = 0;

TIM_HandleTypeDef * timerHandler;




void SessionControllerInit(I2C_HandleTypeDef *I2Cxhandle,SPI_HandleTypeDef *SPIxHandle,UART_HandleTypeDef * HUARTxHandler)
{


	MovementControllerInit(I2Cxhandle,SPIxHandle);
	ConsoleInit(HUARTxHandler);
	FileControllerInit();
	currentState = START;
	timeStateStarted = HAL_GetTick();
	ConsoleProcess();




}
void SessionControllerProcess()
{



// check to see if current state has reached it time out.
	current = stateTabel[currentState];
	uint32_t timeout = current.timeout;
	movementData_t accel;
	movementData_t gyro;

	//
	MovementControllerProcess();
	// if we are logging the data.
	if(1 == GetMovementUSBLogging())
	{
		FileControllerProcess();



	}


	// special case for timeout while in mode we pull the time out from the mode we are in.
	// users stay in mode until they explicitly exit or  meet another criteria ( like no movement ) defined by there mode.
	if(currentState == IN_MODE)
	{
		timeStateStarted = HAL_GetTick();// just for testing.
	}






	if ( HAL_GetTick() - timeStateStarted > timeout )
	{

		current.onEnd();

	}
	if ( 1 == buttonPressed )
	{

		current.onButtonPress();
	}

	if( 1 == accelerometorInterrupt)
	{
		// The interrupt has been triggered.
		// get what interrupted it from movementController.
		gesture_t gesture =  GetInterruptType( ACCELEROMETER );

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
	DebugPrint(" State = starting");
	return 0;
}
int IdleAwake(){
	previouseState = currentState;
	currentState = IDLE_AWAKE;
	timeStateStarted = HAL_GetTick();
	DebugPrint(" State = IdleAwake");
	return 0;
}
int DeepSleep(){
	previouseState = currentState;
	currentState = DEEP_SLEEP;
	timeStateStarted = HAL_GetTick();
	DebugPrint(" State = DeepSleep");
	return 0;
}
int WaitingForSelection(){
	previouseState = currentState;
	currentState = WAITING_FOR_SELECTION;
	timeStateStarted = HAL_GetTick();
	DebugPrint(" State = WaitingForSelection");
	return 0;
}
int LoadMode(){
	previouseState = currentState;
	currentState = WAITING_FOR_SELECTION;
	timeStateStarted = HAL_GetTick();
	DebugPrint(" State = LoadMode");
	return 0;
}
int CliMode(){

	previouseState = currentState;
	currentState = CLI_MODE;
	// clear the button press
	buttonPressed = 0;
	// in climode we want the debug output off while we are waiting for input.
	PauseDebugLogging();
	printf("CLI MODE - waiting command\n");
	timeStateStarted = HAL_GetTick();
	DebugPrint(" State = CliMode");

	return 0;
}
int StartPreviouseMode(){
	currentState = previouseState;
	previouseState = CLI_MODE;
	// we also reset to our currentDebugMode
	ResumeDebugLogging();

	timeStateStarted = HAL_GetTick();
	DebugPrint(" State = StartPreviouseMode");
	return 0;
}
int InMode()
{
	currentState = IN_MODE;
	selectedMode = modeTable[currentMode];
	timeStateStarted = HAL_GetTick();
	DebugPrint(" State = InMode");
	return 0;

}

// output for each function.
int IdelAwakeOutput(){return 0;}
int SleepOutput(){return 0;}
int WaitingForInputOutput(){return 0;}
int CliModeOutput(){return 0;}
int ModeLoading(){return 0;}

int StartProcess(){return 0;}

int IdleAwakeProcess(){return 0;}

int DeepSleepProcess(){return 0;}

int WaitingForSelectionProcess(){
	// check to see if we had any control gestures.
		gesture_t lastGesture  = GetLastGesture();

		if( NO_GESTURE != lastGesture ){
			// gesture recognized response.

			if(TWIST_Y == lastGesture )
			{ currentMode = COLOUR_CHANGE; }
			if(SUDDEN_UP == lastGesture)
			{currentMode = BREATHING_TRAINER;}
			stateTableEntry_t current = stateTabel[currentState];
			current.onGestureRecognize();

			// get the gesture tag from MovementController.

		}



	return 0;}

int LoadModeProcess(){return 0;}

int CliModeProcess(){
	ConsoleProcess();

	return 0;
}
int StartPreviouseModeProcess(){return 0;}

int InModeProcess(){
	selectedMode.modeProcess();
	return 0;}



void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	uint16_t userButtonPin = GPIO_PIN_0;
	uint16_t accelInterruptPin = GPIO_PIN_8;

	// make sure we are  using the right pin for the user button.



	if( GPIO_Pin == userButtonPin){

		buttonPressed = 1;
	}
	if( GPIO_Pin == accelInterruptPin)
	{
		GetInterruptType( ACCELEROMETER );
	}

}
