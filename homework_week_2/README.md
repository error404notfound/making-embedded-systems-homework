# Exercise 2
## STM32F429I-DISC1
### What kind of processor is it?

STM32F429ZIT6 microcontroller

- The STM32F427xx and STM32F429xx devices are based on the high-performance Arm® Cortex®-M4 32-bit RISC core operating at a frequency of up to 180 MHz. The Cortex-M4 core features a Floating point unit (FPU) single precision which supports all Arm® single-precision data-processing instructions and data types. It also implements a full set of DSP instructions and a memory protection unit (MPU) which enhances application security. The STM32F427xx and STM32F429xx devices incorporate high-speed embedded memories (Flash memory up to 2 Mbyte, up to 256 Kbytes of SRAM), up to 4 Kbytes of backup SRAM, and an extensive range of enhanced I/Os and peripherals connected to two APB buses, two AHB buses and a 32-bit multi-AHB bus matrix.
- 
### How much Flash and RAM does it have? Any other memory types?

Flash memory up to 2 Mbyte, up to 256 Kbytes of SRAM), up to 4 Kbytes of backup SRAM

### Does it have any special peripherals? (List 3-5 that you find interesting.)

- I3G4250D, ST MEMS motion sensor 3-axis digital output gyroscope
   - An angular rate gyroscope is a device that produces a positive-going digital output for
counter-clockwise rotation around the axis considered. Sensitivity describes the gain of the
sensor and can be determined by applying a defined angular velocity to it. This value
changes very little over temperature and time 

The I3G4250D has a full-scale of  245/ 500/ 2000 dps and is capable of measuring rates with a user-selectable bandwidth.
The STM32F429ZIT6 controls this motion sensor through the SPI interface.

     - [data sheet](https://www.st.com/resource/en/datasheet/i3g4250d.pdf)
     
- 2.4" QVGA TFT LCD
   - resolution of 320×240. ( Quater of VGA ) 
   - TGFX ( touch on the LCD screen ) 
       - [GUI with touch GFX]( https://www.youtube.com/watch?v=Zy0bTHvviiE)
       - [touch screen tutorial](http://www.st.com/web/en/catalog/tools/PF259429)
       - SDA

- USB OTG
   - [Sample code of using a USB drive as mass storage](https://community.st.com/0D50X00009XkZmmSAF)

- User push-button
   - connected to the I/O PA0


### If it has an ADC, what are the features?
The microcontroller does: 3x12-bit ADC with 24 channels
[ you tube explaining how to access ADC ]( https://www.youtube.com/watch?v=TH4Iruu-DBQ)

### Aditional links

- [blog about stm32f4 discovery kits ](https://stm32f4-discovery.net/category/stm32f429-discovery/)

### Application Notes
   - How to use a USB to update the firmware.

### How much does the board cost vs what the processor costs? Is the processor in stock anywhere? 

|     Item      |   Digikey     |   Mouser      |   Octopart    |
| ------------- | ------------- | ------------- | ------------- | 
| Processor:STM32F429ZIT6 cost | Content Cell  | Content Cell  | Content Cell  | 
| Processor: Avaliablity | Content Cell  | Content Cell  | Content Cell  | 
| Processor: Leadtime | Content Cell  | Content Cell  | Content Cell  | 
| Full board: STM32F429I-DISC1 cost | Content Cell  | Content Cell  | Content Cell  | 
| Full board: Avaliablity | Content Cell  | Content Cell  | Content Cell  |
| Full board: Leadtime | Content Cell  | Content Cell  | Content Cell  | 


## NUCLEO-F446RE

### What kind of processor is it?



### How much Flash and RAM does it have? Any other memory types?


### Does it have any special peripherals? (List 3-5 that you find interesting.)



### If it has an ADC, what are the features?



### How much does the board cost vs what the processor costs? Is the processor in stock anywhere? 


|     Item      |   Digikey     |   Mouser      |   Octopart    | 
| ------------- | ------------- | ------------- | ------------- | 
| Processor:STM32 microcontrolle cost | Content Cell  | Content Cell  | Content Cell  | 
| Processor: Avaliablity | Content Cell  | Content Cell  | Content Cell  |
| Processor: Leadtime | Content Cell  | Content Cell  | Content Cell  | 
| Full board: NUCLEO-F446RE cost | Content Cell  | Content Cell  | Content Cell  | 
| Full board: Avaliablity | Content Cell  | Content Cell  | Content Cell  | 
| Full board: Leadtime | Content Cell  | Content Cell  | Content Cell  | 

### Additional links

### Application Notes
- 
- 
