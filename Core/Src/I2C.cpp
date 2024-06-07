/*
 * I2C.cpp
 *
 *  Created on: Jun 6, 2024
 *      Author: vikra
 */

#include "I2C.h"

I2C::I2C() {
	// TODO Auto-generated constructor stub

}

HAL_StatusTypeDef I2C::Transmit(uint8_t *bits, int no_of_bits)
{
	/*uint8_t Tempbits[no_of_bits];
	/for (int i=0; i<no_of_bits ; i++)
	/{
		Tempbits[i]=*(bits+i);
	}
   */
	return HAL_I2C_Master_Transmit(& hi2c1 , address, bits, no_of_bits, Wait_Delay);
}

void I2C::Init_I2C(uint8_t add,I2C_HandleTypeDef hi2c)
{
	address=add;
	hi2c1=hi2c;
}

//void I2C::initprint(UART_HandleTypeDef huartt)
//{
//	huart=huartt;
//	printflag=true;
//}


void I2C::Set_Wait_Delay(uint32_t delay)
{
Wait_Delay=delay;
}

HAL_StatusTypeDef I2C::Receive_2_Buffer(int noofbytes)
{
	return  HAL_I2C_Master_Receive(& hi2c1, address, I2C_Buffer, noofbytes, HAL_MAX_DELAY);

}


I2C::~I2C() {
	// TODO Auto-generated destructor stub
}

