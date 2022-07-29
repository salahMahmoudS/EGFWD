/**********************************************************************************************************************
*  FILE DESCRIPTION
*  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
*        \brief  This file contains implementation of all functions in port driver
*
*        
*
*        Author: Salah Mahmoud
*********************************************************************************************************************/
/* TODO disable interrupts when initializing */
/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "TM4C123GH6PM_Hw.h"
#include "Port.h"


#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"

/* will check for autosar release compatability after refactoring Det to autosar module */
/*
#if ((PORT_AR_RELEASE_MAJOR_VERSION != DET_AR_MAJOR_VERSION)\
  || (PORT_AR_RELEASE_MINOR_VERSION != DET_AR_MINOR_VERSION)\
  || (PORT_AR_RELEASE_PATCH_VERSION != DET_AR_PATCH_VERSION))
#error "The autosar version of Det.h is not matching this module version"
#endif
*/

#endif

/**********************************************************************************************************************
*  LOCAL DATA 
*********************************************************************************************************************/

/*local variable containing status of port driver*/
uint8 Port_InitializeStatus = PORT_NOT_INITIALIZED;

/* Local Pointer that will point to the configuration pointer */
STATIC const Port_PinConfigType *Port_ConfigurationPinsPointer = NULL_PTR;


/* Mapper that maps port number to the port address through index */
STATIC uint32 portAPBbaseAddressArray[] = {GPIO_Port_A_APB_BASE_ADDRESS,
                                           GPIO_Port_B_APB_BASE_ADDRESS,
                                           GPIO_Port_C_APB_BASE_ADDRESS,
                                           GPIO_Port_D_APB_BASE_ADDRESS,
                                           GPIO_Port_E_APB_BASE_ADDRESS,
                                           GPIO_Port_F_APB_BASE_ADDRESS};

/* structure containing version info for port driver*/
STATIC Std_VersionInfoType Port_VersionInfo = 
                                      {PORT_VENDOR_ID,
                                      PORT_MODULE_ID,
                                      PORT_SW_MAJOR_VERSION,
                                      PORT_SW_MINOR_VERSION,
                                      PORT_SW_PATCH_VERSION,
                                      };









/* Array defining allowed modes for PortA pin 0*/
STATIC uint8 Port_A_Pin_0_Modes[] = {PORT_PA0_DIO,			
                                     PORT_PA0_U0Rx,
                                     PORT_PA0_CAN1Rx		
                                   };

/* Array defining allowed modes for PortA pin 1*/
STATIC uint8 Port_A_Pin_1_Modes[] ={PORT_PA1_DIO,			
                                    PORT_PA1_U0Tx,			
                                    PORT_PA1_CAN1Tx 
                                     };

/* Array defining allowed modes for PortA pin 2*/
STATIC uint8 Port_A_Pin_2_Modes[] ={PORT_PA2_DIO,			
                                    PORT_PA2_SSI0Clk  
                                    };

/* Array defining allowed modes for PortA pin 3*/
STATIC uint8 Port_A_Pin_3_Modes[] ={PORT_PA3_DIO,			
                                    PORT_PA3_SSI0Fss  	
                                    };
/* Array defining allowed modes for PortA pin 4*/
STATIC uint8 Port_A_Pin_4_Modes[] ={PORT_PA4_DIO,			
                                    PORT_PA4_SSI0Rx
                                    };

/* Array defining allowed modes for PortA pin 5*/
STATIC uint8 Port_A_Pin_5_Modes[] ={PORT_PA5_DIO,			
                                    PORT_PA5_SSI0Tx  
                                    };

/* Array defining allowed modes for PortA pin 6*/
STATIC uint8 Port_A_Pin_6_Modes[] ={PORT_PA6_DIO,			
                                    PORT_PA6_I2C1SCL,		
                                    PORT_PA6_M1PWM2 
                                    };

/* Array defining allowed modes for PortA pin 7*/
STATIC uint8 Port_A_Pin_7_Modes[] ={PORT_PA7_DIO,			
                                    PORT_PA7_I2C1SDA,		
                                    PORT_PA7_M1PWM3  
                                    };

/* Array defining allowed modes for PortB pin 0*/
STATIC uint8 Port_B_Pin_0_Modes[] ={PORT_PB0_DIO,			
                                    PORT_PB0_USB0ID,			
                                    PORT_PB0_U1Rx,			
                                    PORT_PB0_T2CCP0   
                                    };

/* Array defining allowed modes for PortB pin 1*/
STATIC uint8 Port_B_Pin_1_Modes[] ={PORT_PB1_DIO,			
                                    PORT_PB1_USB0VBUS,		
                                    PORT_PB1_U1Tx,			
                                    PORT_PB1_T2CCP1
                                    };

/* Array defining allowed modes for PortB pin 2*/
STATIC uint8 Port_B_Pin_2_Modes[] ={PORT_PB2_DIO,			
                                    PORT_PB2_I2C0SCL,		
                                    PORT_PB2_T3CCP0 
                                    };

/* Array defining allowed modes for PortB pin 3*/
STATIC uint8 Port_B_Pin_3_Modes[] ={PORT_PB3_DIO,			
                                    PORT_PB3I2C0SDA,			
                                    PORT_PB3T3CCP1			
                                    };

/* Array defining allowed modes for PortB pin 4*/
STATIC uint8 Port_B_Pin_4_Modes[] ={PORT_PB4_DIO,			
                                    PORT_PB4_AIN10,			
                                    PORT_PB4_SSI2Clk,		
                                    PORT_PB4_M0PWM2,			
                                    PORT_PB4_T1CCP0,
                                    PORT_PB4_CAN0Rx			
                                    };

