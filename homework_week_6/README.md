### Draft Final Project Report


## Introduction
Implementing a subsytem of the bigger sensory stone project. 

## Application description
### Features
- Breathing pattern trainer using LEDS for visual feedback.
- Movement of stone represented with colour and brightness patters and changes
- Sleep timer
- Save user settings to non volitaile memeory
- Data logging of movement  to USB mass storage ( as proof of concept )
- implement cli **( Serial interface ) **
  - pass test data to the cli
  - mimic commands that would be replicated over ble
  - log activity/session data
  - set activity  state table
  - test perpiherlas
  - save  input data to mass storage
  - Load Led patterns 
  - set user prefrences ( like choosing the colour of the light in breathing mode )
## Hardware Description
## Software Description
## Build Instructions
## MVP

## Pitfalls / Blocking 
**Software:**
Working with the IDE
**Hardware:**
Getting additional parts ( external power supply for the neopixels. ) 
## Tasks
### Getting Data out of the sensors
  - Gyroscope 
  - Accelerometor ( needs to be hooked up as an external sensor ) 

### Getting data out to the Neopixels 
Timer configured in PWM output mode, that gets it data from a DMA buffer
  -https://www.thevfdcollective.com/blog/stm32-and-sk6812-rgbw-led
  
### Command line implemtation 
### Button interuppt 


## Code used from 
https://github.dev/adem-alnajjar/Gyroscope-L3GD20-_STM32/

## Licenses
### ST - HAL

HALs are distributed under the 3-clause BSD license, and that means you are free to do pretty much anything with them as long as you propagate the copyright and don't use ST and contributors' names for commercial endorsement or promotion.
https://opensource.org/licenses/BSD-3-Clause

### ARM - csmis
As advertised on arm's website, all CMSIS SW components are under the business-friendly Apache 2.0 license. It is a bit less permissive than BSD, and you should for example pay attention to the clauses regarding redistribution as they are a bit more developed (for example item #4).

http://arm-software.github.io/CMSIS_5/General/html/index.html#License

### Port of VFD collective code fot neopizels on stm32
https://www.thevfdcollective.com/ They have a Open Source statment but no refrence to an actual licence. 

## Project requirement checklist
- 3 perpherials: _PWM LEDS, accelerometor, gyroscope, USB_
- Button that causes an interrupt: _User button switches to CLI mode_
- Cortex-M processor: _STM32F429ZIT6 on the STM32f429i-disc_
- Implement Serail output: _CLI_
- Implement State Machine: _Implicit in overall implementation and in the different modes_
- Algorithmic piece that makes the system interesting: 
   - _Resperation detection and  interpretation for the breathing training _
   - _The interpretation of movement data into hue and brightness changes_



