/**********************************************************************************************************************
*  FILE DESCRIPTION
*  -----------------------------------------------------------------------------------------------------------------*/

/**        \file  FileName.c
*        \brief  
*
*      \details  
*		\Author: Salah Mahmoud
*
*********************************************************************************************************************/ 

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/ 
#include "TM4C123GH6PM_Hw.h"
#include "Dio.h"



#if (DIO_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"

/* will check for autosar release compatability after refactoring Det to autosar module */
/*
#if ((DIO_AR_RELEASE_MAJOR_VERSION != DET_AR_MAJOR_VERSION)\
  || (DIO_AR_RELEASE_MINOR_VERSION != DET_AR_MINOR_VERSION)\
  || (DIO_AR_RELEASE_PATCH_VERSION != DET_AR_PATCH_VERSION))
#error "The autosar version of Det.h is not matching this module version"
#endif
*/

#endif

/**********************************************************************************************************************
*  LOCAL DATA 
*********************************************************************************************************************/ 

/* This array contains all base addresses for PORT driver (advanced peripheral bus) */ 
uint32 portAddressMapper[] =
                            {
                              GPIO_Port_A_APB_BASE_ADDRESS, 
                              GPIO_Port_B_APB_BASE_ADDRESS,
                              GPIO_Port_C_APB_BASE_ADDRESS, 
                              GPIO_Port_D_APB_BASE_ADDRESS,
                              GPIO_Port_E_APB_BASE_ADDRESS, 
                              GPIO_Port_F_APB_BASE_ADDRESS 
                            };


/* structure containing version info for port driver*/
STATIC Std_VersionInfoType Port_VersionInfo = 
                                      {DIO_VENDOR_ID,
                                       DIO_MODULE_ID,
                                       DIO_SW_MAJOR_VERSION,
                                       DIO_SW_MINOR_VERSION,
                                       DIO_SW_PATCH_VERSION,
                                      };

/* pointer that will point to configuration array for initialization */
STATIC const Dio_ChannelConfigType *Dio_ConfigurationChannelsPointer = NULL_PTR;
/* dio initial status*/
uint8 Dio_InitializeStatus = DIO_NOT_INITIALIZED;

/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
*********************************************************************************************************************/ 


/******************************************************************************
* \Syntax          : void Dio_Init( const Dio_ConfigType* ConfigPtr )
* \Description     : Service to initialize Dio driver                               
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to post-build configuration                    
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/ 
void
Dio_Init (const Dio_ConfigType * ConfigPtr) 
{
  
  /*if DET errors are enabled*/ 
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  
  /*if configuration pointer is null during initialize*/ 
  if (ConfigPtr == NULL_PTR)
    
  {
    
    /* Report det error */ 
    Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID,
                     DIO_E_PARAM_CONFIG);
    
    
  }
  
  /*else initialize the DIO driver with the provided pointer */
  else				
    
#endif	
  {
    
    Dio_InitializeStatus = DIO_INITIALIZED;	/*Dio status is initialized */
    /* Point to configuration array */
    Dio_ConfigurationChannelsPointer = ConfigPtr->ConfiguredChannelsArray;
    
  }
  
}


/******************************************************************************
* \Syntax          : void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
* \Description     : Service to set level of a channel during runtime                               
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelID   ID of DIO channel
*                    Level      Value to be written
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/ 
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType pinLevelType) 
{
  uint8 isDetErrorDetected = FALSE;
  
  /*if DET errors are enabled */ 
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  
  /*if DIO module is not initialized */ 
  if (Dio_InitializeStatus == DIO_NOT_INITIALIZED)
    
  {
    
    /*report det error */ 
    isDetErrorDetected = TRUE;
    Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_SID, DIO_E_UNINIT);
    
    
  }
  
  
  else
  {
    /*Do nothing */
  }
  /* if channel ID is not configured by the tool */
  if (ChannelId >= DIO_NUMBER_OF_CONFIGURED_CHANNELS)
  {
    /* set error status to detected and report det error*/
    isDetErrorDetected = TRUE;
    Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    
  }
  
  
