/*
 * colour_change_mode.h
 *
 *  Created on: Jun 1, 2022
 *      Author: jennie.stenhouse
 */

#ifndef INC_MODES_COLOUR_CHANGE_MODE_H_
#define INC_MODES_COLOUR_CHANGE_MODE_H_
#include <mode_template.h>
#include "movementInputController.h"

#define COLOUR_CHANGE_MODE_TIMEOUT 1000

int colourChangeInit();
int colourChangeProcess();
int colourChangeOnEnd();




#endif /* INC_MODES_BREATH_TRAINER_MODE_H_ */
