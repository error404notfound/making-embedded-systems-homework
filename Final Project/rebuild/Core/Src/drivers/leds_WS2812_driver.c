/*
 * leds_WS2812_driver.c
 *
 *  Created on: Jun 8, 2022
 *      Author: jennie.stenhouse
 */


#include "leds_WS2812_driver.h"
#include "stdio.h"
#define MAX_LED 6
#define USE_BRIGHTNESS 1

uint8_t LED_Data[MAX_LED][4];
uint8_t LED_Mod[MAX_LED][4];  // for brightness
volatile int datasentflag = 0;
