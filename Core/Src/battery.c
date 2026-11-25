/*
 * battery.c
 *
 *  Created on: Nov 22, 2026
 *      Author: brobinson
 */

#include <stdbool.h>
#include "cmsis_os.h"
#include "app_queues.h"
#include "battery.h"

uint8_t Battery_get(void) {
	// Retrieve battery once I get batter cell chip
	uint8_t p = 0;
	return p;
}

static void Battery_task(void) {
	for(;;) {
		uint8_t battery_level = Battery_get();
		xQueueSend(batt_queue, &battery_level, portMAX_DELAY);
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

bool ChargingStatus_get(void) {
	return false;
}


