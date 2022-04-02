# Exercise 2
## STM32F429I-DISC1
### What kind of processor is it?

### How much Flash and RAM does it have? Any other memory types?


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

### Aditional links

- [blog about stm32f4 discovery kits ](https://stm32f4-discovery.net/category/stm32f429-discovery/)

### How much does the board cost vs what the processor costs? Is the processor in stock anywhere? 

|     Item      |   Digikey     |   Mouser      |   Octopart    | Aliexpress    |   Amazon      |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| Processor:STM32F446RE cost | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| Processor: Avaliablity | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| Processor: Leadtime | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| Full board: NUCLEO-F446RE cost | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| Full board: Avaliablity | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| Full board: Leadtime | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
## NUCLEO-F446RE
### What kind of processor is it?
STM32F446RE
Core: Arm® 32-bit Cortex®-M4 CPU with FPU, Adaptive real-time accelerator (ART Accelerator) allowing 0-wait state execution from Flash memory, frequency up to 180 MHz, MPU, 225 DMIPS/1.25 DMIPS/MHz (Dhrystone 2.1), and DSP instructions

### How much Flash and RAM does it have? Any other memory types?
- 512 Kbytes of Flash memory
- 128 Kbytes of SRAM
- Flexible external memory controller with up to 16-bit data bus: SRAM, PSRAM, SDRAM/LPSDR SDRAM, NOR/NAND Flash memories

### Does it have any special peripherals? (List 3-5 that you find interesting.)

### If it has an ADC, what are the features?
### How much does the board cost vs what the processor costs? Is the processor in stock anywhere? 


|     Item      |   Digikey     |   Mouser      |   Octopart    | Aliexpress    |   Amazon      |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| Processor:STM32F446RE cost | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| Processor: Avaliablity | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| Processor: Leadtime | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| Full board: NUCLEO-F446RE cost | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| Full board: Avaliablity | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
| Full board: Leadtime | Content Cell  | Content Cell  | Content Cell  | Content Cell  | Content Cell  |
