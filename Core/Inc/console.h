/*
 * Console.h
 *
 *  Created on: Jun 12, 2024
 *      Author: vikra
 */

#ifndef INC_CONSOLE_H_
#define INC_CONSOLE_H_

#include "stm32l4xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <I2C_STATUS.h>
/*
#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif
*/
class console
{
private:
	UART_HandleTypeDef huart;

public:
	console(UART_HandleTypeDef huart);
	//void print(uint32_t Msg);
	void print(const char (&Msg)[]);
	void check_ok(I2C_STATUS rettemp,const char (&operation_title)[]);
	virtual ~console();
};



#endif /* INC_CONSOLE_H_ */
