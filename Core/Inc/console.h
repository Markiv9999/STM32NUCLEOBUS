/*
 * Console.h
 *
 *  Created on: Jun 12, 2024
 *      Author: vikra
 */

#ifndef INC_CONSOLE_H_
#define INC_CONSOLE_H_

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "stm32l4xx_hal.h"
//#include "I2C.h"


class console
{
private:
	UART_HandleTypeDef huart;

public:
	console(UART_HandleTypeDef huart);
	void print(const char (&Msg)[]);
	//void check_ok(I2C::Status rettemp,const char (&operation_title)[]);
	virtual ~console();
};



#endif /* INC_CONSOLE_H_ */
