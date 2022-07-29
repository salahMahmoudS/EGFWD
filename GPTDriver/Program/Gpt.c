/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
 *        \brief  
 *
 *      \details  
 *
 *	Author: Salah Mahmoud
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TM4C123GH6PM_Hw.h"
#include "Gpt.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
/*Clock timer frequecny in microseconds*/
#define GPT_CLOCK_FREQUENCY_US 								 (16U)
/* Maximum allowed value for normal timer 16 bit register */
#define GPT_NORMAL_TIMER_MAX_REGISTER_VALUE 	 (0xFFFF)
/* Maximum allowed value for wide timer 32 bit register */
#define GPT_WIDE_TIMER_MAX_REGISTER_VALUE      (0xFFFFFFFF)
/* Minimum allowed preScalervalue for normal timer 8 bit register */
#define GPT_NORMAL_TIMER_MIN_FREQUENCY_VALUE 	 (1U)
/* Minimum allowed preScalervalue for wide timer 16 bit register */
#define GPT_WIDE_TIMER_MIN_FREQUENCY_VALUE      (1U)
/* Maximum allowed preScalervalue for normal timer 8 bit register */
#define GPT_NORMAL_TIMER_MAX_FREQUENCY_VALUE 	 (16U)
/* Maximum allowed preScalervalue for wide timer 16 bit register */
#define GPT_WIDE_TIMER_MAX_FREQUENCY_VALUE      (16U)
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/* Declaring call back pointer to function */
Gpt_CallBackFunction Gpt_Notification_ptr_Timer0;
Gpt_CallBackFunction Gpt_Notification_ptr_Timer1 ;
Gpt_CallBackFunction Gpt_Notification_ptr_Timer2 ;
Gpt_CallBackFunction Gpt_Notification_ptr_Timer3 ;
Gpt_CallBackFunction Gpt_Notification_ptr_Timer4 ;
Gpt_CallBackFunction Gpt_Notification_ptr_Timer5 ;
Gpt_CallBackFunction Gpt_Notification_ptr_Timer6 ;
Gpt_CallBackFunction Gpt_Notification_ptr_Timer7 ;
Gpt_CallBackFunction Gpt_Notification_ptr_Timer8 ;
Gpt_CallBackFunction Gpt_Notification_ptr_Timer9 ;
Gpt_CallBackFunction Gpt_Notification_ptr_Timer10;
Gpt_CallBackFunction Gpt_Notification_ptr_Timer11;

static uint8 Gpt_PredefinedTimersInitialized = (STD_OFF);
/* Constant Array with BASE ADDRESS of each timer,
Each index of the array contains corresponding timer base address 
index0 contains timer0 base address, index1 contains timer1 base address etc..*/
static const uint32 Gpt_TimersAddressesMapper [12]= {(GPT_NTIMER_0_BASE_ADDRESS),
																										 (GPT_NTIMER_1_BASE_ADDRESS),
																										 (GPT_NTIMER_2_BASE_ADDRESS),
																										 (GPT_NTIMER_3_BASE_ADDRESS),
																										 (GPT_NTIMER_4_BASE_ADDRESS),
																										 (GPT_NTIMER_5_BASE_ADDRESS),
																										 (GPT_WTIMER_0_BASE_ADDRESS),
																										 (GPT_WTIMER_1_BASE_ADDRESS),
																										 (GPT_WTIMER_2_BASE_ADDRESS),
																										 (GPT_WTIMER_3_BASE_ADDRESS),
																										 (GPT_WTIMER_4_BASE_ADDRESS),
																										 (GPT_WTIMER_5_BASE_ADDRESS)};
	
/* Array with Notification status of each Timer,
each index of the array contains corresponding on Timer interrupt status 
(index 0 contains timer0 interrupt status, timer1 contains index1 timer status etc */																								 
static uint8 Gpt_NotificationsEnabledStatus []= {(STD_OFF),
																								 (STD_OFF),
																								 (STD_OFF),
																								 (STD_OFF),
																								 (STD_OFF),
																								 (STD_OFF),
																								 (STD_OFF),
																								 (STD_OFF),
																								 (STD_OFF),
																								 (STD_OFF),
																								 (STD_OFF),
																								 (STD_OFF)};

static uint8 Gpt_Initialized = (STD_OFF);
																								 
