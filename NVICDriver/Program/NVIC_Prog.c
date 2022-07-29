/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  NVIC_Prog.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TM4C123GH6PM_Hw.h"
#include "NVIC.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
NVIC_InterruptLocation NVIC_InterruptVTRegMapper(uint8 interruptType);		//this function takes interrupt number and returns the interrupt Register and interrupt bit offset

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
#if (NVIC_INTERRUPT_PRIORITY_LEVELS == NVIC_INTERRUPT_GROUPING_XXX)
	#define priorityGroupMaxvalue 		7
	#define prioritySubGroupMaxvalue 	0
	#define gShiftValue								0
#elif (NVIC_INTERRUPT_PRIORITY_LEVELS == NVIC_INTERRUPT_GROUPING_XXY)
	#define priorityGroupMaxvalue 		3
	#define prioritySubGroupMaxvalue 	1
	#define gShiftValue								1
#elif (NVIC_INTERRUPT_PRIORITY_LEVELS == NVIC_INTERRUPT_GROUPING_XYY)
	#define priorityGroupMaxvalue 		1
	#define prioritySubGroupMaxvalue 	3
	#define gShiftValue								2

#elif (NVIC_INTERRUPT_PRIORITY_LEVELS == NVIC_INTERRUPT_GROUPING_YYY)
	#define priorityGroupMaxvalue 		0
	#define prioritySubGroupMaxvalue 	7
	#define gShiftValue								3

	#endif
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern NVIC_interruptConfigStructure NVIC_interruptConfiguration[NVIC_NUMBER_OF_ENABLED_INTERUPTS];
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
* \Syntax          : uint8 NVIC_Init(void)        
* \Description     : This function intializes the NVIC module from the given configuration                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  NVIC_SUCCESS
*                                    NVIC_FAIL                                  
*******************************************************************************/


void NVIC_Init(void)
{
	
	/***********************Manually setting up Application interrupt and reset control until driver implementation****/
	
		APINT =(uint32) (((uint32)0x05FA<<16)|((uint32)NVIC_INTERRUPT_PRIORITY_LEVELS<<8)); //Unlock key and the priority grouping in config file
	
	/******************************************************************************************************************/
	
for (uint8 i=0;i<NVIC_NUMBER_OF_ENABLED_INTERUPTS;i++)			//looping on all interrupts configured by user
	{
		NVIC_SetEnableInterrupt(NVIC_interruptConfiguration[i].interruptVTValue);		//enable each configured interrupt
		NVIC_SetInterruptPriority(NVIC_interruptConfiguration[i]);									//set its priorirty			
	}
return;
}	

/******************************************************************************
* \Syntax          : uint8 NVIC_SetEnableInterrupt(uint8 interruptVTValue)        
* \Description     : This function enables the interrupts configured from NVIC_ConfigL.c
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : uint8 interruptVTvalue                     
* \Parameters (out): None                                                      
* \Return value:   : NVIC_SUCCESS;
*									   NVIC_ERROR;
										 NVIC_FAIL
*                                                                      
*******************************************************************************/


uint8 NVIC_SetEnableInterrupt(uint8 interruptVTValue)
{
	NVIC_InterruptLocation resultLocationOfInterrupt;					//local variable containing register number and bitoffset
	resultLocationOfInterrupt= NVIC_InterruptVTRegMapper(interruptVTValue);
	
	switch(resultLocationOfInterrupt.registerNumber)	//enable interrupt 
	{
		case 0: SET_BIT(EN0,resultLocationOfInterrupt.bitOffset); break;
		case 1: SET_BIT(EN1,resultLocationOfInterrupt.bitOffset); break;
		case 2: SET_BIT(EN2,resultLocationOfInterrupt.bitOffset); break;
		case 3: SET_BIT(EN3,resultLocationOfInterrupt.bitOffset); break;
		case 4: 
		if (resultLocationOfInterrupt.bitOffset>10)
		{
			return NVIC_ERROR;
		}
		else{
		SET_BIT(EN4,resultLocationOfInterrupt.bitOffset); break;

		}
				default: return NVIC_FAIL;
	}
	return NVIC_SUCCESS;
}	

