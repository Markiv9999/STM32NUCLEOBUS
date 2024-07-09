/*
 * I2C_DMA.h
 *
 *  Created on: Jun 21, 2024
 *      Author: vikra
 */

#ifndef INC_I2C_DMA_H_
#define INC_I2C_DMA_H_

#include "I2C.h"
//Declare DMA Handle Types here, similar to declaring on top of main. This is to avoid circular dependencies
//that can arise from needing these Handle Types inside the HAL_Msp_Init functions

extern DMA_HandleTypeDef hdma_i2c1_rx;
extern DMA_HandleTypeDef hdma_i2c1_tx;

class I2C_DMA:public I2C
{

public:
	//I2C_DMA(I2C_HandleTypeDef &hi2ctemp);
	I2C_DMA(I2C_HandleTypeDef &hi2ctemp);
	void Init();

	Status Transmit(uint16_t address, uint8_t (&bits)[], uint16_t no_of_bytes) override;
	Status Receive_2_Buffer(uint16_t address, uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes) override;

	virtual ~I2C_DMA();
};

#endif /* INC_I2C_DMA_H_ */
