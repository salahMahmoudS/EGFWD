#include "App.h"


void App_Start(void)
{
	App_LedOnTime = APP_LED_ON_SECONDS;
	App_LedOffTime = APP_LED_OFF_SECONDS;
}
void App_UpdateLedOnTime(uint8 UpdatedTime)
{
	App_LedOnTime = UpdatedTime;
}

void App_UpdateLedOffTime(uint8 UpdatedTime)
{
	App_LedOffTime = UpdatedTime;
}

uint8 App_getLedOnTime()
{
	return App_LedOnTime;
}
uint8 App_getLedOffTime()
{
	return App_LedOffTime;
}