/*
 * I2C_IT.cpp
 *
 *  Created on: Jun 21, 2024
 *      Author: vikra
 */


#include "I2C_IT.h"


I2C_IT::I2C_IT(I2C_HandleTypeDef &hi2ctemp):I2C(hi2ctemp)
{

}


I2C::Status I2C_IT::Transmit(uint16_t address,uint8_t (&bits)[], uint16_t no_of_bytes)
{
	HAL_StatusTypeDef temp;
	temp= HAL_I2C_Master_Transmit_IT(&hi2c1 , address, bits, no_of_bytes);

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


I2C::Status I2C_IT::Receive_2_Buffer(uint16_t address,uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes)
{
	HAL_StatusTypeDef temp;
		temp= HAL_I2C_Master_Receive_IT(&hi2c1, address, I2C_Buffer, no_of_bytes);

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




I2C_IT::~I2C_IT(){
	// TODO Auto-generated destructor stub
}