#endif
  /* if no errors detected */
  if (isDetErrorDetected == FALSE)
    
  {
    
    
    /* Write the desired value on the desired channel */ 
    /* a) get the port from the configuratoin ptr */ 
    uint32 pinBaseAddress =
      portAddressMapper[Dio_ConfigurationChannelsPointer[ChannelId].
        postBuildPortID];
    
    
    /* b) get the channel offset in port */ 
    uint8 pinOffset =
      Dio_ConfigurationChannelsPointer[ChannelId].postBuildChannelID;
    
    
    /* c) get the channel address using bitbanding */ 
    volatile uint32 *pinAddress =
      &(GPIODATA (pinBaseAddress + (0x04 << pinOffset)));
    
    
    
    if (pinLevelType == STD_HIGH)	/* if desired value is high */
      
    {
      
      *pinAddress = STD_HIGH << pinOffset;	/* Set the desired channel to high */
      
    }
    
    else if (pinLevelType == STD_LOW)	/* else if desired value is low */
      
    {
      
      *pinAddress = STD_LOW << pinOffset;	/* Set the desired channel to low */
      
    }
    
    else
      
    {
      
      /* Do nothing */ 
    }
    
  }
  else
  {
    /* Do nothing */ 
  }
  
}



/******************************************************************************
* \Syntax          : void Dio_ReadChannel( Dio_ChannelType ChannelId)
* \Description     : Service to read level of a channel during runtime                               
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelID   ID of DIO channel
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelTypes     STD_HIGH  Physical level of channel is HIGH
                                        STD_LOW   Physical level of channel is LOW
*******************************************************************************/ 

Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId) 
{
  uint8 isDetErrorDetected = FALSE;
  uint8 pinState;		/*This variable will contain the channel state */
  
  
  /*if DET errors are enabled */ 
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  /*if DET errors are enabled*/ 
  
  /*if DIO module is not initialized */ 
  if (Dio_InitializeStatus == DIO_NOT_INITIALIZED)
    
  {
    
    /*report det error */ 
    isDetErrorDetected = TRUE;
    Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_CHANNEL_SID, DIO_E_UNINIT);
    
    
  }
  
  
  else
  {
    /*Do nothing */
  }
  
  if (ChannelId >= DIO_NUMBER_OF_CONFIGURED_CHANNELS)
  {
    isDetErrorDetected = TRUE;
    Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    
  }
  
#endif
  
  if (isDetErrorDetected == FALSE)
    
  {
    
    
    /* Step 1 validate that the channel is output channel */ 
    /*
    
    
    */ 
    
    /* Step 2 Read the desired value from the desired channel */ 
    /* a) get the port from the configuratoin ptr */ 
    uint32 pinBaseAddress =
      portAddressMapper[Dio_ConfigurationChannelsPointer[ChannelId].
        postBuildPortID];
    
    
    /* b) get the channel offset in the port */ 
    uint8 pinOffset =
      Dio_ConfigurationChannelsPointer[ChannelId].postBuildChannelID;
    
    
    /*Get the pin address using bitbanding */ 
    volatile uint32 *pinAddress =
      &(GPIODATA (pinBaseAddress + (0x04 << pinOffset)));
    
    
    /* if the channel state is HIGH, return HIGH */ 
    if (*pinAddress >= STD_HIGH)
      
    {
      
      pinState = STD_HIGH;
      
    }
    
    /* if the channel state is LOW, return LOW */ 
    else if (*pinAddress <= STD_LOW)
      
    {
      
      pinState = STD_LOW;
      
      
    }
    
    else
      
    {
      
      
      /* Do nothing */ 
    }
    
  }
  return pinState;
  
}

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId )
* \Description     : Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel 
*                    and return the level of the channel after flip.                                                         
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelID   ID of DIO channel
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelTypes     STD_HIGH  Physical level of channel is HIGH
                                        STD_LOW   Physical level of channel is LOW
*******************************************************************************/ 

#if (DIO_FLIP_CHANNEL_API == STD_ON)

Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId) 
{
  
  uint8 isDetErrorDetected = FALSE;
  uint8 pinState;		/*This variable will contain the channel state */
  
  
  /*if DET errors are enabled */ 
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  /*if DET errors are enabled*/ 
  
  /*if DIO module is not initialized */ 
  if (Dio_InitializeStatus == DIO_NOT_INITIALIZED)
    
  {
    
    /*report det error */ 
    isDetErrorDetected = TRUE;
    Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_FLIP_CHANNEL_SID, DIO_E_UNINIT);
    
    
  }
  
  
  else
  {
    /*Do nothing */
  }
  
  if (ChannelId >= DIO_NUMBER_OF_CONFIGURED_CHANNELS)
  {
    isDetErrorDetected = TRUE;
    Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_FLIP_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    
  }
  