static Gpt_PreDefinedTimerConfigType Gpt_PredefinedTimerConfigurations;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const uint8 GptTotalNumberOfTimers = 12;
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Gpt_Init(const Gpt_ConfigType * ConfigPtr)        
* \Description     : Funciton to initialize timer driver                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Gpt_ConfigType * ConfigPtr                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_Init(const Gpt_ConfigType * ConfigPtr)
{
	/* TODO version and error Checks */

	
	
	for (uint8 i =0; i<GPT_NUMBER_OF_CONFIGURED_TIMERS; i++)
	{
	
		/* Create pointer to timers configuration array to read its data */ 
		const Gpt_TimerConfigType* InitializationTimersConfigurations = ConfigPtr->Gpt_ConfigurationArray;
		/* Initialize variable to contain base address of timer being configured */
		uint32 GptInitializedTimerBaseAddress = 0;
		/* ****************************************Step 0**************************************************/
		/*************************Select each configured timer to enable its clock and get its base address */
		switch (InitializationTimersConfigurations[i].GptChannelID)
		{
			case GPT_NORMAL_TIMER_0: {SET_BIT(RCGCTIMER,R0); GptInitializedTimerBaseAddress = GPT_NTIMER_0_BASE_ADDRESS; break;    }
			case GPT_NORMAL_TIMER_1: {SET_BIT(RCGCTIMER,R1); GptInitializedTimerBaseAddress = GPT_NTIMER_1_BASE_ADDRESS; break;    }
			case GPT_NORMAL_TIMER_2: {SET_BIT(RCGCTIMER,R2); GptInitializedTimerBaseAddress = GPT_NTIMER_2_BASE_ADDRESS; break;    }
			case GPT_NORMAL_TIMER_3: {SET_BIT(RCGCTIMER,R3); GptInitializedTimerBaseAddress = GPT_NTIMER_3_BASE_ADDRESS; break;    }
			case GPT_NORMAL_TIMER_4: {SET_BIT(RCGCTIMER,R4); GptInitializedTimerBaseAddress = GPT_NTIMER_4_BASE_ADDRESS; break;    }
			case GPT_NORMAL_TIMER_5: {SET_BIT(RCGCTIMER,R5); GptInitializedTimerBaseAddress = GPT_NTIMER_5_BASE_ADDRESS; break;    }
			case GPT_WIDE_TIMER_0:   {SET_BIT(RCGCWTIMER,R0); GptInitializedTimerBaseAddress = GPT_WTIMER_0_BASE_ADDRESS; break;   }
			case GPT_WIDE_TIMER_1:   {SET_BIT(RCGCWTIMER,R1); GptInitializedTimerBaseAddress = GPT_WTIMER_1_BASE_ADDRESS; break;   }
			case GPT_WIDE_TIMER_2:   {SET_BIT(RCGCWTIMER,R2); GptInitializedTimerBaseAddress = GPT_WTIMER_2_BASE_ADDRESS; break;   }
			case GPT_WIDE_TIMER_3:   {SET_BIT(RCGCWTIMER,R3); GptInitializedTimerBaseAddress = GPT_WTIMER_3_BASE_ADDRESS; break;   }
			case GPT_WIDE_TIMER_4:   {SET_BIT(RCGCWTIMER,R4); GptInitializedTimerBaseAddress = GPT_WTIMER_4_BASE_ADDRESS; break;   }
			case GPT_WIDE_TIMER_5:   {SET_BIT(RCGCWTIMER,R5); GptInitializedTimerBaseAddress = GPT_WTIMER_5_BASE_ADDRESS; break;   }
			default: /*TODO THROW ERROR*/return;

			
		}

/******************************************************* Step 1. ***************************************************************/ 
		/************Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making any changes. *******************************/
		
		CLEAR_BIT(GPTMCTL(GptInitializedTimerBaseAddress),TAEN); /* Clear Timer A */
		CLEAR_BIT(GPTMCTL(GptInitializedTimerBaseAddress),TBEN); /* Clear Timer B */

/********************************************Step 2.*************************************************************************/
/******************************************		Write the GPTM Configuration Register ******************************************/
		
		/* Configure 16 bit mode for 16/32 timers and 32 bit mode for 32/64 timer*/
		GPTMCFG(GptInitializedTimerBaseAddress) = 0x04;  /*TODO make timer autosar configurable*/
		
/****************************************************Step 3. *****************************************************/
		/*********************Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR): *************************/
		
	/*	a. Write a value of 0x1 for One-Shot mode.
	  b. Write a value of 0x2 for Periodic mode.
		c. Write a value of 0x3 for Capture mode. */
		
/*****************************************************Step 4. **********************************************************/
/*****************************Optionally configure the TnSNAPS, TnWOT, TnMTE, and TnCDIR bits in the GPTMTnMR register *************************/


/*to select whether to capture the value of the free-running timer at time-out, use an external
trigger to start counting, configure an additional trigger or interrupt, and count up or down.*/
	switch (InitializationTimersConfigurations[i].GptChannelCountDirection)
	{
		case GPT_COUNT_UP   : {SET_BIT(GPTMTAMR(GptInitializedTimerBaseAddress),TACDIR); break;}
		case GPT_COUNT_DOWN : {CLEAR_BIT(GPTMTAMR(GptInitializedTimerBaseAddress),TACDIR); break;}
		default: /* TODO THROW DET ERROR*/ break;
	}
		if (InitializationTimersConfigurations[i].GptChannelMode == GPT_CH_MODE_ONE_SHOT)	
		{
			SET_BIT(GPTMTAMR(GptInitializedTimerBaseAddress),TAMR0);
			CLEAR_BIT(GPTMTAMR(GptInitializedTimerBaseAddress),TAMR1);
		}
		else if(InitializationTimersConfigurations[i].GptChannelMode == GPT_CH_MODE_CONTINOUS)
		{
				CLEAR_BIT(GPTMTAMR(GptInitializedTimerBaseAddress),TAMR0);
				SET_BIT(GPTMTAMR(GptInitializedTimerBaseAddress),TAMR1);
		}
		/* TODO ADD third mode and uncomment below */
		/*else if(InitializationTimersConfigurations[i].GptChannelMode == GPT_CH_MODE_CAPTURE)
		{
				
				CLEAR_BIT(GPTMTAMR(GptInitializedTimerBaseAddress),TAMR0); 
				SET_BIT(GPTMTAMR(GptInitializedTimerBaseAddress),TAMR1); 
		} */
		else
		{
			/* DO NOTHING AND THROW DET ERROR */
		}
		
			
			/* TODO ADD COUNT UP AND COUNT DOWN AS MODES IN DRIVER*/
			/*Configure driver either one shot or continous modes */
		
		
/* Disable interrupts as per AUTOSAR specifications */
		GPTMIMR(GptInitializedTimerBaseAddress) = 0x0000;		


/**************************************************Step 5.******************************************************************************/
/************Initialize prescaler and check the Max timer value into the GPTM Timer n Interval Load Register (GPTMTnILR).*************/
		
		
		if ((InitializationTimersConfigurations[i].GptChannelTickValueMax >GPT_NORMAL_TIMER_MAX_REGISTER_VALUE &&
			(GptInitializedTimerBaseAddress == GPT_NTIMER_0_BASE_ADDRESS || 
		   GptInitializedTimerBaseAddress == GPT_NTIMER_1_BASE_ADDRESS ||
			 GptInitializedTimerBaseAddress == GPT_NTIMER_2_BASE_ADDRESS || 
		   GptInitializedTimerBaseAddress == GPT_NTIMER_3_BASE_ADDRESS ||
			 GptInitializedTimerBaseAddress == GPT_NTIMER_4_BASE_ADDRESS ||
			 GptInitializedTimerBaseAddress == GPT_NTIMER_5_BASE_ADDRESS))||
		  (InitializationTimersConfigurations[i].GptChannelTickValueMax >GPT_WIDE_TIMER_MAX_REGISTER_VALUE &&
			(GptInitializedTimerBaseAddress == GPT_NTIMER_0_BASE_ADDRESS || 
		   GptInitializedTimerBaseAddress == GPT_NTIMER_1_BASE_ADDRESS ||
			 GptInitializedTimerBaseAddress == GPT_NTIMER_2_BASE_ADDRESS ||
			 GptInitializedTimerBaseAddress == GPT_NTIMER_3_BASE_ADDRESS ||
			 GptInitializedTimerBaseAddress == GPT_NTIMER_4_BASE_ADDRESS ||
			 GptInitializedTimerBaseAddress == GPT_NTIMER_5_BASE_ADDRESS )))
		{
			/* THROW EXCEPTION */ 
			return;
		}
		else
		{
			/* Do nothing */
		}
		
		if (InitializationTimersConfigurations[i].GptChannelTickFrequency <GPT_NORMAL_TIMER_MIN_FREQUENCY_VALUE ||
			  InitializationTimersConfigurations[i].GptChannelTickFrequency >GPT_NORMAL_TIMER_MAX_FREQUENCY_VALUE ||
				(InitializationTimersConfigurations[i].GptChannelTickFrequency%2 != 0x01 														&&	
			  InitializationTimersConfigurations[i].GptChannelTickFrequency%2 != 0x00 																	))
		{
			/*TODO Throw exception and do nothing*/
		}
		else
		{
			/* Initialize the prescaler value according to the configured frequency*/
			GPTMTAPR(GptInitializedTimerBaseAddress) = (uint8) (50/InitializationTimersConfigurations[i].GptChannelTickFrequency)-1;
		}
		
/* *******************************************6) Last step ***************************************************************/
		/************************initialize the user defined function to be the call back function **********************************/
/******************************************************************************************************************************************************************/	
		
		if (InitializationTimersConfigurations[i].GptChannelID == GPT_NORMAL_TIMER_0)
		  {
			 if (InitializationTimersConfigurations[i].GptNotification == NULL_PTR)
			 	{
			 		/* TODO:THROW ERROR*/
			 	return;
			 	}
			 	else
			 	{
			 		/* assign configuration Notification ptr value to corresponding timer channel*/
			 		Gpt_Notification_ptr_Timer0 = InitializationTimersConfigurations[i].GptNotification; 
					
			 }
		  }
			
			else if (InitializationTimersConfigurations[i].GptChannelID == GPT_NORMAL_TIMER_1)
		  {
			 if (InitializationTimersConfigurations[i].GptNotification == NULL_PTR)
			 	{
			 		/* TODO:THROW ERROR*/
			 	return;
			 	}
			 	else
			 	{
			 		/* assign configuration Notification ptr value to corresponding timer channel*/
			 		Gpt_Notification_ptr_Timer1 = InitializationTimersConfigurations[i].GptNotification; 
					
			 }
		  }
			else if (InitializationTimersConfigurations[i].GptChannelID == GPT_NORMAL_TIMER_2)
		  {
			 if (InitializationTimersConfigurations[i].GptNotification == NULL_PTR)
			 	{
			 		/* TODO:THROW ERROR*/
			 	return;
			 	}
			 	else
			 	{
			 		/* assign configuration Notification ptr value to corresponding timer channel*/
			 		Gpt_Notification_ptr_Timer2 = InitializationTimersConfigurations[i].GptNotification; 
					
			 }
		  }	
			else if (InitializationTimersConfigurations[i].GptChannelID == GPT_NORMAL_TIMER_3)
		  {
			 if (InitializationTimersConfigurations[i].GptNotification == NULL_PTR)
			 	{
			 		/* TODO:THROW ERROR*/
			 	return;
			 	}
			 	else
			 	{
			 		/* assign configuration Notification ptr value to corresponding timer channel*/
			 		Gpt_Notification_ptr_Timer3 = InitializationTimersConfigurations[i].GptNotification; 
					
			 }
		  }
			else if (InitializationTimersConfigurations[i].GptChannelID == GPT_NORMAL_TIMER_4)
		  {
			 if (InitializationTimersConfigurations[i].GptNotification == NULL_PTR)
			 	{
			 		/* TODO:THROW ERROR*/
			 	return;
			 	}
			 	else
			 	{
			 		/* assign configuration Notification ptr value to corresponding timer channel*/
			 		Gpt_Notification_ptr_Timer4 = InitializationTimersConfigurations[i].GptNotification; 
					
			 }
		  }
			else if (InitializationTimersConfigurations[i].GptChannelID == GPT_NORMAL_TIMER_5)
		  {
			 if (InitializationTimersConfigurations[i].GptNotification == NULL_PTR)
			 	{
			 		/* TODO:THROW ERROR*/
			 	return;
			 	}
			 	else
			 	{
			 		/* assign configuration Notification ptr value to corresponding timer channel*/
			 		Gpt_Notification_ptr_Timer5 = InitializationTimersConfigurations[i].GptNotification; 
					
			 }
		  }
			else if(InitializationTimersConfigurations[i].GptChannelID == GPT_WIDE_TIMER_0)
			{
				if (InitializationTimersConfigurations[i].GptNotification == NULL_PTR)
				{
				 	return;
				}
					else
				{
					Gpt_Notification_ptr_Timer6 = InitializationTimersConfigurations[i].GptNotification; 
				}	
			}
			else if(InitializationTimersConfigurations[i].GptChannelID == GPT_WIDE_TIMER_1)
			{
				if (InitializationTimersConfigurations[i].GptNotification == NULL_PTR)
				{
				 	return;
				}
					else
				{
					Gpt_Notification_ptr_Timer7 = InitializationTimersConfigurations[i].GptNotification; 
				}	
			}
			else if(InitializationTimersConfigurations[i].GptChannelID == GPT_WIDE_TIMER_2)
			{
				if (InitializationTimersConfigurations[i].GptNotification == NULL_PTR)
				{
				 	return;
				}
					else
				{
					Gpt_Notification_ptr_Timer8 = InitializationTimersConfigurations[i].GptNotification; 
				}	
			}
			else if(InitializationTimersConfigurations[i].GptChannelID == GPT_WIDE_TIMER_3)
			{
				if (InitializationTimersConfigurations[i].GptNotification == NULL_PTR)
				{
				 	return;
				}
					else
				{
					Gpt_Notification_ptr_Timer9 = InitializationTimersConfigurations[i].GptNotification; 
				}	
			}
			else if(InitializationTimersConfigurations[i].GptChannelID == GPT_WIDE_TIMER_4)
			{
				if (InitializationTimersConfigurations[i].GptNotification == NULL_PTR)
				{
				 	return;
				}
					else
				{
					Gpt_Notification_ptr_Timer10 = InitializationTimersConfigurations[i].GptNotification; 
				}	
			}
			else if(InitializationTimersConfigurations[i].GptChannelID == GPT_WIDE_TIMER_5)
			{
				if (InitializationTimersConfigurations[i].GptNotification == NULL_PTR)
				{
				 	return;
				}
					else
				{
					Gpt_Notification_ptr_Timer11 = InitializationTimersConfigurations[i].GptNotification; 
				}	
			}
			else
			{
				/*TODO THROW ERROR*/
				return;
			}
		}
	
	
	/***********************************************************************************************************************/
	/********************************************** After finalizing the Configures timers configure predefined timers *******************************/
	
		/* Use wide timer 5-B for the predefined timers */	
		#if (GPT_PREDEF_TIMER_100US_32BIT_ENABLE == STD_ON || GPT_PREDEF_TIMER_1US_16BIT_ENABLE == STD_ON || GPT_PREDEF_TIMER_1US_24BIT_ENABLE == STD_ON || GPT_PREDEF_TIMER_1US_32BIT_ENABLE == STD_ON ) 
		/* if there is no previously defined Wide timer to contain predefined timers, use Widetimer0 */
		if(CHECK_BIT(RCGCWTIMER,R0) == 0x00 &&
			 CHECK_BIT(RCGCWTIMER,R1) == 0x00 &&
			 CHECK_BIT(RCGCWTIMER,R2) == 0x00 &&
			 CHECK_BIT(RCGCWTIMER,R3) == 0x00 &&
			 CHECK_BIT(RCGCWTIMER,R4) == 0x00 &&
			 CHECK_BIT(RCGCWTIMER,R5) == 0x00   )
		{
			/* Enable timer0 clock*/
			SET_BIT(RCGCWTIMER,R0);
			/* Make the predefined timer channel = R0 */
			Gpt_PredefinedTimerConfigurations.Gpt_PreDefinedTimersChannel = R0;
			
		}
		else
		{
			if (CHECK_BIT(RCGCWTIMER,R0) == 0x01)
			{
				Gpt_PredefinedTimerConfigurations.Gpt_PreDefinedTimersChannel = R0;
			}
			else if (CHECK_BIT(RCGCWTIMER,R1) == 0x01)
			{
				Gpt_PredefinedTimerConfigurations.Gpt_PreDefinedTimersChannel = R1;
			}
			else if (CHECK_BIT(RCGCWTIMER,R2) == 0x01)
			{
				Gpt_PredefinedTimerConfigurations.Gpt_PreDefinedTimersChannel = R2;
			}
			else if(CHECK_BIT(RCGCWTIMER,R3) == 0x01)
			{
				Gpt_PredefinedTimerConfigurations.Gpt_PreDefinedTimersChannel = R3;
			}
			else if (CHECK_BIT(RCGCWTIMER,R4) == 0x01) 
			{
				Gpt_PredefinedTimerConfigurations.Gpt_PreDefinedTimersChannel = R4;
			}
			else if(CHECK_BIT(RCGCWTIMER,R5) == 0x01)
			{
				Gpt_PredefinedTimerConfigurations.Gpt_PreDefinedTimersChannel = R5;

			}				
		}
		/* Assign preTimer base address value to the seleted timer */
			uint32 Gpt_PredefinedTimersRegisterBaseAddress = Gpt_TimersAddressesMapper[Gpt_PredefinedTimerConfigurations.Gpt_PreDefinedTimersChannel+6];
			/* Clear Timer B */
			CLEAR_BIT(GPTMCTL(Gpt_PredefinedTimersRegisterBaseAddress),TBEN); 
		/* 32 bits mode */
			GPTMCFG(Gpt_PredefinedTimersRegisterBaseAddress) = 0x04;
			/* Load Timer B in continous Mode */ 
			GPTMTBMR(Gpt_PredefinedTimersRegisterBaseAddress) |= 0x0012;
			/* Load prescaler Register with configuration value 1599 to obtain prescaler value 1600 */
			GPTMTBPR(Gpt_PredefinedTimersRegisterBaseAddress) = 0x1388;
			/* Load interval load Register with max value */
			
			
			
			#if (GPT_PREDEF_TIMER_100US_32BIT_ENABLE == STD_ON)
			Gpt_PredefinedTimerConfigurations.Gpt_PreDefinedTimersStatus[GPT_PREDEF_TIMER_100US_32BIT] = STD_ON;
			#else
			/* Do nothing */
			#endif
			
			#if (GPT_PREDEF_TIMER_1US_32BIT_ENABLE == STD_ON)
					Gpt_PredefinedTimerConfigurations.Gpt_PreDefinedTimersStatus[GPT_PREDEF_TIMER_1US_32BIT] = STD_ON;
			#else
			/* Do nothing */	
			#endif
			
			#if (GPT_PREDEF_TIMER_1US_24BIT_ENABLE == STD_ON)
			Gpt_PredefinedTimerConfigurations.Gpt_PreDefinedTimersStatus[GPT_PREDEF_TIMER_1US_24BIT] = STD_ON;
			#else
			/* Do nothing */
			#endif
			
			#if (GPT_PREDEF_TIMER_1US_16BIT_ENABLE == STD_ON)
				Gpt_PredefinedTimerConfigurations.Gpt_PreDefinedTimersStatus[GPT_PREDEF_TIMER_1US_16BIT] = STD_ON;
			#else
			/* Do nothing */
			#endif
		
		GPTMTBILR(Gpt_PredefinedTimersRegisterBaseAddress) = 0xFFFFFFFF;
			SET_BIT(GPTMCTL(Gpt_PredefinedTimersRegisterBaseAddress),TBEN);
			Gpt_PredefinedTimersInitialized = (STD_ON);			
		#else
		/* Do nothing */
		#endif
		
		
		
	
	Gpt_Initialized = (STD_ON);
	
}





