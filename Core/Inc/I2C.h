/*
 * I2C.h
 *
 *  Created on: Jun 6, 2024
 *      Author: vikra
 */

#ifndef I2C_H_
#define I2C_H_


//Hal Includes here
#include "stm32l4xx_hal.h"



#include <string.h>
#include <stdio.h>

//Includes End

//Defines Here
//Required for Initialization
#define I2C_STATE_NONE    ((uint32_t)(HAL_I2C_MODE_NONE))
#define TIMING_CLEAR_MASK   (0xF0FFFFFFU)
//Defines End
class I2C{

private:
	//Mode variable: IT=2, DMA=3, Blocking=Other
	short int Mode=1;
	uint32_t Wait_Delay= HAL_MAX_DELAY;

public:
	static DMA_HandleTypeDef hdma_i2c1_tx;
	static DMA_HandleTypeDef hdma_i2c1_rx;
	static I2C_HandleTypeDef hi2c1;


	typedef enum
		{
			OK,

			ERROR,

			BUSY,

			TIMEOUT,

			SHOULD_NOT_HAPPEN
		}Status;

	//Constructor to take in hi2c object by reference and wait delay.
	I2C(short int tempmode,uint32_t delay=HAL_MAX_DELAY);
	virtual ~I2C();

	//Initialization Functions
	void Init();
	HAL_StatusTypeDef Init_Step_2(I2C_HandleTypeDef *hi2c);
	void Init_Step_3(I2C_HandleTypeDef* hi2c);


	//Operational Functions
	Status Transmit(uint16_t address, uint8_t (&bits)[], uint16_t no_of_bytes);
	Status Receive(uint16_t address, uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes);

	//Convenience function for checking error code
	Status Check_Status(HAL_StatusTypeDef temp);

	//Error Handler Function
	void Error_Handler(const char (&Msg)[]);

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
