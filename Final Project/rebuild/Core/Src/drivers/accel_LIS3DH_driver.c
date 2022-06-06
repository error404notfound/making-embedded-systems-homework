/*
 * accel_LIS3DH_driver.c
 *	inspireation from adafruit lis3dh library and https://github.com/STMicroelectronics/lis3dh/blob/master/lis3dh_reg.c
 *  Created on: May 30, 2022
 *      Author: jennie.stenhouse
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
HAL_StatusTypeDef Lis3dhInteruptSetup();

uint8_t LIS3DH_readReg(uint8_t lis3dhReg){


return 0;

}
void LIS3DH_writeReg(uint8_t lis3dhReg, uint8_t lis3dhValue)
{


}



HAL_StatusTypeDef Lis3dhInit(I2C_HandleTypeDef *I2Cxhandle){
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
				sendBuff[1] = LIS3DH_ON_100HZ;
				ret = HAL_I2C_Master_Transmit(I2Cx, LIS3DH_ADDR, sendBuff, 2, HAL_MAX_DELAY);

				//Read to make sure the write worked.
				sendBuff[0]  = LIS3DH_REG_CTRL1  |LIS3DH_READ;

				ret = HAL_I2C_Master_Transmit(I2Cx, LIS3DH_ADDR, sendBuff, 1, HAL_MAX_DELAY);
				ret = HAL_I2C_Master_Receive(I2Cx, LIS3DH_ADDR, reciveBuff, 2, HAL_MAX_DELAY);

				ret = Lis3dhInteruptSetup();


	        }

	    }


return ret;




}
HAL_StatusTypeDef Lis3dhGetAcc(){

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

	 int16_t val[3];

	 val[0] = (int16_t)reciveBuff[1];
	  val[0] = (val[0] * 256) + (int16_t)reciveBuff[0];
	  val[1] = (int16_t)reciveBuff[3];
	  val[1] = (val[1] * 256) + (int16_t)reciveBuff[2];
	  val[2] = (int16_t)reciveBuff[5];
	  val[2] = (val[2] * 256) + (int16_t)reciveBuff[4];

	  LastXAcel = val[0];
	  LastYAcel = val[1];
	  LastZAcel = val[2];

	return ret;
}
void Lis3dhSetRange(int8_t range){}

void AccelGetData(int16_t *acelX, int16_t*acelY, int16_t*acelZ)
{
	*acelX = LastXAcel;
	*acelY = LastYAcel;
	*acelZ = LastZAcel;

}
HAL_StatusTypeDef Lis3dhInteruptSetup()
{
	HAL_StatusTypeDef ret = HAL_OK;
	uint8_t sendBuff[2];
	uint8_t reciveBuff[12];
	// set the double tap interrupt

	sendBuff[0] = LIS3DH_REG_CTRL1;
	sendBuff[1] = 0x57;
	ret = HAL_I2C_Master_Transmit(I2Cx, LIS3DH_ADDR, sendBuff, 2, HAL_MAX_DELAY);

	return ret;

}
void errorHandler()
{
	// handle the error
}