void Gpt_DisableNotification (Gpt_ChannelType Channel)
{
	/* If trying to access wrong index */
	if (Channel<0|| Channel>11)
	{
		/* TODO Throw error */
	}
	else
	{
		/* Clear interrupts register to disable notificatoins*/
	CLEAR_BIT(GPTMIMR(Gpt_TimersAddressesMapper[Channel]),TATOIM);
		/* Change notification status of corresponding timer to disabled */
	Gpt_NotificationsEnabledStatus[Channel] = (STD_OFF);
	}
}
void Gpt_EnableNotification (Gpt_ChannelType Channel)
{
	/* If trying to access wrong channel index */
	if (Channel<0|| Channel>11)
	{
		/* TODO Throw error */
		return;
	}
	else
	{
		/* Set tp enable interrupts register bit notificatoins*/
	SET_BIT(GPTMIMR(Gpt_TimersAddressesMapper[Channel]),TATOIM);
		/* Change notification status of corresponding timer to enabled */
	Gpt_NotificationsEnabledStatus[Channel] = (STD_ON);
	}
}


/******************************************************************************
* \Syntax          : void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType value)        
* \Description     : Funciton to start timer channel with specific time                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType Channel
*										 Gpt_ValueType value                 
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType value)
{
	/* Check if load value is suitable for selected address */
	if ((value >GPT_NORMAL_TIMER_MAX_REGISTER_VALUE &&
			(Gpt_TimersAddressesMapper[Channel] == GPT_NTIMER_0_BASE_ADDRESS || 
		   Gpt_TimersAddressesMapper[Channel] == GPT_NTIMER_1_BASE_ADDRESS ||
			 Gpt_TimersAddressesMapper[Channel] == GPT_NTIMER_2_BASE_ADDRESS || 
		   Gpt_TimersAddressesMapper[Channel] == GPT_NTIMER_3_BASE_ADDRESS ||
			 Gpt_TimersAddressesMapper[Channel] == GPT_NTIMER_4_BASE_ADDRESS ||
			 Gpt_TimersAddressesMapper[Channel] == GPT_NTIMER_5_BASE_ADDRESS))||
		  (value >GPT_WIDE_TIMER_MAX_REGISTER_VALUE &&
			(Gpt_TimersAddressesMapper[Channel] == GPT_WTIMER_0_BASE_ADDRESS || 
		   Gpt_TimersAddressesMapper[Channel] == GPT_WTIMER_1_BASE_ADDRESS ||
			 Gpt_TimersAddressesMapper[Channel] == GPT_WTIMER_2_BASE_ADDRESS ||
			 Gpt_TimersAddressesMapper[Channel] == GPT_WTIMER_3_BASE_ADDRESS ||
			 Gpt_TimersAddressesMapper[Channel] == GPT_WTIMER_4_BASE_ADDRESS ||
			 Gpt_TimersAddressesMapper[Channel] == GPT_WTIMER_5_BASE_ADDRESS )))
		{
			/* if value is not matching the selected address */
			/* THROW EXCEPTION */ 
			return;
		}
		else
		{
			/* Do nothing */
		}
		
	/* Load timer register A with desired value */
		GPTMTAILR(Gpt_TimersAddressesMapper[Channel]) = value;
		/* Enable timer to start counting */
	SET_BIT(GPTMCTL(Gpt_TimersAddressesMapper[Channel]),TAEN);
		
}


