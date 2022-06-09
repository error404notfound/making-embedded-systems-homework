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
#include "colour_change_mode.h"
#include "meditation_breathing_mode.h"

// utilities
#include "console.h"
#include "retarget.h"
#include "util.h"

// user
#include "user.h"


// private varaibles.
#define MAX_STATE_TIMEOUT 1000
int userID = 12345678;


typedef int (*stateFunc )(void);
typedef int (*modeFunc )(void);
typedef int (*ledOutput)(void);


typedef enum { START, IDLE_AWAKE, DEEP_SLEEP, WAITING_FOR_SELECTION, LOAD_MODE, IN_MODE,CLI_MODE } state_t;
typedef enum { IDEL_AWAKE_OUTPUT, SLEEP_OUTPUT, WAITING_FOR_INPUT, CLI_MODE_OUTPUT, LOADING_MODE_OUTPUT} output_t;
typedef enum { BREATHING_TRAINER, COLOUR_CHANGE} modeSelection_t;


typedef struct {
	/*Button press Response */ stateFunc onButtonPress;
	/*Gesture recon response */ stateFunc onGestureRecognize;
	/*Shake to wake */ stateFunc onShakeToWake;
	/*LED output */ ledOutput LedOutput;
	/*OnEnd */stateFunc onEnd;
	/* timeout */ int timeout;
	/* stateProcess */ stateFunc stateProcess;
}stateTableEntry_t;

typedef struct{

	modeFunc onStart;
	modeFunc modeProcess;
	modeFunc onEnd;
	int timeout;

}modeTableEntry_t;


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
/*START*/		{ NULL,				NULL, 				NULL,		NULL, 		&IdleAwake, 		800,&StartProcess },
/*IDEL AWAKE */	{ &CliMode,			NULL, 				NULL,		NULL, 		&WaitingForSelection, 800, &IdleAwakeProcess },
/*DEEP SLEEP */	{ &CliMode,			NULL, 				IdleAwake,	NULL, 		&DeepSleep, 800, &DeepSleepProcess },
/* WAITING */	{ &CliMode,			LoadMode, 			NULL,		NULL, 		&DeepSleep, 800 , &WaitingForSelectionProcess},
/* LOAD_MODE */	{ &CliMode,			NULL, 				NULL,		NULL, 		&InMode, 800 , &LoadModeProcess},
/* IN_MODE */	{ &CliMode,			NULL, 				NULL,		NULL, 		&IdleAwake, 800, &InModeProcess },
/* CLI_MODE */	{ &StartPreviouseMode,NULL, 			NULL,		NULL, 	&StartPreviouseMode, MAX_STATE_TIMEOUT, &CliModeProcess },

};
// these methods are defined in the modes headers.
static modeTableEntry_t modeTable[]={
	{ &colourChangeInit,&colourChangeProcess,&colourChangeOnEnd,COLOUR_CHANGE_MODE_TIMEOUT},
	{ &meditationBreathingInit,&meditationBreathingProcess,&meditationBreathingOnEnd,MEDIATION_BREATHING_MODE_TIMEOUT}
};
// Basic state managment
state_t currentState;

state_t previouseState;
//
modeTableEntry_t currentMode;

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
	stateTableEntry_t current = stateTabel[currentState];
	uint32_t timeout = current.timeout;

	//out put for training model
	MovementControllerProcess();



	// special case for timeout while in mode we pull the time out from the mode we are in.
	if(currentState == IN_MODE)
	{

	}



	//MovementControllerProcess();


	if ( HAL_GetTick() - timeStateStarted > timeout )
	{

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
	if( 1 == accelerometorInterrupt)
	{
		// The interrupt has been triggered.
		// get what interrupted it from movementController.
		gesture_t gesture =  getInterruptType( ACCELEROMETER );

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
	debugPrint(" State = starting");
	return 0;
}
int IdleAwake(){
	previouseState = currentState;
	currentState = IDLE_AWAKE;
	timeStateStarted = HAL_GetTick();
	debugPrint(" State = IdleAwake");
	return 0;
}
int DeepSleep(){
	previouseState = currentState;
	currentState = DEEP_SLEEP;
	timeStateStarted = HAL_GetTick();
	debugPrint(" State = DeepSleep");
	return 0;
}
int WaitingForSelection(){
	previouseState = currentState;
	currentState = WAITING_FOR_SELECTION;
	timeStateStarted = HAL_GetTick();
	debugPrint(" State = WaitingForSelection");
	return 0;
}
int LoadMode(){
	previouseState = currentState;
	currentState = WAITING_FOR_SELECTION;
	timeStateStarted = HAL_GetTick();
	debugPrint(" State = LoadMode");
	return 0;
}
int CliMode(){

	previouseState = currentState;
	currentState = CLI_MODE;
	// clear the button press
	buttonPressed = 0;
	// in climode we want the debug output off while we are waiting for input.
	pauseDebugLogging();

	timeStateStarted = HAL_GetTick();
	debugPrint(" State = CliMode");

	return 0;
}
int StartPreviouseMode(){
	currentState = previouseState;
	previouseState = CLI_MODE;
	// we also reset to our currentDebugMode
	resumeDebugLogging();

	timeStateStarted = HAL_GetTick();
	debugPrint(" State = StartPreviouseMode");
	return 0;
}
int InMode()
{
	currentState = IN_MODE;

	timeStateStarted = HAL_GetTick();
	debugPrint(" State = InMode");
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

int WaitingForSelectionProcess(){return 0;}

int LoadModeProcess(){return 0;}

int CliModeProcess(){
	ConsoleProcess();

	return 0;
}
int StartPreviouseModeProcess(){return 0;}

int InModeProcess(){
	currentMode.modeProcess();
	return 0;}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	uint16_t userButtonPin = GPIO_PIN_0;
	GPIO_TypeDef *userButtonPort = GPIOA;

	// make sure we are  using the right pin for the user button.



	if(HAL_GPIO_ReadPin (userButtonPort, userButtonPin)==GPIO_PIN_SET){

		buttonPressed = 1;
	}
	if( GPIO_Pin == GPIO_PIN_8)
	{
		accelerometorInterrupt = 1;
	}

}