#endif
  
  if (isDetErrorDetected == FALSE)
    
  {
    
    
    /*if channel state is HIGH, Flip channel by writing LOW */ 
    if (Dio_ReadChannel (ChannelId) == STD_HIGH)
      
    {
      
      Dio_WriteChannel (ChannelId, STD_LOW);
      
      pinState = STD_LOW;	/*set the channel state to LOW */
      
    }
    
    /*else if channel state is LOW, Flip channel by writing HIGH */ 
    else if (Dio_ReadChannel (ChannelId) == STD_LOW)
      
    {
      
      Dio_WriteChannel (ChannelId, STD_HIGH);
      
      pinState = STD_HIGH;	/*set the channel state to HIGH */
      
    }
    
    else
      
    {
      
      /* Do nothing */ 
    }
  }
  return pinState;
  
}

#else
/* Do nothing */
#endif


/******************************************************************************
* \Syntax          : void Dio_WritePort( Dio_PortType ChannelId, Dio_PortLevelType Level )
* \Description     : Service to set value of a port during runtime                               
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortID   ID of DIO port
*                    Level      Value to be written
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/ 

void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level) 
{
  uint8 isDetErrorDetected = FALSE;
  
  /*if DET errors are enabled */ 
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  /*if DET errors are enabled*/ 
  
  /*if DIO module is not initialized */ 
  if (Dio_InitializeStatus == DIO_NOT_INITIALIZED)
    
  {
    
    /*report det error */ 
    isDetErrorDetected = TRUE;
    Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_WRITE_PORT_SID, DIO_E_UNINIT);
    
    
  }
  
  
  else
  {
    /*Do nothing */
  }
  
  if (PortId >= MCU_NUMBER_OF_PORTS)
  {
    isDetErrorDetected = TRUE;
    Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
    
  }
  
#endif
  
  if (isDetErrorDetected == FALSE)
    
  {
    
    
    /*get the desired port address */ 
    uint32 portAddress = portAddressMapper[PortId];
    
    
    /*write the desired level value on the port using bitbanding */ 
    GPIODATA ((portAddress + 0x3FC)) = Level;
    
  }
} 

/******************************************************************************
* \Syntax          : void Dio_ReadPort( Dio_PortType PortId)
* \Description     : Service to read level of a port during runtime                               
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId   ID of DIO port
* \Parameters (out): None                                                      
* \Return value:   : Dio_PortLevelType     Return level of all channels in port
*******************************************************************************/ 

Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId) 
{
  uint8 isDetErrorDetected = FALSE;
  uint8 portValue;
  /*if DET errors are enabled */ 
#if (DIO_DEV_ERROR_DETECT == STD_ON)
  /*if DET errors are enabled*/ 
  
  /*if DIO module is not initialized */ 
  if (Dio_InitializeStatus == DIO_NOT_INITIALIZED)
    
  {
    
    /*report det error */ 
    isDetErrorDetected = TRUE;
    Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_PORT_SID, DIO_E_UNINIT);
    
    
  }
  
  
  else
  {
    /*Do nothing */
  }
  
  /* if the Port ID is bigger than number of ports */
  if (PortId >= MCU_NUMBER_OF_PORTS)
  {
    isDetErrorDetected = TRUE;
    Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
    
  }
  
#endif
  
  if (isDetErrorDetected == FALSE)
    
  {
    uint32 portAddress = portAddressMapper[PortId];	/* Get the physical address of the desired port */
    
    
    portValue = GPIODATA ((portAddress + 0x3FC));	/* Read the desired port and return result using bitbanding */
  }
  return portValue;
}


/******************************************************************************
* \Syntax          : void Dio_GetVersionInfo( Std_VersionInfoType* versioninfo )
* \Description     : This function returns version information of this module
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): versioninfo (pointer to where version info are stored of this module)                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
void Dio_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
   /* variable to detect det error */
  boolean isDetErrorDetected = FALSE;
#if (DIO_DEV_ERROR_DETECT == STD_ON)       
  /* If port is not initialized*/      
  if (Dio_InitializeStatus == DIO_NOT_INITIALIZED)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_GET_VERSION_INFO_SID, DIO_E_UNINIT);
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
    Det_ReportError  (DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_GET_VERSION_INFO_SID, DIO_E_PARAM_POINTER);
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



/**********************************************************************************************************************
*  END OF FILE: FileName.c
*********************************************************************************************************************/ 
