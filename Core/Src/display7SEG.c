/*
 * display7SEG.c
 *
 *  Created on: Nov 4, 2022
 *      Author: minhl
 */

#include "display7SEG.h"

uint8_t segmentArray[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6F}; //From 0 to 9
int state7SEG = 1;

void display7SEG(int8_t counter) {
	if (counter<0 || counter>9) return;
	for (int i=0; i<7; i++) {
		HAL_GPIO_WritePin(s0_GPIO_Port, s0_Pin << i, !((segmentArray[counter]>>i)&0x1));
	}
}
