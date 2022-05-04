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
- implement cli
  - pass test data to the cli
  - mimic commands that would be replicated over ble
  - log activity/session data
  - set activity  state table
  - test perpiherlas
  - save  input data to mass storage
  - Load Led patterns 
  - set user prefrences ( like choosing the colour of the light in breathing mode )
  - 
## Hardware Description
## Software Description
Describe the code in general
○ Describe the parts you wrote in some detail (maybe 3-5 sentences per module)
○ Describe code you re-used from other sources, including the licenses for those
## Build Instructions
○ How to build the system (including the toolchain(s))
■ Hardware
■ Software
○ How you debugged and tested the system
○ How you powered it (and how you might in the future)

## MVP

###Using only only on boad peripherals instead of additional ones. 
  - LED screen for visual out put 
  - Gyroscope only 
  - USB for storage/data logging 
 
 ###Implement simple gestures for the mode selection only using gyroscope:
   - x full twist for Breathing  mode
   - y full twist for Colour response mode
  
  ###Mode simplification 
  - **Breathing Mode**
   -   use timer to change colour of Led with arrow to indicate inwards breath and outwards breaths.
  
  - **Color Mode**
    - X rotation changes R value
    - Y rotation changes G value
    - Z rotation changes B value
  
  - Button press to enter CLI mode
  - State Machine for General Mode management and for the Modes them selves.
  - USB mass storage 


## Pitfalls / Blocking 
### Software:
Working with the IDE

### Hardware:
Getting additional parts ( external power supply for the neopixels. ) 
ABlity to actually wire the system with my limited hardware experince ( quality of soldering ) 

## Tasks
### Getting Data out of the sensors
  - Gyroscope 
  - Accelerometor ( needs to be hooked up as an external sensor ) 

### Getting data out to the Neopixels 
Timer configured in PWM output mode, that gets it data from a DMA buffer
  -https://www.thevfdcollective.com/blog/stm32-and-sk6812-rgbw-led
  
### Command line implemtation 
### Button interuppt 

## Extension 
○ What would be needed to get this project ready for production?
○ How would you extend this project to do something more? Are there other
features you’d like? How would you go about adding them?
- firmware update
- Low power 
- Implementing the Edge Impulse gesture recognition

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
- 3 perpherials: _PWM LEDS, accelerometor on I2C, gyroscope on SPI , USB_
- Button that causes an interrupt: _User button switches to CLI mode_
- Cortex-M processor: _STM32F429ZIT6 on the STM32f429i-disc_
- Implement Serail output: _CLI_
- Implement State Machine: _Implicit in overall implementation and in the different modes_
- Algorithmic piece that makes the system interesting: 
  -  _Resperation detection and  interpretation for the breathing training_ 
  -  _The interpretation of movement data into hue and brightness change_ 


