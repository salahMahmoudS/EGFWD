/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  <TM4C123GH6PM_Hw.h>
*       Module:  Common
*
*  Description:  This file contains the TM4C123GH6PM registers and pins which are mapped to the real board     
*  Author: Salah Mahmoud
************************************************************************************************************************/
#ifndef TM4C123GH6PM_HW_H
#define TM4C123GH6PM_HW_H


/**********************************************************************************************************************
*  GLOBAL DATA PROTOTYPES
*********************************************************************************************************************/
#define MCU_NUMBER_OF_PORTS                                 (6U)
#define MCU_NUMBER_OF_PINS                                  (43U)
/******************* BASE ADDRESSES ***************************************************************************************/

#define CORE_PERIPHERAL_BASE_ADDRESS 		        (0xE000E000)
#define SYSTEM_CONTROL_BASE_ADDRESS			(0x400FE000)
/******************************************************************************************************************************/

/*******************************************System control block (MCU) registers **********************************************/

#define APINT 								(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0xD0C )))  		//Application Interrupt and Reset Control
#define RCGCGPIO							(*((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS +  0x608 )))		//General-Purpose Input/Output Run Mode Clock Gating control	
#define R0									(0)		   			//pin for portA clock
#define R1									(1)          			//pin for portB clock
#define R2									(2)          			//pin for portC clock
#define R3									(3)          			//pin for portD clock
#define R4									(4)          			//pin for portE clock
#define R5									(5)          			//pin for portF clock

#define MCU_RIS_REGISTER					(*((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x050)))			//Raw interrupt status register
#define MCU_PLLRIS_BIT						((uint8)0x06)					//This bit indicates that PLL timer reached ready state to lock

#define MCU_RCC_REGISTER					(*((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x060)))			//Run-mode clock configuration register
#define MCU_USESYSDIV_BIT					((uint8)0x16)

#define MCU_RCC2_REGISTER					(*((volatile uint32*)(SYSTEM_CONTROL_BASE_ADDRESS + 0x070)))			//Run-mode clock configuration 2 register
#define MCU_USERRCC2_BIT					((uint8) 0x1f)					//This bit identifies main run mode clock configuration register to be RCC2
#define MCU_DIV400_BIT						((uint8) 0x1E)					//This bit Add SYSDIV2LSB to the SYSDIV2 bit field, which makes the bitfield 7 divisor bits that control 400MHz PLL output
#define MCU_SYSDIV2LSB_BIT					((uint8) 0x16)					//when SCB_DIV400_BIT is set, this acts as the least signifacnt bit in the SYSDIV2 divisor
#define MCU_USBPWRDWN_BIT					((uint8) 0x0E)					//This bit powers down the USB PLL
#define MCU_PWRDWN2_BIT						((uint8) 0x0D)					//This bit powers down the PLL 
#define MCU_BYPASS2_BIT						((uint8) 0x0B)					//Configures the system output clock to be either PLL or Oscillator

#define SYSCTL_RCGC2_R          			(*((volatile unsigned long *)0x400FE108))


