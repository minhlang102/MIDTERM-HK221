/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: minhl
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "input_reading.h"
#include "debug_led.h"

#define INIT			0
#define INC_PRESSED		1
#define DEC_PRESSED		2
#define INC_3S			3
#define DEC_3S			4
#define AUTO_COUNTDOWN	5

extern int status_led;
extern int status;
extern int counter;
extern int CYCLE;

#endif /* INC_GLOBAL_H_ */