/* Array defining allowed modes for PortB pin 5*/
STATIC uint8 Port_B_Pin_5_Modes[] ={PORT_PB5_DIO,			
                                    PORT_PB5_AIN11,			
                                    PORT_PB5_SSI2Fss,		
                                    PORT_PB5_M0PWM3,			
                                    PORT_PB5_T1CCP1,			
                                    PORT_PB5_CAN0Tx,
                                    };

/* Array defining allowed modes for PortB pin 6*/
STATIC uint8 Port_B_Pin_6_Modes[] ={PORT_PB6_DIO,			
                                    PORT_PB6_SSI2Rx,			
                                    PORT_PB6_M0PWM0,			
                                    PORT_PB6_T0CCP0,   
                                    };

/* Array defining allowed modes for PortB pin 7*/
STATIC uint8 Port_B_Pin_7_Modes[] ={PORT_PB7_DIO,			
                                    PORT_PB7_SSI2Tx,			
                                    PORT_PB7_M0PWM1,			
                                    PORT_PB7_T0CCP1,
                                    };

/* Array defining allowed modes for PortC pin 0*/
STATIC uint8 Port_C_Pin_0_Modes[] ={PORT_PC0_DIO,			
                                    PORT_PC0_TCKSWCLK,		
                                    PORT_PC0_T4CCP0 
                                    };

/* Array defining allowed modes for PortC pin 1*/
STATIC uint8 Port_C_Pin_1_Modes[] ={PORT_PC1_DIO,			
                                    PORT_PC1_TMSSWDIO,		
                                    PORT_PC1_T4CCP1    	        
                                    };

/* Array defining allowed modes for PortC pin 2*/
STATIC uint8 Port_C_Pin_2_Modes[] ={PORT_PC2_DIO,			
                                    PORT_PC2_TDI,			
                                    PORT_PC2_T5CCP0     
                                    };

/* Array defining allowed modes for PortC pin 3*/
STATIC uint8 Port_C_Pin_3_Modes[] ={PORT_PC3_DIO,			
                                    PORT_PC3_TDOSWO,			
                                    PORT_PC3_T5CCP1
                                    };

/* Array defining allowed modes for PortC pin 4*/
STATIC uint8 Port_C_Pin_4_Modes[] ={PORT_PC4_DIO,			
                                    PORT_PC4_C1_NEG,			
                                    PORT_PC4_U4Rx,			
                                    PORT_PC4_U1Rx,			
                                    PORT_PC4_M0PWM6,			
                                    PORT_PC4_IDX1,			
                                    PORT_PC4_WT0CCP0,		
                                    PORT_PC4_U1RTS
                                    };

/* Array defining allowed modes for PortC pin 5*/
STATIC uint8 Port_C_Pin_5_Modes[] ={PORT_PC5_DIO,			
                                    PORT_PC5_C1_POS,			
                                    PORT_PC5_U4Tx,			
                                    PORT_PC5_U1Tx,			
                                    PORT_PC5_M0PWM7,			
                                    PORT_PC5_PhA1,			
                                    PORT_PC5_WT0CCP1,		
                                    PORT_PC5_U1CTS 
                                    };

/* Array defining allowed modes for PortC pin 6*/
STATIC uint8 Port_C_Pin_6_Modes[] ={PORT_PC6_DIO,			
                                    PORT_PC6_C0_POS,			
                                    PORT_PC6_U3Rx,			
                                    PORT_PC6_PhB1,			
                                    PORT_PC6_WT1CCP0,		
                                    PORT_PC6_USB0EPEN       	
                                    };

/* Array defining allowed modes for PortC pin 7*/
STATIC uint8 Port_C_Pin_7_Modes[] ={PORT_PC7_DIO,			
                                    PORT_PC7_C0_NEG, 		
                                    PORT_PC7_U3Tx,			
                                    PORT_PC7_WT1CCP1,		
                                    PORT_PC7_USB0PFLT    
                                    };



/* Array defining allowed modes for PortD pin 0*/
STATIC uint8 Port_D_Pin_0_Modes[] ={PORT_PD0_DIO,			
                                    PORT_PD0_AIN7,			
                                    PORT_PD0_SSI3Clk,		
                                    PORT_PD0_SSI1Clk,		
                                    PORT_PD0_I2C3SCL,		
                                    PORT_PD0_M0PWM6,			
                                    PORT_PD0_M1PWM0,			
                                    PORT_PD0_WT2CCP0  		
                                    };

/* Array defining allowed modes for PortD pin 1*/
STATIC uint8 Port_D_Pin_1_Modes[] ={PORT_PD1_DIO,			
                                    PORT_PD1_AIN6,			
                                    PORT_PD1_SSI3Fss,		
                                    PORT_PD1_SSI1Fss,		
                                    PORT_PD1_I2C3SDA,		
                                    PORT_PD1_M0PWM7,			
                                    PORT_PD1_M1PWM1,			
                                    PORT_PD1_WT2CCP1    
                                    };

/* Array defining allowed modes for PortD pin 2*/
STATIC uint8 Port_D_Pin_2_Modes[] ={PORT_PD2_DIO,			
                                    PORT_PD2_AIN5,			
                                    PORT_PD2_SSI3Rx, 		
                                    PORT_PD2_SSI1Rx,			
                                    PORT_PD2_M0FAULT0,		
                                    PORT_PD2_WT3CCP0,	
                                    PORT_PD2_USB0EPEN,
                                    };

