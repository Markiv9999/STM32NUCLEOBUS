/*
 * I2C.h
 *
 *  Created on: Jun 6, 2024
 *      Author: vikra
 */

#ifndef I2C_H_
#define I2C_H_



//Includes here
#include "stm32l4xx_hal.h"
#include <string.h>
#include <stdio.h>
#include <I2C_STATUS.h>
//Includes End

//Defines Here


//Defines End
class I2C_IT {



uint32_t Wait_Delay= HAL_MAX_DELAY;






public:
    I2C_HandleTypeDef hi2c1;
    uint16_t address;

	I2C_IT(uint16_t tempaddress, I2C_HandleTypeDef hi2c, uint32_t delay);

	//TBD, Shouldnt be needed


	//Operational Functions
	I2C_STATUS Transmit(uint8_t (&bits)[], uint16_t no_of_bytes);
	I2C_STATUS Receive_2_Buffer(uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes);


	virtual ~I2C_IT();
};




#endif /* I2C_H_ */
