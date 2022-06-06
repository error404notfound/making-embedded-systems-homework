/*
 * gyro_I3g450D_driver.h
 *
 *  Created on: May 30, 2022
 *      Author: jennie.stenhouse
 */

#ifndef INC_DRIVERS_GYRO_I3G450D_DRIVER_H_
#define INC_DRIVERS_GYRO_I3G450D_DRIVER_H_

#ifdef __cplusplus
 extern "C" {
#endif


#include <stdint.h>
#include "main.h"
#include "stm32f4xx_hal.h"

	 void I3G450D_Init(SPI_HandleTypeDef * hspi5);
	 void I3G450D_loop(void);
	 void GyroGetData(int16_t *x, int16_t*y, int16_t*z);


	 #ifdef __cplusplus
}
#endif



#endif /* INC_DRIVERS_GYRO_I3G450D_DRIVER_H_ */
