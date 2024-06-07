/*
 * TMP100I2C.cpp
 *
 *  Created on: Jun 6, 2024
 *      Author: vikra
 */

#include "TMP100I2C.h"

TMP100I2C::TMP100I2C() {
	// TODO Auto-generated constructor stub

}


void TMP100I2C::Set_Config_Reg(uint8_t settingbits)
{
		uint8_t config[2]={TMP_100_Config_Registry_Address, settingbits};
		HAL_I2C_Master_Transmit(& hi2c1 , address, config, 2, waitdelay);
}



void TMP100I2C::Set_Delay(uint32_t delay)
{
waitdelay=delay;
}


void TMP100I2C::Select_Temp_Reg()
{

	//Switch Sensor to Temperature Registor for later reading
			     ret = HAL_I2C_Master_Transmit(&hi2c1, address, TMP_100_Temp_Registry_Address, 1, waitdelay);
}

uint16_t TMP100I2C::Read_Temp()
{
				//Switch Sensor to Temperature Registor for later reading
				Select_Temp_Reg();
		       // Read 2 bytes from the temperature register
		       ret = HAL_I2C_Master_Receive(& hi2c1, TMP100_ADDRESS, buf, 2, HAL_MAX_DELAY);

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
		         sprintf((char*)buf,
		               "%u.%u C\r\n",
		               ((unsigned int)temp_c / 100),
		               ((unsigned int)temp_c % 100));



		       }


		     // Send out buffer (temperature or error message)




}

TMP100I2C::~TMP100I2C() {
	// TODO Auto-generated destructor stub
}