/* Array defining allowed modes for PortD pin 3*/
STATIC uint8 Port_D_Pin_3_Modes[] ={PORT_PD3_DIO,			
                                    PORT_PD3_AIN4,			
                                    PORT_PD3_SSI3Tx,			
                                    PORT_PD3_SSI1Tx,			
                                    PORT_PD3_IDX0,			
                                    PORT_PD3_WT3CCP1,		
                                    PORT_PD3_USB0PFLT,   
                                    };

/* Array defining allowed modes for PortD pin 4*/
STATIC uint8 Port_D_Pin_4_Modes[] ={PORT_PD4_DIO,			
                                    PORT_PD4_USB0DM,			
                                    PORT_PD4_U6Rx,			
                                    PORT_PD4_WT4CCP0,      
                                    };

/* Array defining allowed modes for PortD pin 5*/
STATIC uint8 Port_D_Pin_5_Modes[] ={PORT_PD5_DIO,			
                                    PORT_PD5_USB0DP, 		
                                    PORT_PD5_U6Tx, 			
                                    PORT_PD5_WT4CCP1,
                                    };

/* Array defining allowed modes for PortD pin 6*/
STATIC uint8 Port_D_Pin_6_Modes[] ={PORT_PD6_DIO,			
                                    PORT_PD6_U2Rx,			
                                    PORT_PD6_M0FAULT0,		
                                    PORT_PD6_PhA0,			
                                    PORT_PD6_WT5CCP0,       
                                    };

/* Array defining allowed modes for PortD pin 7*/
STATIC uint8 Port_D_Pin_7_Modes[] ={PORT_PD7_DIO,			
                                    PORT_PD7_U2Tx,			
                                    PORT_PD7_PhB0,			
                                    PORT_PD7_WT5CCP1,		
                                    PORT_PD7_NMI,                    
                                    };


/* Array defining allowed modes for PortE pin 0*/
STATIC uint8 Port_E_Pin_0_Modes[] ={PORT_PE0_DIO,			
                                    PORT_PE0_AIN3,			
                                    PORT_PE0_U7Rx
                                    };

/* Array defining allowed modes for PortE pin 1*/
STATIC uint8 Port_E_Pin_1_Modes[] ={PORT_PE1_DIO,			
                                    PORT_PE1_AIN2,			
                                    PORT_PE1_U7Tx      
                                    };

/* Array defining allowed modes for PortE pin 2*/
STATIC uint8 Port_E_Pin_2_Modes[] ={PORT_PE2_DIO,			
                                    PORT_PE2_AIN1
                                    };

/* Array defining allowed modes for PortE pin 3*/
STATIC uint8 Port_E_Pin_3_Modes[] ={PORT_PE3_DIO,			
                                    PORT_PE3_AIN0 
                                    };

/* Array defining allowed modes for PortE pin 4*/
STATIC uint8 Port_E_Pin_4_Modes[] ={PORT_PE4_DIO,			
                                    PORT_PE4_AIN9,			
                                    PORT_PE4_U5Rx,			
                                    PORT_PE4_I2C2SCL,		
                                    PORT_PE4_M0PWM4,			
                                    PORT_PE4_M1PWM2,			
                                    PORT_PE4_CAN0Rx        
                                    };

/* Array defining allowed modes for PortE pin 5*/
STATIC uint8 Port_E_Pin_5_Modes[] ={PORT_PE5_DIO,			
                                    PORT_PE5_AIN8,			
                                    PORT_PE5_U5Tx,			
                                    PORT_PE5_I2C2SDA,		
                                    PORT_PE5_M0PWM5,			
                                    PORT_PE5_M1PWM3,			
                                    PORT_PE5_CAN0Tx     
                                    };


 /* Array defining allowed modes for PortF pin 0*/           
STATIC uint8 Port_F_Pin_0_Modes[] ={PORT_PF0_DIO,			
                                    PORT_PF0_U1RTS,			
                                    PORT_PF0_SSI1Rx,			
                                    PORT_PF0_CAN0Rx,			
                                    PORT_PF0_M1PWM4,			
                                    PORT_PF0_PhA0,			
                                    PORT_PF0_T0CCP0,			
                                    PORT_PF0_NMI,			
                                    PORT_PF0_C0o     
                                    };

/* Array defining allowed modes for PortF pin 1*/
STATIC uint8 Port_F_Pin_1_Modes[] ={PORT_PF1_DIO,			
                                    PORT_PF1_U1CTS,			
                                    PORT_PF1_SSI1Tx,			
                                    PORT_PF1_M1PWM5,			
                                    PORT_PF1_PhB0,			
                                    PORT_PF1_T0CCP1, 		
                                    PORT_PF1_C1o,			
                                    PORT_PF1_TRD1	
                                    };

/* Array defining allowed modes for PortF pin 2*/
STATIC uint8 Port_F_Pin_2_Modes[] ={PORT_PF2_DIO,			
                                    PORT_PF2_SSI1Clk,		
                                    PORT_PF2_M0FAULT0,		
                                    PORT_PF2_M1PWM6,			
                                    PORT_PF2_T1CCP0,			
                                    PORT_PF2_TRD0      
                                    };

/* Array defining allowed modes for PortF pin 3*/
STATIC uint8 Port_F_Pin_3_Modes[] ={PORT_PF3_DIO,			
                                    PORT_PF3_SSI1Fss,		
                                    PORT_PF3_CAN0Tx,			
                                    PORT_PF3_M1PWM7,			
                                    PORT_PF3_T1CCP1, 		
                                    PORT_PF3_TRCLK   
                                    };

