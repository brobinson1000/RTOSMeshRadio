/*
 * battery.c
 *
 *  Created on: Nov 22, 2026
 *      Author: brobinson
 */

#include <stdbool.h>
#include "cmsis_os.h"

uint8_t Battery_get(void) {
	// Retrieve battery once I get batter cell chip
	uint8_t p = 0;
	return p;
}

bool ChargingStatus_get(void) {
	return false;
}

