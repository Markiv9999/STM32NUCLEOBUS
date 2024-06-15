/*
 * STATUS.h
 *
 *  Created on: Jun 12, 2024
 *      Author: vikra
 */

#ifndef INC_I2CSTATUS_H_
#define INC_I2CSTATUS_H_


enum class I2C_STATUS
	{
		OK,

		ERROR,

		BUSY,

		TIMEOUT,

		SHOULD_NOT_HAPPEN
	};


#endif /* INC_I2CSTATUS_H_ */
