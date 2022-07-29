/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <NVIC_Config.h>
 *       Module:  -
 *
 *  Description:  This file allows you to configure the Nested vector interrupt control with below configurations:   
 *	-number of ENABLED Interrupts  
 *	-Define the group priority field
 *
 *
 *
 *********************************************************************************************************************/
#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**************************************interrupt priority levels***************
* DESCRIPTION: Configuring the below allows user to choose interrupt priority levels. allowed values are below 
NVIC_INTERRUPT_GROUPING_XXX 	Allows user to configure priority groups as Groups/Groups/Groups
NVIC_INTERRUPT_GROUPING_XXY		Allows user to configure priority groups as Groups/Groups/Sub-Groups
NVIC_INTERRUPT_GROUPING_XYY		Allows user to configure priority groups as Groups/Sub-Groups/Sub-Groups
NVIC_INTERRUPT_GROUPING_YYY		Allows user to configure priority groups as Sub-Groups/Sub-Groups/Sub-Groups
*/
#define NVIC_INTERRUPT_PRIORITY_LEVELS 	NVIC_INTERRUPT_GROUPING_XYY
/*************************************************************************************/


/**************************************Number of Enabled interrupts***************
* DESCRIPTION: Configuring the below allows user to configure number of interrupts he wishes to enable. default value is 0 
, if users wants to enable 2 interrupts set the below value to 2
 interrupts to be enabled configuration is in file NVIC_ConfigL.c
*/
#define NVIC_NUMBER_OF_ENABLED_INTERUPTS 4

/*************************************************************************************/




 
#endif  /* NVIC_CONFIG_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
