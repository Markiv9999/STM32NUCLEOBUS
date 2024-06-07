/*
 * TMP100I2C.h
 *
 *  Created on: Jun 6, 2024
 *      Author: vikra
 */

#ifndef SRC_TMP100I2C_H_
#define SRC_TMP100I2C_H_
//Defines Here
#define TMP_100_Config_Registry_Address 0x01
#define TMP_100_Temp_Registry_Address 0x00
//


#ifdef __cplusplus
extern "C" {
#endif

//Includes here
#include "stm32l4xx_hal.h"

//End includes


class TMP100I2C {
private:
uint8_t address;
I2C_HandleTypeDef hi2c1;
uint32_t waitdelay= HAL_MAX_DELAY;
HAL_StatusTypeDef ret;
uint8_t buf[2];

public:
	TMP100I2C();
	void Set_Config_Reg(uint8_t settingbits);
	void Select_Temp_Reg();
	uint16_t Read_Temp();
	void Set_Delay(uint32_t delay);
	virtual ~TMP100I2C();
};


#ifdef __cplusplus
}
#endif


#endif /* SRC_TMP100I2C_H_ */
