/*
 * UartConsole.h
 *
 *  Created on: Jul 9, 2024
 *      Author: vikra
 */

#ifndef INC_UARTCONSOLE_H_
#define INC_UARTCONSOLE_H_

#include "stm32l4xx_hal.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA

class UartConsole {

	private:
		static UART_HandleTypeDef huart2;

	public:
		UartConsole();

		void print(const char (&Msg)[]);

		//Init Functions
		void Init();
		HAL_StatusTypeDef UART_Init2(UART_HandleTypeDef *huart);
		void UART_Init3(UART_HandleTypeDef *huart);

		void Error_Handler(void);



	virtual ~UartConsole();
};

#endif /* INC_UARTCONSOLE_H_ */
