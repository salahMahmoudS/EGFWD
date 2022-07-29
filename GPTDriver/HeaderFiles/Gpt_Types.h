/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Gpt_Types.h>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H


/* Defining the Module software verison by Major.Minor.Patch format */
/* Module 1.0.0 */

#define GPT_SW_MAJOR_VERSION				(1U)
#define GPT_SW_MINOR_VERSION				(0U)
#define GPT_SW_PATCH_VERSION				(0U)


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/* Below define available Gpt Modes */
#define GPT_CH_MODE_CONTINOUS (Gpt_ModeType) (1U)	//Gpt will run in continous mode
#define GPT_CH_MODE_ONE_SHOT	(Gpt_ModeType) (2U) //Gpt will run in one shot mode

#define GPT_NORMAL_TIMER_0  (Gpt_ChannelType)(0U) 	//Timer0 16/32 bit
#define GPT_NORMAL_TIMER_1  (Gpt_ChannelType)(1U) 	//Timer1 16/32 bit
#define GPT_NORMAL_TIMER_2  (Gpt_ChannelType)(2U)   //Timer2 16/32 bit
#define GPT_NORMAL_TIMER_3  (Gpt_ChannelType)(3U)   //Timer3 16/32 bit
#define GPT_NORMAL_TIMER_4  (Gpt_ChannelType)(4U)   //Timer4 16/32 bit
#define GPT_NORMAL_TIMER_5  (Gpt_ChannelType)(5U)   //Timer5 16/32 bit
#define GPT_WIDE_TIMER_0    (Gpt_ChannelType)(6U)   //Timer0 32/64 bit
#define GPT_WIDE_TIMER_1    (Gpt_ChannelType)(7U)   //Timer1 32/64 bit
#define GPT_WIDE_TIMER_2    (Gpt_ChannelType)(8U)   //Timer2 32/64 bit
#define GPT_WIDE_TIMER_3    (Gpt_ChannelType)(9U)   //Timer3 32/64 bit
#define GPT_WIDE_TIMER_4    (Gpt_ChannelType)(10U)  //Timer4 32/64 bit
#define GPT_WIDE_TIMER_5    (Gpt_ChannelType)(11U)	//Timer5 32/64 bit 

#define GPT_NUMBER_OF_PREDEFINED_TIMERS 										(4U)		//Number of configured predefined timers in this Driver
#define GPT_PREDEF_TIMER_1US_16BIT		(Gpt_PreDefTimerType) (0U)		//Work in a predefined mode 1Us overflow time and 16 timer Reg
#define GPT_PREDEF_TIMER_1US_24BIT    (Gpt_PreDefTimerType) (1U)    //Work in a predefined mode 1Us overflow time and 24 timer Reg
#define GPT_PREDEF_TIMER_1US_32BIT    (Gpt_PreDefTimerType) (2U)    //Work in a predefined mode 1Us overflow time and 32 timer Reg
#define GPT_PREDEF_TIMER_100US_32BIT  (Gpt_PreDefTimerType) (3U)    //Work in a predefined mode 100Us overflow time and 32 timer Reg

#define GPT_COUNT_UP									(Gpt_CountDirectionType) (1U)		//Timer count mode is up
#define GPT_COUNT_DOWN								(Gpt_CountDirectionType) (2U)		//Timer count mode is down




/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* defining type for timer channels (timer0, timer1 , etc) */
typedef uint8 Gpt_ChannelType;  
/* defining type that will store maximum ticks value in timer register */
typedef uint32 Gpt_ValueType;
/* Defining which mode to be used either continous or one shot*/
typedef uint8 Gpt_ModeType;
/*typedef for predefined timer types*/
typedef uint8 Gpt_PreDefTimerType;
/*typedef for call back function that will be used with each timer*/
typedef	uint8 Gpt_CountDirectionType;
/* Call back pointer to function type*/
typedef void (*Gpt_CallBackFunction)(void);


/* Structure containing configurations of Gpt driver*/
typedef struct
{
	Gpt_ChannelType GptChannelID;
	uint8 GptChannelTickFrequency;
	Gpt_ValueType GptChannelTickValueMax;
	Gpt_ModeType GptChannelMode;
	Gpt_CountDirectionType GptChannelCountDirection;
	Gpt_CallBackFunction GptNotification; /*Pointer for call back function*/
	
}Gpt_TimerConfigType;

typedef struct
{
	Gpt_ChannelType Gpt_PreDefinedTimersChannel;
	uint8 Gpt_PreDefinedTimersStatus [GPT_NUMBER_OF_PREDEFINED_TIMERS];
}Gpt_PreDefinedTimerConfigType;

typedef struct
{
	Gpt_TimerConfigType Gpt_ConfigurationArray[GPT_NUMBER_OF_CONFIGURED_TIMERS];
	
}Gpt_ConfigType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* GPT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Types.h
 *********************************************************************************************************************/
