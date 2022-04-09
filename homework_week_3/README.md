# Homework 3

## Make Blinky

### Build enviroment 
STMCubeIDE on MacOS 
with the STM32F429I-DISC1

### Project description 
Pressing the user button starts and stops the blinking of the LED with a pause of 1 second between each flash. 
I have used the HAL calls and also register manipulation as an example. 


I use the interrupt HAL_GPIO_EXTI_Callback which I override in my main.c 
to be able to use the interrupt I had to set up the NVIC in the STM .ioc interface, I have it set to fire on the rising and falling edge. 
To debounce I check to see if the last fire is still with in my debouncing time offset, if so it counts as a SINGLE_PRESS.

I want to extend the button press intergration to detect a long press to switch between 
  - User LD3: The green LED 
  - User LD4: the red LED

#### What are the hardware registers that cause the LED to turn on and off?
The LEDS are accesed through the GPIO registers.

The GPIO registers can be accessed by byte (8 bits), half-words (16 bits) or words (32 bits).
GPIO port bit set/reset register ( BSRR ) you need to know which pin you are accesing and which port. 
so for the Green LED the port is the GPIO G and the pin is 13.

#### What are the registers you read to find the state of the user button?
To read the status of the user button I have to look at GIPOA and pin 0,
The IDR (GPIO port input data register) is read.
```
(GPIOA->IDR & GPIO_PIN_0)
```
#### Can you read the register directly and see the button change in the debugger or output the value of the memory address to the debugger.
Yes, by making sure the register view is open. I found it usefull to screen shot the before and after so it was easy to compare for changes. 
Working through [this tutorial]( https://shawnhymel.com/1873/how-to-use-printf-on-stm32/) you can use printf, which I haven't yet implemented.
### Resources
[HAL library](https://microcontrollerslab.com/led-blinking-tutorial-stm32f4-discovery-board-gpio-hal-library/)