/******************************************************************************
* \Syntax          : void Gpt_StopTimer(Gpt_ChannelType Channel,Gpt_ValueType value)        
* \Description     : Funciton to stop timer channel with specific time                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType Channel
*										 Gpt_ValueType value                 
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
	if (Channel<0|| Channel>11)
	{
		/* TODO Throw error */
		return;
	}
	else
	{
		/* Clear timerA Enable register to disable the timer */
	CLEAR_BIT(GPTMCTL(Gpt_TimersAddressesMapper[Channel]),TAEN);
	}	
	
}

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GettimeElapsed(Gpt_ChannelType Channel)        
* \Description     : Funciton to return value of elapsed time in specified timer channel                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType Channel
*										                  
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);




/******************************************************************************
* \Syntax          : Gpt_ValueType  Gpt_GetTimeRemaiing(Gpt_ChannelType Channel)        
* \Description     : Funciton to return value of remaining time to overflow in specified timer channel                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType Channel
*									              
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);



/******************************************************************************
* \Syntax          : Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PreDefTimerType PredefTimer,uint32* TimerValuePtr);
    
* \Description     : Funciton to Get current value in a predefined timer                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PreDefTimer: desired predefined timer
*										 TimeValuePtr: pointer that will contain the required value                
* \Parameters (out): None                                                      
* \Return value:   : E_OK
*										 E_NOT_OK
*******************************************************************************/
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PreDefTimerType PredefTimer,uint32* TimerValuePtr);


