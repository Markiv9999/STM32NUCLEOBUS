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
#include "I2C.h"

//End includes


class TMP100I2C {

private:
I2C Connection;

public:
	TMP100I2C();

	void setconfig(uint8_t settings);

	void gettemperature();

	virtual ~TMP100I2C();
};


#ifdef __cplusplus
}
#endif


#endif /* SRC_TMP100I2C_H_ */
