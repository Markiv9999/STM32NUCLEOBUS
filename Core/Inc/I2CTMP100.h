/*
 * I2CTMP100.h
 *
 *  Created on: Jun 5, 2024
 *      Author: vikra
 */
extern "C"{
#include "stm32l4xx_hal.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
}
#ifndef I2CTMP100_H_
#define I2CTMP100_H_



class I2CTMP100{
private:
    //7bit address of peripheral left shifted once and held in 8bit variable


	void setConfigReg(uint8_t settingbits);
	uint16_t ReadTempReg();

	void Ping();


public:
	uint8_t address;
	I2C_HandleTypeDef hi2c;
	HAL_StatusTypeDef ret;
	int16_t val;
	uint8_t buf[2];
	double temp_c;

	I2CTMP100(uint8_t addtemp,I2C_HandleTypeDef tempi2c);
	virtual ~I2CTMP100();
};

#endif /* I2CTMP100_H_ */
