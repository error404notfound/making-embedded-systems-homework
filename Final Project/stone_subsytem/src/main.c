
#include "main.h"

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
DMA_HandleTypeDef hdma_tim2_ch1; // Needed by leds
SPI_HandleTypeDef hspi5;// gyroscope
// accelermoter
UART_HandleTypeDef huart1;// command line

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_DMA_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_SPI5_Init(void);

int main(void)
{
    HAL_Init();
    while(1)
    {

    }
}
/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */

void Error_Handler(void)
{
  // do something usefull here.
}