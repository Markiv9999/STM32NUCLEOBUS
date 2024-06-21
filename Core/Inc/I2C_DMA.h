/*
 * I2C_DMA.h
 *
 *  Created on: Jun 21, 2024
 *      Author: vikra
 */

#ifndef INC_I2C_DMA_H_
#define INC_I2C_DMA_H_

#include "I2C.h"

class I2C_DMA:public I2C
{
public:
	I2C_DMA(I2C &i2ctemp);
		//Copy constructor to pass I2C object by reference to each sensor
		//Operational Functions
	Status Transmit(uint16_t address, uint8_t (&bits)[], uint16_t no_of_bytes) override;
	Status Receive_2_Buffer(uint16_t address, uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes) override;
	virtual ~I2C_DMA();
};

#endif /* INC_I2C_DMA_H_ */
