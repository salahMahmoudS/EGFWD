/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  Dio_Cfg.h
*       Module:  Dio
*
*  Description:  Dile containing all configurations of Dio module
*	Author: Salah Mahmoud
*  
*********************************************************************************************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H



/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/
/* Defining the company ID in the AUTOSAR */
/* I am using a dummy ID for now */

#define COMPILER_VENDOR_ID					(2007U)


/* Defining the Module software verison by Major.Minor.Patch format */

#define DIO_CFG_SW_MAJOR_VERSION			(1U)
#define DIO_CFG_SW_MINOR_VERSION			(0U)
#define DIO_CFG_SW_PATCH_VERSION			(0U)

/* Defining the autosar version ued for the module */

#define DIO_CFG_AR_RELEASE_MAJOR_VERSION		(4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION		(0U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION		(3U)


/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                            (STD_ON)

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                            (STD_ON)

/* Pre-compile option for Flip Channel API */
#define DIO_FLIP_CHANNEL_API                            (STD_ON)

#define DIO_NUMBER_OF_CONFIGURED_CHANNELS		(5U)

/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_SW1_CHANNEL_ID_INDEX        ((uint8)0x00)
#define DioConf_LED1_CHANNEL_ID_INDEX         ((uint8)0x01)
#define DioConf_LED2_CHANNEL_ID_INDEX         ((uint8)0x02)
#define DioConf_LED3_CHANNEL_ID_INDEX         ((uint8)0x03)
#define DioConf_SW2_CHANNEL_ID_INDEX        ((uint8)0x04)

/* DIO Configured Port ID's  */
#define DioConf_SW1_PORT_NUM                ((Dio_PortType)DIO_PORT_F)		 /* PORTF */
#define DioConf_LED1_PORT_NUM                 ((Dio_PortType)DIO_PORT_F) 		 /* PORTF */
#define DioConf_LED2_PORT_NUM                ((Dio_PortType)DIO_PORT_F)   /* PORTF */
#define DioConf_LED3_PORT_NUM                 ((Dio_PortType)DIO_PORT_F) 	 /* PORTF */
#define DioConf_SW2_PORT_NUM                ((Dio_PortType)DIO_PORT_F) 	 /* PORTF */

/* DIO Configured Channel ID's */
#define DioConf_SW1_CHANNEL_NUM             ((Dio_ChannelType)DIO_CHANNEL_F_0)  /* Pin 0 in PORTF */
#define DioConf_LED1_CHANNEL_NUM              ((Dio_ChannelType)DIO_CHANNEL_F_1)  /* Pin 1 in PORTF */
#define DioConf_LED2_CHANNEL_NUM             ((Dio_ChannelType)DIO_CHANNEL_F_2)  /* Pin 2 in PORTF */
#define DioConf_LED3_CHANNEL_NUM              ((Dio_ChannelType)DIO_CHANNEL_F_3)  /* Pin 3 in PORTF */
#define DioConf_SW2_CHANNEL_NUM             ((Dio_ChannelType)DIO_CHANNEL_F_4)  /* Pin 4 in PORTF */



#endif /* DIO_H */
