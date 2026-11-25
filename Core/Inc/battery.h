/*
 * battery.h
 *
 *  Created on: Nov 22, 2026
 *      Author: brobinson
 */

#ifndef INC_BATTERY_H_
#define INC_BATTERY_H_

#include <stdbool.h>

uint8_t Battery_get(void);

bool ChargingStatus_get(void);

#endif /* INC_BATTERY_H_ */
