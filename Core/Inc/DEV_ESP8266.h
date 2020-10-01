/*
 * DEV_ESP8266.h
 *
 *  Created on: 1 de out de 2020
 *      Author: eng_p
 */

#ifndef INC_DEV_ESP8266_H_
#define INC_DEV_ESP8266_H_

#include <stdbool.h>

#define DEV_ESP8266_Task_PRIORITY (configMAX_PRIORITIES - 1)

static void DEV_ESP8266_Task(void *pvParameters);

void	DEV_ESP8266_Init( void );

bool 	DEV_ESP8266_Echo_Off( void );

#endif /* INC_DEV_ESP8266_H_ */
