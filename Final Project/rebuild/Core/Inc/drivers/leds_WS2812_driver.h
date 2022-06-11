/*
 * leds_WS2812_driver.h
 *
 *  Created on: Jun 8, 2022
 *      Author: jennie.stenhouse
 *      inspired from techcontroller
 *
 */

#ifndef INC_DRIVERS_LEDS_WS2812_DRIVER_H_
#define INC_DRIVERS_LEDS_WS2812_DRIVER_H_

#include <math.h>
#include "stdio.h"
#include "stm32f4xx_hal.h"

#define MAX_LED 6
#define USE_BRIGHTNESS 1

void InitLEDS( TIM_HandleTypeDef * htimX);
void SetLED (int LEDnum, int Red, int Green, int Blue);
void SetBrightness (int brightness);
void SendLEDS (void);


#endif /* INC_DRIVERS_LEDS_WS2812_DRIVER_H_ */
