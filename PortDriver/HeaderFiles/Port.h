/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  <Port.h>
*       Module:  -
*
*  Description:  <In this file you will find port driver interface>     
*  
*********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H


/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/

/* Defining the company ID in the AUTOSAR */
/* I am using a dummy ID for now */

#define PORT_VENDOR_ID					(2007U)


/* Defining the Module software verison by Major.Minor.Patch format */
#define PORT_SW_MAJOR_VERSION				(1U)
#define PORT_SW_MINOR_VERSION				(0U)
#define PORT_SW_PATCH_VERSION				(0U)

/* Defining the autosar version ued for the module */
#define PORT_AR_RELEASE_MAJOR_VERSION		(4U)
#define PORT_AR_RELEASE_MINOR_VERSION		(0U)
#define PORT_AR_RELEASE_PATCH_VERSION		(3U)


/* Defining the port ID according to autosar and isntance ID*/
#define PORT_MODULE_ID          (124U)
#define PORT_INSTANCE_ID        (0U)




/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "Std_Types.h"
/* checking autosar and software version compatability between port.h and Std_types.h */
#if ((PORT_AR_RELEASE_MAJOR_VERSION     != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
  || ( PORT_AR_RELEASE_MINOR_VERSION     != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
  || ( PORT_AR_RELEASE_PATCH_VERSION     != STD_TYPES_AR_RELEASE_PATCH_VERSION))
#error "The autosar version of Std_types is not matching this module version"
#endif



#include "Port_Cfg.h"   
/* checking autosar and software version compatability between port.h and port_cfg.h */
#if ((PORT_SW_MAJOR_VERSION != PORT_CFG_SW_MAJOR_VERSION)\
||	 (PORT_SW_MINOR_VERSION != PORT_CFG_SW_MINOR_VERSION)\
  ||	 (PORT_SW_PATCH_VERSION != PORT_CFG_SW_PATCH_VERSION))
#error "The software version of Dio_Cfg is not matching this module version"
#endif

#if ((PORT_AR_RELEASE_MAJOR_VERSION != PORT_CFG_AR_RELEASE_MAJOR_VERSION)\
||	 (PORT_AR_RELEASE_MINOR_VERSION != PORT_CFG_AR_RELEASE_MINOR_VERSION)\
  ||	 (PORT_AR_RELEASE_PATCH_VERSION != PORT_CFG_AR_RELEASE_PATCH_VERSION))
#error "The autosar version of Std_types is not matching this module version"
#endif



#include "Port_Types.h" 
/* checking autosar and software version compatability between port.h and port_types.h */
#if ((PORT_SW_MAJOR_VERSION != PORT_TYPES_SW_MAJOR_VERSION)\
||	 (PORT_SW_MINOR_VERSION != PORT_TYPES_SW_MINOR_VERSION)\
  ||	 (PORT_SW_PATCH_VERSION != PORT_TYPES_SW_PATCH_VERSION))
#error "The autosar version of Dio_Cfg is not matching this module version"
#endif

#if ((PORT_AR_RELEASE_MAJOR_VERSION != PORT_TYPES_AR_RELEASE_MAJOR_VERSION)\
||	 (PORT_AR_RELEASE_MINOR_VERSION != PORT_TYPES_AR_RELEASE_MINOR_VERSION)\
  ||	 (PORT_AR_RELEASE_PATCH_VERSION != PORT_TYPES_AR_RELEASE_PATCH_VERSION))
#error "The autosar version of Port_types is not matching this module version"
#endif



/**********************************************************************************************************************
*  GLOBAL FUNCTION PROTOTYPES
*********************************************************************************************************************/
/*This functions initializes the GPIO port*/
void Port_Init(const Port_ConfigType * ConfigPtr);
/* This function sets the pin direction to input/output*/
void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction); 
/* This function refresh the mode of all pins whose mode is not changeable during runtime*/
void Port_RefreshPortDirection(void); 
/*This function is used to get version info of the module*/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
/* This functions sets the pinMode of the pin*/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
/**********************************************************************************************************************
*  GLOBAL DATA TYPES AND STRUCTURES
***********************************************************************************************************************/





/******************************************************************************
*                      API Service Id Macros                                 *
******************************************************************************/
/* Service ID for Port_Init */
#define PORT_INIT_SID          						((uint8)0x00)

/* Service ID for Port_SetPinDirection */
#define PORT_SET_PIN_DIRECTION_SID         			        ((uint8)0x01)

/* Service ID for Port_RefreshPortDirection */
#define PORT_REFRESH_PORT_DIRECTION_SID          	                ((uint8)0x02)

/* Service ID for Port_GetVersionInfo */
#define PORT_GET_VERSION_INFO_SID           		                ((uint8)0x03)

/* Service ID for Port Initialize */
#define PORT_SET_PIN_MODE_SID           			        ((uint8)0x04)






/*******************************************************************************
*                      DET Error Codes                                        *
*******************************************************************************/

/*DET code for Invalid Port Pin ID requested*/
#define PORT_E_PARAM_PIN						0x0A	

/*DET code Port Pin not configured as changeable*/
#define PORT_E_DIRECTION_UNCHANGEABLE			                0x0B

/*DET code API Port_Init service called with wrong parameter*/
#define PORT_E_PARAM_CONFIG						0x0C

/*DET code API Port_SetPinMode service called when mode is unchangeable.*/
#define PORT_E_PARAM_INVALID_MODE				        0x0D

/*DET code API Port_SetPinMode service called when mode is unchangeable.*/
#define PORT_E_MODE_UNCHANGEABLE				        0x0E

/*DET code API service called without module initialization*/
#define PORT_E_UNINIT							0x0F

/*DET code APIs called with a Null Pointer*/
#define PORT_E_PARAM_POINTER					        0x10






/*******************************************************************************
*                       External Variables                                    *
*******************************************************************************/
/* extern the port configurations array */
extern Port_ConfigType Port_Configuration;










#endif  /* PORT_H_ */

/**********************************************************************************************************************
*  END OF FILE: Port.h
*********************************************************************************************************************/