/* Array defining allowed modes for PortF pin 4*/
STATIC uint8 Port_F_Pin_4_Modes[] ={PORT_PF4_DIO,			
                                    PORT_PF4_M1FAULT0,		
                                    PORT_PF4_IDX0,			
                                    PORT_PF4_T2CCP0,			
                                    PORT_PF4_USB0EPEN    
                                    };
/* Array of pointer to all allowed modes for the Mcu */  	
STATIC uint8* Port_ModesMapper[] = {Port_A_Pin_0_Modes,
                                    Port_A_Pin_1_Modes,
                                    Port_A_Pin_2_Modes,
                                    Port_A_Pin_3_Modes,
                                    Port_A_Pin_4_Modes,
                                    Port_A_Pin_5_Modes,
                                    Port_A_Pin_6_Modes,
                                    Port_A_Pin_7_Modes,
                                    Port_B_Pin_0_Modes,
                                    Port_B_Pin_1_Modes,
                                    Port_B_Pin_2_Modes,
                                    Port_B_Pin_3_Modes,
                                    Port_B_Pin_4_Modes,
                                    Port_B_Pin_5_Modes,
                                    Port_B_Pin_6_Modes,
                                    Port_B_Pin_7_Modes,
                                    Port_C_Pin_0_Modes,
                                    Port_C_Pin_1_Modes,
                                    Port_C_Pin_2_Modes,
                                    Port_C_Pin_3_Modes,
                                    Port_C_Pin_4_Modes,
                                    Port_C_Pin_5_Modes,
                                    Port_C_Pin_6_Modes,
                                    Port_C_Pin_7_Modes,
                                    Port_D_Pin_0_Modes,
                                    Port_D_Pin_1_Modes,
                                    Port_D_Pin_2_Modes,
                                    Port_D_Pin_3_Modes,
                                    Port_D_Pin_4_Modes,
                                    Port_D_Pin_5_Modes,
                                    Port_D_Pin_6_Modes,
                                    Port_D_Pin_7_Modes,
                                    Port_E_Pin_0_Modes,
                                    Port_E_Pin_1_Modes,
                                    Port_E_Pin_2_Modes,
                                    Port_E_Pin_3_Modes,
                                    Port_E_Pin_4_Modes,
                                    Port_E_Pin_5_Modes,
                                    Port_F_Pin_0_Modes,
                                    Port_F_Pin_1_Modes,
                                    Port_F_Pin_2_Modes,
                                    Port_F_Pin_3_Modes,
                                    Port_F_Pin_4_Modes
                                    };
/* Array containing number of allowed modes*/
STATIC uint8 Port_PinNumberOfAllowedModes[] ={sizeof(Port_A_Pin_0_Modes)/sizeof(Port_A_Pin_0_Modes[0]),
                                            sizeof(Port_A_Pin_1_Modes)/sizeof(Port_A_Pin_1_Modes[0]),
                                            sizeof(Port_A_Pin_2_Modes)/sizeof(Port_A_Pin_2_Modes[0]),
                                            sizeof(Port_A_Pin_3_Modes)/sizeof(Port_A_Pin_3_Modes[0]),
                                            sizeof(Port_A_Pin_4_Modes)/sizeof(Port_A_Pin_4_Modes[0]),
                                            sizeof(Port_A_Pin_5_Modes)/sizeof(Port_A_Pin_5_Modes[0]),
                                            sizeof(Port_A_Pin_6_Modes)/sizeof(Port_A_Pin_6_Modes[0]),
                                            sizeof(Port_A_Pin_7_Modes)/sizeof(Port_A_Pin_7_Modes[0]),
                                            sizeof(Port_B_Pin_0_Modes)/sizeof(Port_B_Pin_0_Modes[0]),
                                            sizeof(Port_B_Pin_1_Modes)/sizeof(Port_B_Pin_1_Modes[0]),
                                            sizeof(Port_B_Pin_2_Modes)/sizeof(Port_B_Pin_2_Modes[0]),
                                            sizeof(Port_B_Pin_3_Modes)/sizeof(Port_B_Pin_3_Modes[0]),
                                            sizeof(Port_B_Pin_4_Modes)/sizeof(Port_B_Pin_4_Modes[0]),
                                            sizeof(Port_B_Pin_5_Modes)/sizeof(Port_B_Pin_5_Modes[0]),
                                            sizeof(Port_B_Pin_6_Modes)/sizeof(Port_B_Pin_6_Modes[0]),
                                            sizeof(Port_B_Pin_7_Modes)/sizeof(Port_B_Pin_7_Modes[0]),
                                            sizeof(Port_C_Pin_0_Modes)/sizeof(Port_C_Pin_0_Modes[0]),
                                            sizeof(Port_C_Pin_1_Modes)/sizeof(Port_C_Pin_1_Modes[0]),
                                            sizeof(Port_C_Pin_2_Modes)/sizeof(Port_C_Pin_2_Modes[0]),
                                            sizeof(Port_C_Pin_3_Modes)/sizeof(Port_C_Pin_3_Modes[0]),
                                            sizeof(Port_C_Pin_4_Modes)/sizeof(Port_C_Pin_4_Modes[0]),
                                            sizeof(Port_C_Pin_5_Modes)/sizeof(Port_C_Pin_5_Modes[0]),
                                            sizeof(Port_C_Pin_6_Modes)/sizeof(Port_C_Pin_6_Modes[0]),
                                            sizeof(Port_C_Pin_7_Modes)/sizeof(Port_C_Pin_7_Modes[0]),
                                            sizeof(Port_D_Pin_0_Modes)/sizeof(Port_D_Pin_0_Modes[0]),
                                            sizeof(Port_D_Pin_1_Modes)/sizeof(Port_D_Pin_1_Modes[0]),
                                            sizeof(Port_D_Pin_2_Modes)/sizeof(Port_D_Pin_2_Modes[0]),
                                            sizeof(Port_D_Pin_3_Modes)/sizeof(Port_D_Pin_3_Modes[0]),
                                            sizeof(Port_D_Pin_4_Modes)/sizeof(Port_D_Pin_4_Modes[0]),
                                            sizeof(Port_D_Pin_5_Modes)/sizeof(Port_D_Pin_5_Modes[0]),
                                            sizeof(Port_D_Pin_6_Modes)/sizeof(Port_D_Pin_6_Modes[0]),
                                            sizeof(Port_D_Pin_7_Modes)/sizeof(Port_D_Pin_7_Modes[0]),
                                            sizeof(Port_E_Pin_0_Modes)/sizeof(Port_E_Pin_0_Modes[0]),
                                            sizeof(Port_E_Pin_1_Modes)/sizeof(Port_E_Pin_1_Modes[0]),
                                            sizeof(Port_E_Pin_2_Modes)/sizeof(Port_E_Pin_2_Modes[0]),
                                            sizeof(Port_E_Pin_3_Modes)/sizeof(Port_E_Pin_3_Modes[0]),
                                            sizeof(Port_E_Pin_4_Modes)/sizeof(Port_E_Pin_4_Modes[0]),
                                            sizeof(Port_E_Pin_5_Modes)/sizeof(Port_E_Pin_5_Modes[0]),
                                            sizeof(Port_F_Pin_0_Modes)/sizeof(Port_F_Pin_0_Modes[0]),
                                            sizeof(Port_F_Pin_1_Modes)/sizeof(Port_F_Pin_1_Modes[0]),
                                            sizeof(Port_F_Pin_2_Modes)/sizeof(Port_F_Pin_2_Modes[0]),
                                            sizeof(Port_F_Pin_3_Modes)/sizeof(Port_F_Pin_3_Modes[0]),
                                            sizeof(Port_F_Pin_4_Modes)/sizeof(Port_F_Pin_4_Modes[0])
                                            };