/****************** Nested Vectored Interrupt Controller (NVIC) Registers *****************************************************/
#define DDRA *((u8 volatile *) 0x3A)
#define	 EN0           						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x100 )))	   // Interrupt 0-31 Set Enable
#define	 EN1           						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x104 )))        // Interrupt 32-63 Set Enable 
#define	 EN2           						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x108 )))        // Interrupt 64-95 Set Enable 
#define	 EN3           						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x10C )))        // Interrupt 96-127 Set Enable
#define	 EN4           						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x110 )))        // Interrupt 128-138 Set Enable
#define	 DIS0          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x180 )))        // Interrupt 0-31 Clear Enable 
#define	 DIS1          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x184 )))        // Interrupt 32-63 Clear Enable
#define	 DIS2          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x188 )))        // Interrupt 64-95 Clear Enable
#define	 DIS3          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x18C )))        // Interrupt 96-127 Clear Enable 
#define	 DIS4          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x190 )))        // Interrupt 128-138 Clear Enable
#define	 PEND0         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x200 )))        // Interrupt 0-31 	Set Pending 
#define	 PEND1         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x204 )))        // Interrupt 32-63 Set Pending 
#define	 PEND2         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x208 )))        // Interrupt 64-95 Set Pending 
#define	 PEND3         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x20C )))        // Interrupt 96-127 Set Pending
#define	 PEND4         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x210 )))        // Interrupt 128-138 Set Pending
#define	 UNPEND0       						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x280 )))        // Interrupt 0-31 Clear Pending 
#define	 UNPEND1       						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x284 )))        // Interrupt 32-63 Clear Pending
#define	 UNPEND2       						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x288 )))        // Interrupt 64-95 Clear Pending
#define	 UNPEND3       						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x28C )))        // Interrupt 96-127 Clear Pending 
#define	 UNPEND4       						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x290 )))        // Interrupt 128-138 Clear Pending
#define	 ACTIVE0       						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x300 )))        // Interrupt 0-31 Active Bit 
#define	 ACTIVE1       						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x304 )))        // Interrupt 32-63 Active Bit
#define	 ACTIVE2       						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x308 )))        // Interrupt 64-95 Active Bit
#define	 ACTIVE3       						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x30C )))        // Interrupt 96-127 Active Bit 
#define	 ACTIVE4       						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x310 )))        // Interrupt 128-138 Active Bit
#define	 PRI0          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x400 )))        // Interrupt 0-3 Priority 
#define	 PRI1          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x404 )))        // Interrupt 4-7 Priority 
#define	 PRI2          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x408 )))        // Interrupt 8-11 Priority
#define	 PRI3          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x40C )))        // Interrupt 12-15 Priority 
#define	 PRI4          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x410 )))        // Interrupt 16-19 Priority 
#define	 PRI5          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x414 )))        // Interrupt 20-23 Priority 
#define	 PRI6          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x418 )))        // Interrupt 24-27 Priority 
#define	 PRI7          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x41C )))        // Interrupt 28-31 Priority 
#define	 PRI8          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x420 )))        // Interrupt 32-35 Priority 
#define	 PRI9          						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x424 )))        // Interrupt 36-39 Priority 
#define	 PRI10         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x428 )))        // Interrupt 40-43 Priority 
#define	 PRI11         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x42C )))        // Interrupt 44-47 Priority 
#define	 PRI12         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x430 )))        // Interrupt 48-51 Priority 
#define	 PRI13         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x434 )))        // Interrupt 52-55 Priority 
#define	 PRI14         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x438 )))        // Interrupt 56-59 Priority 
#define	 PRI15         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x43C )))        // Interrupt 60-63 Priority 
#define	 PRI16         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x440 )))        // Interrupt 64-67 Priority 
#define	 PRI17         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x444 )))        // Interrupt 68-71 Priority 
#define	 PRI18         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x448 )))        // Interrupt 72-75 Priority 
#define	 PRI19         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x44C )))        // Interrupt 76-79 Priority 
#define	 PRI20         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x450 )))        // Interrupt 80-83 Priority 
#define	 PRI21         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x454 )))        // Interrupt 84-87 Priority 
#define	 PRI22         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x458 )))        // Interrupt 88-91 Priority 
#define	 PRI23         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x45C )))        // Interrupt 92-95 Priority 
#define	 PRI24         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x460 )))        // Interrupt 96-99 Priority 
#define	 PRI25         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x464 )))        // Interrupt 100-103 Priority 
#define	 PRI26         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x468 )))        // Interrupt 104-107 Priority 
#define	 PRI27         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x46C )))        // Interrupt 108-111 Priority 
#define	 PRI28         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x470 )))        // Interrupt 112-115 Priority 
#define	 PRI29         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x474 )))        // Interrupt 116-119 Priority 
#define	 PRI30         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x478 )))        // Interrupt 120-123 Priority 
#define	 PRI31         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x47C )))        // Interrupt 124-127 Priority 
#define	 PRI32         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x480 )))        // Interrupt 128-131 Priority 
#define	 PRI33         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x484 )))        // Interrupt 132-135 Priority 
#define	 PRI34         						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x488 )))        // Interrupt 136-138 Priority 
#define	 SWTRIG        						(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0xF00 )))        // Software Trigger Interrupt