uint8 NVIC_DisableInterrupt(uint8 interruptVTValue)
{//WARNING:Not yet tested
	NVIC_InterruptLocation resultLocationOfInterrupt;
	resultLocationOfInterrupt= NVIC_InterruptVTRegMapper(interruptVTValue);
	
	switch(resultLocationOfInterrupt.registerNumber)
	{
		case 0: SET_BIT(DIS0,resultLocationOfInterrupt.bitOffset); break;
		case 1: SET_BIT(DIS1,resultLocationOfInterrupt.bitOffset); break;
		case 2: SET_BIT(DIS2,resultLocationOfInterrupt.bitOffset); break;
		case 3: SET_BIT(DIS3,resultLocationOfInterrupt.bitOffset); break;
		case 4: 
		if (resultLocationOfInterrupt.bitOffset>10)
		{
			return NVIC_ERROR;
		}
		else{
		SET_BIT(DIS4,resultLocationOfInterrupt.bitOffset); break;

		}
				default: return NVIC_FAIL;
	}
	return NVIC_SUCCESS;
}
uint8 NVIC_SetInterruptToPending(uint8 interruptVTValue)
{//Not yet tested
	NVIC_InterruptLocation resultLocationOfInterrupt;
	resultLocationOfInterrupt= NVIC_InterruptVTRegMapper(interruptVTValue);
	
	switch(resultLocationOfInterrupt.registerNumber)
	{
		case 0: SET_BIT(PEND0,resultLocationOfInterrupt.bitOffset); break;
		case 1: SET_BIT(PEND1,resultLocationOfInterrupt.bitOffset); break;
		case 2: SET_BIT(PEND2,resultLocationOfInterrupt.bitOffset); break;
		case 3: SET_BIT(PEND3,resultLocationOfInterrupt.bitOffset); break;
		case 4: 
		if (resultLocationOfInterrupt.bitOffset>10)
		{
			return NVIC_ERROR;
		}
		else{
		SET_BIT(PEND4,resultLocationOfInterrupt.bitOffset); break;

		}
				default: return NVIC_FAIL;
	}
	return NVIC_SUCCESS;
}

uint8 NVIC_ClearPendingInterrupt(uint8 interruptVTValue)
{//Not yet tested
	NVIC_InterruptLocation resultLocationOfInterrupt;
	resultLocationOfInterrupt= NVIC_InterruptVTRegMapper(interruptVTValue);
	
	switch(resultLocationOfInterrupt.registerNumber)
	{
		case 0: SET_BIT(UNPEND0,resultLocationOfInterrupt.bitOffset); break;
		case 1: SET_BIT(UNPEND1,resultLocationOfInterrupt.bitOffset); break;
		case 2: SET_BIT(UNPEND2,resultLocationOfInterrupt.bitOffset); break;
		case 3: SET_BIT(UNPEND3,resultLocationOfInterrupt.bitOffset); break;
		case 4: 
		if (resultLocationOfInterrupt.bitOffset>10)
		{
			return NVIC_ERROR;
		}
		else{
		SET_BIT(UNPEND4,resultLocationOfInterrupt.bitOffset); break;

		}
				default: return NVIC_FAIL;
	}
	return NVIC_SUCCESS;
}

