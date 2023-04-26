/*
 * LED_int.h
 *
 *  Created on: Apr 24, 2023
 *      Author: Ahmed Osama
 */

#ifndef LED_INT_H_
#define LED_INT_H_

ES_t LED_enuInit(LED_t * Copy_PstrLedConfig);

ES_t LED_enuTurnOn(LED_t *Copy_PstrLedID);

ES_t LED_enuTurnOff(LED_t *Copy_PstrLedID);

#endif /* LED_INT_H_ */
