/*
 * Switch_prog.c
 *
 *  Created on: Apr 23, 2023
 *      Author: Ahmed Osama
 */
#include "Std_Types.h"
#include "error_status.h"
#include "Switch_priv.h"
#include "Switch_config.h"
#include "DIO_int.h"

ES_t Switch_enuInit(SW_t * Copy_AstrSwitchs)
{
ES_t Local_enuErrorState = ES_NOK;
if(Copy_AstrSwitchs !=NULL)
{
for(u8 Local_u8Iterator =0;Local_u8Iterator <SW_NUM;Local_u8Iterator++)
	{
	Local_enuErrorState=DIO_enuSetPinDirection(Copy_AstrSwitchs[Local_u8Iterator].Sw_PortID,
											   Copy_AstrSwitchs[Local_u8Iterator].Sw_PinID,
											   DIO_INPUT);
	Local_enuErrorState=DIO_enuSetPinValue(Copy_AstrSwitchs[Local_u8Iterator].Sw_PortID,
										   Copy_AstrSwitchs[Local_u8Iterator].Sw_PinID,
										   Copy_AstrSwitchs[Local_u8Iterator].Sw_Status);
	}
}else {Local_enuErrorState=ES_NULL_POINTER;}
	return Local_enuErrorState;
}




ES_t Switch_enuGetState(SW_t * Copy_AstrSwitchs ,u8 *Copypu8Swstate)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_AstrSwitchs !=NULL && Copypu8Swstate!=NULL)
	{
	Local_enuErrorState=DIO_enuGetPinValue(Copy_AstrSwitchs->Sw_PortID,
										   Copy_AstrSwitchs->Sw_PinID,
										   Copypu8Swstate);
	}else{Local_enuErrorState=ES_NULL_POINTER;}
	return Local_enuErrorState;
}
