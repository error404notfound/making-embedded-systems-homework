// Console IO is a wrapper between the actual in and output and the console code
// In an embedded system, this might interface to a UART driver.

#include "consoleIo.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>

UART_HandleTypeDef *consoleHuart;
int readComplete = 0;
int charCount = 0;
// Buffer to hold command
uint8_t tempBuffer[10];
uint8_t byte;
void reset(){
	charCount = 0;
	readComplete =0;

}

eConsoleError ConsoleIoInit(UART_HandleTypeDef *huart)

{
	consoleHuart = huart;
	// So that we start the call back
	HAL_UART_Receive_IT(consoleHuart,&byte,1);
	return CONSOLE_SUCCESS;
}

// This is modified for the Wokwi RPi Pico simulator. It works fine
// but that's partially because the serial terminal sends all of the
// characters at a time without losing any of them. What if this function
// wasn't called fast enough?
eConsoleError ConsoleIoReceive(uint8_t *buffer, const uint32_t bufferLength, uint32_t *readLength)
{
	uint32_t i = 0;


	///HAL_UART_Receive_IT(consoleHuart,byte,1);
	if( readComplete==1)
	{
		// copy the command to the buffer
		// set the length
		//return console_success
		while(i<charCount+1){
			buffer[i] = tempBuffer[i];
			i++;
		}
		*readLength = charCount;
		printf("%s", tempBuffer);
		// reset counts
		reset();
		//return console_success

		return CONSOLE_SUCCESS;

	}


	*readLength = i;
	return CONSOLE_SUCCESS;
}

eConsoleError ConsoleIoSendString(const char *buffer)
{
	printf("%s", buffer);
	return CONSOLE_SUCCESS;
}
void HAL_UART_RxCpltCallback (UART_HandleTypeDef *huart)
{


	//uint8_t lastChar = *(huart->pRxBuffPtr);
	tempBuffer[charCount] = byte;

	charCount ++;

	if( byte == '\n'){
	readComplete = 1;

	}
	HAL_UART_Receive_IT(consoleHuart,&byte,1);

}
