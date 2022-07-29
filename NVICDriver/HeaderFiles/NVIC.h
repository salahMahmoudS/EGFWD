
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <NVIC_INT_H>
 *       Module:  NVICDriver
 *
 *  Description:  <This file contains the prototype functions used in this driver>     
 *  
 *********************************************************************************************************************/
#ifndef NVIC_H
#define NVIC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "NVIC_Types.h"
#include "NVIC_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	uint8 interruptVTValue;
	uint8 interruptPriorityLevelGroup;
	uint8 interruptPriorityLevelSubGroup;
	
}NVIC_interruptConfigStructure;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define NVIC_SUCCESS 										(0U)
#define NVIC_FAIL 											(1U)
#define NVIC_ERROR											(95U)
#define NVIC_IS_ACTIVE										(2U)
#define NVIC_IS_NOT_ACTIVE									(3U)
#define NVIC_IS_ENABLED										(4U)
#define NVIC_Is_DISABLED									(5U)
#define NVIC_IS_PENDING										(6U)
#define NVIC_IS_NOT_PENDING									(7U)



/************************************Defining interrupt vector table Interrupt number ***********************************************/
#define	INTERRUPT_VT_GPIO_PORT_A							(0U) 		 
#define	INTERRUPT_VT_GPIO_PORT_B							(1U) 		 
#define	INTERRUPT_VT_GPIO_PORT_C							(2U) 		 
#define	INTERRUPT_VT_GPIO_PORT_D							(3U) 		 
#define	INTERRUPT_VT_GPIO_PORT_E							(4U) 		 
#define	INTERRUPT_VT_UART0								(5U) 		 
#define	INTERRUPT_VT_UART1								(6U) 		 
#define	INTERRUPT_VT_SSI0								(7U) 		 
#define	INTERRUPT_VT_I2C0								(8U) 		 
#define	INTERRUPT_VT_PWM0_FAULT								(9U) 		 
#define	INTERRUPT_VT_PWM0_GENERATOR_0						        (10U)		
#define	INTERRUPT_VT_PWM0_GENERATOR_1						        (11U)		
#define	INTERRUPT_VT_PWM0_GENERATOR_2						        (12U)		
#define	INTERRUPT_VT_QEI0								(13U)		
#define	INTERRUPT_VT_ADC0_SEQUENCE_0						        (14U)		
#define	INTERRUPT_VT_ADC0_SEQUENCE_1						        (15U)		
#define	INTERRUPT_VT_ADC0_SEQUENCE_2						        (16U)		
#define	INTERRUPT_VT_ADC0_SEQUENCE_3						        (17U)		
#define	INTERRUPT_VT_WATCHDOG_TIMERS_0_AND_1			                        (18U)		
#define	INTERRUPT_VT_16_32_BIT_TIMER_0A						        (19U)		
#define	INTERRUPT_VT_16_32_BIT_TIMER_0B						        (20U)		
#define	INTERRUPT_VT_16_32_BIT_TIMER_1A						        (21U)		
#define	INTERRUPT_VT_16_32_BIT_TIMER_1B						        (22U)		
#define	INTERRUPT_VT_16_32_BIT_TIMER_2A						        (23U)		
#define	INTERRUPT_VT_16_32_BIT_TIMER_2B						        (24U)		
#define	INTERRUPT_VT_ANALOG_COMPARATOR_0					        (25U)		
#define	INTERRUPT_VT_ANALOG_COMPARATOR_1					        (26U)		
#define	INTERRUPT_VT_SYSTEM_CONTROL						        (28U)	
#define	INTERRUPT_VT_FLASH_MEMORY_AND_EEPROM_CONTROL	                                (29U) 
#define	INTERRUPT_VT_GPIO_PORT_F                                                        (30U) 
#define	INTERRUPT_VT_UART2                                                              (33U) 
#define	INTERRUPT_VT_SSI1                                                               (34U) 
#define	INTERRUPT_VT_16_32_BIT_TIMER_3A                                                 (35U) 
#define	INTERRUPT_VT_16_32_BIT_TIMER_3B                                                 (36U) 
#define	INTERRUPT_VT_I2C1                                                               (37U) 
#define	INTERRUPT_VT_QEI1                                                               (38U) 
#define	INTERRUPT_VT_CAN0                                                               (39U) 
#define	INTERRUPT_VT_CAN1                                                               (40U) 
#define	INTERRUPT_VT_HIBERNATION_MODULE                                                 (43U) 
#define	INTERRUPT_VT_USB                                                                (44U)
#define	INTERRUPT_VT_PWM_GENERATOR_3                                                    (45U)
#define INTERRUPT_VT_MDMA                                                               (46U)
#define INTERRUPT_VT_MDMA_ERRPR                                                         (47U)
#define	INTERRUPT_VT_ADC1_SEQUENCE_0                                                    (48U)
#define	INTERRUPT_VT_ADC1_SEQUENCE_1                                                    (49U)
#define	INTERRUPT_VT_ADC1_SEQUENCE_2                                                    (50U)
#define	INTERRUPT_VT_ADC1_SEQUENCE_3                                                    (51U)
#define	INTERRUPT_VT_SSI2                                                               (57U)
#define	INTERRUPT_VT_SSI3                                                               (58U) 
#define	INTERRUPT_VT_UART3                                                              (59U) 
#define	INTERRUPT_VT_UART4                                                              (60U) 
#define	INTERRUPT_VT_UART5                                                              (61U) 
#define	INTERRUPT_VT_UART6                                                              (62U) 
#define	INTERRUPT_VT_UART7                                                              (63U) 
#define	INTERRUPT_VT_I2C2                                                               (68U) 
#define	INTERRUPT_VT_I2C3                                                               (69U) 
#define	INTERRUPT_VT_16_32_BIT_TIMER_4A                                                 (70U) 
#define	INTERRUPT_VT_16_32_BIT_TIMER_4B                                                 (71U) 
#define	INTERRUPT_VT_16_32_BIT_TIMER_5A                                                 (92U) 
#define	INTERRUPT_VT_16_32_BIT_TIMER_5B                                                 (93U) 
#define	INTERRUPT_VT_32_64_BIT_TIMER_0A                                                 (94U) 
#define	INTERRUPT_VT_32_64_BIT_TIMER_0B                                                 (95U) 
#define	INTERRUPT_VT_32_64_BIT_TIMER_1A                                                 (96U) 
#define	INTERRUPT_VT_32_64_BIT_TIMER_1B                                                 (97U) 
#define	INTERRUPT_VT_32_64_BIT_TIMER_2A                                                 (98U) 
#define	INTERRUPT_VT_32_64_BIT_TIMER_2B                                                 (99U) 
#define	INTERRUPT_VT_32_64_BIT_TIMER_3A                                                 (100U)
#define	INTERRUPT_VT_32_64_BIT_TIMER_3B                                                 (101U)
#define	INTERRUPT_VT_32_64_BIT_TIMER_4A                                                 (102U)
#define	INTERRUPT_VT_32_64_BIT_TIMER_4B                                                 (103U)
#define	INTERRUPT_VT_32_64_BIT_TIMER_5A                                                 (104U)
#define	INTERRUPT_VT_32_64_BIT_TIMER_5B                                                 (105U)
#define	INTERRUPT_VT_SYSTEM_EXCEPTION_IMPRECISE		                       	        (106U)
#define	INTERRUPT_VT_PWM1_GENERATOR_0                                                   (134U)
#define	INTERRUPT_VT_PWM1_GENERATOR_1                                                   (135U)
#define	INTERRUPT_VT_PWM1_GENERATOR_2                                                   (136U)
#define	INTERRUPT_VT_PWM1_GENERATOR_3                                                   (137U)
#define	INTERRUPT_VT_PWM1_FAULT                                                         (138U)
 