/**************************************************SYSTICK Registers*****************************************************************/

#define		SYSTICK_STCTRL_ENABLE			((uint8) 0x00)
#define		SYSTICK_STCTRL_INTEN			((uint8) 0x01)	 
#define		SYSTICK_STCTRL_CLK_SRC			((uint8) 0x02)
#define		SYSTICK_STCTRL_COUNT			( 16U  )

#define		SYSTICK_STCTRL        			(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x010 )))
#define		SYSTICK_STRELOAD       			(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x014 )))
#define		SYSTICK_STCURRENT      			(*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x018 )))

/**************************************************GPIO Registers*****************************************************************/

#define  GPIO_Port_A_APB_BASE_ADDRESS		((uint32) 0x40004000)
#define  GPIO_Port_A_AHB_BASE_ADDRESS		((uint32) 0x40058000)
#define  GPIO_Port_B_APB_BASE_ADDRESS		((uint32) 0x40005000)
#define  GPIO_Port_B_AHB_BASE_ADDRESS		((uint32) 0x40059000)
#define  GPIO_Port_C_APB_BASE_ADDRESS		((uint32) 0x40006000)
#define  GPIO_Port_C_AHB_BASE_ADDRESS		((uint32) 0x4005A000)
#define  GPIO_Port_D_APB_BASE_ADDRESS		((uint32) 0x40007000)
#define  GPIO_Port_D_AHB_BASE_ADDRESS		((uint32) 0x4005B000)
#define  GPIO_Port_E_APB_BASE_ADDRESS		((uint32) 0x40024000)
#define  GPIO_Port_E_AHB_BASE_ADDRESS		((uint32) 0x4005C000)
#define  GPIO_Port_F_APB_BASE_ADDRESS		((uint32) 0x40025000)
#define  GPIO_Port_F_AHB_BASE_ADDRESS		((uint32) 0x4005D000)


#define  GPIODATA_OFFSET 		  			0x000		//GPIO Data 
#define  GPIODIR_OFFSET 		  			0x400		//GPIO Direction 
#define  GPIOAFSEL_OFFSET		  			0x420		//GPIO Alternate Function Select 
#define  GPIODR2R_OFFSET		  			0x500		//GPIO 2-mA Drive Select 
#define  GPIODR4R_OFFSET		  			0x504		//GPIO 4-mA Drive Select 
#define  GPIODR8R_OFFSET		  			0x508		//GPIO 8-mA Drive Select 
#define  GPIOODR_OFFSET		 	  			0x50C		//GPIO Open Drain Select 
#define  GPIOPUR_OFFSET		 	  			0x510		//GPIO Pull-Up Select 
#define  GPIOPDR_OFFSET		 	  			0x514		//GPIO Pull-Down Select 
#define  GPIOSLR_OFFSET		 	  			0x518		//GPIO Slew Rate Control Select 
#define  GPIODEN_OFFSET		 	  			0x51C		//GPIO Digital Enable 
#define  GPIOLOCK_OFFSET 		  			0x520		//GPIO Lock 
#define  GPIOCR_OFFSET 		      			        0x524		//GPIO Commit
#define  GPIOAMSEL_OFFSET		  			0x528		//GPIO Analog Mode Select 
#define  GPIOPCTL_OFFSET 		  			0x52C		//GPIO Port Control
#define  GPIOADCCTL_OFFSET		  			0x530		//GPIO ADC Control 
#define  GPIODMACTL_OFFSET		  			0x534		//GPIO DMA Control 
#define  GPIOPeriphID4_OFFSET 	  			        0xFD0 	        //GPIO Peripheral Identification 4 
#define  GPIOPeriphID5_OFFSET 	  			        0xFD4	 	//GPIO Peripheral Identification 5 
#define  GPIOPeriphID6_OFFSET 	  			        0xFD8	 	//GPIO Peripheral Identification 6 
#define  GPIOPeriphID7_OFFSET 	  			        0xFDC	 	//GPIO Peripheral Identification 7 
#define  GPIOPeriphID0_OFFSET 	  			        0xFE0	 	//GPIO Peripheral Identification 0 
#define  GPIOPeriphID1_OFFSET 	  			        0xFE4	 	//GPIO Peripheral Identification 1 
#define  GPIOPeriphID2_OFFSET 	  			        0xFE8	 	//GPIO Peripheral Identification 2 
#define  GPIOPeriphID3_OFFSET 	  			        0xFEC	 	//GPIO Peripheral Identification 3 
#define  GPIOPCellID0_OFFSET	  			        0xFF0		//GPIO PrimeCell Identification 0 
#define  GPIOPCellID1_OFFSET	  			        0xFF4		//GPIO PrimeCell Identification 1 
#define  GPIOPCellID2_OFFSET	  			        0xFF8		//GPIO PrimeCell Identification 2 
#define  GPIOPCellID3_OFFSET	  			        0xFFC		//GPIO PrimeCell Identification 3 



