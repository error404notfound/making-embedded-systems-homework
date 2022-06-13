// ConsoleCommands.c
// This is where you add commands:
//		1. Add a protoype
//			static eCommandResult_T ConsoleCommandVer(const char buffer[]);
//		2. Add the command to mConsoleCommandTable
//		    {"ver", &ConsoleCommandVer, HELP("Get the version string")},
//		3. Implement the function, using ConsoleReceiveParam<Type> to get the parameters from the buffer.

#include <string.h>
#include "consoleCommands.h"
#include "fileController.h"
#include "console.h"
#include "consoleIo.h"
#include "util.h"
#include "user.h"

#define IGNORE_UNUSED_VARIABLE(x)     if ( &x == &x ) {}

static eCommandResult_T ConsoleCommandComment(const char buffer[]);
static eCommandResult_T ConsoleCommandVer(const char buffer[]);
static eCommandResult_T ConsoleCommandHelp(const char buffer[]);
static eCommandResult_T ConsoleCommandParamExampleInt16(const char buffer[]);
static eCommandResult_T ConsoleCommandParamExampleHexUint16(const char buffer[]);

// these are the commands specific to the stone subsystem.
static eCommandResult_T ConsoleCommandDebugPrint(const char buffer[]);
static eCommandResult_T ConsoleCommandSetMode(const char buffer[]);
static eCommandResult_T ConsoleCommandSetState(const char buffer[]);
static eCommandResult_T ConsoleCommandSetStateTimeout(const char buffer[]);
static eCommandResult_T ConsoleCommandSetLogging(const char buffer[]);
static eCommandResult_T ConsoleCommandSetLogging(const char buffer[]);
static eCommandResult_T ConsoleCommandsetMainColour(const char buffer[]);

static const sConsoleCommandTable_T mConsoleCommandTable[] =
{
	{";", &ConsoleCommandComment, HELP("Comment! You do need a space after the semicolon. ")},
	{"help", &ConsoleCommandHelp, HELP("Lists the commands available")},
	{"ver", &ConsoleCommandVer, HELP("Get the version string")},
	{"int", &ConsoleCommandParamExampleInt16, HELP("How to get a signed int16 from params list: int -321")},
	{"u16h", &ConsoleCommandParamExampleHexUint16, HELP("How to get a hex u16 from the params list: u16h aB12")},

	{"debug", &ConsoleCommandDebugPrint, HELP("Toggle Debug output on or off")},
	{"setMode",&ConsoleCommandSetMode, HELP("Set the Mode see documentation for options")},
	{"setState",&ConsoleCommandSetState, HELP("Set the State see documentation for options")},
	{"setTimeout" ,&ConsoleCommandSetStateTimeout, HELP("Set the time out in milliseconds  state name : timeout")},
	{"setLogging" ,&ConsoleCommandSetLogging, HELP("Start or stop movement logging to usb")},
	{"saveSettings" ,&ConsoleCommandSetLogging, HELP("Save current user settings to usb")},
	{"setMainColour" ,&ConsoleCommandsetMainColour, HELP("Save current user settings to usb")},




	CONSOLE_COMMAND_TABLE_END // must be LAST
};

static eCommandResult_T ConsoleCommandComment(const char buffer[])
{
	// do nothing
	IGNORE_UNUSED_VARIABLE(buffer);
	return COMMAND_SUCCESS;
}

