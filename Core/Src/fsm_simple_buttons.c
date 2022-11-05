/*
 * fsm_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: minhl
 */

#include "fsm_simple_buttons.h"

int last_counter = 0;

void inc_counter() {
	if (counter >= 9) {
		counter = 0;
	} else {
		counter++;
	}
	last_counter = counter;
}

void dec_counter() {
	if (counter <= 0) {
		counter = 9;
	} else {
		counter--;
	}
	last_counter = counter;
}

void fsm_simple_buttons_run() {
	switch (status) {
		case 0:
			if (timer2_flag == 1) {
				status = 5;
				counter-=2;
				setTimer2(500);
			}
			if (check_button_flag(0)) {
				counter = 0;
			}
			if (check_button_flag(1)) {
				status = 1;
				inc_counter();
				setTimer2(10000);
			}
			if (check_button_flag(2)) {
				status = 2;
				dec_counter();
				setTimer2(10000);
			}
			if (is_button_pressed_3s(1)){
				status = 3;
				inc_counter();
				setTimer1(1000);
			}
			if (is_button_pressed_3s(2)){
				status = 4;
				dec_counter();
				setTimer1(1000);
			}
			break;
		case 1:
			if (timer2_flag == 1) {
				status = 5;
				if (counter == 1) {
					counter = 0;
				} else {
					counter-=2;
				}
				setTimer2(1000);
			}
			if (check_button_flag(0)) {
				status = 0;
				counter = 0;
			}
			if (check_button_flag(1)) {
				inc_counter();
				setTimer2(10000);
			}
			if (check_button_flag(2)) {
				status = 2;
				dec_counter();
				setTimer2(10000);
			}
			if (is_button_pressed_3s(1)){
				status = 3;
				inc_counter();
				setTimer1(1000);
			}
			if (is_button_pressed_3s(2)){
				status = 4;
				dec_counter();
				setTimer1(1000);
			}
			break;
		case 2:
			if (timer2_flag == 1) {
				status = 5;
				if (counter == 1) {
					counter = 0;
				} else {
					counter-=2;
				}
				setTimer2(1000);
			}
			if (check_button_flag(0)) {
				status = 0;
				counter = 0;
			}
			if (check_button_flag(1)) {
				status = 1;
				inc_counter();
				setTimer2(5000);
			}
			if (check_button_flag(2)) {
				dec_counter();
				setTimer2(10000);
			}
			if (is_button_pressed_3s(1)){
				status = 3;
				inc_counter();
				setTimer1(1000);
			}
			if (is_button_pressed_3s(2)){
				status = 4;
				dec_counter();
				setTimer1(1000);
			}
			break;
		case 3:
			setTimer2(10000);
			if (!is_button_pressed(1)) {
				status = 0;
			}
			if (check_button_flag(0)) {
				counter = 0;
				setTimer1(1000);
			}
			if (check_button_flag(2)) {
				dec_counter();
				setTimer1(1000);
			} else if (is_button_pressed(2)) {
				setTimer1(1000);
			} else if (timer1_flag == 1) {
				inc_counter();
				setTimer1(1000);
			}
			break;
		case 4:
			setTimer2(5000);
			if (!is_button_pressed(2)) {
				status = 0;
			}
			if (check_button_flag(0)) {
				counter = 0;
				setTimer1(1000);
			}
			if (check_button_flag(1)) {
				inc_counter();
				setTimer1(1000);
			} else if (is_button_pressed(1)) {
				setTimer1(1000);
			} else if (timer1_flag == 1) {
				dec_counter();
				setTimer1(1000);
			}
			break;
		case 5:
			if (check_button_flag(0)) {
				status = 0;
				counter = 0;
			}
			if (timer2_flag == 1) {
				if (counter <= 0 || counter == 1) {
					counter = 0;
				} else {
					counter-=2;
				}
				setTimer2(1000);
			}
			if (check_button_flag(1) || check_button_flag(2)) {
				status = 0;
				counter = last_counter;
				setTimer2(10000);
			}
			break;
		default:
			break;
	}
}


