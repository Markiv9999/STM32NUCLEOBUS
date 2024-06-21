/*
 * I2C_DMA.cpp
 *
 *  Created on: Jun 21, 2024
 *      Author: vikra
 */

#include "I2C_DMA.h"

I2C_DMA::I2C_DMA(I2C &i2ctemp) : I2C(i2ctemp)
{

}

I2C::Status I2C_DMA::Transmit(uint16_t address,uint8_t (&bits)[], uint16_t no_of_bytes)
{
	HAL_StatusTypeDef temp;
	temp= HAL_I2C_Master_Transmit_DMA(&hi2c1 , address, bits, no_of_bytes);

	switch(temp)
	{
		case HAL_OK:
			return Status::OK;
			break;

		case HAL_ERROR:
			return Status::ERROR;
			break;

		case HAL_BUSY:
			return Status::BUSY;
			break;

		case HAL_TIMEOUT:
			return Status::TIMEOUT;
			break;
	}

	return Status::SHOULD_NOT_HAPPEN;
}


I2C::Status I2C_DMA::Receive_2_Buffer(uint16_t address,uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes)
{
	HAL_StatusTypeDef temp;
		temp= HAL_I2C_Master_Receive_DMA(&hi2c1, address, I2C_Buffer, no_of_bytes);

		switch(temp)
		{
			case HAL_OK:
				return Status::OK;
				break;

			case HAL_ERROR:
				return Status::ERROR;
				break;

			case HAL_BUSY:
				return Status::BUSY;
				break;

			case HAL_TIMEOUT:
				return Status::TIMEOUT;
				break;
		}

		return Status::SHOULD_NOT_HAPPEN;
}




I2C_DMA::~I2C_DMA() {
	// TODO Auto-generated destructor stub
}