/******************************************************************************
* \Syntax          : void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType value)        
* \Description     : Funciton to start timer channel with specific time                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Gpt_ChannelType Channel
*										 Gpt_ValueType value                 
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_ClearInterruptFlag (Gpt_ChannelType Channel)
{
	if (Channel<0|| Channel>11)
	{
		/* TODO Throw error */
		return;
	}
	else
	{
		/* Clear timerA Enable register to disable the timer */
	SET_BIT(GPTMICR(Gpt_TimersAddressesMapper[Channel]),TATOCINT);
	}	
}

/* Below functtion call its corresponding pointer to function that calls back user defined ISR in the APP layer */
void Gpt_Notification_Timer0(void)
{
	(*Gpt_Notification_ptr_Timer0)();
}

/* Below functtion call its corresponding pointer to function that calls back user defined ISR in the APP layer */
void Gpt_Notification_Timer1(void)
{
	(*Gpt_Notification_ptr_Timer1)();
}

/* Below functtion call its corresponding pointer to function that calls back user defined ISR in the APP layer */
void Gpt_Notification_Timer2(void)
{
	(*Gpt_Notification_ptr_Timer2)();
}

/* Below functtion call its corresponding pointer to function that calls back user defined ISR in the APP layer */
void Gpt_Notification_Timer3(void)
{
	(*Gpt_Notification_ptr_Timer3)();
}

