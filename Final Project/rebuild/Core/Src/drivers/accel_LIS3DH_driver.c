/*
 * accel_LIS3DH_driver.c
 *
 *  Created on: May 30, 2022
 *      Author: jennie.stenhouse
 */




/** @file lis3dh.c
 * @author david.siorpaes@st.com
 * LIS3DH accelerometer device driver. Uses SPI2 interface.
 *
 */



#include "accel_LIS3DH_driver.h"
#include "accel_LIS3DH_regs.h"
#include "stm32f4xx_hal.h"


const uint16_t LIS3DH_ADDR =  (0x18<<1);// if SDO/SA0 is 3V, its 0x19 and shifted
const uint16_t i2c_timeout = 200;
I2C_HandleTypeDef *I2Cx;
uint16_t  LastXAcel;
uint16_t  LastYAcel;
uint16_t  LastZAcel;

void errorHandler();

uint8_t LIS3DH_readReg(uint8_t lis3dhReg){


return 0;

}
void LIS3DH_writeReg(uint8_t lis3dhReg, uint8_t lis3dhValue)
{


}



void Lis3dhInit(I2C_HandleTypeDef *I2Cxhandle){
/*Once the device is powered up, it automatically downloads the calibration coefficients from
the embedded flash to the internal registers. When the boot procedure is completed, i.e.
after approximately 5 milliseconds, the device automatically enters power-down mode. To
turn on the device and gather acceleration data, select the HR bit in CTRL_REG4 and the
LPen bit in CTRL_REG1, enable at least one of the axes and select the preferred ODR.*/


	 HAL_StatusTypeDef ret;

	    uint8_t sendBuff[2];
	    uint8_t reciveBuff[12];
	    I2Cx = I2Cxhandle;

	    sendBuff[0] = WHO_AM_I|LIS3DH_READ;
	    ret = HAL_I2C_IsDeviceReady(I2Cx,LIS3DH_ADDR,1, HAL_MAX_DELAY);

	    ret = HAL_I2C_Master_Transmit(I2Cx, LIS3DH_ADDR, sendBuff, 1, HAL_MAX_DELAY);
	    if(ret != HAL_OK) {
	        //Handle Error
	    	errorHandler();

	    } else {

	        ret = HAL_I2C_Master_Receive(I2Cx, LIS3DH_ADDR, reciveBuff, 2, HAL_MAX_DELAY);
	        if(ret != HAL_OK) {

	        	//Handle error.
	        	errorHandler();

	        } else {

	        	// configure the sensor.
	        	// Setting our resolution 100HZ so that we can use interrupts
	        	// and that we will read all three axis
				sendBuff[0]  = LIS3DH_REG_CTRL1  |LIS3DH_READ;

				ret = HAL_I2C_Master_Transmit(I2Cx, LIS3DH_ADDR, sendBuff, 1, HAL_MAX_DELAY);
				ret = HAL_I2C_Master_Receive(I2Cx, LIS3DH_ADDR, reciveBuff, 2, HAL_MAX_DELAY);

				sendBuff[0] = LIS3DH_REG_CTRL1;
				sendBuff[1] = 0x57;
				ret = HAL_I2C_Master_Transmit(I2Cx, LIS3DH_ADDR, sendBuff, 2, HAL_MAX_DELAY);

				//Read to make sure the write worked.
				sendBuff[0]  = LIS3DH_REG_CTRL1  |LIS3DH_READ;

				ret = HAL_I2C_Master_Transmit(I2Cx, LIS3DH_ADDR, sendBuff, 1, HAL_MAX_DELAY);
				ret = HAL_I2C_Master_Receive(I2Cx, LIS3DH_ADDR, reciveBuff, 2, HAL_MAX_DELAY);


	        }

	    }







}
int Lis3dhGetAcc(){

	uint8_t sendBuff[2];
	uint8_t reciveBuff[12];

	HAL_StatusTypeDef ret;

	//1. Read STATUS_REG
	 sendBuff[0]  = LIS3DH_REG_STATUS  | LIS3DH_READ;
		ret = HAL_I2C_Master_Transmit(I2Cx, LIS3DH_ADDR, sendBuff, 1, HAL_MAX_DELAY);
		ret = HAL_I2C_Master_Receive(I2Cx, LIS3DH_ADDR, reciveBuff, 2, HAL_MAX_DELAY);

	// if there is new data on any axis proceed ZYXDA,ZDA,YDA = 1 in the status_reg.

	// else do nothing. this isn't ideal maybe we should hang out here till there is new data.
	sendBuff[0] = LIS3DH_REG_OUT_X_L  | LIS3DH_READ;
	ret = HAL_I2C_Master_Transmit(I2Cx, LIS3DH_ADDR, sendBuff, 1, HAL_MAX_DELAY);
	ret = HAL_I2C_Master_Receive(I2Cx, LIS3DH_ADDR, reciveBuff, 6 , HAL_MAX_DELAY);



	LastXAcel = *((int16_t*)reciveBuff);
	LastYAcel = *((int16_t*)(reciveBuff + 2));
	LastZAcel = *((int16_t*)(reciveBuff + 4));


	return 0;
}
void Lis3dhSetRange(int8_t range){}

void AccelGetData(int16_t *acelX, int16_t*acelY, int16_t*acelZ)
{
	*acelX = LastXAcel;
	*acelY = LastYAcel;
	*acelZ = LastZAcel;

}
void errorHandler()
{
	// handle the error
}


