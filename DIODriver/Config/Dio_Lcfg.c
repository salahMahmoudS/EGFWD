/**********************************************************************************************************************
*  FILE DESCRIPTION
*  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio_Lcfg.c
*        \brief  Link time Configuration Source file for TM4C123GH6PM Microcontroller - Dio Driver
*
*      \details  
*
*
*********************************************************************************************************************/

/* Defining the Module software verison by Major.Minor.Patch format */
/* Module 1.0.0 */

#define DIO_LCFG_SW_MAJOR_VERSION				(1U)
#define DIO_LCFG_SW_MINOR_VERSION				(0U)
#define DIO_LCFG_SW_PATCH_VERSION				(0U)

/* Defining the autosar version ued for the module */
/* Autosar version 4.0.3 */
#define DIO_LCFG_AR_RELEASE_MAJOR_VERSION		        (4U)
#define DIO_LCFG_AR_RELEASE_MINOR_VERSION		        (0U)
#define DIO_LCFG_AR_RELEASE_PATCH_VERSION		        (3U)


/* Checking for software version compitability */
/* Checking for autosar veriosn compitability */
/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "Dio.h"

/* checking autosar and software version compatability between port.h and port_cfg.h */
#if ((DIO_LCFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
||   (DIO_LCFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
||   (DIO_LCFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
#error "The software version of Dio.h is not matching this module version"
#endif

#if ((DIO_LCFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
||   (DIO_LCFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
  || (DIO_LCFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
#error "The autosar version of Dio.h is not matching this module version"
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
/*Std_ReturnType FunctionName(AnyType parameterName)
{


}
*/
/**********************************************************************************************************************
*  END OF FILE: FileName.c
*********************************************************************************************************************/
