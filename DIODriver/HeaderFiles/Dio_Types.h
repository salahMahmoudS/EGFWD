/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  <Write File Name>
*       Module:  -
*
*  Description:  <Write File DESCRIPTION here>     
*  
*********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H


/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/
/* Defining the company ID in the AUTOSAR */
/* I am using a dummy ID for now */

#define COMPILER_VENDOR_ID					(2007U)


/* Defining the Module software verison by Major.Minor.Patch format */

#define DIO_TYPES_SW_MAJOR_VERSION			(1U)
#define DIO_TYPES_SW_MINOR_VERSION			(0U)
#define DIO_TYPES_SW_PATCH_VERSION			(0U)

/* Defining the autosar version ued for the module */

#define DIO_TYPES_AR_RELEASE_MAJOR_VERSION		(4U)
#define DIO_TYPES_AR_RELEASE_MINOR_VERSION		(0U)
#define DIO_TYPES_AR_RELEASE_PATCH_VERSION		(3U)


/**********************************************************************************************************************
*  GLOBAL FUNCTION MACROS
*********************************************************************************************************************/


/**********************************************************************************************************************
*  GLOBAL DATA TYPES AND STRUCTURES
*********************************************************************************************************************/

/* Type definition for portLevel Type */
typedef uint8   Dio_PortLevelType; 

/* Type definition for channel Level type */
typedef uint8	Dio_LevelType;

/* Type definition for channelType and the allowed channels */
typedef uint8	Dio_ChannelType;

#define	DIO_CHANNEL_A_0 			((Dio_ChannelType) 0x00)		//PIN0
#define	DIO_CHANNEL_A_1 			((Dio_ChannelType) 0x01)     	//PIN1
#define	DIO_CHANNEL_A_2 			((Dio_ChannelType) 0x02)     	//PIN2
#define	DIO_CHANNEL_A_3 			((Dio_ChannelType) 0x03)     	//PIN3
#define	DIO_CHANNEL_A_4 			((Dio_ChannelType) 0x04)     	//PIN4
#define	DIO_CHANNEL_A_5 			((Dio_ChannelType) 0x05)     	//PIN5
#define	DIO_CHANNEL_A_6 			((Dio_ChannelType) 0x06)     	//PIN6
#define	DIO_CHANNEL_A_7 			((Dio_ChannelType) 0x07)     	//PIN7
#define	DIO_CHANNEL_B_0 			((Dio_ChannelType) 0x00)     	//PIN8
#define	DIO_CHANNEL_B_1 			((Dio_ChannelType) 0x01)     	//PIN9
#define	DIO_CHANNEL_B_2 			((Dio_ChannelType) 0x02)     	//PIN10
#define	DIO_CHANNEL_B_3 			((Dio_ChannelType) 0x03)     	//PIN11
#define	DIO_CHANNEL_B_4 			((Dio_ChannelType) 0x04)     	//PIN12
#define	DIO_CHANNEL_B_5 			((Dio_ChannelType) 0x05)     	//PIN13
#define	DIO_CHANNEL_B_6 			((Dio_ChannelType) 0x06)     	//PIN14
#define	DIO_CHANNEL_B_7 			((Dio_ChannelType) 0x07)     	//PIN15
#define	DIO_CHANNEL_C_0 			((Dio_ChannelType) 0x00)     	//PIN16
#define	DIO_CHANNEL_C_1 			((Dio_ChannelType) 0x01)     	//PIN17
#define	DIO_CHANNEL_C_2 			((Dio_ChannelType) 0x02)     	//PIN18
#define	DIO_CHANNEL_C_3 			((Dio_ChannelType) 0x03)     	//PIN19
#define	DIO_CHANNEL_C_4 			((Dio_ChannelType) 0x04)     	//PIN20
#define	DIO_CHANNEL_C_5 			((Dio_ChannelType) 0x05)     	//PIN21
#define	DIO_CHANNEL_C_6 			((Dio_ChannelType) 0x06)     	//PIN22
#define	DIO_CHANNEL_C_7 			((Dio_ChannelType) 0x07)     	//PIN23
#define	DIO_CHANNEL_D_0 			((Dio_ChannelType) 0x00)     	//PIN24
#define	DIO_CHANNEL_D_1 			((Dio_ChannelType) 0x01)     	//PIN25
#define	DIO_CHANNEL_D_2 			((Dio_ChannelType) 0x02)     	//PIN26
#define	DIO_CHANNEL_D_3 			((Dio_ChannelType) 0x03)     	//PIN27
#define	DIO_CHANNEL_D_4 			((Dio_ChannelType) 0x04)     	//PIN28
#define	DIO_CHANNEL_D_5 			((Dio_ChannelType) 0x05)     	//PIN29
#define	DIO_CHANNEL_D_6 			((Dio_ChannelType) 0x06)     	//PIN30
#define	DIO_CHANNEL_D_7 			((Dio_ChannelType) 0x07)     	//PIN31
#define	DIO_CHANNEL_E_0 			((Dio_ChannelType) 0x00)     	//PIN32
#define	DIO_CHANNEL_E_1 			((Dio_ChannelType) 0x01)     	//PIN33
#define	DIO_CHANNEL_E_2 			((Dio_ChannelType) 0x02)     	//PIN34
#define	DIO_CHANNEL_E_3 			((Dio_ChannelType) 0x03)     	//PIN35
#define	DIO_CHANNEL_E_4 			((Dio_ChannelType) 0x04)     	//PIN36
#define	DIO_CHANNEL_E_5 			((Dio_ChannelType) 0x05)     	//PIN37
#define	DIO_CHANNEL_F_0 			((Dio_ChannelType) 0x00)     	//PIN38 
#define	DIO_CHANNEL_F_1 			((Dio_ChannelType) 0x01)     	//PIN39
#define	DIO_CHANNEL_F_2 			((Dio_ChannelType) 0x02)     	//PIN40
#define	DIO_CHANNEL_F_3 			((Dio_ChannelType) 0x03)     	//PIN41
#define	DIO_CHANNEL_F_4 			((Dio_ChannelType) 0x04)     	//PIN42


/*Type definition for port types and their allowed values */
typedef uint8 	Dio_PortType;

#define DIO_PORT_A	    	 ((Dio_PortType) 0x00U)	     	  //PORTA
#define DIO_PORT_B           ((Dio_PortType) 0x01U)           //PORTB
#define DIO_PORT_C           ((Dio_PortType) 0x02U)           //PORTC
#define DIO_PORT_D           ((Dio_PortType) 0x03U)           //PORTD
#define DIO_PORT_E           ((Dio_PortType) 0x04U)           //PORTE
#define DIO_PORT_F           ((Dio_PortType) 0x05U)           //PORTF




/* Type definition for the channel group type and their parameters */
typedef struct
{
  uint8 mask;
  uint8 offset;
  Dio_PortType port;
  
}Dio_ChannelGroupType;


/*Type definition for the channel configuration type */ 
typedef struct
{
  Dio_PortType         	postBuildPortID;
  Dio_ChannelType       postBuildChannelID;
}Dio_ChannelConfigType;

typedef struct
{
  Dio_ChannelConfigType ConfiguredChannelsArray[DIO_NUMBER_OF_CONFIGURED_CHANNELS];
}Dio_ConfigType;

/**********************************************************************************************************************
*  GLOBAL DATA PROTOTYPES
*********************************************************************************************************************/


/**********************************************************************************************************************
*  GLOBAL FUNCTION PROTOTYPES
*********************************************************************************************************************/


#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
*  END OF FILE: Std_Types.h
*********************************************************************************************************************/