uint8 NVIC_GetIsPendingInterupt(uint8 interruptVTValue)
{//Not yet tested
	uint8 result;
	NVIC_InterruptLocation resultLocationOfInterrupt;
	resultLocationOfInterrupt= NVIC_InterruptVTRegMapper(interruptVTValue);
	
	switch(resultLocationOfInterrupt.registerNumber)
	{
		
		case 0: result= CHECK_BIT(PEND0,resultLocationOfInterrupt.bitOffset);	break;
		case 1: result= CHECK_BIT(PEND1,resultLocationOfInterrupt.bitOffset);break;
		case 2: result= CHECK_BIT(PEND2,resultLocationOfInterrupt.bitOffset); break;
		case 3: result= CHECK_BIT(PEND3,resultLocationOfInterrupt.bitOffset); break;
		case 4: 
		if (resultLocationOfInterrupt.bitOffset>10)
		{
			return NVIC_ERROR;
		}
		else{
		result= CHECK_BIT(PEND4,resultLocationOfInterrupt.bitOffset); break;

		}
				default: return NVIC_FAIL;
	}
	
	if(result ==1)
	{
		
	return NVIC_IS_PENDING;
	}
	else if (result ==0)
	{
		return NVIC_IS_NOT_PENDING;
	}
	else
	{
		return NVIC_ERROR;
	}
}


uint8 NVIC_SWActivateInterrupt(uint8 interruptVTValue)
{
	if (interruptVTValue<=138)
	{
	SWTRIG = interruptVTValue;
	return NVIC_SUCCESS;
	}
	else
	{
		return NVIC_FAIL;
	}
}


/******************************************************************************
* \Syntax          : uint8 NVIC_SetInterruptPriority(NVIC_interruptConfigStructure desiredInterrupt)        
* \Description     : Tis function set the interrupt priority according to the priority group and subgroup configured in
*										 NVIC_ConfigL.c file
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : NVIC_interruptConfigStructure                     
* \Parameters (out): None                                                      
* \Return value:   : NVIC_SUCCESS;
*									   NVIC_ERROR;
*                                                                      
*******************************************************************************/

uint8 NVIC_SetInterruptPriority(NVIC_interruptConfigStructure desiredInterrupt)
{
	//determining the PRIn register address
	 
	uint32 * regPRInaddress =(uint32*) (CORE_PERIPHERAL_BASE_ADDRESS + 0x400 + (desiredInterrupt.interruptVTValue/4)*4);	
	//check that interrupt group and subgroup are in correct range according to the configuration of NVIC_INTERRUPT_PRIORITY_LEVELS
	if (desiredInterrupt.interruptPriorityLevelGroup<=priorityGroupMaxvalue
				&&desiredInterrupt.interruptPriorityLevelSubGroup<=prioritySubGroupMaxvalue)	
	{
	//steps 1) construct 3 bit number according to the priority group and sub group configuration
	//			2) shift it to the correct byte in the PRIx register according to interrupt number
	//			3) shift 5 to pass the reserved values
		*regPRInaddress |= (uint32)(desiredInterrupt.interruptPriorityLevelSubGroup|desiredInterrupt.interruptPriorityLevelGroup<<gShiftValue)<<((8)*(desiredInterrupt.interruptVTValue%4))<<5; 
	
		return NVIC_SUCCESS;
	
	}
	else
	{
		return	NVIC_ERROR;
	}
		
}


/******************************************************************************
* \Syntax          : NVIC_InterruptLocation NVIC_InterruptVTRegMapper(uint16 interruptType)        
* \Description     : For NVIC operations (ENABLE,DISABLE,GetInterruptStatus, Set interrupt to pending, that use 5
										 Registers to map the vector table. This functions maps the request to one of the  registers and 
										 Determines the bit offset in this register
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : interruptType  The interrupt type from the configurationL file                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  NVIC_InterruptLocation
*                                                                      
*******************************************************************************/


NVIC_InterruptLocation NVIC_InterruptVTRegMapper(uint8 interruptType)
{
	NVIC_InterruptLocation mappedLocationFromInterrupt;
	mappedLocationFromInterrupt.registerNumber = interruptType/32;	//to determine register number
	mappedLocationFromInterrupt.bitOffset=interruptType%32;					// to determine bit offset 
	
	return mappedLocationFromInterrupt;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