/**********************************************************************************************************************
*  GLOBAL DATA
*********************************************************************************************************************/

/*configuration pointer*/
extern Port_ConfigType Port_Configuration;

/**********************************************************************************************************************
*  LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************************/
/* local function to configure output current ampere*/
STATIC void Port_ConfigOutputCurrent(uint8 portOutputCurrent,uint32 pinAddress,Port_PinType offset); 
/* local function to configure attached resistor to input pin */
STATIC void Port_ConfigureAttachresistor(uint8 resistorType, uint32 regaddress, Port_PinType offset);
/* local function to configure pin mode */
STATIC void Port_ConfigurePinMode(Port_PinModeType alternatingFun,uint32 regAddress,Port_PinType offset);
/* local function to check if mode is valid*/
STATIC boolean Port_IsPortModeValid(uint8 pinMode,Port_PortType portNumber ,uint8 offset);


/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
*********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Port_Init(const Port_ConfigType * ConfigPtr)        
* \Description     : This function initializes ALL port pins in port driver module using configuration files                            
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : const Port_ConfigType * ConfigPtr                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr)
{
  
  /*if DET errors are enabled*/ 
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  
  /*if configuration pointer is null during initialize*/ 
  if (ConfigPtr == NULL_PTR)
    
  {
    
    /* Report det error */ 
    Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                     PORT_E_PARAM_CONFIG);
    
    
  }
  else				/*else initialize the Port driver with the provided pointer */