#define  GPIODATA(base_address)		    (*((volatile uint32*) (base_address + GPIODATA_OFFSET 	 )))
#define  GPIODIR(base_address)              (*((volatile uint32*) (base_address + GPIODIR_OFFSET 	 )))
#define  GPIOAFSEL(base_address)            (*((volatile uint32*) (base_address + GPIOAFSEL_OFFSET	 )))
#define  GPIODR2R(base_address)             (*((volatile uint32*) (base_address + GPIODR2R_OFFSET	 )))
#define  GPIODR4R(base_address)             (*((volatile uint32*) (base_address + GPIODR4R_OFFSET	 )))
#define  GPIODR8R(base_address)             (*((volatile uint32*) (base_address + GPIODR8R_OFFSET	 )))
#define  GPIOODR(base_address)              (*((volatile uint32*) (base_address + GPIOODR_OFFSET	 )))
#define  GPIOPUR(base_address)              (*((volatile uint32*) (base_address + GPIOPUR_OFFSET	 )))
#define  GPIOPDR(base_address)              (*((volatile uint32*) (base_address + GPIOPDR_OFFSET	 )))
#define  GPIOSLR(base_address)              (*((volatile uint32*) (base_address + GPIOSLR_OFFSET	 )))
#define  GPIODEN(base_address)              (*((volatile uint32*) (base_address + GPIODEN_OFFSET	 )))
#define  GPIOLOCK(base_address)             (*((volatile uint32*) (base_address + GPIOLOCK_OFFSET 	 )))
#define  GPIOCR(base_address)               (*((volatile uint32*) (base_address + GPIOCR_OFFSET 	 )))
#define  GPIOAMSEL(base_address)            (*((volatile uint32*) (base_address + GPIOAMSEL_OFFSET	 )))
#define  GPIOPCTL(base_address)             (*((volatile uint32*) (base_address + GPIOPCTL_OFFSET 	 )))
#define  GPIOADCCTL(base_address)           (*((volatile uint32*) (base_address + GPIOADCCTL_OFFSET	 )))
#define  GPIODMACTL(base_address)           (*((volatile uint32*) (base_address + GPIODMACTL_OFFSET	 )))
#define  GPIOPeriphID4(base_address)        (*((volatile uint32*) (base_address + GPIOPeriphID4_OFFSE)))
#define  GPIOPeriphID5(base_address)        (*((volatile uint32*) (base_address + GPIOPeriphID5_OFFSE)))
#define  GPIOPeriphID6(base_address)        (*((volatile uint32*) (base_address + GPIOPeriphID6_OFFSE)))
#define  GPIOPeriphID7(base_address)        (*((volatile uint32*) (base_address + GPIOPeriphID7_OFFSE)))
#define  GPIOPeriphID0(base_address)        (*((volatile uint32*) (base_address + GPIOPeriphID0_OFFSE)))
#define  GPIOPeriphID1(base_address)        (*((volatile uint32*) (base_address + GPIOPeriphID1_OFFSE)))
#define  GPIOPeriphID2(base_address)        (*((volatile uint32*) (base_address + GPIOPeriphID2_OFFSE)))
#define  GPIOPeriphID3(base_address)        (*((volatile uint32*) (base_address + GPIOPeriphID3_OFFSE)))
#define  GPIOPCellID0(base_address)         (*((volatile uint32*) (base_address + GPIOPCellID0_OFFSET)))
#define  GPIOPCellID1(base_address)         (*((volatile uint32*) (base_address + GPIOPCellID1_OFFSET)))
#define  GPIOPCellID2(base_address)         (*((volatile uint32*) (base_address + GPIOPCellID2_OFFSET)))
#define  GPIOPCellID3(base_address)         (*((volatile uint32*) (base_address + GPIOPCellID3_OFFSET)))


