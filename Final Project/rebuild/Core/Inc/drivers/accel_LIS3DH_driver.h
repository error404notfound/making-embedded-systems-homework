/*
 * accel_LIS3DH_driver.h
 *
 *  Created on: May 30, 2022
 *      Author: jennie.stenhouse
 */

#ifndef INC_DRIVERS_ACCEL_LIS3DH_DRIVER_H_
#define INC_DRIVERS_ACCEL_LIS3DH_DRIVER_H_


#include <stdint.h>
#include "accel_LIS3DH_regs.h"
#include "stm32f4xx.h"
/* error code */
typedef enum
{
	NO_ERROR,
	CONFIG_ERROR
}LIS3DH_ErrorType;
/* Range definitions. Map them to actual bitmasks. */
#define RANGE_2G   CTRL_REG4_FS2G
#define RANGE_4G   CTRL_REG4_FS4G
#define RANGE_8G   CTRL_REG4_FS8G
#define RANGE_16G  CTRL_REG4_FS16G

/* CS pin */
#define CSpin GPIO_PIN_2
#define CSport GPIOD
/* Public APIs */
void Lis3dhInit(I2C_HandleTypeDef *I2Cxhandle);
HAL_StatusTypeDef Lis3dhGetAcc();
void Lis3dhSetRange(int8_t range);
void AccelGetData(int16_t *x, int16_t*y, int16_t*z);


#endif /* INC_DRIVERS_ACCEL_LIS3DH_DRIVER_H_ */