/* Below functtion call its corresponding pointer to function that calls back user defined ISR in the APP layer */
void Gpt_Notification_Timer4(void)
{
	(*Gpt_Notification_ptr_Timer4)();
}

/* Below functtion call its corresponding pointer to function that calls back user defined ISR in the APP layer */
void Gpt_Notification_Timer5(void)
{
	(*Gpt_Notification_ptr_Timer5)();
}

/* Below functtion call its corresponding pointer to function that calls back user defined ISR in the APP layer */
void Gpt_Notification_Timer6(void)
{
	(*Gpt_Notification_ptr_Timer6)();
}

/* Below functtion call its corresponding pointer to function that calls back user defined ISR in the APP layer */
void Gpt_Notification_Timer7(void)
{
	(*Gpt_Notification_ptr_Timer7)();
}

/* Below functtion call its corresponding pointer to function that calls back user defined ISR in the APP layer */
void Gpt_Notification_Timer8(void)
{
	(*Gpt_Notification_ptr_Timer8)();
}

/* Below functtion call its corresponding pointer to function that calls back user defined ISR in the APP layer */
void Gpt_Notification_Timer9(void)
{
	(*Gpt_Notification_ptr_Timer9)();
}

/* Below functtion call its corresponding pointer to function that calls back user defined ISR in the APP layer */
void Gpt_Notification_Timer10(void)
{
	(*Gpt_Notification_ptr_Timer10)();
}

