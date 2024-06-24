/*
 * I2C_IT.h
 *
 *  Created on: Jun 21, 2024
 *      Author: vikra
 */

#ifndef INC_I2C_IT_H_
#define INC_I2C_IT_H_

#include "I2C.h"
// Interrupt ************************************************** Interrupt
class I2C_IT:public I2C
{
public:
	I2C_IT(I2C_HandleTypeDef &hi2ctemp);
	virtual ~I2C_IT();
		//Operational Functions

	void Init();

	Status Transmit(uint16_t address, uint8_t (&bits)[], uint16_t no_of_bytes) override;
	Status Receive_2_Buffer(uint16_t address, uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes) override;

};



#endif /* INC_I2C_IT_H_ */
