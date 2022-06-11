/*
 * mode_template.h
 *
 *  Created on: Jun 2, 2022
 *      Author: jennie.stenhouse
 */

#ifndef INC_MODES_MODE_TEMPLATE_H_
#define INC_MODES_MODE_TEMPLATE_H_

typedef int (*modeFunc )(void);
typedef enum { BREATHING_TRAINER, COLOUR_CHANGE} modeSelection_t;
typedef struct{

	modeFunc onStart;
	modeFunc modeProcess;
	modeFunc onEnd;
	modeFunc getTimeOut;

}modeTableEntry_t;


#endif /* INC_MODES_MODE_TEMPLATE_H_ */