#endif	
  {
    
    /* Set port driver status is initialized */      
    Port_InitializeStatus = PORT_INITIALIZED;	
    /* set configuration pointer to the configuration array */
    Port_ConfigurationPinsPointer = ConfigPtr->ConfiguredPinsArray;
    
    /*********** First Clock enable for ports to apply initial configuration********************/
    
    /*************************enabling port A ************************/
#if(PORTA_ENABLE==PORT_ENABLE)
    
    SET_BIT(RCGCGPIO,R0);
#elif(PORTA_ENABLE==PORT_DISABLE)
    
#else
#error "Wrong configuration, please choose either PORT_ENABLE or PORT_DISABLE"
#endif
    /*************************enabling port B ************************/
#if(PORTB_ENABLE==PORT_ENABLE)
    
    SET_BIT(RCGCGPIO,R1);
#elif(PORTB_ENABLE==PORT_DISABLE)
    
#else
#error "Wrong configuration, please choose either PORT_ENABLE or PORT_DISABLE"
#endif
    /*************************enabling port C ************************/
    
#if(PORTC_ENABLE==PORT_ENABLE)
    SET_BIT(RCGCGPIO,R2);
#elif(PORTC_ENABLE==PORT_DISABLE)
    
#else
#error "Wrong configuration, please choose either PORT_ENABLE or PORT_DISABLE"
#endif
    
    /*************************enabling port D ************************/
    
#if(PORTD_ENABLE==PORT_ENABLE)
    SET_BIT(RCGCGPIO,R3);
#elif(PORTD_ENABLE==PORT_DISABLE)
    
#else
#error "Wrong configuration, please choose either PORT_ENABLE or PORT_DISABLE"
#endif
    
    /*************************enabling port E ************************/
    
#if(PORTE_ENABLE==PORT_ENABLE)
    SET_BIT(RCGCGPIO,R4);
#elif(PORTE_ENABLE==PORT_DISABLE)
    
#else
#error "Wrong configuration, please choose either PORT_ENABLE or PORT_DISABLE"
#endif
    
    /*************************enabling port F ************************/
    
#if(PORTF_ENABLE==PORT_ENABLE)
    SET_BIT(RCGCGPIO,R5);
#elif(PORTF_ENABLE==PORT_DISABLE)
    
#else
#error "Wrong configuration, please choose either PORT_ENABLE or PORT_DISABLE"
#endif
    
    
    /*********************Second set configurations of each pin*********************************************/
    
    /* loop for all the configuration pins */
    for (uint8 i=0;i<PORT_NUMBER_OF_CONFIGURED_PINS;i++)
    {
      /* Get port number from configuration pointer*/
      Port_PortType ConfiguredPort = Port_ConfigurationPinsPointer[i].PortConfigPortNumber;
      /* Get the port address using the mapping array */
      uint32 pinBaseAddress = portAPBbaseAddressArray[Port_ConfigurationPinsPointer[i].PortConfigPortNumber];
      /* Get pin number from configuration pointer */
      Port_PinType ConfiguredPin = Port_ConfigurationPinsPointer[i].PortConfigPinNumber;
      
      
      /***************** Step1) Unlock the register if required ******************************/        
      /*if the configured pin is PD7 or PF0*/
      if (((ConfiguredPort == PORT_PORT_D)&&(ConfiguredPin == PORT_PIN_D_7))
          ||((ConfiguredPort == PORT_PORT_F)&&((ConfiguredPin == PORT_PIN_F_0))))
      {
        /*Unlock the lock register*/
        GPIOLOCK(pinBaseAddress) = 0x4C4F434B;
        /*Commit the change*/
        SET_BIT(GPIOCR(pinBaseAddress),ConfiguredPin);        }
      /* else if the configured pins are the JTAG pins*/
      else if (((ConfiguredPort == PORT_PORT_C)&&(ConfiguredPin == PORT_PIN_C_3
                                                  ||ConfiguredPin == PORT_PIN_C_2
                                                    ||ConfiguredPin == PORT_PIN_C_1
                                                      ||ConfiguredPin == PORT_PIN_C_0)))
      {
        /* Do nothing these are JTAG pins */
      }
      else
      {
        /* Do nothing */
      }
      
      /***********************Step2) Configure the pinMode of the pin*****************************************/
      Port_ConfigurePinMode(Port_ConfigurationPinsPointer[i].PortPinMode,pinBaseAddress,ConfiguredPin);
      
      
      /*************************Step4) Configure the pin Direction ***********************************/
      /*************************Step5) Configure output current if output and resistor config if input *****/
      
      /* if the pin direction is output*/
      if (Port_ConfigurationPinsPointer[i].PortPinDirection == PORT_PIN_OUT)
      {
        /*Set direction to output*/
        SET_BIT(GPIODIR(pinBaseAddress),ConfiguredPin);				
        /*configure output current value*/
        Port_ConfigOutputCurrent(Port_ConfigurationPinsPointer[i].PortOutputCurrent,pinBaseAddress,ConfiguredPin);
        /*Get bid address for bit banding */
        volatile uint32* pinAddress = &(GPIODATA(pinBaseAddress+(0x04<<ConfiguredPin)));
        /*Set the output value */
        *pinAddress = Port_ConfigurationPinsPointer[i].PortPinLevelValue<<ConfiguredPin;             
	
      }
      /* if pin direction is input */
      else if (Port_ConfigurationPinsPointer[i].PortPinDirection == PORT_PIN_IN)
      {
		
				
        /*Clear direction register to set pin as input*/
        CLEAR_BIT(GPIODIR(pinBaseAddress),ConfiguredPin);
        
			
				
      /* Configure input resistor */
      Port_ConfigureAttachresistor(Port_ConfigurationPinsPointer[i].PortPinResistorAttchIfInput, pinBaseAddress, ConfiguredPin);
      
				        
      }
      else 
      {
        /*Do nothing and return error*/
      }
      
      
    }
    
    
  }
}

/******************************************************************************
* \Syntax          : void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)       
* \Description     : This function sets the port pin direction during runtime                           
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Pin (Port pin ID number)
*                    Direction (Port Pin directon)
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction)
{
  /* variable to detect det error */
  boolean isDetErrorDetected = FALSE;
  /* Get the port address using the mapping array */
  uint32 pinBaseAddress = portAPBbaseAddressArray[Port_ConfigurationPinsPointer[Pin].PortConfigPortNumber];
  /* Get pin number from configuration pointer */
  Port_PinType ConfiguredPin = Port_ConfigurationPinsPointer[Pin].PortConfigPinNumber;
  /* if Det errors are enabled */        
#if (PORT_DEV_ERROR_DETECT == STD_ON)       
  /* If port is not initialized*/      
  if (Port_InitializeStatus == PORT_NOT_INITIALIZED)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
  }
  else
  {
    /*Do nothing*/
  }
  
  /*if Pin ID is greater than the number of configured pins*/
  if (Pin>= PORT_NUMBER_OF_CONFIGURED_PINS)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
  }
  else
  {
    /*Do nothing*/
  }
  
  
  /* If pin is not allowed to be configured during runtime*/
  if (Port_ConfigurationPinsPointer[Pin].PortPinDirectionChangeable == FALSE)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
    
  }
  else
  {
    /*Do nothing*/
  }
  
