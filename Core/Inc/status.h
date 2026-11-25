/*
 * status.h
 *
 *  Created on: Nov 22, 2026
 *      Author: brobinson
 */

#ifndef INC_STATUS_H_
#define INC_STATUS_H_

#include <stdbool.h>
#include "cmsis_os.h"

typedef struct {
	uint8_t battery_percent;
	bool is_charging;
	bool radio_connected;
} Status_t;


static osMutexId_t statusMutex;
static Status_t status;

void Status_init(void);

void Status_set(Status_t *in);

Status_t Status_get(void);


#endif /* INC_STATUS_H_ */