/**************************************************ICU Registers*****************************************************************/



#define  ICU_GPIOIS_OFFSET 		 	  			0x404		//GPIO Interrupt Sense 
#define  ICU_GPIOIBE_OFFSET		 	  			0x408		//GPIO Interrupt Both Edges 
#define  ICU_GPIOIEV_OFFSET 		  			0x40C		//GPIO Interrupt Event 
#define  ICU_GPIOIM_OFFSET 		 	  			0x410		//GPIO Interrupt Mask
#define  ICU_GPIORIS_OFFSET		 	  			0x414		//GPIO Raw Interrupt Status 
#define  ICU_GPIOMIS_OFFSET		 	  			0x418		//GPIO Masked Interrupt Status 
#define  ICU_GPIOICR_OFFSET		 	  			0x41C		//GPIO Interrupt Clear 


#define  ICU_GPIOIS_REGISTER(base_address)               (*((volatile uint32*) (base_address + ICU_GPIOIS_OFFSET )))
#define  ICU_GPIOIBE_REGISTER(base_address)              (*((volatile uint32*) (base_address + ICU_GPIOIBE_OFFSET)))
#define  ICU_GPIOIEV_REGISTER(base_address)              (*((volatile uint32*) (base_address + ICU_GPIOIEV_OFFSET)))
#define  ICU_GPIOIM_REGISTER(base_address)               (*((volatile uint32*) (base_address + ICU_GPIOIM_OFFSET )))
#define  ICU_GPIORIS_REGISTER(base_address)              (*((volatile uint32*) (base_address + ICU_GPIORIS_OFFSET)))
#define  ICU_GPIOMIS_REGISTER(base_address)              (*((volatile uint32*) (base_address + ICU_GPIOMIS_OFFSET)))
#define  ICU_GPIOICR_REGISTER(base_address)              (*((volatile uint32*) (base_address + ICU_GPIOICR_OFFSET)))


/***************************************************GPT REGISTERS********************************************************/

#define  GPT_BASE_ADDRESS		((uint32) 0x400FE000)
#define GPT_NTIMER_0_BASE_ADDRESS  ((uint32) 0x40030000)
#define GPT_NTIMER_1_BASE_ADDRESS  ((uint32) 0x40031000)
#define GPT_NTIMER_2_BASE_ADDRESS  ((uint32) 0x40032000)
#define GPT_NTIMER_3_BASE_ADDRESS  ((uint32) 0x40033000)
#define GPT_NTIMER_4_BASE_ADDRESS  ((uint32) 0x40034000)
#define GPT_NTIMER_5_BASE_ADDRESS  ((uint32) 0x40035000)
#define GPT_WTIMER_0_BASE_ADDRESS ((uint32) 0x40036000)
#define GPT_WTIMER_1_BASE_ADDRESS ((uint32) 0x40037000)
#define GPT_WTIMER_2_BASE_ADDRESS ((uint32) 0x4004C000)
#define GPT_WTIMER_3_BASE_ADDRESS ((uint32) 0x4004D000)
#define GPT_WTIMER_4_BASE_ADDRESS ((uint32) 0x4004E000)
#define GPT_WTIMER_5_BASE_ADDRESS ((uint32) 0x4004F000)

