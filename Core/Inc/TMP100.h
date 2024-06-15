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

#define TMP_100_Temp_Registry_Address 0x00
//



//User Includes here
#include "stm32l4xx_hal.h"

#include "I2C.h"


//End Includes

class TMP100 {

private:

	//Just change class of object to change between blocking(I2C),Interrupt(I2C_INT)
	//and DMA(I2C_DMA) modes and change header file.
	I2C &i2c;
	I2C_STATUS ret;

	//Define a class buffer according to peripheral
	uint8_t I2C_Buffer[10];


	//Temperature in signed bits
	int16_t val;



public:

	TMP100(uint16_t tempaddress, I2C_HandleTypeDef hi2c,  uint32_t delay=HAL_MAX_DELAY);

	I2C_STATUS Select_Temp_Registry();
	I2C_STATUS Set_Config(uint8_t settings = 0x60);
	I2C_STATUS Get_Temperature(double &temp_c);




	virtual ~TMP100();
};




#endif /* TMP100_H_ */
