/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
// the four user LED register locations

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
struct LEDS {
		GPIO_TypeDef * port;
	    uint16_t pin;
	  };

typedef enum{
	SINGLE_PRESS,
	DOUBLE_PRESS,
	LONG_PRESS,
	NO_PRESS
} ButtonPressType;

int ledArrayIndex = 0;// which LED we are lighting
int ledGoing = 0;// if the LEDS are going
ButtonPressType buttonPress= NO_PRESS;
uint16_t userButtonPin = GPIO_PIN_0;
GPIO_TypeDef *userButtonPort = GPIOA;
static uint32_t doubleClickMargin = 2000;
static uint32_t debounceTime = 50;
static uint32_t lastButtonPress=0;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
ButtonPressType getButtonStatus();
void buttonDownEvent();
void buttonUpEvent();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

	struct LEDS ledsInfo[] ={{GPIOG, GPIO_PIN_13} //User LD3: The green LED
	,{GPIOG,GPIO_PIN_14}// User LD4: The red LED
	} ;



  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  	ledArrayIndex = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {



	// ledArrayIndex is set in the button press call back and switches between
	if(ledGoing)
	{
		// the users red led and the green led.
		GPIO_TypeDef * currentPort = ledsInfo[ledArrayIndex].port;
		uint16_t currentPin = ledsInfo[ledArrayIndex].pin;

		// Use the HAL calls to set the Pin
		HAL_GPIO_WritePin(currentPort,currentPin, GPIO_PIN_SET);
		HAL_Delay(1000);
		// rest to turn it off.
		HAL_GPIO_WritePin(currentPort,currentPin, GPIO_PIN_RESET);
		HAL_Delay(1000);

		// Direct register call - set current Pin high
		currentPort->BSRR = currentPin;
		// clear the bit to turn it off.
		HAL_Delay(1000);
		currentPort->BSRR = (uint32_t)currentPin << 16U;
		HAL_Delay(1000);
	}

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 50;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV8;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void buttonDownEvent()
{
	// set last button down event
	uint32_t thisButtonEvent = HAL_GetTick() ;
	// if the last button down event is within our double click time frame run double click
	uint32_t diff = thisButtonEvent - lastButtonPress;

	if( (thisButtonEvent - lastButtonPress) <= doubleClickMargin)
	{
		ledArrayIndex = 1-ledArrayIndex;
	}
	else{
		// else its single click
		ledGoing = 1 - ledGoing;
	}


	lastButtonPress = thisButtonEvent;

}
void buttonUpEvent()
{}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{


	/*if (GPIO_Pin == userButtonPin){// make we are only looking at the user button.
		if (HAL_GPIO_ReadPin (userButtonPort, userButtonPin)==GPIO_PIN_SET)
		{
			buttonPressTime = HAL_GetTick();
		}

	}*/
	static int timestamp_pressed = -1; // -1 means not pressed

	if(HAL_GPIO_ReadPin (userButtonPort, userButtonPin)==GPIO_PIN_SET){
		if (timestamp_pressed == -1) {
			// user just pressed the button
			timestamp_pressed = HAL_GetTick();  // milliseconds since startup
		}
		else if (HAL_GetTick() - timestamp_pressed > debounceTime) {

				buttonDownEvent();

			}
	}
	else{
		if (timestamp_pressed == -1) {
				// user just pressed the button
				timestamp_pressed = HAL_GetTick();  // milliseconds since startup
			}
			else if (HAL_GetTick() - timestamp_pressed > debounceTime) {

					buttonUpEvent();

				}

	}

}




/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
