/*
 * DEV_ESP8266.c
 *
 *  Created on: 1 de out de 2020
 *      Author: eng_p
 */


#include "DEV_ESP8266.h"
#include "stm32l4xx_hal.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

UART_HandleTypeDef DEV_ESP8266_UART_Handle;

static void DEV_ESP8266_Task(void *pvParameters)
{
	DEV_ESP8266_Init( );
	for(;;)
	{

	}
}

void	DEV_ESP8266_Init( void )
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* USART1 clock enable */
	__HAL_RCC_USART1_CLK_ENABLE();

	__HAL_RCC_GPIOA_CLK_ENABLE();
	/**USART1 GPIO Configuration
	    PA9     ------> USART1_TX
	    PA10     ------> USART1_RX
	 */
	GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


	DEV_ESP8266_UART_Handle.Instance = USART1;
	DEV_ESP8266_UART_Handle.Init.BaudRate = 115200;
	DEV_ESP8266_UART_Handle.Init.WordLength = UART_WORDLENGTH_8B;
	DEV_ESP8266_UART_Handle.Init.StopBits = UART_STOPBITS_1;
	DEV_ESP8266_UART_Handle.Init.Parity = UART_PARITY_NONE;
	DEV_ESP8266_UART_Handle.Init.Mode = UART_MODE_TX_RX;
	DEV_ESP8266_UART_Handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	DEV_ESP8266_UART_Handle.Init.OverSampling = UART_OVERSAMPLING_16;
	DEV_ESP8266_UART_Handle.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	DEV_ESP8266_UART_Handle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_UART_Init(&DEV_ESP8266_UART_Handle) != HAL_OK)
	{
		while(1);
	}

	/* USART1 interrupt Init */
	HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
}

bool 	DEV_ESP8266_Echo_Off( void )
{

}
