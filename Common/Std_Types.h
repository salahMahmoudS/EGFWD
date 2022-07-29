
/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  Std_Types
*       Module:  Common
*
*  Description:  This file defines the std type that are used accross the project in common folder     
*  Author: Salah Mahmoud 
*
*********************************************************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H


/**********************************************************************************************************************
*  SOFTWARE AND AUTOSAR VERSIONS
*********************************************************************************************************************/


/* Defining the company ID in the AUTOSAR */
/* I am using a dummy ID for now */

#define COMPILER_VENDOR_ID					(2007U)


/* Defining the Module software verison by Major.Minor.Patch format */

#define STD_TYPES_SW_MAJOR_VERSION			(1U)
#define STD_TYPES_SW_MINOR_VERSION			(0U)
#define STD_TYPES_SW_PATCH_VERSION			(0U)

/* Defining the autosar version ued for the module */

#define STD_TYPES_AR_RELEASE_MAJOR_VERSION		(4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION		(0U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION		(3U)


/**********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
/*TODO add checker on version and autosar on compiler.h */
#include "Compiler.h"
#include "Common_Macros.h"
/**********************************************************************************************************************
*  GLOBAL DATA TYPES AND STRUCTURES
*********************************************************************************************************************/
/*define signed char as int8 */
typedef char sint8;					
/*define unsigned char as boolean         */
typedef unsigned char boolean;   
/*define unsigned char as uint8           */
typedef unsigned char uint8;
/*define signed short as sint16            */
typedef short sint16;	
/*define unsigned short as uint16         */
typedef unsigned short uint16;
/*define signed long as sint32             */
typedef long sint32;	
/*define unsigned long as uint32          */
typedef unsigned long uint32;		                
typedef long long sint64;
/*define signed loong long as int64       */
typedef unsigned long long uint64;	
/*define unsigned long long as uint64     */
typedef float float32;	
/*define float as f32                     */
typedef double float64;		

/* define std_returnType */
typedef uint8 Std_ReturnType;

/* structure contains version info of a specific module */
typedef struct
{
  uint16 vendorID;
  uint16 moduleID;
  uint8 sw_major_version;
  uint8 sw_minor_version;
  uint8 sw_patch_version;
} Std_VersionInfoType;

/*
* Boolean Values
*/
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif


#define STD_HIGH        (0x01U)    /*physical state 5V or 3.3V */
#define STD_LOW         (0x00U)    /*physical state 0V */

#define STD_ACTIVE      (0x01U)    /* Logical state active */
#define STD_IDLE        (0x00U)    /* Logical state idle */ 

#define STD_ON          (0x01U)    /* Logical state ON */
#define STD_OFF         (0x00U)    /* Logical state OFF */

#define E_OK			((Std_ReturnType)(0x00U))
#define E_NOT_OK		((Std_ReturnType)(0x01U))

#endif  /* STD_TYPES_H */

/**********************************************************************************************************************
*  END OF FILE: Std_Types.h
*********************************************************************************************************************/
