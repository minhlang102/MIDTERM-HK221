/*
 * input_reading.h
 *
 *  Created on: Nov 4, 2022
 *      Author: minhl
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
#include "software_timer.h"
#include "global.h"

int check_button_flag(int i);
void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_3s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