/* Below functtion call its corresponding pointer to function that calls back user defined ISR in the APP layer */
void Gpt_Notification_Timer11(void)
{
	(*Gpt_Notification_ptr_Timer11)();
}


/* Handler function for Timer0A */
void TIMER0A_Handler()
{
	/* call the call back function */
	(*Gpt_Notification_Timer0)();
}

/* Handler function for Timer1A */
void TIMER1A_Handler()
{
		/* call the call back function */
	(*Gpt_Notification_Timer1)();
}

/* Handler function for Timer2A */
void TIMER2A_Handler()
{
		/* call the call back function */
	(*Gpt_Notification_Timer2)();
}

/* Handler function for Timer3A */
void TIMER3A_Handler()
{
		/* call the call back function */
	while(1);
	(*Gpt_Notification_Timer3)();
}

/* Handler function for Timer4A */
void TIMER4A_Handler()
{
		/* call the call back function */
	(*Gpt_Notification_Timer4)();
}

/* Handler function for Timer5A */
void TIMER5A_Handler()
{
		/* call the call back function */
	(*Gpt_Notification_Timer5)();}

/* Handler function for Timer6A */
void WTIMER0A_Handler()
{
		/* call the call back function */
	
	(*Gpt_Notification_Timer6)();
}

/* Handler function for Timer7A */
void WTIMER1A_Handler()
{
		/* call the call back function */
		
	(*Gpt_Notification_Timer7)();
}

/* Handler function for Timer8A */
void WTIMER2A_Handler()
{
	/* call the call back function */
	
	(*Gpt_Notification_Timer8)();
}

/* Handler function for Timer9A */
void WTIMER3A_Handler()
{
		/* call the call back function */
	
	(*Gpt_Notification_Timer9)();
}

/* Handler function for Timer10A */
void WTIMER4A_Handler()
{
		/* return call back function */
	while(1);
	(*Gpt_Notification_Timer10)();
}

/* Handler function for Timer11A */
void WTIMER5A_Handler()
{
		/* call the call back function */
	(*Gpt_Notification_Timer11)();
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
