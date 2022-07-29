/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  <Write File Name>
*       Module:  -
*
*  Description:  <Write File DESCRIPTION here>
*	Author: Salah Mahmoud
*  
*********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H



/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/
/* Dio Module Id */
#define DIO_MODULE_ID    (120U)                

/* Dio Instance Id */
#define DIO_INSTANCE_ID  (0U)


/* Defining the company ID in the AUTOSAR */
/* I am using a dummy ID for now */

#define DIO_VENDOR_ID					(2007U)


/* Defining the Module software verison by Major.Minor.Patch format */
/* Module 1.0.0 */

#define DIO_SW_MAJOR_VERSION				(1U)
#define DIO_SW_MINOR_VERSION				(0U)
#define DIO_SW_PATCH_VERSION				(0U)

/* Defining the autosar version ued for the module */
/* Autosar version 4.0.3 */
#define DIO_AR_RELEASE_MAJOR_VERSION		(4U)
#define DIO_AR_RELEASE_MINOR_VERSION		(0U)
#define DIO_AR_RELEASE_PATCH_VERSION		(3U)

/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/

#include "Std_Types.h"


/* checking AUTOSAR compatability */


#if ((DIO_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
  || (DIO_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
  || (DIO_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
#error "The autosar version of Std_types is not matching this module version"
#endif


#include "Dio_Cfg.h"

/* checking AUTOSAR compatability */

/* checking Software version compatability */

#if ((DIO_SW_MAJOR_VERSION != DIO_CFG_SW_MAJOR_VERSION)\
||	 (DIO_SW_MINOR_VERSION != DIO_CFG_SW_MINOR_VERSION)\
  ||	 (DIO_SW_PATCH_VERSION != DIO_CFG_SW_PATCH_VERSION))
#error "The autosar version of Dio_Cfg is not matching this module version"
#endif



/* checking AUTOSAR compatability */

#if ((DIO_AR_RELEASE_MAJOR_VERSION != DIO_CFG_AR_RELEASE_MAJOR_VERSION)\
||	 (DIO_AR_RELEASE_MINOR_VERSION != DIO_CFG_AR_RELEASE_MINOR_VERSION)\
  ||	 (DIO_AR_RELEASE_PATCH_VERSION != DIO_CFG_AR_RELEASE_PATCH_VERSION))
#error "The autosar version of Dio_Cfg is not matching this module version"
#endif




#include "Dio_Types.h"


/* checking Software version compatability */

#if ((DIO_SW_MAJOR_VERSION != DIO_TYPES_SW_MAJOR_VERSION)\
||	 (DIO_SW_MINOR_VERSION != DIO_TYPES_SW_MINOR_VERSION)\
  ||	 (DIO_SW_PATCH_VERSION != DIO_TYPES_SW_PATCH_VERSION))
#error "The autosar version of Dio_types is not matching this module version"
#endif



/* checking AUTOSAR compatability */

#if ((DIO_AR_RELEASE_MAJOR_VERSION != DIO_TYPES_AR_RELEASE_MAJOR_VERSION)\
||	 (DIO_AR_RELEASE_MINOR_VERSION != DIO_TYPES_AR_RELEASE_MINOR_VERSION)\
  ||	 (DIO_AR_RELEASE_PATCH_VERSION != DIO_TYPES_AR_RELEASE_PATCH_VERSION))
#error "The autosar version of Dio_types is not matching this module version"
#endif





/*
* Macros for module Status
*/
#define DIO_INITIALIZED                ((uint8) 0x01)
#define DIO_NOT_INITIALIZED            ((uint8) 0x00)




/**********************************************************************************************************************
*  GLOBAL FUNCTION PROTOTYPES
*********************************************************************************************************************/
/* Service to initialize Dio driver   */
void Dio_Init(const Dio_ConfigType* ConfigPtr);
/* Service to set level of a channel during runtime    */
void Dio_WriteChannel(Dio_ChannelType pinNumber, Dio_LevelType Level);
/* Service to read level of a channel during runtime      */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel */
#if (DIO_FLIP_CHANNEL_API  == (STD_ON))
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#else
/* Do nothing*/
#endif

/* Service to set value of a port during runtime    */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
/*Service to read level of a port during runtime    */
Dio_PortLevelType Dio_ReadPort(Dio_PortType portId); 

/*This function is used to get version info of the module*/
void Dio_GetVersionInfo( Std_VersionInfoType* versioninfo );
/******************************************************************************
*                      API Service Id Macros                                 *
******************************************************************************/

/* Service ID for DIO read channel */
#define DIO_READ_CHANNEL_SID          	 	((uint8)0x00)

/* Service ID for DIO write channel */
#define DIO_WRITE_CHANNEL_SID           	((uint8)0x01)

/* Service ID for DIO read port */
#define DIO_READ_PORT_SID           		((uint8)0x02)

/* Service ID for DIO write port */
#define DIO_WRITE_PORT_SID           		((uint8)0x03)

/* Service ID for DIO read channel group */
#define DIO_READ_CHANNEL_GROUP_SID              ((uint8)0x04)

/* Service ID for DIO write channel group */
#define DIO_WRITE_CHANNEL_GROUP_SID    		((uint8)0x05)

/* Service ID to get version information */
#define DIO_GET_VERSION_INFO_SID          	((uint8)0x12)

/* Service ID to intialize DIO driver */
#define DIO_INIT_SID          			((uint8)0x10)

/* Service ID to intialize DIO driver */
#define DIO_FLIP_CHANNEL_SID          		((uint8)0x11)


/*******************************************************************************
*                      DET Error Codes                                        *
*******************************************************************************/

/* DET code for Invalid channel name requested */
#define DIO_E_PARAM_INVALID_CHANNEL_ID				        ((uint8) 0x0A)	

/* DET code for API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG					        ((uint8)0x10)			

/* DET code for Invalid port name requested */
#define DIO_E_PARAM_INVALID_PORT_ID					((uint8)0x14)			

/* DET code for Invalid ChannelGroup */
#define DIO_E_PARAM_INVALID_GROUP					((uint8)0x1F)

/* DET code for service called with a NULL pointer */
/* The API service shall return immediately without any further action,
* beside reporting this development error.
*/
#define DIO_E_PARAM_POINTER						((uint8)0x20)

/*
* API service used without module initialization is reported using following
* error code (Not exist in AUTOSAR 4.0.3 DIO SWS Document.
*/
#define DIO_E_UNINIT                   				((uint8)0xF0)




/*******************************************************************************
*                              Module Data Types                              *
*******************************************************************************/









/*******************************************************************************
*                      Function Prototypes                                    *
*******************************************************************************/











/*******************************************************************************
*                       External Variables                                    *
*******************************************************************************/

extern const Dio_ConfigType Dio_Configuration;


#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
*  END OF FILE: Std_Types.h
*********************************************************************************************************************/





