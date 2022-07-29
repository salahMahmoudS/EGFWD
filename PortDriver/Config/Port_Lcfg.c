/**********************************************************************************************************************
*  FILE DESCRIPTION
*  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_Lcfg.c
*        \brief  Link time Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
*
*      \details  
*       Author: Salah Mahmoud
*
*********************************************************************************************************************/


/* Defining the Module software verison by Major.Minor.Patch format */
/* Module 1.0.0 */

#define PORT_LCFG_SW_MAJOR_VERSION				(1U)
#define PORT_LCFG_SW_MINOR_VERSION				(0U)
#define PORT_LCFG_SW_PATCH_VERSION				(0U)

/* Defining the autosar version ued for the module */
/* Autosar version 4.0.3 */
#define PORT_LCFG_AR_RELEASE_MAJOR_VERSION		        (4U)
#define PORT_LCFG_AR_RELEASE_MINOR_VERSION		        (0U)
#define PORT_LCFG_AR_RELEASE_PATCH_VERSION		        (3U)


/* Checking for software version compitability */
/* Checking for autosar veriosn compitability */
/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "Port.h"

/* checking autosar and software version compatability between port.h and port_cfg.h */
#if ((PORT_LCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
||   (PORT_LCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
||   (PORT_LCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The software version of Port.h is not matching this module version"
#endif

#if ((PORT_LCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
||   (PORT_LCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
  || (PORT_LCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The autosar version of Port.h is not matching this module version"
#endif


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
*  LOCAL DATA 
*********************************************************************************************************************/

/**********************************************************************************************************************
*  GLOBAL DATA
*********************************************************************************************************************/

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
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

/**********************************************************************************************************************
*  END OF FILE: FileName.c
*********************************************************************************************************************/
