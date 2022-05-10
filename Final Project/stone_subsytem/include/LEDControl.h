
/*
 * ledController.h
 *
 *  Created on: 9 May 2022
 *      Author: jennie.stenhouse
 *      Controller for LED out put/
 */

#ifndef INC_LEDCONTROLLER_H_
#define INC_LEDCONTROLLER_H_


/**
  ******************************************************************************
  * @file    STONE_SUBSYSTEM/LEDControl.h 
  * @author  Jennie Stenhouse
  * @brief   Header for LEDControl.c module
  ******************************************************************************
  * @attention
  * This is the upper level controller for LED output, abstracted from the specific LED used 
  *
  ******************************************************************************
  */

#include <stdint.h>
#include "WS2812B.h"

struct LEDControlColour
{
   
    uint8_t r;
    uint8_t g;
    uint8_t b;
    /* data */
};

uint32_t hsl_to_rgb(uint8_t h, uint8_t s, uint8_t l);
void setRGB();
void setAll();
void renderLED();
struct LEDControlColour getLED(uint8_t index);

#endif INC_LEDCONTROLLER_H_