//27		-	Reserved	 
//41-42	-	Reserved
//31-32 	-	Reserved
//52-56 	-	Reserved
//64-67 	-	Reserved
//72-91  	-	Reserved
//107-133	-	Reserved


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/*This function initializes the interrupt			*/
void NVIC_Init(void);				
/*This function enables the configured interrupts   */													
uint8 NVIC_SetEnableInterrupt(uint8 interruptVTValue); 
/*This function disables the interrupt              */									
uint8 NVIC_GetIsPendingInterupt(uint8 interruptVTValue);
/*This function sets enabled interrupt to pending   */								
uint8 NVIC_SetInterruptToPending(uint8 interruptVTValue);
/*this fiunction clears any pending interrupt       */								
uint8 NVIC_ClearPendingInterrupt(uint8 interruptVTValue);
/*This function returns if interrupt is pending     */								
uint8 NVIC_GetIsPendingInterupt(uint8 interruptVTValue);
/*This function activates interrupt by softwarre    */								
uint8 NVIC_SWActivateInterrupt(uint8 interruptVTValue);		
/*This function configures the interrupt priority	*/							
uint8 NVIC_SetInterruptPriority(NVIC_interruptConfigStructure desiredInterrupt);	
/*This function disable interrupt                   */		
uint8 NVIC_DisableInterrupt(uint8 interruptVTValue);									

 
#endif  /* NVIC_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
