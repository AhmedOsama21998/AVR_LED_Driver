/*
 * LED_config.h
 *
 *  Created on: Apr 24, 2023
 *      Author: Ahmed Osama
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define LED_NUM		3
typedef struct
{
	u8 LED_PortID;
	u8 LED_PinID;
	u8 LED_Connect;
	u8 LED_InitState;
}LED_t;

#endif /* LED_CONFIG_H_ */