#define GPTMCFG_OFFSET 			(0x000)
#define GPTMTAMR_OFFSET 		(0x004)
#define GPTMTBMR_OFFSET 		(0x008)
#define GPTMCTL_OFFSET 			(0x00C)
#define GPTMSYNC_OFFSET 		(0x010)
#define GPTMIMR_OFFSET 			(0x018)
#define GPTMRIS_OFFSET 			(0x01C)
#define GPTMMIS_OFFSET 			(0x020)
#define GPTMICR_OFFSET 			(0x024)
#define GPTMTAILR_OFFSET 		(0x028)
#define GPTMTBILR_OFFSET 		(0x02C)
#define GPTMTAMATCH_OFFSET  (0x030)
#define GPTMTBMATCH_OFFSET  (0x034)
#define GPTMTAPR_OFFSET 		(0x038)
#define GPTMTBPR_OFFSET 		(0x03C)
#define GPTMTAPMR_OFFSET 		(0x040)
#define GPTMTBPMR_OFFSET 		(0x044)
#define GPTMTAR_OFFSET 			(0x048)
#define GPTMTBR_OFFSET 			(0x04C)
#define GPTMTAV_OFFSET 			(0x050)
#define GPTMTBV_OFFSET 			(0x054)
#define GPTMRTCPD_OFFSET 		(0x058)
#define GPTMTAPS_OFFSET 		(0x05C)
#define GPTMTBPS_OFFSET 		(0x060)
#define GPTMTAPV_OFFSET 		(0x064)
#define GPTMTBPV_OFFSET 		(0x068)
#define GPTMPP_OFFSET 			(0xFC0)



#define  RCGCTIMER              		(*((volatile uint32*) (GPT_BASE_ADDRESS + 0x604 ))) 							/*General-Purpose Timer Run Mode Clock Gating Control*/
#define  RCGCWTIMER            		  (*((volatile uint32*) (GPT_BASE_ADDRESS + 0x65C ))) 							/*General-Purpose Wide Timer Run Mode Clock Gating Control*/


#define  GPTMCFG(base_address)      (*((volatile uint32*) (base_address + GPTMCFG_OFFSET 		 ))) 		  /* GPTM Configuration 						  */								
#define TBEN								(8U)			/* Timer B enable */
#define TAEN								(0U)			/* Timer A enable bit */


