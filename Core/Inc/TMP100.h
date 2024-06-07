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
	HAL_StatusTypeDef ret;
	char Error_Msg[15];
	//Temperature in Celsius
	double Temp_C;
	//Temperature in signed bits
	int16_t val;


	//huart is to be initialized if the print functions are to be used
	UART_HandleTypeDef huart;
	//Printflag will be set true when huart is initialized
	bool Print_Flag=false;

public:
	TMP100();
	TMP100(uint8_t add,I2C_HandleTypeDef hi2c);
	TMP100(uint8_t add,I2C_HandleTypeDef hi2c, UART_HandleTypeDef huartt);

	void Init(uint8_t add,I2C_HandleTypeDef hi2c);
	void Init(uint8_t add,I2C_HandleTypeDef hi2c,UART_HandleTypeDef huartt);
	void Set_Config(uint8_t settings = 0x60);
	double Get_Temperature();



	virtual ~TMP100();
};


#ifdef __cplusplus
}
#endif


#endif /* TMP100_H_ */
