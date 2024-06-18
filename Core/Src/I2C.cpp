/*
 * I2C.cpp
 *
 *  Created on: Jun 6, 2024
 *      Author: vikra
 */

#include "I2C.h"
//Select I2C instance no from {1,2,3} (STM32NucleoL476 has 3 instances I2C1, I2C2, I2C3) and mode from {1=normal(100kbps), 2=fastmode(400kbps), 3=fastmodeplus(1Mbps)}

I2C::I2C(I2C_HandleTypeDef &hi2ctemp, uint32_t delay)
{

hi2c1=hi2ctemp;
Wait_Delay=delay;

}

I2C::I2C(I2C &I2Ctemp)
{
hi2c1	= I2Ctemp.hi2c1;
}



I2C::Status I2C::Transmit(uint16_t address,uint8_t (&bits)[], uint16_t no_of_bytes)
{
	HAL_StatusTypeDef temp;
	temp= HAL_I2C_Master_Transmit(&hi2c1 , address, bits, no_of_bytes, Wait_Delay);

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



I2C::Status I2C::Receive_2_Buffer(uint16_t address,uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes)
{
	HAL_StatusTypeDef temp;
		temp= HAL_I2C_Master_Receive(&hi2c1, address, I2C_Buffer, no_of_bytes, Wait_Delay);

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




I2C::~I2C() {
	// TODO Auto-generated destructor stub
}


// DMA ************************************************* DMA



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

// Interrupt Mode ************************************************************* Interrupt Mode


I2C_IT::I2C_IT(I2C &i2ctemp):I2C(i2ctemp)
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



