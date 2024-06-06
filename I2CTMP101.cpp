/*
 * I2CTMP100.cpp
 *
 *  Created on: Jun 5, 2024
 *      Author: vikra
 */

#include "I2CTMP100.h"
#ifndef TMP100_CONFIG_REGISTER 0x01
#ifndef TMP100_TEMP_REGISTER 0x00

I2C_TMP100::I2C_TMP100(uint8_t addtemp) {
	// TODO Auto-generated constructor stub
	address=addtemp;
}

I2C_TMP100::~I2C_TMP100() {
	// TODO Auto-generated destructor stub
}

void setConfigReg(uint8_t settingbits, uint8_t )
{
	uint8_t config[2]={TMP100_CONFIG_REGISTER
	HAL_I2C_Master_Transmit(&hi2c1, TMP100_ADDRESS, config, 1, HAL_MAX_DELAY);
}

void ReadTempReg
