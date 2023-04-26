/*
 * LED_config.c
 *
 *  Created on: Apr 24, 2023
 *      Author: Ahmed Osama
 */
#include "Std_Types.h"
#include "error_status.h"
#include "LED_priv.h"
#include "LED_config.h"
#include "DIO_int.h"

LED_t LED_AstrLedConfig[LED_NUM]=/*Asrt->(Array of struct)*/
{
	{DIO_u8PORTD,DIO_u8PIN0,LED_SINK  ,LED_OFF},/*SINK  ->on=0 ,off=1*/
	{DIO_u8PORTB,DIO_u8PIN1,LED_SOURCE,LED_ON },/*SOURCE->on=1 ,off=0*/
	{DIO_u8PORTC,DIO_u8PIN3,LED_SOURCE,LED_OFF}/*SOURCE->on=1 ,off=0*/
};
