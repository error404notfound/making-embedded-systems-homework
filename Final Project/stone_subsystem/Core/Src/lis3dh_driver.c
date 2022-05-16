/** @file lis3dh.c
 * @author david.siorpaes@st.com
 * LIS3DH accelerometer device driver. Uses SPI2 interface.
 *
 */



#include "lis3dh_driver.h"
#include "lis3dh_regs.h"


static uint8_t spiTxBuf[2];
static uint8_t spiRxBuf[7];
uint8_t LIS3DH_readReg(uint8_t lis3dhReg);
void LIS3DH_writeReg(uint8_t lis3dhReg, uint8_t lis3dhValue);

SPI_HandleTypeDef * LIS3DH_hspi;

uint8_t LIS3DH_readReg(uint8_t lis3dhReg)
{
	uint8_t sendAddr;
	uint8_t readData;

	sendAddr = LIS3DH_READ | lis3dhReg;

   // LIS3DH_SPI_ENABLE;

    HAL_SPI_Transmit(LIS3DH_hspi, &sendAddr, 1, HAL_MAX_DELAY);
    HAL_SPI_Receive(LIS3DH_hspi, &readData, 1, HAL_MAX_DELAY);

	//LIS3DH_SPI_DISABLE;

	return (readData);

}
void LIS3DH_writeReg(uint8_t lis3dhReg, uint8_t lis3dhValue)
{
	uint8_t sendAddr;
	uint8_t sendData;

	sendAddr = LIS3DH_WRITE | lis3dhReg;
	sendData = lis3dhValue;

    LIS3DH_SPI_ENABLE;

    HAL_SPI_Transmit(&LIS3DH_hspi, &sendAddr, 1, HAL_MAX_DELAY);
    HAL_SPI_Transmit(&LIS3DH_hspi, &sendData, 1, HAL_MAX_DELAY);

	LIS3DH_SPI_DISABLE;

	return;

}



void Lis3dhHInit(SPI_HandleTypeDef *hspi){
/*Once the device is powered up, it automatically downloads the calibration coefficients from
the embedded flash to the internal registers. When the boot procedure is completed, i.e.
after approximately 5 milliseconds, the device automatically enters power-down mode. To
turn on the device and gather acceleration data, select the HR bit in CTRL_REG4 and the
LPen bit in CTRL_REG1, enable at least one of the axes and select the preferred ODR.*/


uint8_t cmd = 0;
cmd |= SPI_READ;
cmd |= (SPI_READ & WHO_AM_I);
HAL_StatusTypeDef status = HAL_ERROR;
LIS3DH_hspi = hspi;


		status = LIS3DH_readReg(WHO_AM_I);





}
int Lis3dhGetAcc(int16_t* x, int16_t* y, int16_t* z){

	//HAL_SPI_Transmit (SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout)
	return 0;
}
void Lis3dhSetRange(int8_t range){}


/* Private APIs */
void csOn(void){}
void csOff(void){}
int spiConfig(void){return 0;}
int spiRead(uint8_t addr, uint8_t* buffer, int len){
	if(len <= 0)
			return -1;

		/* It's a read operation */
		addr |= SPI_READ;

		/* It's a multiple read operation */
		if(len > 1)
			addr |= SPI_MULTI_ACCESS;


		return 0;
}
int spiWrite(uint8_t addr, uint8_t* buffer, int len){

	if(len <= 0)
			return -1;
	return 0;}
