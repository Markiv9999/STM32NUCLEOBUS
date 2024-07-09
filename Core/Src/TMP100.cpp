/*
 * TMP100.cpp
 *
 *  Created on: Jun 7, 2024
 *      Author: vikra
 */

#include "TMP100.h"

TMP100::TMP100(uint16_t tempaddress, I2C i2c_temp): address(tempaddress), i2c_obj(i2c_temp)
{

}



I2C::Status TMP100::Initialize()
{

	I2C::Status ret;
	// Select config registry and overwrite bits according to requirement
	I2C_Buffer[0]=CONFIG_REG;
	I2C_Buffer[1]=RESOLUTION_12_BIT;

	ret=i2c_obj.Transmit(address,I2C_Buffer, 2);

	return ret;
}

I2C::Status TMP100::Select_Temp_Registry()
{
	I2C::Status ret;

	// Select config registry and overwrite bits
	I2C_Buffer[0]=TEMP_REG;

	ret=i2c_obj.Transmit(address,I2C_Buffer, 1);

	return ret;
}

I2C::Status TMP100::Get_Temperature(double &temp_c)
{   // Select temperature registry
	//Initiate temporary variables
	I2C::Status ret;
	int16_t val;

			// Read 2 bytes from the temperature register to i2c_obj object buffer
	ret = i2c_obj.Receive(address,I2C_Buffer,2);

	if(ret != I2C::Status::OK)
	{
		return ret;
	}
	else
	{
		 //Combine the bytes from i2c_obj internal buffer to temperature as signed integer
		 val = ((int16_t)I2C_Buffer[0] << 4) | (I2C_Buffer[1] >> 4);

		 // Convert to 2's complement, since temperature can be negative
		 if ( val > 0x7FF )
			 {
			   val |= 0xF000;
			 }

		 // Convert to float temperature value (Celsius)
		 temp_c = val * 0.0625;
	 }



return ret;
}



TMP100::~TMP100() {
	// TODO Auto-generated destructor stub
}

