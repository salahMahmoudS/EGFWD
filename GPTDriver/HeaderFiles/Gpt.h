/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Gpt.h>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/*TODO add compatability checks*/
#include "Std_Types.h"
#include "Gpt_cfg.h"
#include "Gpt_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const Gpt_ConfigType Gpt_Configuration;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 
*********************************************************************************************************************/
/* Functions initializes timer driver */
void Gpt_Init(const Gpt_ConfigType * ConfigPtr);
/* Function to disable interrupts for timer channel */
void Gpt_DisableNotification (Gpt_ChannelType Channel);
/*Function to enable notification for timer channel */
void Gpt_EnableNotification (Gpt_ChannelType Channel);
/* Function to clear interupt flag for certain channel */
void Gpt_ClearInterruptFlag (Gpt_ChannelType Channel);
/* Function to start timer and load it Load Register value */
void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType value);
/* Function to stop running timer */
void Gpt_StopTimer(Gpt_ChannelType Channel);
/* function to get elapsed time for a certain timer channel */
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
/* function to get time remaining in a certain timer channel */
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
/* Function to get predefine timer timer value */
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PreDefTimerType PredefTimer,uint32* TimerValuePtr);
/* Function triggers Notification for each timer chanel */
void Gpt_Notification_Timer0(void);
void Gpt_Notification_Timer1(void);
void Gpt_Notification_Timer2(void);
void Gpt_Notification_Timer3(void);
void Gpt_Notification_Timer4(void);
void Gpt_Notification_Timer5(void);
void Gpt_Notification_Timer6(void);
void Gpt_Notification_Timer7(void);
void Gpt_Notification_Timer8(void);
void Gpt_Notification_Timer9(void);
void Gpt_Notification_Timer10(void);
void Gpt_Notification_Timer11(void);





/*TODO*/

/*******************************************************************

//Planned to be implemented functions to comply with AUTOSAR

void Gpt_GetVersionInfo(Std_VersionInfoType* VersionInfoPtr);
void Gpt_DeInit(void);
void Gpt_SetMode(Gpt_ModeType Mode);
void Gpt_DisableWakeup(Gpt_ChannelType Channel);
void Gpt_EnableWakeup(Gpt_ChannelType Channel);
void Gpt_CheckWakeup(Gpt_ChannelType Channel);

*******************************************************************/

#endif  /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
