/*
 * Switch_config.h
 *
 *  Created on: Apr 23, 2023
 *      Author: Ahmed Osama
 */

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

#define SW_NUM		4
typedef struct
{
	u8 Sw_PortID;
	u8 Sw_PinID;
	u8 Sw_Status;
}SW_t;

#endif /* SWITCH_CONFIG_H_ */
