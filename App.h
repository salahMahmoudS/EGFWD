 /******************************************************************************
 *
 * Module: Common - Compiler Abstraction
 *
 * File Name: App.h
 *
 * Description:  This file contains the definitions and macros specified by
 *               AUTOSAR for the abstraction of compiler specific keywords.
 *
 * Author: Salah Mahmoud
 *
 *******************************************************************************/


#ifndef APP_H
#define APP_H

#include "Std_Types.h"
#include "Port.h"
#include "NVIC.h"
#include "Dio.h"
#include "Gpt.h"
#include "EventRecorder.h"

/*
 * Module Version 1.0.0
 */
#define COMPILER_SW_MAJOR_VERSION                           (1U)
#define COMPILER_SW_MINOR_VERSION                           (0U)
#define COMPILER_SW_PATCH_VERSION                           (0U)

#define APP_LED_ON_SECONDS  (2U)
#define APP_LED_OFF_SECONDS (2U)

/*Variable containing current ontime */
static uint8 App_LedOnTime = 0;
/*Variable containing current offtime */
static uint8 App_LedOffTime = 0;

/*********************************Function protoypes *************************/

/* Function to initialize and start the Application */
void App_Start(void);
/* Function to set the on time for the led */
void Led_SetOnTime(uint8 desiredOnTime);
/* Function to set the offtime for the led */
void Led_SetOfTime(uint8 desiredOffTime);
void App_UpdateLedOnTime(uint8 UpdatedTime);
void App_UpdateLedOffTime(uint8 UpdatedTime);
uint8 App_getLedOnTime();
uint8 App_getLedOffTime();

#endif
