/*
 * meditation_breathing_mode.h
 *
 *  Created on: 3 Jun. 2022
 *      Author: jennie.stenhouse
 */

#ifndef SRC_MODES_MEDITATION_BREATHING_MODE_H_
#define SRC_MODES_MEDITATION_BREATHING_MODE_H_

#include <mode_template.h>
#include "movementInputController.h"

#define MEDIATION_BREATHING_MODE_TIMEOUT 1000

int meditationBreathingInit();
int meditationBreathingProcess();
int meditationBreathingOnEnd();



#endif /* SRC_MODES_MEDITATION_BREATHING_MODE_H_ */