#define  GPTMTAMR(base_address)     (*((volatile uint32*) (base_address + GPTMTAMR_OFFSET 	 ))) 		  /* GPTM Timer A Mode                */
#define TACDIR							(4U)			/* Timer A count direction */
#define TAMR0								(0U)			/* Timer A Mode LSB*/
#define TAMR1								(1U)			/* Timer A Mode MSB*/
#define  GPTMTBMR(base_address)     (*((volatile uint32*) (base_address + GPTMTBMR_OFFSET 	 ))) 		  /* GPTM Timer B Mode                */
#define TBCDIR							(4U)			/* Timer B count direction */
#define TBMR0								(0U)			/* Timer B Mode LSB*/
#define TBMR1								(1U)			/* Timer B Mode MSB*/
#define  GPTMCTL(base_address)      (*((volatile uint32*) (base_address + GPTMCTL_OFFSET 		 )))  	  /* GPTM Control                     */
#define  GPTMSYNC(base_address)     (*((volatile uint32*) (base_address + GPTMSYNC_OFFSET 	 )))  	  /* GPTM Synchronize                 */
#define  GPTMIMR(base_address)      (*((volatile uint32*) (base_address + GPTMIMR_OFFSET 		 )))  	  /* GPTM Interrupt Mask              */
#define  TATOIM							(0U)
#define  GPTMRIS(base_address)      (*((volatile uint32*) (base_address + GPTMRIS_OFFSET 		 )))  	  /* GPTM Raw Interrupt Status        */		
#define  GPTMMIS(base_address)      (*((volatile uint32*) (base_address + GPTMMIS_OFFSET 		 )))  	  /* GPTM Masked Interrupt Status     */
#define  GPTMICR(base_address)      (*((volatile uint32*) (base_address + GPTMICR_OFFSET 		 )))  	  /* GPTM Interrupt Clear             */		
#define  TATOCINT						(0U)
#define  GPTMTAILR(base_address)    (*((volatile uint32*) (base_address + GPTMTAILR_OFFSET 	 ))) 		  /* GPTM Timer A Interval Load       */
#define  GPTMTBILR(base_address)    (*((volatile uint32*) (base_address + GPTMTBILR_OFFSET 	 ))) 		  /* GPTM Timer B Interval Load       */
#define  GPTMTAMATCH(base_address)  (*((volatile uint32*) (base_address + GPTMTAMATCH_OFFSET )))  	  /* GPTM Timer A Match               */
#define  GPTMTBMATCH(base_address)  (*((volatile uint32*) (base_address + GPTMTBMATCH_OFFSET )))  	  /* GPTM Timer B Match               */
#define  GPTMTAPR(base_address)     (*((volatile uint32*) (base_address + GPTMTAPR_OFFSET 	 ))) 		  /* GPTM Timer A Prescale            */
#define  GPTMTBPR(base_address)     (*((volatile uint32*) (base_address + GPTMTBPR_OFFSET 	 )))  	  /* GPTM Timer B Prescale            */
#define  GPTMTAPMR(base_address)    (*((volatile uint32*) (base_address + GPTMTAPMR_OFFSET 	 ))) 		  /* GPTM TimerA Prescale Match       */
#define  GPTMTBPMR(base_address)    (*((volatile uint32*) (base_address + GPTMTBPMR_OFFSET 	 ))) 		  /* GPTM TimerB Prescale Match       */
#define  GPTMTAR(base_address)      (*((volatile uint32*) (base_address + GPTMTAR_OFFSET 		 ))) 		  /* GPTM Timer A                     */
#define  GPTMTBR(base_address)      (*((volatile uint32*) (base_address + GPTMTBR_OFFSET 		 ))) 		  /* GPTM Timer B                     */
#define  GPTMTAV(base_address)      (*((volatile uint32*) (base_address + GPTMTAV_OFFSET 		 ))) 		  /* GPTM Timer A Value               */
#define  GPTMTBV(base_address)      (*((volatile uint32*) (base_address + GPTMTBV_OFFSET 		 ))) 		  /* GPTM Timer B Value               */
#define  GPTMRTCPD(base_address)    (*((volatile uint32*) (base_address + GPTMRTCPD_OFFSET 	 ))) 		  /* GPTM RTC Predivide               */
#define  GPTMTAPS(base_address)     (*((volatile uint32*) (base_address + GPTMTAPS_OFFSET 	 ))) 		  /* GPTM Timer A Prescale Snapshot   */
#define  GPTMTBPS(base_address)     (*((volatile uint32*) (base_address + GPTMTBPS_OFFSET 	 ))) 		  /* GPTM Timer B Prescale Snapshot   */
#define  GPTMTAPV(base_address)     (*((volatile uint32*) (base_address + GPTMTAPV_OFFSET 	 ))) 		  /* GPTM Timer A Prescale Value      */
#define  GPTMTBPV(base_address)     (*((volatile uint32*) (base_address + GPTMTBPV_OFFSET 	 ))) 		  /* GPTM Timer B Prescale Value      */
#define  GPTMPP(base_address)       (*((volatile uint32*) (base_address + GPTMPP_OFFSET 		 )))  	  /* GPTM Peripheral Properties       */
		






#endif  /* TM4C123GH6PM_HW_H */

/**********************************************************************************************************************
*  END OF FILE: Std_Types.h
*********************************************************************************************************************/
