/*
 * Switch_config.c
 *
 *  Created on: Apr 23, 2023
 *      Author: Ahmed Osama
 */
#include "Std_Types.h"
#include "error_status.h"
#include "Switch_priv.h"
#include "Switch_config.h"
#include "DIO_int.h"

SW_t Switch_AstrSwitchState[SW_NUM]=/*Asrt->(Array of struct)*/
{
	{DIO_u8PORTA,DIO_u8PIN0,DIO_PULL_UP},
	{DIO_u8PORTB,DIO_u8PIN1,DIO_FLOAT},
	{DIO_u8PORTC,DIO_u8PIN2,DIO_PULL_UP}
};
