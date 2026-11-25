#include "clock.h"
#include "main.h"

static RTC_HandleTypeDef hrtc_clock;

ClockTime_t Clock_Get_t(void)
{
	RTC_TimeTypeDef time;
	RTC_DateTypeDef date;
	ClockTime_t now;

	Clock_Get(&time, &date);

	now.hours = time.Hours;
	now.minutes = time.Minutes;
	now.seconds = time.Seconds;
	now.day = date.Date;
	now.month = date.Month;
	now.year = 2000 + date.Year;

	return now;

}

void Clock_Init(void)
{
  RCC_OscInitTypeDef osc = {0};
  RCC_PeriphCLKInitTypeDef periph = {0};

  /* Power and backup domain access are needed to change the RTC clock */
  __HAL_RCC_PWR_CLK_ENABLE();
  HAL_PWR_EnableBkUpAccess();

  /* Start the LSI oscillator (about 32 kHz) */
  osc.OscillatorType = RCC_OSCILLATORTYPE_LSI;
  osc.LSIState = RCC_LSI_ON;
  if (HAL_RCC_OscConfig(&osc) != HAL_OK) Error_Handler();

  /* Use LSI as the RTC clock */
  periph.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  periph.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&periph) != HAL_OK) Error_Handler();

  __HAL_RCC_RTC_ENABLE();

  /* 32 kHz / ((127 + 1) * (249 + 1)) = 1 Hz */
  hrtc_clock.Instance = RTC;
  hrtc_clock.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc_clock.Init.AsynchPrediv = 127;
  hrtc_clock.Init.SynchPrediv = 249;
  hrtc_clock.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc_clock.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc_clock.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc_clock) != HAL_OK) Error_Handler();
}

void Clock_SetInitialTime(void)
{
  RTC_TimeTypeDef t = {0};
  RTC_DateTypeDef d = {0};

  t.Hours = 16;
  t.Minutes = 50;
  t.Seconds = 0;
  HAL_RTC_SetTime(&hrtc_clock, &t, RTC_FORMAT_BIN);

  d.WeekDay = RTC_WEEKDAY_SUNDAY;
  d.Month = RTC_MONTH_NOVEMBER;
  d.Date = 22;
  d.Year = 26;
  HAL_RTC_SetDate(&hrtc_clock, &d, RTC_FORMAT_BIN);
}

void Clock_Get(RTC_TimeTypeDef *time, RTC_DateTypeDef *date)
{
  HAL_RTC_GetTime(&hrtc_clock, time, RTC_FORMAT_BIN);
  HAL_RTC_GetDate(&hrtc_clock, date, RTC_FORMAT_BIN);  /* call GetDate after GetTime */
}
