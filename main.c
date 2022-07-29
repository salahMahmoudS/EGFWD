#include "Port.h"
#include "NVIC.h"
#include "Dio.h"
#include "Gpt.h"
#include "App.h"
#include "EventRecorder.h"

#define GPT_TEST_TIMER_OFF_CTRL GPT_WIDE_TIMER_3
#define GPT_TEST_TIMER_ON_CTRL GPT_WIDE_TIMER_0

/*Variable containing current ontime */

/*Variable containing current offtime */



int main()
{
	EventRecorderInitialize(EventRecordAll,1u);
	Port_Init(&Port_Configuration);
	NVIC_Init();
	Dio_Init(&Dio_Configuration);
  Gpt_Init(&Gpt_Configuration);
	App_Start();
	Gpt_EnableNotification(GPT_TEST_TIMER_ON_CTRL);
	Gpt_EnableNotification(GPT_TEST_TIMER_OFF_CTRL);
	
//	Gpt_EnableNotification(GPT_WIDE_TIMER_1);
  Gpt_StartTimer(GPT_TEST_TIMER_ON_CTRL,(App_getLedOnTime()*1000000));
	

	
///* Following code segment will be here until I develop a driver */
////1. Mask the corresponding port by clearing the IME field in the GPIOIM register.
//ICU_GPIOIM_REGISTER(GPIO_Port_F_APB_BASE_ADDRESS) = 0x00;
////2. Configure the IS field in the GPIOIS register and the IBE field in the GPIOIBE register.
//ICU_GPIOIS_REGISTER(GPIO_Port_F_APB_BASE_ADDRESS) = 0x00;
//ICU_GPIOIEV_REGISTER(GPIO_Port_F_APB_BASE_ADDRESS) = 0x00;
////3. Clear the GPIORIS register.
//ICU_GPIORIS_REGISTER(GPIO_Port_F_APB_BASE_ADDRESS) = 0x00;
//	//4. Unmask the port by setting the IME field in the GPIOIM register.
//ICU_GPIOIM_REGISTER(GPIO_Port_F_APB_BASE_ADDRESS) = 0x11;
	
	/***************************************************************/
	while(1)
	{
		
	}
}
/*
void GPIOF_Handler()
{
	Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_HIGH);
//		Dio_WriteChannel(DioConf_LED2_CHANNEL_ID_INDEX,STD_HIGH);
//		Dio_WriteChannel(DioConf_LED3_CHANNEL_ID_INDEX,STD_HIGH);
}
*/

void ISRUSER1(void)
{
	EventStartCv(0,0,0);
	Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_HIGH);
	Gpt_StopTimer(GPT_TEST_TIMER_ON_CTRL);
	Gpt_ClearInterruptFlag (GPT_TEST_TIMER_ON_CTRL);
	Gpt_StartTimer(GPT_TEST_TIMER_OFF_CTRL,App_getLedOnTime()*1000000);
}


void ISRUSER2(void)
{
	EventStartCv(0,0,0);
	Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,STD_LOW);
	Gpt_StopTimer(GPT_TEST_TIMER_OFF_CTRL);
	Gpt_ClearInterruptFlag (GPT_TEST_TIMER_OFF_CTRL);
	Gpt_StartTimer(GPT_TEST_TIMER_ON_CTRL,App_getLedOffTime()*1000000);
	
}

void ISRUSER3(void)
{
	EventStartCv(0,0,0);
	Dio_FlipChannel(DioConf_LED1_CHANNEL_ID_INDEX);
	Gpt_ClearInterruptFlag (GPT_TEST_TIMER_ON_CTRL);
	
}