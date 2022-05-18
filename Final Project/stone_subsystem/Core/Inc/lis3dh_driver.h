/** @file lis3dh.h
 * @author david.siorpaes@st.com
 * Header file for LIS3DH driver. Includes both public and private APIs.
 */

#include <stdint.h>
#include "lis3dh_regs.h"
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
void Lis3dhInit(I2C_HandleTypeDef *I2Cx);
int Lis3dhGetAcc(int16_t* x, int16_t* y, int16_t* z);
void Lis3dhSetRange(int8_t range);


/* Private APIs */
void csOn(void);
void csOff(void);
int spiConfig(void);
uint8_t LIS3DH_readReg(uint8_t lis3dhReg);
void LIS3DH_writeReg(uint8_t lis3dhReg, uint8_t lis3dhValue);

