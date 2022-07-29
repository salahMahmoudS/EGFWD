/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  Det.h
*       Module:  Common
*
*  Description:  this file contains all prototypes and interface details of Det module   
*  Author: Salah Mahomud
*  
*********************************************************************************************************************/
#ifndef DET_H
#define DET_H

/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/

/*Defining the Module software version by Major.Minor.Patch format */

#define DET_SW_MAJOR_VERSION		(1U)
#define DET_SW_MINOR_VERSION		(0U)
#define DET_SW_PATCH_VERSION		(0U)

#include "Std_Types.h"


/**********************************************************************************************************************
*  GLOBAL DATA PROTOTYPES
*********************************************************************************************************************/
extern uint16 Det_ModuleId;             /* The DET driver ID*/
extern uint8 Det_InstanceId;           /* The DET driver instance ID*/
extern uint8 Det_ApiId;              /* The DET Api (function) ID*/
extern uint8 Det_ErrorId;             /* The DET error code*/


/**********************************************************************************************************************
*  GLOBAL FUNCTION PROTOTYPES
*********************************************************************************************************************/
Std_ReturnType Det_ReportError  ( uint16 ModuleId,
                                 uint8 InstanceId,
                                 uint8 ApiId,
                                 uint8 ErrorId
                                   );

boolean Det_TestLastReportError(uint16 ModuleId, 
                                uint8 InstanceId, 
                                uint8 ApiId, 
                                uint8 ErrorId);

#endif  /* DET_H */

/**********************************************************************************************************************
*  END OF FILE: Det.h
*********************************************************************************************************************/
