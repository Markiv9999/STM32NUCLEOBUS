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

class UartConsole {

	private:
		UART_HandleTypeDef huart;

	public:
		UartConsole(UART_HandleTypeDef huart);
		void print(const char (&Msg)[]);

	virtual ~UartConsole();
};

#endif /* INC_UARTCONSOLE_H_ */
