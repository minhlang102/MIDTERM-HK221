/*
 * fsm_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: minhl
 */

#include "fsm_simple_buttons.h"

void inc_counter() {
	if (counter >= 9) {
		counter = 0;
	} else {
		counter++;
	}
}

void dec_counter() {
	if (counter <= 0) {
		counter = 9;
	} else {
		counter--;
	}
}

void fsm_simple_buttons_run() {
	switch (status) {
		case INIT:
			if (timer2_flag == 1) {
				status = AUTO_COUNTDOWN;
				if (counter > 0) {
					counter--;
				}
				setTimer2(1000);
			}
			if (check_button_flag(0)) {
				counter = 0;
			}
			if (check_button_flag(1)) {
				status = INC_PRESSED;
				inc_counter();
				setTimer2(10000);
			}
			if (check_button_flag(2)) {
				status = DEC_PRESSED;
				dec_counter();
				setTimer2(10000);
			}
			break;
		case INC_PRESSED:
			if (timer2_flag == 1) {
				status = AUTO_COUNTDOWN;
				if (counter > 0) {
					counter--;
				}
				setTimer2(1000);
			}
			if (check_button_flag(0)) {
				status = INIT;
				counter = 0;
			}
			if (check_button_flag(1)) {
				inc_counter();
				setTimer2(10000);
			}
			if (check_button_flag(2)) {
				status = DEC_PRESSED;
				dec_counter();
				setTimer2(10000);
			}
			if (is_button_pressed_3s(1)){
				status = INC_3S;
				inc_counter();
				setTimer1(1000);
			}
			break;
		case DEC_PRESSED:
			if (timer2_flag == 1) {
				status = AUTO_COUNTDOWN;
				if (counter > 0) {
					counter--;
				}
				setTimer2(1000);
			}
			if (check_button_flag(0)) {
				status = INIT;
				counter = 0;
			}
			if (check_button_flag(1)) {
				status = INC_PRESSED;
				inc_counter();
				setTimer2(10000);
			}
			if (check_button_flag(2)) {
				dec_counter();
				setTimer2(10000);
			}
			if (is_button_pressed_3s(2)){
				status = DEC_3S;
				dec_counter();
				setTimer1(1000);
			}
			break;
		case INC_3S:
			if (!is_button_pressed(1)) {
				status = INIT;
				setTimer2(10000);
			}
			if (check_button_flag(0)) {
				counter = 0;
				setTimer1(1000);
			}
			// Neu nut 2 duoc nhan thi counter giam 1
			// Neu nut 2 chua tha thi counter giu nguyen gia tri
			// Neu nut 2 khong duoc nhan counter se giam 1 don vi moi giay
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
		case DEC_3S:
			if (!is_button_pressed(2)) {
				status = INIT;
				setTimer2(10000);
			}
			if (check_button_flag(0)) {
				counter = 0;
				setTimer1(1000);
			}
			// Neu nut 1 duoc nhan thi counter giam 1
			// Neu nut 1 chua tha thi counter giu nguyen gia tri
			// Neu nut 1 khong duoc nhan counter se giam 1 don vi moi giay
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
		case AUTO_COUNTDOWN:
			if (check_button_flag(0)) {
				status = INIT;
				counter = 0;
			}
			if (timer2_flag == 1) {
				if (counter > 0) {
					counter--;
				}
				setTimer2(1000);
			}
			if (check_button_flag(1) || check_button_flag(2)) {
				status = INIT;
				setTimer2(10000);
			}
			break;
		default:
			break;
	}
}


