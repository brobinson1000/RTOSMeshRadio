/*
 * status.c
 *
 *  Created on: Nov 22, 2026
 *      Author: brobinson
 */

#include "cmsis_os.h"
#include "status.h"
#include "battery.h"
#include "clock.h"
#include "radio.h"
#include <stdbool.h>

void Status_init(void) {
	statusMutex = osMutexNew(NULL);
}

void Status_set(Status_t *in) {
	osMutexAcquire(statusMutex, osWaitForever);
	in->battery_percent = Battery_get();
	in->is_charging = ChargingStatus_get();
	in->radio_connected = RadioStatus_get();
	osMutexRelease(statusMutex);
}

Status_t Status_get(void) {
	Status_t copy;
	osMutexAcquire(statusMutex, osWaitForever);
	copy = status;
	osMutexRelease(statusMutex);
	return copy;
}
