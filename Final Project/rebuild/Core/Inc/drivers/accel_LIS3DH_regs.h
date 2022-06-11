/*
 * accel_LIS3DH_regs.h
 *
 *  Created on: May 30, 2022
 *      Author: jennie.stenhouse
 */

#ifndef INC_DRIVERS_ACCEL_LIS3DH_REGS_H_
#define INC_DRIVERS_ACCEL_LIS3DH_REGS_H_

#define LIS3DH_REG_STATUS_AUX    0x07
#define LIS3DH_REG_OUT_ADC1_L    0x08
#define LIS3DH_REG_OUT_ADC1_H    0x09
#define LIS3DH_REG_OUT_ADC2_L    0x0a
#define LIS3DH_REG_OUT_ADC2_H    0x0b
#define LIS3DH_REG_OUT_ADC3_L    0x0c
#define LIS3DH_REG_OUT_ADC3_H    0x0d
#define LIS3DH_REG_INT_COUNTER   0x0e
#define LIS3DH_REG_WHO_AM_I      0x0f
#define LIS3DH_REG_TEMP_CFG      0x1f


#define LIS3DH_REG_CTRL1         0x20
#define LIS3DH_REG_CTRL2		 0x21
#define LIS3DH_REG_CTRL3		 0x22
#define LIS3DH_REG_CTRL4		 0x23
#define LIS3DH_REG_CTRL5		 0x24
#define LIS3DH_REG_STATUS        0x27
#define LIS3DH_REG_OUT_X_L       0x28
#define LIS3DH_REG_OUT_X_H       0x29
#define LIS3DH_REG_OUT_Y_L       0x2a
#define LIS3DH_REG_OUT_Y_H       0x2b
#define LIS3DH_REG_OUT_Z_L       0x2c
#define LIS3DH_REG_OUT_Z_H       0x2d


#define LIS3DH_CLICK_CFG		0x38
#define LIS3DH_CLICK_SRC		0x39
#define LIS3DH_CLICK_THS		0x3a
#define	LIS3DH_TIMELIMIT		0x3b
#define LIS3DH_TIME_LATENCY		0x3c
#define LIS3DH_TIME_WINDOW		0x3d

#define LIS3DH_READ				 (1 << 7)
#define LIS3DH_WRITE			 0x00

#define LIS3DH_ON_1HZ		 	 0x17
#define LIS3DH_ON_10HZ		     0x27
#define LIS3DH_ON_25HZ		     0x37
#define LIS3DH_ON_50HZ		     0x47
#define LIS3DH_ON_100HZ		     0x57
#define LIS3DH_ON_200HZ		     0x67
#define LIS3DH_ON_400HZ		     0x77
#define LIS3DH_ON_ADC		     0x80


#define WHO_AM_I         0X8F
#define WHO_AM_I_VALUE   0x33



#endif /* INC_DRIVERS_ACCEL_LIS3DH_REGS_H_ */
