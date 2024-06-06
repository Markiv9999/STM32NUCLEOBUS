/*
 * I2CTMP100.cpp
 *
 *  Created on: Jun 5, 2024
 *      Author: vikra
 */

#include "I2CTMP100.h"
#define TMP100_CONFIG_REGISTER 0x01
#define TMP100_TEMP_REGISTER 0x00

I2C_TMP100::I2C_TMP100(uint8_t addresstemp, I2C_HandleTypeDef i2ctemp) {
	// TODO Auto-generated constructor stub
	address=addresstemp;
    hi2c=i2ctemp;
}

I2C_TMP100::~I2C_TMP100() {
	// TODO Auto-generated destructor stub
}

void I2C_TMP100::setConfigReg(uint8_t settingbits)
{
	uint8_t config[2]={TMP100_CONFIG_REGISTER, settingbits};
	HAL_I2C_Master_Transmit(& hi2c , address, config, 2, HAL_MAX_DELAY);
}

uint16_t I2C_TMP100::ReadTempReg()
{

	return 0
}
