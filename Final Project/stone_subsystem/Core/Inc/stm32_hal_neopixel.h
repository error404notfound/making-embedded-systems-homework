/*
 * stm_hal_neopixel.h
 *
 *  Created on: 9 May 2022
 *      Author: jennie.stenhouse
 *      Port from VDF collective STM_HAL NEOPIXEL code from here:https://github.dev/hey-frnk/STM32_HAL_NeoPixel/
 */

#ifndef INC_STM32_HAL_NEOPIXEL_H_
#define INC_STM32_HAL_NEOPIXEL_H_


#include <stdint.h>

void led_set_RGB(uint8_t index, uint8_t r, uint8_t g, uint8_t b);
void led_set_RGBW(uint8_t index, uint8_t r, uint8_t g, uint8_t b, uint8_t w);
void led_set_all_RGB(uint8_t r, uint8_t g, uint8_t b);
void led_set_all_RGBW(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
void led_render();


#endif /* INC_STM32_HAL_NEOPIXEL_H_ */
