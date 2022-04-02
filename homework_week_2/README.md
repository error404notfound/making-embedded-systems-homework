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

|     Item      |   Digikey     |   Mouser      |   Avent    |
| ------------- | ------------- | ------------- | ------------- | 
| Processor:STM32F429ZIT6 microcontrolle cost | $34.07000| 	$33.58  |14.305  | 
| Processor: Avaliablity | 0 | 0 | 0 |
| Processor: Leadtime | N/A  | n/A | N/A | 
| Full board: STM32F429I-DISC1 cost | $49.45000  | $48.74  | 44.252  | 
| Full board: Avaliablity | 10  | 29 | 0 |
| Full board: Leadtime | N/A  | N/A | constrained part leadtime unavalible  | 


## NUCLEO-F446RE
- The STM32 Nucleo-64 board provides an affordable and flexible way for users
to try out new concepts and build prototypes by choosing from the various
combinations of performance and power consumption features, provided by the
STM32 microcontroller. For the compatible boards, the external SMPS significantly
reduces power consumption in Run mode.

### What kind of processor is it?
STM32G070RB

### How much Flash and RAM does it have? Any other memory types?

high-speed embedded memories (128 Kbytes of Flash program memory with read protection, write protection, and 36 Kbytes of SRAM), DMA and an extensive range of system functions

### Does it have any special peripherals? (List 3-5 that you find interesting.)
- User LD2: the green LED 
   - the I/O is HIGH value, the LED is on
   - the I/O is LOW, the LED is off

- User Push button 
   -the user button is connected to the I/O PC13 (pin 2) of the STM32
microcontroller.

-CN5, CN6, CN8, and CN9 are female connectors compatible with ARDUINO® standard.
Most shields designed for ARDUINO® can fit the STM32 Nucleo boards.


### If it has an ADC, what are the features?

- [getting started with ADC digikey video](https://www.digikey.co.nz/en/maker/projects/getting-started-with-stm32-working-with-adc-and-dma/f5009db3a3ed4370acaf545a3370c30c)

### How much does the board cost vs what the processor costs? Is the processor in stock anywhere? 


|     Item      |   Digikey     |   Mouser      |  Avnet    | 
| ------------- | ------------- | ------------- | ------------- | 
| Processor:STM32G070RB microcontrolle cost | $5.06 | 	$4.97  |$1.60 | 
| Processor: Avaliablity | 0 | 0 | 0 |
| Processor: Leadtime | N/A  | n/A | N/A | 
| Full board: NUCLEO-F446RE cost | $24.64000  |$22.82  |$20.72  | 
| Full board: Avaliablity | 0  | 0  | 0 | 
| Full board: Leadtime |N/A | 53Weeks  | 0 | 

Most  sites say it is a constrained part and the lead time is unavalaible

### Additional links

### Application Notes
- Once the boot pins are selected, the application software can modify the memory
accessible in the code area (in this way the code can be executed through the ICode bus in
place of the System bus). This modification is performed by programming the Section 8.2.1:
SYSCFG memory remap register (SYSCFG_MEMRMP) in the SYSCFG controller.
The following memories can thus be remapped:
- 
