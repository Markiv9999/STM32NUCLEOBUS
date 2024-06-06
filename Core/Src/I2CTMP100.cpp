/*
 * I2CTMP100.cpp
 *
 *  Created on: Jun 5, 2024
 *      Author: vikra
 */

#include "I2CTMP100.h"
#define TMP100_CONFIG_REGISTER 0x01
#define TMP100_TEMP_REGISTER 0x00

I2CTMP100::I2CTMP100(uint8_t addresstemp, I2C_HandleTypeDef i2ctemp) {
	// TODO Auto-generated constructor stub
	address=addresstemp;
    hi2c=i2ctemp;
}

I2CTMP100::~I2CTMP100() {
	// TODO Auto-generated destructor stub
}

void I2CTMP100::setConfigReg(uint8_t settingbits=0x60)
{
	uint8_t config[2]={TMP100_CONFIG_REGISTER, settingbits};
	HAL_I2C_Master_Transmit(& hi2c , address, config, 2, HAL_MAX_DELAY);
}

uint16_t I2CTMP100::ReadTempReg()
{	//Set Registry to temperature
	ret = HAL_I2C_Master_Transmit(&hi2c, address, TMP100_TEMP_REGISTER, 1, HAL_MAX_DELAY);

		if ( ret != HAL_OK )
	     {
	       strcpy((char*)buf, "Error Tx\r\n");
	       return 0;
	     }
	     else
	     {
	       // Read 2 bytes from the temperature register
	       ret = HAL_I2C_Master_Receive(&hi2c, address, buf, 2, HAL_MAX_DELAY);

	       if ( ret != HAL_OK )
	       {
	         strcpy((char*)buf, "Error Rx\r\n");
	       }
	       else
	       {
	         //Combine the bytes
	         val = ((int16_t)buf[0] << 4) | (buf[1] >> 4);

	         // Convert to 2's complement, since temperature can be negative
	         if ( val > 0x7FF ) {
	           val |= 0xF000;
	         }

	         // Convert to float temperature value (Celsius)
	         temp_c = val * 0.0625;

	         // Convert temperature to decimal format
	         temp_c *= 100;
	       }
	     }


}
