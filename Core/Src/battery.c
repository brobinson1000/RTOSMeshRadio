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

uint16_t Battery_get(void) {
	// Retrieve battery once I get batter cell chip
	uint16_t p = 0;
	return p;
}

static void Battery_task(void) {
	for(;;) {
		ui_event_t ui_battery_event = {
				.type = UI_EVT_BATTERY,
				.evt_data.battery_percentage = Battery_get()
		};

		xQueueSend(ui_queue, &ui_battery_event, portMAX_DELAY);
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

bool ChargingStatus_get(void) {
	return false;
}


