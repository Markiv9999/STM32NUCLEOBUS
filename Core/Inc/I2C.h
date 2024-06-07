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
//Includes End

//Defines Here


//Defines End
class I2C {

uint8_t address;
I2C_HandleTypeDef hi2c1;
uint32_t waitdelay= HAL_MAX_DELAY;
HAL_StatusTypeDef ret;

public:
	uint8_t I2C_Buffer[12];


	I2C();

	void Init_I2C(uint8_t add,I2C_HandleTypeDef hi2c);

	void Set_Wait_Delay(uint32_t delay);

	void Transmit(uint8_t *bits, int no_of_bits);

	HAL_StatusTypeDef Receive_2_Buffer(int noofbytes);

	virtual ~I2C();
};


#ifdef __cplusplus
}
#endif


#endif /* I2C_H_ */
