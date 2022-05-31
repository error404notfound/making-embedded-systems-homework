#ifndef __GYRO_I3G450D_H
#define __GYRO_I3G450D_H

#ifdef __cplusplus
 extern "C" {
#endif


#include <stdint.h>
#include "main.h"


	 void I3G450D_Init(void);
	 void I3G450D_loop(void);
	 void GyroGetData(int16_t *x, int16_t*y, int16_t*z);


	 #ifdef __cplusplus
}
#endif

#endif /*__GYRO_I3G450D_H */
