/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  NVIC_ConfigL.c
 *        \brief  This file contains configurable structures in NVIC driver
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "NVIC_Types.h"
#include "NVIC_Cfg.h"
#include "NVIC.h"

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
* \Structure       : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/



/*******************************Expand for all vector interrupts in Vector table VT types***********************************************

*   INTERRUPT_VT_GPIO_PORT_A					
	INTERRUPT_VT_GPIO_PORT_B					
	INTERRUPT_VT_GPIO_PORT_C					
	INTERRUPT_VT_GPIO_PORT_D					
	INTERRUPT_VT_GPIO_PORT_E					
	INTERRUPT_VT_UART0							
	INTERRUPT_VT_UART1							
	INTERRUPT_VT_SSI0							
	INTERRUPT_VT_I2C0							
	INTERRUPT_VT_PWM0_FAULT						
	INTERRUPT_VT_PWM0_GENERATOR_0				
	INTERRUPT_VT_PWM0_GENERATOR_1				
	INTERRUPT_VT_PWM0_GENERATOR_2				
	INTERRUPT_VT_QEI0							
	INTERRUPT_VT_ADC0_SEQUENCE_0				
	INTERRUPT_VT_ADC0_SEQUENCE_1				
	INTERRUPT_VT_ADC0_SEQUENCE_2				
	INTERRUPT_VT_ADC0_SEQUENCE_3				
	INTERRUPT_VT_WATCHDOG_TIMERS_0_AND_1		
	INTERRUPT_VT_16_32_BIT_TIMER_0A				
	INTERRUPT_VT_16_32_BIT_TIMER_0B				
	INTERRUPT_VT_16_32_BIT_TIMER_1A				
	INTERRUPT_VT_16_32_BIT_TIMER_1B				
	INTERRUPT_VT_16_32_BIT_TIMER_2A				
	INTERRUPT_VT_16_32_BIT_TIMER_2B				
	INTERRUPT_VT_ANALOG_COMPARATOR_0			
	INTERRUPT_VT_ANALOG_COMPARATOR_1			
	INTERRUPT_VT_SYSTEM_CONTROL					
	INTERRUPT_VT_FLASH_MEMORY_AND_EEPROM_CONTROL
	INTERRUPT_VT_GPIO_PORT_F                    
	INTERRUPT_VT_UART2                          
	INTERRUPT_VT_SSI1                           
	INTERRUPT_VT_16_32_BIT_TIMER_3A             
	INTERRUPT_VT_16_32_BIT_TIMER_3B             
	INTERRUPT_VT_I2C1                           
	INTERRUPT_VT_QEI1                           
	INTERRUPT_VT_CAN0                           
	INTERRUPT_VT_CAN1                           
	INTERRUPT_VT_HIBERNATION_MODULE             
	INTERRUPT_VT_USB                            
	INTERRUPT_VT_PWM_GENERATOR 3                
	INTERRUPT_VT_ΜDMA_SOFTWARE                  
	INTERRUPT_VT_ΜDMA_ERROR                     
	INTERRUPT_VT_ADC1_SEQUENCE_0                
	INTERRUPT_VT_ADC1_SEQUENCE_1                
	INTERRUPT_VT_ADC1_SEQUENCE_2                
	INTERRUPT_VT_ADC1_SEQUENCE_3                
	INTERRUPT_VT_SSI2                           
	INTERRUPT_VT_SSI3                           
	INTERRUPT_VT_UART3                          
	INTERRUPT_VT_UART4                          
	INTERRUPT_VT_UART5                          
	INTERRUPT_VT_UART6                          
	INTERRUPT_VT_UART7                          
	INTERRUPT_VT_I2C2                           
	INTERRUPT_VT_I2C3                           
	INTERRUPT_VT_16_32_BIT_TIMER_4A             
	INTERRUPT_VT_16_32_BIT_TIMER_4B             
	INTERRUPT_VT_16_32_BIT_TIMER_5A             
	INTERRUPT_VT_16_32_BIT_TIMER_5B             
	INTERRUPT_VT_32_64_BIT_TIMER_0A             
	INTERRUPT_VT_32_64_BIT_TIMER_0B             
	INTERRUPT_VT_32_64_BIT_TIMER_1A             
	INTERRUPT_VT_32_64_BIT_TIMER_1B             
	INTERRUPT_VT_32_64_BIT_TIMER_2A             
	INTERRUPT_VT_32_64_BIT_TIMER_2B             
	INTERRUPT_VT_32_64_BIT_TIMER_3A             
	INTERRUPT_VT_32_64_BIT_TIMER_3B             
	INTERRUPT_VT_32_64_BIT_TIMER_4A             
	INTERRUPT_VT_32_64_BIT_TIMER_4B             
	INTERRUPT_VT_32_64_BIT_TIMER_5A             
	INTERRUPT_VT_32_64_BIT_TIMER_5B             
	INTERRUPT_VT_SYSTEM_EXCEPTION_IMPRECISE		
	INTERRUPT_VT_PWM1_GENERATOR_0               
	INTERRUPT_VT_PWM1_GENERATOR_1               
	INTERRUPT_VT_PWM1_GENERATOR_2               
	INTERRUPT_VT_PWM1_GENERATOR_3               
	INTERRUPT_VT_PWM1_FAULT      
*    
*    
*     
*     
*     
*     
*
*     
*******************************************************************************/


/*********************************Please configure all the needed interrupts here in the below form ****************************/
/**********************************{InterruptVectorTableValue,GroupPriority,SubgroupPriority}*********************************/
/*********************************NOTE: YOU NEED TO CONFIGURE NVIC_INTERRUPT_PRIORITY_LEVELS IN NVIC_Config.h file*********************/  
/*********************************NOTE: YOU NEED TO CONFIGURE NVIC_NUMBER_OF_ENABLED_INTERUPTS IN NVIC_Config.h file*********************/       

 //{interruptVTValue1,interruptPriorityLevelGroup1,interruptPriorityLevelSubGroup1},
//{interruptVTValue2,interruptPriorityLevelGroup2,interruptPriorityLevelSubGroup2}    
NVIC_interruptConfigStructure NVIC_interruptConfiguration[NVIC_NUMBER_OF_ENABLED_INTERUPTS] =   {{INTERRUPT_VT_GPIO_PORT_F,0,0},
                                                                                                 {INTERRUPT_VT_GPIO_PORT_C,0,2},
                                                                                                 {INTERRUPT_VT_32_64_BIT_TIMER_0A,1,1},
																																																{INTERRUPT_VT_32_64_BIT_TIMER_3A,1,1}};


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
