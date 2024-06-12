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

#ifdef __cplusplus
extern "C" {
#endif

//User Includes here
#include "stm32l4xx_hal.h"
#include "I2C.h"


//End Includes

class TMP100 {

private:


	I2C i2c;
	I2C::STATUS ret;

	//Define a class buffer according to peripheral
	uint8_t I2C_Buffer[2];


	//Temperature in signed bits
	int16_t val;


	//huart is to be initialized if the print functions are to be used
	UART_HandleTypeDef huart;
	//Printflag will be set true when huart is initialized
	bool Print_Flag=false;

public:

<<<<<<< HEAD
	TMP100(int I2CInstanceNo, int mode, uint8_t tempaddress,UART_HandleTypeDef huart2 ,  uint32_t delay=HAL_MAX_DELAY);
=======
<<<<<<< HEAD
	TMP100(uint8_t tempaddress,UART_HandleTypeDef huart2, I2C_HandleTypeDef hi2c,  uint32_t delay=HAL_MAX_DELAY);
=======
	TMP100(int I2CInstanceNo, int mode, uint8_t tempaddress,UART_HandleTypeDef huart2 ,  uint32_t delay=HAL_MAX_DELAY);
>>>>>>> parent of ea59823 (Committing implementation)
>>>>>>> parent of 758cae6 (revert commit)


	I2C::STATUS Set_Config(uint8_t settings = 0x60);
	I2C::STATUS Get_Temperature(double &temp_c);




	virtual ~TMP100();
};


#ifdef __cplusplus
}
#endif


#endif /* TMP100_H_ */
