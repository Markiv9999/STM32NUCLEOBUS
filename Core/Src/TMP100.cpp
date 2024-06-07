/*
 * TMP100.cpp
 *
 *  Created on: Jun 7, 2024
 *      Author: vikra
 */

#include "TMP100.h"

TMP100::TMP100() {
	// TODO Auto-generated constructor stub

}

void init(uint8_t add,I2C_HandleTypeDef hi2c)
{
	i2c.init(add, hi2c);
}

void setconfig(uint8_t settings)
{
uint8 config[2]= {TMP_100_Config_Registry_Address, 0x60};
i2c.Transmit(&config, 2);
}
void gettemperature();



TMP100::~TMP100() {
	// TODO Auto-generated destructor stub
}

