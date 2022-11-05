/*
 * debug_led.c
 *
 *  Created on: Nov 5, 2022
 *      Author: minhl
 */

#include "debug_led.h"

void blink_led() {
	switch (status_led) {
		case 0:
			setTimer0(1000);
			status_led = 1;
			break;
		case 1:
			if (timer0_flag == 1) {
				HAL_GPIO_TogglePin(LED_TEST_GPIO_Port, LED_TEST_Pin);
				setTimer0(1000);
			}
			//Degbug code

			//
		default:
			break;
	}
}