#endif
  
  
  if (isDetErrorDetected == FALSE) 
  {
    /* if direction is set to output */
    if (Direction == PORT_PIN_OUT)
    {
      /*Set direction to output*/
      SET_BIT(GPIODIR(pinBaseAddress),ConfiguredPin);				
     
    }
    /* if direction is set to input */
    else if (Direction == PORT_PIN_IN)
    {
      /*Clear direction register to set pin as input*/
      CLEAR_BIT(GPIODIR(pinBaseAddress),ConfiguredPin);
      
    }
    else 
    {
      /*Do nothing */
    }
    
    
  }
}

/* This function refresh the mode of all pins whose mode is not changeable during runtime*/
/******************************************************************************
* \Syntax          : void Port_RefreshPortDirection( void )
* \Description     : This function refreshes port direction for pins whose
*                    direction is unchangeable during runtime
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
void Port_RefreshPortDirection(void)
{
  /* variable to detect det error */
  boolean isDetErrorDetected = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)       
  /* If port is not initialized*/      
  if (Port_InitializeStatus == PORT_NOT_INITIALIZED)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
  }
  else
  {
    /*Do nothing*/
  }
  
  
#endif
  
  
  if (isDetErrorDetected == FALSE) 
  {
    
    for (int i=0;i<PORT_NUMBER_OF_CONFIGURED_PINS;i++)
    {
      /* Get the port address using the mapping array */
      uint32 pinBaseAddress = portAPBbaseAddressArray[Port_ConfigurationPinsPointer[i].PortConfigPortNumber];
      /* Get pin number from configuration pointer */
      Port_PinType ConfiguredPin = Port_ConfigurationPinsPointer[i].PortConfigPinNumber;
      
      /* if pin direction is not changeable in run time*/
      if (Port_ConfigurationPinsPointer[i].PortPinDirectionChangeable == FALSE)
      {
        /*if the direction is configured to output*/
        if (Port_ConfigurationPinsPointer[i].PortPinDirection == PORT_PIN_OUT)
        {
          /*Set direction to output*/
          SET_BIT(GPIODIR(pinBaseAddress),ConfiguredPin);				
           
        }
        /*if the direction is configured to input*/
        else if (Port_ConfigurationPinsPointer[i].PortPinDirection == PORT_PIN_IN)
        {
          /*Clear direction register to set pin as input*/
          CLEAR_BIT(GPIODIR(pinBaseAddress),ConfiguredPin);
          
        }
        else 
        {
          /*Do nothing and return error*/
        }
      }
      else
      {
        /* Do nothing */
      }
    }
  }
  
}

/******************************************************************************
* \Syntax          : void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
* \Description     : This function returns version information of this module
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): versioninfo (pointer to where version info are stored of this module)                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)

void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
  /* variable to detect det error */
  boolean isDetErrorDetected = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)       
  /* If port is not initialized*/      
  if (Port_InitializeStatus == PORT_NOT_INITIALIZED)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_UNINIT);
  }
  else
  {
    /*Do nothing*/
  }
  
  /*if the versioninfo ointer in null pointer*/
  if (versioninfo == NULL_PTR)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  (PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
  }
  else
  {
    /* Do nothing */
  }
  
#endif
  
  
  if (isDetErrorDetected == FALSE) 
  {
    /* point the versioninfo to the structure containing driver data*/
    *versioninfo = Port_VersionInfo;
    
  }
}
#elif (PORT_GET_VERSION_INFO_API == STD_OFF)

#else
#error "Wrong mode chosen for PORT_GET_VERSION_INFO_API, please choose either STD_ON or STD_OFF"
#endif 


/******************************************************************************
* \Syntax          : void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
* \Description     : This function sets pin mode of the port pins during runtime
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Pin (Port Pin ID number)
*                    Mode (New port pin Mode)
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
/* This functions sets the pinMode of the pin*/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
  /* variable to detect det error */
  boolean isDetErrorDetected = FALSE;
  /* Get the port address using the mapping array */
  uint32 pinBaseAddress = portAPBbaseAddressArray[Port_ConfigurationPinsPointer[Pin].PortConfigPortNumber];
  /* Get pin number from configuration pointer */
  Port_PinType ConfiguredPin = Port_ConfigurationPinsPointer[Pin].PortConfigPinNumber;
  
  /* if Det errors are enabled */        
#if (PORT_DEV_ERROR_DETECT == STD_ON)  
  /* If pin mode is not valid */
  if (Port_IsPortModeValid(Mode, Port_ConfigurationPinsPointer[Pin].PortConfigPortNumber,ConfiguredPin) == FALSE)
  {
     /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
    
  }
  else
  {
    /*Do nothing*/
  }

  /* If port is not initialized*/      
  if (Port_InitializeStatus == PORT_NOT_INITIALIZED)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
  }
  else
  {
    /*Do nothing*/
  }
  
  /*if Pin ID is greater than the number of configured pins*/
  if (Pin>= PORT_NUMBER_OF_CONFIGURED_PINS)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
  }
  else
  {
    /*Do nothing*/
  }
  
  
  /* If pin is not allowed to be configured during runtime*/
  if (Port_ConfigurationPinsPointer[Pin].PortPinModeChangeable == FALSE)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
    
  }
  else
  {
    /*Do nothing*/
  }
  
  
  
