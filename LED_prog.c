/*
 * LED_prog.c
 *
 *  Created on: Apr 24, 2023
 *      Author: Ahmed Osama
 */
#include "Std_Types.h"
#include "error_status.h"
#include "LED_priv.h"
#include "LED_config.h"
#include "DIO_int.h"

ES_t LED_enuInit(LED_t * Copy_PstrLedConfig)
{
	ES_t Local_enuErrorState =ES_NOK;
if(Copy_PstrLedConfig!=NULL)
{
for(u8 Local_u8Iterator=0 ;Local_u8Iterator<=LED_NUM ;Local_u8Iterator++)
 {
Local_enuErrorState=DIO_enuSetPinDirection(Copy_PstrLedConfig[Local_u8Iterator].LED_PortID,
										   Copy_PstrLedConfig[Local_u8Iterator].LED_PinID,
										   DIO_OUTPUT);
if(Copy_PstrLedConfig[Local_u8Iterator].LED_Connect==LED_SINK)
{
if(Copy_PstrLedConfig[Local_u8Iterator].LED_InitState==LED_ON)
	{
Local_enuErrorState=DIO_enuSetPinValue(Copy_PstrLedConfig[Local_u8Iterator].LED_PortID,
									   Copy_PstrLedConfig[Local_u8Iterator].LED_PinID,
									   DIO_LOW);
	}else if (Copy_PstrLedConfig[Local_u8Iterator].LED_InitState==LED_OFF)
		{
Local_enuErrorState=DIO_enuSetPinValue(Copy_PstrLedConfig[Local_u8Iterator].LED_PortID,
									   Copy_PstrLedConfig[Local_u8Iterator].LED_PinID,
									   DIO_HIGH);
		}else
		{
		return ES_OUT_OF_RANGE;
		}
}else if(Copy_PstrLedConfig[Local_u8Iterator].LED_Connect==LED_SOURCE)
	{
if(Copy_PstrLedConfig[Local_u8Iterator].LED_InitState==LED_ON)
	{
Local_enuErrorState=DIO_enuSetPinValue(Copy_PstrLedConfig[Local_u8Iterator].LED_PortID,
									   Copy_PstrLedConfig[Local_u8Iterator].LED_PinID,
									   DIO_HIGH);
	}else if (Copy_PstrLedConfig[Local_u8Iterator].LED_InitState==LED_OFF)
		{
Local_enuErrorState=DIO_enuSetPinValue(Copy_PstrLedConfig[Local_u8Iterator].LED_PortID,
									   Copy_PstrLedConfig[Local_u8Iterator].LED_PinID,
									   DIO_LOW);
		}
	else
		{
		return ES_OUT_OF_RANGE;
		}
	}
	else
	{
	return ES_OUT_OF_RANGE;
	}
 }
} else
{
	Local_enuErrorState=ES_NULL_POINTER;
}
return Local_enuErrorState;
}

ES_t LED_enuTurnOn(LED_t *Copy_PstrLedID)
{
	ES_t Local_enuErrorState =ES_NOK;
if(Copy_PstrLedID!=NULL)
{
	if(Copy_PstrLedID->LED_Connect==LED_SINK)
	{
	Local_enuErrorState=DIO_enuSetPinValue(Copy_PstrLedID->LED_PortID,
										   Copy_PstrLedID->LED_PinID,
										   DIO_LOW);
	}else if(Copy_PstrLedID->LED_Connect==LED_SOURCE)
	{
	Local_enuErrorState=DIO_enuSetPinValue(Copy_PstrLedID->LED_PortID,
										   Copy_PstrLedID->LED_PinID,
										   DIO_HIGH);
	}else {Local_enuErrorState=ES_OUT_OF_RANGE;}
}	else{Local_enuErrorState=ES_NULL_POINTER;}
	return Local_enuErrorState;
}

ES_t LED_enuTurnOff(LED_t *Copy_PstrLedID)
{
ES_t Local_enuErrorState =ES_NOK;
if(Copy_PstrLedID != NULL)
{
	if(Copy_PstrLedID->LED_Connect==LED_SINK)
	{
	Local_enuErrorState=DIO_enuSetPinValue(Copy_PstrLedID->LED_PortID,
										   Copy_PstrLedID->LED_PinID,
										   DIO_HIGH);
	}else if(Copy_PstrLedID->LED_Connect==LED_SOURCE)
	{
	Local_enuErrorState=DIO_enuSetPinValue(Copy_PstrLedID->LED_PortID,
										   Copy_PstrLedID->LED_PinID,
										   DIO_LOW);
	}else {Local_enuErrorState=ES_OUT_OF_RANGE;}
}		else{Local_enuErrorState=ES_NULL_POINTER;}
	return Local_enuErrorState;
}

