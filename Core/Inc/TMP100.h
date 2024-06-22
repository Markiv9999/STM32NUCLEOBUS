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
//#include "I2C.h"
#include "I2C_IT.h"
//#include "I2C_DMA.h"

//End Includes

//Defines Here

//Internal Register Address
#define TEMP_REG					0x00
#define CONFIG_REG					0x01
#define TEMP_THRESH_HIGH_REG		0x02
#define TEMP_THRESH_LOW_REG			0x03

//Config Register Settings [takes 8 bits each deciding a different setting, see config register in TMP100 Documentation ]
//If you do not want to worry about settings, select 0x60 (RESOLUTION_12_BIT).

//Shutdown Mode
#define ENABLE_SHUTDOWN				0x01
#define DISABLE_SHUTDOWN			0x00

//Thermostat mode
#define COMPARATOR_MODE				0x00
#define INTERRUPT_MODE				0x02

//Polarity
#define POLARITY_LOW				0x00		//Active Low
#define POLARITY_HIGH				0x04		//Active High

//Fault queue
#define CONSECUTIVE_FAULTS_1		0x00
#define CONSECUTIVE_FAULTS_2		0x08
#define CONSECUTIVE_FAULTS_4		0x10
#define CONSECUTIVE_FAULTS_6		0x18

//Converter Resolution
#define RESOLUTION_9_BIT			0x00		//0.5 degC
#define RESOLUTION_10_BIT			0x20		//0.25 degC
#define RESOLUTION_11_BIT			0x40		//0.125 degC
#define RESOLUTION_12_BIT			0x60		//0.0625 degC

//End Defines


class TMP100 {

private:

	//Just change class of object to change between blocking(I2C),Interrupt(I2C_INT)
	//and DMA(I2C_DMA) modes and change header file.
	I2C_IT &i2c;

	const uint16_t address;
	//Define a class buffer according to peripheral
	uint8_t I2C_Buffer[10];

	I2C::Status Select_Temp_Registry();
	//Temperature in signed bits




public:

	TMP100(uint16_t tempaddress, I2C_IT &i2ctemp);

	I2C::Status Set_Config();
	I2C::Status Get_Temperature(double &temp_c);




	virtual ~TMP100();
};




#endif /* TMP100_H_ */
