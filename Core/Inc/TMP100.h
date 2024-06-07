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
I2C Connection;

public:
	TMP100();

	void init(uint8_t add,I2C_HandleTypeDef hi2c);
	void setconfig(uint8_t settings);
	void gettemperature();

	virtual ~TMP100();
};


#ifdef __cplusplus
}
#endif


#endif /* TMP100_H_ */
