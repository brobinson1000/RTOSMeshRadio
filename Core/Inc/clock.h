#ifndef CLOCK_H
#define CLOCK_H

#include "stm32f4xx_hal.h"

typedef struct {
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
	uint8_t day;
	uint8_t month;
	uint16_t year;
} ClockTime_t;

void Clock_Init(void);
void Clock_SetInitialTime(void);
void Clock_Get(RTC_TimeTypeDef *time, RTC_DateTypeDef *date);
ClockTime_t Clock_Get_t(void);

#endif /* CLOCK_H */
