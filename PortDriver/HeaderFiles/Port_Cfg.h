/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  <Write File Name>
*       Module:  -
*
*  Description:  <Write File DESCRIPTION here>     
*  
*********************************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H


/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/
/* Defining the Module software verison by Major.Minor.Patch format */
#define PORT_CFG_SW_MAJOR_VERSION				(1U)
#define PORT_CFG_SW_MINOR_VERSION				(0U)
#define PORT_CFG_SW_PATCH_VERSION				(0U)

/* Defining the autosar version ued for the module */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION		(4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION		(0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION		(3U)



/*************************** DEFAULT CONFIGURATIONS FOR PORT DRIVER ****************************************/
/* Enable precompile configurations in case configuration tool will not configure all pins by default*/
#define PORT_ENABLE_PRE_COMPILE_CONFIGURATIONS  (STD_ON)
/* configuration to enable or disable DET errrors */
#define PORT_DEV_ERROR_DETECT			(STD_ON)
/* Configuration to enable or disable Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API		(STD_ON)
/* Configuration to enable or disable Port_SetPinMode API */
#define PORT_SET_PIN_MODE_API			(STD_ON)
/* Configuration to enable or disable VersionInfo API */
#define PORT_VERSION_INFO_API		        (STD_ON)



/******THIS CONFIGURATION ACTIVATES PORTx IN ORDER TO PROGRAM IT  ************
ALL PORTS SHOULD BE ENABLED FOR AUTOSAR CONFIGURATION**********/
#define PORTA_ENABLE	PORT_ENABLE
#define PORTB_ENABLE	PORT_ENABLE
#define PORTC_ENABLE	PORT_ENABLE
#define PORTD_ENABLE	PORT_ENABLE
#define PORTE_ENABLE	PORT_ENABLE
#define PORTF_ENABLE	PORT_ENABLE



/****************************** DEFAULT CONFIGURATIONS FOR PORT PINS *************************************/
/* Configuration for default pinMode configuration for all pins */
#define PORT_DEFAULT_PIN_MODE                   (PORT_PINx_DIO)  
/* Configuration for default pinDirection configuration for all pins */
#define PORT_DEFAULT_PIN_DIRECTION              (PORT_PIN_OUT)
/* Configuration for default pinLevel configuration for all pins */
#define PORT_DEFAULT_LEVEL                      (STD_LOW)
/* Configuration for default pinOutputCurrent configuration for all pins */
#define PORT_DEFAULT_OUTPUT_CURRENT             (PORT_OCURRENT_2_MA)  
/* Configuration for default pinResistorType configuration for all pins */
#define PORT_DEFAULT_RESISTOR_TYPE              (PORT_NA)   
/* Configuration for default configuration if pinDirection is changeable for all pins */
#define PORT_DEFAULT_IS_DIRECTION_CHANGEABLE    (FALSE)
/* Configuration for default configuration if pinMode is changeable for all pins */
#define PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE     (FALSE)







/* Number of configured pins*/
#define PORT_NUMBER_OF_CONFIGURED_PINS		(39U)



/* Indeces of configured pins */
#define PortConf_PORT_PIN_00_INDEX             ((uint8)0x00)
#define PortConf_PORT_PIN_01_INDEX             ((uint8)0x01)
#define PortConf_PORT_PIN_02_INDEX             ((uint8)0x02)
#define PortConf_PORT_PIN_03_INDEX             ((uint8)0x03)
#define PortConf_PORT_PIN_04_INDEX             ((uint8)0x04)
#define PortConf_PORT_PIN_05_INDEX             ((uint8)0x05)
#define PortConf_PORT_PIN_06_INDEX             ((uint8)0x06)
#define PortConf_PORT_PIN_07_INDEX             ((uint8)0x07)
#define PortConf_PORT_PIN_08_INDEX             ((uint8)0x08)
#define PortConf_PORT_PIN_09_INDEX             ((uint8)0x09)
#define PortConf_PORT_PIN_10_INDEX             ((uint8)0x0A)
#define PortConf_PORT_PIN_11_INDEX             ((uint8)0x0B)
#define PortConf_PORT_PIN_12_INDEX             ((uint8)0x0C)
#define PortConf_PORT_PIN_13_INDEX             ((uint8)0x0D)
#define PortConf_PORT_PIN_14_INDEX             ((uint8)0x0E)
#define PortConf_PORT_PIN_15_INDEX             ((uint8)0x0F)

/* Exclude JTAG PINS
PortConf_PORT_C_PIN_16_ID_INDEX             
PortConf_PORT_C_PIN_17_ID_INDEX             
PortConf_PORT_C_PIN_18_ID_INDEX             
PortConf_PORT_C_PIN_19_ID_INDEX             
*/
#define PortConf_PORT_PIN_20_INDEX              ((uint8)0x10)
#define PortConf_PORT_PIN_21_INDEX              ((uint8)0x11)
#define PortConf_PORT_PIN_22_INDEX              ((uint8)0x12)
#define PortConf_PORT_PIN_23_INDEX              ((uint8)0x13)
#define PortConf_PORT_PIN_24_INDEX              ((uint8)0x14)
#define PortConf_PORT_PIN_25_INDEX              ((uint8)0x15)
#define PortConf_PORT_PIN_26_INDEX              ((uint8)0x16)
#define PortConf_PORT_PIN_27_INDEX              ((uint8)0x17)
#define PortConf_PORT_PIN_28_INDEX              ((uint8)0x18)
#define PortConf_PORT_PIN_29_INDEX              ((uint8)0x19)
#define PortConf_PORT_PIN_30_INDEX              ((uint8)0x1A)
#define PortConf_PORT_PIN_31_INDEX              ((uint8)0x1B)
#define PortConf_PORT_PIN_32_INDEX              ((uint8)0x1C)
#define PortConf_PORT_PIN_33_INDEX              ((uint8)0x1D)
#define PortConf_PORT_PIN_34_INDEX              ((uint8)0x1E)
#define PortConf_PORT_PIN_35_INDEX              ((uint8)0x1F)
#define PortConf_PORT_PIN_36_INDEX              ((uint8)0x20)
#define PortConf_PORT_PIN_37_INDEX              ((uint8)0x21)
#define PortConf_PORT_PIN_38_INDEX              ((uint8)0x22)
#define PortConf_LED1_PIN_ID_INDEX              ((uint8)0x23)
#define PortConf_PORT_PIN_40_INDEX              ((uint8)0x24)
#define PortConf_PORT_PIN_41_INDEX              ((uint8)0x25)
#define PortConf_SW1_PIN_ID_INDEX               ((uint8)0x26)

/* Port Configured Port ID's  */
#define PortConf_PORT_PIN_00_PORT                     ((Port_PortType)PORT_PORT_A) /* PORTA */
#define PortConf_PORT_PIN_01_PORT                     ((Port_PortType)PORT_PORT_A) /* PORTA */
#define PortConf_PORT_PIN_02_PORT                     ((Port_PortType)PORT_PORT_A) /* PORTA */
#define PortConf_PORT_PIN_03_PORT                     ((Port_PortType)PORT_PORT_A) /* PORTA */
#define PortConf_PORT_PIN_04_PORT                     ((Port_PortType)PORT_PORT_A) /* PORTA */
#define PortConf_PORT_PIN_05_PORT                     ((Port_PortType)PORT_PORT_A) /* PORTA */
#define PortConf_PORT_PIN_06_PORT                     ((Port_PortType)PORT_PORT_A) /* PORTA */
#define PortConf_PORT_PIN_07_PORT                     ((Port_PortType)PORT_PORT_A) /* PORTA */
#define PortConf_PORT_PIN_08_PORT                     ((Port_PortType)PORT_PORT_B) /* PORTB */
#define PortConf_PORT_PIN_09_PORT                     ((Port_PortType)PORT_PORT_B) /* PORTB */
#define PortConf_PORT_PIN_10_PORT                     ((Port_PortType)PORT_PORT_B) /* PORTB */
#define PortConf_PORT_PIN_11_PORT                     ((Port_PortType)PORT_PORT_B) /* PORTB */
#define PortConf_PORT_PIN_12_PORT                     ((Port_PortType)PORT_PORT_B) /* PORTB */
#define PortConf_PORT_PIN_13_PORT                     ((Port_PortType)PORT_PORT_B) /* PORTB */
#define PortConf_PORT_PIN_14_PORT                     ((Port_PortType)PORT_PORT_B) /* PORTB */
#define PortConf_PORT_PIN_15_PORT                     ((Port_PortType)PORT_PORT_B) /* PORTB */
#define PortConf_PORT_PIN_20_PORT                     ((Port_PortType)PORT_PORT_C) /* PORTC */
#define PortConf_PORT_PIN_21_PORT                     ((Port_PortType)PORT_PORT_C) /* PORTC */
#define PortConf_PORT_PIN_22_PORT                     ((Port_PortType)PORT_PORT_C) /* PORTC */
#define PortConf_PORT_PIN_23_PORT                     ((Port_PortType)PORT_PORT_C) /* PORTC */
#define PortConf_PORT_PIN_24_PORT                     ((Port_PortType)PORT_PORT_D) /* PORTD */
#define PortConf_PORT_PIN_25_PORT                     ((Port_PortType)PORT_PORT_D) /* PORTD */
#define PortConf_PORT_PIN_26_PORT                     ((Port_PortType)PORT_PORT_D) /* PORTD */
#define PortConf_PORT_PIN_27_PORT                     ((Port_PortType)PORT_PORT_D) /* PORTD */
#define PortConf_PORT_PIN_28_PORT                     ((Port_PortType)PORT_PORT_D) /* PORTD */
#define PortConf_PORT_PIN_29_PORT                     ((Port_PortType)PORT_PORT_D) /* PORTD */
#define PortConf_PORT_PIN_30_PORT                     ((Port_PortType)PORT_PORT_D) /* PORTD */
#define PortConf_PORT_PIN_31_PORT                     ((Port_PortType)PORT_PORT_D) /* PORTD */
#define PortConf_PORT_PIN_32_PORT                     ((Port_PortType)PORT_PORT_E) /* PORTD */
#define PortConf_PORT_PIN_33_PORT                     ((Port_PortType)PORT_PORT_E) /* PORTD */
#define PortConf_PORT_PIN_34_PORT                     ((Port_PortType)PORT_PORT_E) /* PORTE */
#define PortConf_PORT_PIN_35_PORT                     ((Port_PortType)PORT_PORT_E) /* PORTE */
#define PortConf_PORT_PIN_36_PORT                     ((Port_PortType)PORT_PORT_E) /* PORTE */
#define PortConf_PORT_PIN_37_PORT                     ((Port_PortType)PORT_PORT_E) /* PORTE */
#define PortConf_PORT_PIN_38_PORT                     ((Port_PortType)PORT_PORT_F) /* PORTE */
#define PortConf_LED1_PIN_ID_PORT                     ((Port_PortType)PORT_PORT_F) /* PORTF */
#define PortConf_PORT_PIN_40_PORT                     ((Port_PortType)PORT_PORT_F) /* PORTF */
#define PortConf_PORT_PIN_41_PORT                     ((Port_PortType)PORT_PORT_F) /* PORTF */
#define PortConf_SW1_PIN_ID_PORT                      ((Port_PortType)PORT_PORT_F) /* PORTF */

/* Port Configured pins  */
#define PortConf_PORT_PIN_00_PIN                      ((Port_PinType)PORT_PIN_A_0)
#define PortConf_PORT_PIN_01_PIN                      ((Port_PinType)PORT_PIN_A_1)
#define PortConf_PORT_PIN_02_PIN                      ((Port_PinType)PORT_PIN_A_2)
#define PortConf_PORT_PIN_03_PIN                      ((Port_PinType)PORT_PIN_A_3)
#define PortConf_PORT_PIN_04_PIN                      ((Port_PinType)PORT_PIN_A_4)
#define PortConf_PORT_PIN_05_PIN                      ((Port_PinType)PORT_PIN_A_5)
#define PortConf_PORT_PIN_06_PIN                      ((Port_PinType)PORT_PIN_A_6)
#define PortConf_PORT_PIN_07_PIN                      ((Port_PinType)PORT_PIN_A_7)
#define PortConf_PORT_PIN_08_PIN                      ((Port_PinType)PORT_PIN_B_0)
#define PortConf_PORT_PIN_09_PIN                      ((Port_PinType)PORT_PIN_B_1)
#define PortConf_PORT_PIN_10_PIN                      ((Port_PinType)PORT_PIN_B_2)
#define PortConf_PORT_PIN_11_PIN                      ((Port_PinType)PORT_PIN_B_3)
#define PortConf_PORT_PIN_12_PIN                      ((Port_PinType)PORT_PIN_B_4)
#define PortConf_PORT_PIN_13_PIN                      ((Port_PinType)PORT_PIN_B_5)
#define PortConf_PORT_PIN_14_PIN                      ((Port_PinType)PORT_PIN_B_6)
#define PortConf_PORT_PIN_15_PIN                      ((Port_PinType)PORT_PIN_B_7)
#define PortConf_PORT_PIN_20_PIN                      ((Port_PinType)PORT_PIN_C_4)
#define PortConf_PORT_PIN_21_PIN                      ((Port_PinType)PORT_PIN_C_5)
#define PortConf_PORT_PIN_22_PIN                      ((Port_PinType)PORT_PIN_C_6)
#define PortConf_PORT_PIN_23_PIN                      ((Port_PinType)PORT_PIN_C_7)
#define PortConf_PORT_PIN_24_PIN                      ((Port_PinType)PORT_PIN_D_0)
#define PortConf_PORT_PIN_25_PIN                      ((Port_PinType)PORT_PIN_D_1)
#define PortConf_PORT_PIN_26_PIN                      ((Port_PinType)PORT_PIN_D_2)
#define PortConf_PORT_PIN_27_PIN                      ((Port_PinType)PORT_PIN_D_3)
#define PortConf_PORT_PIN_28_PIN                      ((Port_PinType)PORT_PIN_D_4)
#define PortConf_PORT_PIN_29_PIN                      ((Port_PinType)PORT_PIN_D_5)
#define PortConf_PORT_PIN_30_PIN                      ((Port_PinType)PORT_PIN_D_6)
#define PortConf_PORT_PIN_31_PIN                      ((Port_PinType)PORT_PIN_D_7)
#define PortConf_PORT_PIN_32_PIN                      ((Port_PinType)PORT_PIN_E_0)
#define PortConf_PORT_PIN_33_PIN                      ((Port_PinType)PORT_PIN_E_1)
#define PortConf_PORT_PIN_34_PIN                      ((Port_PinType)PORT_PIN_E_2)
#define PortConf_PORT_PIN_35_PIN                      ((Port_PinType)PORT_PIN_E_3)
#define PortConf_PORT_PIN_36_PIN                      ((Port_PinType)PORT_PIN_E_4)
#define PortConf_PORT_PIN_37_PIN                      ((Port_PinType)PORT_PIN_E_5)
#define PortConf_PORT_PIN_38_PIN                      ((Port_PinType)PORT_PIN_F_0)
#define PortConf_LED1_PIN_ID_PIN                      ((Port_PinType)PORT_PIN_F_1)
#define PortConf_PORT_PIN_40_PIN                      ((Port_PinType)PORT_PIN_F_2)
#define PortConf_PORT_PIN_41_PIN                      ((Port_PinType)PORT_PIN_F_3)
#define PortConf_SW1_PIN_ID_PIN                       ((Port_PinType)PORT_PIN_F_4)


/* Port Configured pins mode  */  
#define PortConf_PORT_PIN_00_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_01_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_02_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_03_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_04_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_05_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_06_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_07_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_08_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_09_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_10_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_11_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_12_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_13_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_14_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_15_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_20_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_21_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_22_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_23_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_24_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_25_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_26_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_27_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_28_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_29_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_30_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_31_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_32_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_33_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_34_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_35_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_36_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_37_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_38_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_LED1_PIN_ID_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_40_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_PORT_PIN_41_MODE                      PORT_DEFAULT_PIN_MODE
#define PortConf_SW1_PIN_ID_MODE                       PORT_DEFAULT_PIN_MODE


/* Port Configured pins direction  */
#define PortConf_PORT_PIN_00_DIRECTION                      PORT_PIN_IN
#define PortConf_PORT_PIN_01_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_02_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_03_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_04_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_05_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_06_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_07_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_08_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_09_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_10_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_11_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_12_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_13_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_14_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_15_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_20_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_21_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_22_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_23_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_24_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_25_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_26_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_27_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_28_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_29_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_30_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_31_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_32_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_33_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_34_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_35_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_36_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_37_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_38_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_LED1_PIN_ID_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_40_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_41_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION
#define PortConf_PORT_PIN_42_DIRECTION                      PORT_DEFAULT_PIN_DIRECTION

/* Port Configured pins level  */
#define PortConf_PORT_PIN_00_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_01_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_02_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_03_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_04_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_05_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_06_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_07_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_08_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_09_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_10_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_11_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_12_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_13_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_14_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_15_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_20_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_21_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_22_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_23_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_24_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_25_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_26_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_27_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_28_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_29_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_30_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_31_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_32_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_33_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_34_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_35_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_36_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_37_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_38_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_LED1_PIN_ID_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_40_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_PORT_PIN_41_LEVEL                               PORT_DEFAULT_PIN_LEVEL 
#define PortConf_SW1_PIN_ID_LEVEL                                PORT_DEFAULT_PIN_LEVEL 


/* Port Configured pins output current  */   
#define PortConf_PORT_PIN_00_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_01_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_02_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_03_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_04_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_05_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_06_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_07_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_08_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_09_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_10_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_11_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_12_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_13_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_14_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_15_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_20_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_21_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_22_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_23_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_24_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_25_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_26_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_27_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_28_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_29_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_30_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_31_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_32_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_33_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_34_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_35_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_36_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_37_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_38_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_LED1_PIN_ID_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_40_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_PORT_PIN_41_OUTPUT_CURRENT                      PORT_DEFAULT_OUTPUT_CURRENT
#define PortConf_SW1_PIN_ID_OUTPUT_CURRENT                       PORT_DEFAULT_OUTPUT_CURRENT





/* Port Configured pins attached resistor */    
#define PortConf_PORT_PIN_00_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_01_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_02_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_03_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_04_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_05_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_06_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_07_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_08_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_09_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_10_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_11_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_12_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_13_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_14_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_15_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_20_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_21_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_22_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_23_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_24_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_25_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_26_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_27_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_28_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_29_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_30_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_31_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_32_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_33_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_34_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_35_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_36_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_37_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_38_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_LED1_PIN_ID_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_40_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_PORT_PIN_41_RESISTOR_TYPE                       PORT_DEFAULT_RESISTOR_TYPE
#define PortConf_SW1_PIN_ID_RESISTOR_TYPE                        PORT_DEFAULT_RESISTOR_TYPE




/* is configured pin direction changeable configuration */   
#define PortConf_PORT_PIN_00_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_01_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_02_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_03_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_04_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_05_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_06_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_07_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_08_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_09_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_10_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_11_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_12_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_13_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_14_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_15_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_20_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_21_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_22_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_23_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_24_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_25_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_26_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_27_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_28_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_29_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_30_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_31_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_32_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_33_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_34_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_35_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_36_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_37_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_38_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_LED1_PIN_ID_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_40_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_PORT_PIN_41_IS_DIRECTION_CHANGEABLE            PORT_DEFAULT_IS_DIRECTION_CHANGEABLE
#define PortConf_SW1_PIN_ID_IS_DIRECTION_CHANGEABLE             TRUE

/* is configured pin mode changeable configuration */   
#define PortConf_PORT_PIN_00_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_01_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_02_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_03_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_04_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_05_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_06_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_07_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_08_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_09_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_10_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_11_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_12_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_13_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_14_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_15_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_20_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_21_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_22_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_23_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_24_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_25_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_26_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_27_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_28_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_29_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_30_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_31_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_32_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_33_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_34_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_35_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_36_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_37_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_38_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_LED1_PIN_ID_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_40_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_PORT_PIN_41_IS_PIN_MODE_CHANGEABLE   PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE
#define PortConf_SW1_PIN_ID_IS_PIN_MODE_CHANGEABLE    PORT_DEFAULT_IS_PIN_MODE_CHANGEABLE



#endif  /* PORT_CFG_H */

