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
class I2C{

private:

uint32_t Wait_Delay= HAL_MAX_DELAY;

public:
I2C_HandleTypeDef &hi2c1;
typedef enum
	{
		OK,

		ERROR,

		BUSY,

		TIMEOUT,

		SHOULD_NOT_HAPPEN
	}Status;
	//Constructor to initialize I2C object
	I2C(I2C_HandleTypeDef &hi2ctemp, uint32_t delay=HAL_MAX_DELAY);
	virtual ~I2C();

	void Init();ss


	//Operational Functions
	virtual Status Transmit(uint16_t address, uint8_t (&bits)[], uint16_t no_of_bytes);
	virtual Status Receive_2_Buffer(uint16_t address, uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes);



};
/*

// Interrupt ************************************************** Interrupt
class I2C_IT:public I2C
{
public:
	I2C_IT(I2C &i2ctemp);
		//Operational Functions
	Status Transmit(uint16_t address, uint8_t (&bits)[], uint16_t no_of_bytes) override;
	Status Receive_2_Buffer(uint16_t address, uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes) override;
	virtual ~I2C_IT();
};



//DMA ********************************************************* DMA


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


*/

#endif /* I2C_H_ */
