/******************************************************************************
*
* Module: ModuleTest
*
* File Name: Port_ModuleTest.c
*
* Description: Source file for the Port Test Cases.
*
* Author: Salah Mahmoud
******************************************************************************/
#include <assert.h>
#include "Port.h"
#include "Dio.h"
#include "Det.h"
#include "TM4C123GH6PM_HW.h"

/* assert is like an if condition but it makes a run time error when condition is false */
/* This can be a variable or any C expression. If expression evaluates to TRUE, assert() does nothing. 
If expression evaluates to FALSE, assert() displays an error message on stderr (standard error stream
to display error messages and diagnostics) and aborts program execution.*/

#define PORT_INVALID_PIN_INDEX 99


/************************************************************************************
* Test ID :TestCase1 (Write here test case name)
* Description: Write here test case description, when error should be called 
*              example:(Test for Write, Read and Flip Channel API's report a DIO_E_UNINIT DET 
*              error in case the Dio_Init is not called yet.)
*
* Pre-requisits:  Write here all prequisites to make this test case trigger error
*                  example: (Dio Module is not initialized before Run this test case.)
*
* Test Procedure : Write the test case steps and expected results 
*                  example: 
*                 (1. Call Dio_WriteChannel DET error DIO_E_UNINIT should be reported.
*                  2. Call Dio_ReadChannel DET error DIO_E_UNINIT should be reported.
*                  3. Call Dio_FlipChannel DET error DIO_E_UNINIT should be reported.)
*************************************************************************************/

/*
PortConf_LED1_PIN_ID_INDEX              PF1
PortConf_LED2_PIN_ID_INDEX              PF2
PortConf_SW1_PIN_ID_INDEX               PF4
PortConf_SW2_PIN_ID_INDEX               PF0
*/

/************************************************************************************
* Test ID :Port_TestCase1 
* Description: Test for SetPinDirection, SetPinMode, RefreshPortDirection and GetVersionInfo APIs report a PORT_E_UNINIT DET
*              error in case the Port_Init is not called yet.
*
* Pre-requisits:  Port Module is not initialized before Run this test case.
*
* Test Procedure : 
*                  1. Call SetPinDirection DET error PORT_E_UNINIT  should be reported.
*                  2. Call SetPinMode DET error PORT_E_UNINIT  should be reported.
*                  3. Call GetVersionInfo DET error PORT_E_UNINIT  should be reported.
*                  4. Call RefreshPortDirection DET error PORT_E_UNINIT  should be reported.
*************************************************************************************/
void Port_TestCase1 (void)
{
  
  
#if (PORT_SET_PIN_DIRECTION_API  == (STD_ON))
  
  Port_SetPinDirection(PortConf_LED1_PIN_ID_INDEX,PORT_PIN_IN);
  
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_UNINIT));
#else
  /*Do nothing */
#endif
  
  
#if (PORT_SET_PIN_MODE_API == (STD_ON))
  
  Port_SetPinMode(PortConf_SW1_PIN_ID_INDEX,PORT_PF4_DIO);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE_SID,PORT_E_UNINIT));
#else
  /*Do nothing*/
#endif
  
  
#if (PORT_GET_VERSION_INFO_API	==(STD_ON))
  Std_VersionInfoType testVersionInfo;
  Port_GetVersionInfo(&testVersionInfo);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_GET_VERSION_INFO_SID,PORT_E_UNINIT));
#else
  /* Do nothing*/
#endif
  
  Port_RefreshPortDirection();
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_REFRESH_PORT_DIRECTION_SID,PORT_E_UNINIT));
  
}

/************************************************************************************
* Test ID :TestCase2
* Description: Test for Port_Init API reports the correct DET 
*              error in case the API called with NULL pointer.
* Pre-requisits: No Need
* Test Procedure : Call Port_Init DET error PORT_E_PARAM_CONFIG should be reported.
*************************************************************************************/
void Port_TestCase2(void)
{
  
  Port_Init(NULL_PTR);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_INIT_SID,PORT_E_PARAM_CONFIG));
  
  
}
/************************************************************************************
* Test ID :TestCase3
* Description: Test for Port_GetVersionInfo API reports the correct DET 
*              error in case the API called with NULL pointer.
* Pre-requisits: No Need
* Test Procedure : Call Port_GetVersionInfo DET error PORT_E_PARAM_POINTER should be reported.
*************************************************************************************/
void Port_TestCase3(void)
{
#if (PORT_VERSION_INFO_API == STD_ON)
  
  Port_GetVersionInfo(NULL_PTR);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_GET_VERSION_INFO_SID,PORT_E_PARAM_POINTER));
