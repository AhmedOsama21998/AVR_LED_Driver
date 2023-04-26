/*
 * main.c
 *
 *  Created on: Apr 24, 2023
 *      Author: Ahmed Osama
 */
#include "Std_Types.h"
#include "error_status.h"
#include <util/delay.h>
#include "DIO_int.h"
#include "LED_config.h"
#include "LED_int.h"
#include "Switch_config.h"
#include "Switch_int.h"
extern LED_t LED_AstrLedConfig[LED_NUM];
extern SW_t	 Switch_AstrSwitchState[SW_NUM];
int main(void)
{
	DIO_enuInit();
	LED_enuInit(LED_AstrLedConfig);
	Switch_enuInit(Switch_AstrSwitchState);
	u8 state=0;
	while(1)
	{
		Switch_enuGetState(&Switch_AstrSwitchState[2],&state);
		if(state==0){ LED_enuTurnOn(&LED_AstrLedConfig[2]); }
		else 		{ LED_enuTurnOff(&LED_AstrLedConfig[2]);}

	}
}
