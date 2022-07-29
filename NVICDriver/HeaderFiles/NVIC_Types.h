/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef NVIC_TYPES_H_
#define NVIC_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 
 
 *********************************************************************************************************************/
#define SCB_APINT_KEY					0x05FA	

typedef struct 
{
	uint8 registerNumber;
	uint8 bitOffset;
}NVIC_InterruptLocation;






/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/



/*************defining interrupt priority levels*******************************************************************/
#define 	NVIC_INTERRUPT_GROUPING_XXX		0x4
#define 	NVIC_INTERRUPT_GROUPING_XXY		0x5
#define 	NVIC_INTERRUPT_GROUPING_XYY		0x6
#define 	NVIC_INTERRUPT_GROUPING_YYY		0x7
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* NVIC_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
