/*
 * TMP100.h
 *
 *  Created on: Jun 7, 2024
 *      Author: vikra
 */

#ifndef TMP100_H_
#define TMP100_H_

//User defines here
#define TMP_100_Config_Registry_Address 0x01
#define TMP_100_Config_value 0x60
#define TMP_100_Temp_Registry_Address 0x00
//



//User Includes here
#include "stdint.h"
#include "I2C.h"

//End Includes

class TMP100 {

private:

	//Just change class of object to change between blocking(I2C),Interrupt(I2C_INT)
	//and DMA(I2C_DMA) modes and change header file.
	I2C &i2c;

	const uint16_t address;
	//Define a class buffer according to peripheral
	uint8_t I2C_Buffer[10];


	//Temperature in signed bits
	int16_t val;



public:

	TMP100(uint16_t tempaddress, I2C &i2ctemp);
	I2C::Status Select_Temp_Registry();
	I2C::Status Set_Config();
	I2C::Status Get_Temperature(double &temp_c);




	virtual ~TMP100();
};




#endif /* TMP100_H_ */
