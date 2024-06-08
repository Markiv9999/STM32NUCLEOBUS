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
//Includes End

//Defines Here


//Defines End
class I2C {

uint8_t address;

uint32_t Wait_Delay= HAL_MAX_DELAY;

//hi2c1 needs to be initiated.
I2C_HandleTypeDef hi2c1;


public:
	//Functions will set read value to buffer.
	uint8_t I2C_Buffer[12];




	I2C();

	//Initialization Functions
	void Init_I2C(uint8_t add,I2C_HandleTypeDef hi2c);
	//Optional Initializations
	//void initprint(UART_HandleTypeDef huartt);
	void Set_Wait_Delay(uint32_t delay);

	//Operational Functions
	HAL_StatusTypeDef Transmit(uint8_t bits[12], int no_of_bits);
	HAL_StatusTypeDef Receive_2_Buffer(int noofbytes);

	HAL_StatusTypeDef Transmit_DMA(uint8_t bits[12], int no_of_bits);
	HAL_StatusTypeDef Receive_2_Buffer_DMA(int noofbytes);
	//Print Functions
	//void printretflag(UART_HandleTypeDef huart);

	virtual ~I2C();
};


#ifdef __cplusplus
}
#endif


#endif /* I2C_H_ */