#else
  /* Do nothing */ 
#endif
  
}

/************************************************************************************
* Test ID :Port_TestCase4
* Description: Test for SetPinDirection and SetPinMode APIs report a 
*              PORT_E_PARAM_INVALID_PIN DET error in case invalid Pin ID.
* Pre-requisits: Port Module is initialized before Run this test case.
* Test Procedure : 1. Call Port_SetPinDirection with invalid Pin index, DET error PORT_E_PARAM_PIN 
*                     should be reported.
*                  2. Call Port_SetPinMode DET error PORT_E_PARAM_PIN 
*                     should be reported.
*************************************************************************************/
void Port_TestCase4(void)
{
#if (PORT_SET_PIN_DIRECTION_API  == (STD_ON))
  
  Port_SetPinDirection(PORT_INVALID_PIN_INDEX,PORT_PIN_IN);
  
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_PARAM_PIN));
#else
  /*Do nothing */
#endif
  
  
#if (PORT_SET_PIN_MODE_API == (STD_ON))
  
  Port_SetPinMode(PORT_INVALID_PIN_INDEX,PORT_PF4_DIO);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_MODE_SID,PORT_E_PARAM_PIN));
#else
  /*Do nothing*/
#endif
  
}

/************************************************************************************
* Test ID :Port_TestCase5
* Description: Test for GetVersionInfo API functionality.
* Pre-requisits: No Need
* Test Procedure : Call Port_GetVersionInfo and get the required information.
*************************************************************************************/

void Port_TestCase5(void)
{
  #if (PORT_VERSION_INFO_API == STD_ON)
  Std_VersionInfoType Version_Info;
  Port_GetVersionInfo(&Version_Info);
  assert(Version_Info.vendorID == PORT_VENDOR_ID);
  assert(Version_Info.moduleID == PORT_MODULE_ID);
  assert(Version_Info.sw_major_version == PORT_SW_MAJOR_VERSION);
  assert(Version_Info.sw_minor_version == PORT_SW_MINOR_VERSION);
  assert(Version_Info.sw_patch_version == PORT_SW_PATCH_VERSION);
#else
  /* Do nothing */
#endif
}

/************************************************************************************
* Test ID :Port_TestCase6
* Description: Test for SetPinDirection. API reports PORT_E_DIRECTION_UNCHANGEABLE in case
*               API is trying to call a pin whose direction configuration is unchangeable.
* Pre-requisits: Dio Module is initialized before Run this test case.
* Test Procedure : 1. call Port_SetPinDirection for pin with unchangeable direction configuration, DET error 
*                     PORT_E_DIRECTION_UNCHANGEABLE should be returned.
*************************************************************************************/
void Port_TestCase6(void)
{
  Port_SetPinDirection(PortConf_LED1_PIN_ID_INDEX,PORT_PIN_IN);
  assert(Det_TestLastReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_DIRECTION_UNCHANGEABLE));
  
}

/************************************************************************************
* Test ID :Port_TestCase7
* Description: Test for refreshing the port pins.
* Pre-requisits: Port Module is initialized before Run this test case.
* Test Procedure : 1. Change configuration of configurations array pin.
*                  2. Call Port_RefreshPortDirection should change the corresponding value in the direction register
*************************************************************************************/
void Port_TestCase7(void)
{
  Port_Configuration.ConfiguredPinsArray[0].PortPinDirection = PORT_PIN_OUT;
  Port_RefreshPortDirection();
}



int main(void)
{
  /* Run the First Test Case */
  Port_TestCase1();
  
  /* Run the Second Test Case */
  Port_TestCase2();
  
  /* Initailize PF0, PF1, PF2 and PF4 as GPIO pins */
  Port_Init(&Port_Configuration);
    
  /* Run the Third Test Case */
  Port_TestCase3();
  
#if (PORT_VERSION_INFO_API == STD_ON)
  /* Run the Forth Test Case */
  Port_TestCase4();
#endif
  
  /* Run the Fifth Test Case */
  Port_TestCase5();
  
  /* Run the Sixth Test Case */
  Port_TestCase6();
  
  /* Run the Sixth Test Case */
  Port_TestCase7();
  
}
