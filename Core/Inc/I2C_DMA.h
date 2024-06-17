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

//Includes End

//Defines Here


//Defines End
class I2C_DMA: public I2C{

	//Constructor to initialize I2C object
		I2C_DMA(I2C_HandleTypeDef hi2c, uint32_t delay=HAL_MAX_DELAY);
		//Copy constructor to pass I2C object by reference to each sensor
		I2C_DMA( I2C &i2ctemp );


		//Operational Functions
		virtual I2C_STATUS Transmit(uint16_t address, uint8_t (&bits)[], uint16_t no_of_bytes);
		virtual I2C_STATUS Receive_2_Buffer(uint16_t address, uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes);


		virtual ~I2C_DMA();

};





#endif /* I2C_H_ */