static eCommandResult_T ConsoleCommandHelp(const char buffer[])
{
	uint32_t i;
	uint32_t tableLength;
	eCommandResult_T result = COMMAND_SUCCESS;

    IGNORE_UNUSED_VARIABLE(buffer);

	tableLength = sizeof(mConsoleCommandTable) / sizeof(mConsoleCommandTable[0]);
	for ( i = 0u ; i < tableLength - 1u ; i++ )
	{
		ConsoleIoSendString(mConsoleCommandTable[i].name);
#if CONSOLE_COMMAND_MAX_HELP_LENGTH > 0
		ConsoleIoSendString(" : ");
		ConsoleIoSendString(mConsoleCommandTable[i].help);
#endif // CONSOLE_COMMAND_MAX_HELP_LENGTH > 0
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}

static eCommandResult_T ConsoleCommandParamExampleInt16(const char buffer[])
{
	int16_t parameterInt;
	eCommandResult_T result;
	result = ConsoleReceiveParamInt16(buffer, 1, &parameterInt);
	if ( COMMAND_SUCCESS == result )
	{
		ConsoleIoSendString("Parameter is ");
		ConsoleSendParamInt16(parameterInt);
		ConsoleIoSendString(" (0x");
		ConsoleSendParamHexUint16((uint16_t)parameterInt);
		ConsoleIoSendString(")");
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}
static eCommandResult_T ConsoleCommandParamExampleHexUint16(const char buffer[])
{
	uint16_t parameterUint16;
	eCommandResult_T result;
	result = ConsoleReceiveParamHexUint16(buffer, 1, &parameterUint16);
	if ( COMMAND_SUCCESS == result )
	{
		ConsoleIoSendString("Parameter is 0x");
		ConsoleSendParamHexUint16(parameterUint16);
		ConsoleIoSendString(STR_ENDLINE);
	}
	return result;
}

static eCommandResult_T ConsoleCommandVer(const char buffer[])
{
	eCommandResult_T result = COMMAND_SUCCESS;

    IGNORE_UNUSED_VARIABLE(buffer);

	ConsoleIoSendString(VERSION_STRING);
	ConsoleIoSendString(STR_ENDLINE);
	return result;
}


const sConsoleCommandTable_T* ConsoleCommandsGetTable(void)
{
	return (mConsoleCommandTable);
}

static eCommandResult_T ConsoleCommandDebugPrint(const char buffer[])
{
	eCommandResult_T result = COMMAND_SUCCESS;
	// this makes funciton about the expected input. values that have n as the second letter will also trigger debug on.
	// All though it's great input sanitisation it's okay for this.
	char command[5] ={0};
	result = ConsoleReceiveParamString(buffer, 1, command);
	char trigger = command[1];
	if ('n'==trigger)
	{
		// trigger is on
		SetUserDebugLogging(1);
	}
	else if('f'== trigger){

		// trigger is off.
		SetUserDebugLogging(0);
	}
	else
	{
		//the inputs bad output guide text.
		return COMMAND_ERROR;
	}

	return result;

}
static eCommandResult_T ConsoleCommandSetMode(const char buffer[]){

	eCommandResult_T result = COMMAND_SUCCESS;
	char command[5] ={0};
	// get the mode they want to set.
	result = ConsoleReceiveParamString(buffer, 1, command);
	return result;
}
static eCommandResult_T ConsoleCommandSetState(const char buffer[]){
	eCommandResult_T result = COMMAND_SUCCESS;
	char command[5] ={0};
	result = ConsoleReceiveParamString(buffer, 1, command);

	return result;
}
static eCommandResult_T ConsoleCommandSetStateTimeout(const char buffer[]){
	eCommandResult_T result = COMMAND_SUCCESS;
	return result;
}
static eCommandResult_T ConsoleCommandSetLogging(const char buffer[]){
	eCommandResult_T result = COMMAND_SUCCESS;
		// this makes funciton about the expected input. values that have n as the second letter will also trigger debug on.
		// All though it's great input sanitisation it's okay for this.
		char command[5] ={0};
		result = ConsoleReceiveParamString(buffer, 1, command);
		char trigger = command[1];
		//if(checkUSBConnected() == NO_ERROR){
			if ('n'==trigger)
			{
				// trigger is on
				SetMovementUSBLogging(1);
			}
			else if('f'== trigger){

				// trigger is off.
				SetMovementUSBLogging(0);
			}
		//}


		else
		{
			//the inputs bad output guide text.
			printf("No USB Connected\n");
			return COMMAND_ERROR;
		}

		return result;
}

static eCommandResult_T ConsoleCommandsetMainColour(const char buffer[]){
	eCommandResult_T result = COMMAND_SUCCESS;
	int r,g,b;
	SetUserMainColour(r,g,b);
	return result;
}
