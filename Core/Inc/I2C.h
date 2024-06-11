/*
 * I2C.h
 *
 *  Created on: Jun 6, 2024
 *      Author: vikra
 */

#ifndef I2C_H_
#define I2C_H_

#ifdef __cplusplus
extern "C" {
#endif

//Includes here
#include "stm32l4xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <main.h>
//Includes End

//Defines Here


//Defines End
class I2C {



uint32_t Wait_Delay= HAL_MAX_DELAY;

I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart;


public:

	uint8_t address;
	enum class STATUS
	{
		OK,

		ERROR,

		BUSY,

		TIMEOUT,

		SHOULD_NOT_HAPPEN
	};

	/*
	enum I2C_Mode
	{
		I2C_NORMAL,

		I2C_FAST,

		I2C_FASTPLUS
	};

*/

	I2C( int I2CInstanceNo, int mode,UART_HandleTypeDef huart2, uint32_t delay=HAL_MAX_DELAY );

	//TBD, Shouldnt be needed
	void Error_Handler();

	//Operational Functions
	STATUS Transmit(uint8_t (&bits)[], int no_of_bytes);
	STATUS Receive_2_Buffer(uint8_t (&I2C_Buffer)[],int no_of_bytes);


	virtual ~I2C();
};


#ifdef __cplusplus
}
#endif


#endif /* I2C_H_ */
