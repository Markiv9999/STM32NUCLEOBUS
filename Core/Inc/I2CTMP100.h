/*
 * I2CTMP100.h
 *
 *  Created on: Jun 5, 2024
 *      Author: vikra
 */
#include <stdint.h>
#include "stm32l4xx_hal.h"
#ifndef I2CTMP100_H_
#define I2CTMP100_H_

class I2C_TMP100 {
private:
    //7bit address of peripheral left shifted once and held in 8bit variable


	void setConfigReg(uint8_t settingbits);
	uint16_t ReadTempReg();
	void Ping();


public:
	uint8_t address;
	I2C_HandleTypeDef hi2c;

	I2C_TMP100(uint8_t addtemp,I2C_HandleTypeDef tempi2c);
	virtual ~I2C_TMP100();
};

#endif /* I2CTMP100_H_ */
