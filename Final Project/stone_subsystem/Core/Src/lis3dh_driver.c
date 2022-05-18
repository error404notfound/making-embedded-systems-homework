/** @file lis3dh.c
 * @author david.siorpaes@st.com
 * LIS3DH accelerometer device driver. Uses SPI2 interface.
 *
 */



#include "lis3dh_driver.h"
#include "lis3dh_regs.h"
#include "stm32f4xx_hal.h"


#define LIS3DH_ADDR (0x19)// if SDO/SA0 is 3V, its 0x19
const uint16_t i2c_timeout = 100;

static uint8_t accelSpiTxBuf[2];
static uint8_t accelSpiRxBuf[7];


SPI_HandleTypeDef * LIS3DH_hspi;

uint8_t LIS3DH_readReg(uint8_t lis3dhReg){




		uint8_t sendAddr;
		uint8_t readData;

		sendAddr = LIS3DH_READ | lis3dhReg;

	    csOn();

	    HAL_SPI_Transmit(LIS3DH_hspi, &sendAddr, 1, HAL_MAX_DELAY);
	    HAL_SPI_Receive( LIS3DH_hspi, &readData, 1, HAL_MAX_DELAY);

		csOff();

		return (readData);

}
void LIS3DH_writeReg(uint8_t lis3dhReg, uint8_t lis3dhValue)
{
	uint8_t sendAddr;
	uint8_t sendData;

	sendAddr = LIS3DH_WRITE | lis3dhReg;
	sendData = lis3dhValue;

   csOn();

    HAL_SPI_Transmit(LIS3DH_hspi, &sendAddr, 1, HAL_MAX_DELAY);
    HAL_SPI_Transmit(LIS3DH_hspi, &sendData, 1, HAL_MAX_DELAY);

	csOff();

	return;

}



void Lis3dhInit(I2C_HandleTypeDef *I2Cx){
/*Once the device is powered up, it automatically downloads the calibration coefficients from
the embedded flash to the internal registers. When the boot procedure is completed, i.e.
after approximately 5 milliseconds, the device automatically enters power-down mode. To
turn on the device and gather acceleration data, select the HR bit in CTRL_REG4 and the
LPen bit in CTRL_REG1, enable at least one of the axes and select the preferred ODR.*/



	/*(LIS3DH_hspi = hspi;
	HAL_StatusTypeDef hal_res;

//writs to Ctrl_reg1 to wake it up.
	LIS3DH_writeReg(0x20,0x7);
	uint8_t ctrl_reg =LIS3DH_readReg(0x20);
	uint8_t who_am_i = LIS3DH_readReg(0x0f);
	*/
	uint8_t check;
	uint8_t Data;
	HAL_I2C_Mem_Read(I2Cx, LIS3DH_ADDR, WHO_AM_I, 1, &check, 1, i2c_timeout);






}
int Lis3dhGetAcc(int16_t* x, int16_t* y, int16_t* z){


	/*1. Read STATUS_REG
	2. If STATUS_REG(3) = 0 then go to 1
	3. If STATUS_REG(7) = 1 then some data have been overwritten
	4. Read OUTX_L
	5. Read OUTX_H
	6. Read OUTY_L
	7. Read OUTY_H
	8. Read OUTZ_L
	9. Read OUTZ_H
	10. Data processing
	11. Go to 1*/
	//HAL_SPI_Transmit (SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout)
	return 0;
}
void Lis3dhSetRange(int8_t range){}


/* Private APIs */
/** @brief Set SPI Chip select OFF
 * @retval none
 */
void csOff(void)
{
	HAL_GPIO_WritePin(CSport, CSpin , GPIO_PIN_SET);
}


/** @brief Set SPI Chip select ON this accelerometor expects low on cs transmitting
 * @retval none
 */
void csOn(void)
{
	HAL_GPIO_WritePin(CSport, CSpin , GPIO_PIN_RESET);
}