#endif
  
  
  if (isDetErrorDetected == FALSE) 
  {
    /* call local function to configure the configure the pinMode */
    Port_ConfigurePinMode(Mode,pinBaseAddress,ConfiguredPin);
    
  }
  else
  {
    /* do nothing */
  }
}


/**********************************************************************************************************************
*  LOCAL FUNCTIONS
*********************************************************************************************************************/
/* function to set the output current of output pins */
STATIC void Port_ConfigOutputCurrent(uint8 portOutputCurrent,uint32 regAddress,uint8 offset)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
{
  switch(portOutputCurrent)
  {
    /* In case the pin output current configured to 2mA, configure the corresponding register*/
  case PORT_OCURRENT_2_MA: SET_BIT(GPIODR2R(regAddress),offset);break;
  /* In case the pin output current configured to 4mA, configure the corresponding register*/
  case PORT_OCURRENT_4_MA: SET_BIT(GPIODR4R(regAddress),offset);break;
  /* In case the pin output current configured to 8mA, configure the corresponding register*/
  case PORT_OCURRENT_8_MA: SET_BIT(GPIODR8R(regAddress),offset);break;
  /* In case the pin output current configured to NA Do nothing*/
  case PORT_NA: break;
  default: /*Do nothing*/;
  
  }
}

/* function to configure attached resistors for input pins */
STATIC void Port_ConfigureAttachresistor(uint8 resistorType, uint32 regaddress, uint8 offset)
{
  switch (resistorType)
  {
    /* In case the pin resistor configured to pull down resistor, configure the corresponding register*/
  case PORT_ATTACH_PULL_DOWN_RESISTOR: SET_BIT(GPIOPDR(regaddress),offset);break;
  /* In case the pin resistor configured to pull Up resistor, configure the corresponding register*/
  case PORT_ATTACH_PULL_UP_RESISTOR: SET_BIT(GPIOPUR(regaddress),offset);break;
  /* In case the pin resistor configured to open drain, configure the corresponding register*/
  case PORT_ATTACH_OPEN_DRAIN: SET_BIT(GPIOODR(regaddress),offset);break;
  /* In case the pin resistor  no configuration, Do nothing*/
  case PORT_NA:break;
  default : /*Do nothing*/;
  }			
}

STATIC boolean Port_IsPortModeValid(uint8 pinMode,Port_PortType portNumber ,Port_PinType offset)
{
  /* if pi mode is greater than largest allowed value*/
  if (pinMode >15)
  {
    /*return false*/
    return FALSE;
    
  }
  else
  {
    /*Do Nothing*/
  }
  /*set initial value for portOffset to 0, port offset value is the starting pin location of the current port, ex: portB starts with pin8 */
  uint8 portOffset = 0;
  /* get the portOffset which corresponds to location of the pin in the array*/
  switch (portNumber)
  {
  case PORT_PORT_A: portOffset =  0;break;
  case PORT_PORT_B: portOffset =  8;break;
  case PORT_PORT_C: portOffset = 16;break;
  case PORT_PORT_D: portOffset = 24;break;
  case PORT_PORT_E: portOffset = 32;break;
  case PORT_PORT_F: portOffset = 38;break;
  default:break; 
  }
  /*get the allowed values array location*/
  uint8 arrayMapperPointerLocation = portOffset + offset;
  /*loop on all allowed modes for the current pin*/
  for (uint8 i =0; i<Port_PinNumberOfAllowedModes[arrayMapperPointerLocation]; i++)
  {
    /*if current mode exists in the allowed modes*/
    if (pinMode == Port_ModesMapper[arrayMapperPointerLocation][i])
    {
      /* return true*/
      return TRUE;
    }
    else
    {
      /* Do nothing*/
    }
  }
    /*if looped on all values and mode not found return false*/
    return FALSE;
  }

/* function to configure pinMode of the port pin */
STATIC void Port_ConfigurePinMode(uint8 alternatingFun,uint32 regAddress,uint8 offset)
{
  if (alternatingFun == PORT_PINx_ANALOG_FUNC)
  {
    /*Disable Digital Mode*/
    CLEAR_BIT(GPIODEN(regAddress),offset);
    /*Enable alternative mode*/
    SET_BIT(GPIOAMSEL(regAddress),offset);		
  }
  else if(alternatingFun == PORT_PINx_DIO)
  {
    /*Disable Alternative function*/
    CLEAR_BIT(GPIOAFSEL(regAddress),offset);
    /*Enable digital mode*/
    SET_BIT(GPIODEN(regAddress),offset);	
    /*Disable alternative mode*/
    CLEAR_BIT(GPIOAMSEL(regAddress),offset);		
  }
  else if (alternatingFun > PORT_PINx_DIO && alternatingFun <= 15)
  {
    /* Set the Mode to Alternative function*/
    SET_BIT(GPIOAFSEL(regAddress),offset);	
    /*Clear any pin previous mode configuration*/
    GPIOPCTL(regAddress) &=(uint32) 0x0<<(offset*4);
    /*Set the pin Mode to the new configuration*/
    GPIOPCTL(regAddress) |=(uint32) alternatingFun<<(offset*4);		
    /*Enable digital mode*/
    SET_BIT(GPIODEN(regAddress),offset);	
    /*Disable Analog mode*/
    CLEAR_BIT(GPIOAMSEL(regAddress),offset);		
  }
  else
  {
    /*Do nothing and return error*/
  }
}




/**********************************************************************************************************************
*  END OF FILE: Port.c
*********************************************************************************************************************/

