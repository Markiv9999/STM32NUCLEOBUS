/*
 * I2CTMP100.h
 *
 *  Created on: Jun 5, 2024
 *      Author: vikra
 */

#ifndef I2CTMP100_H_
#define I2CTMP100_H_

class I2C_TMP100 {
private:
    //7bit address of peripheral left shifted once and held in 8bit variable
	uint8_t address;

	void SetRegistry();
	uint16_t ReadRegistry();
	void Ping();


public:
	I2C_TMP100(uint8_t addtemp);
	virtual ~I2C_TMP100();
};

#endif /* I2CTMP100_H_ */
