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
	return HAL_I2C_Master_Transmit(& hi2c1 , address, bits, no_of_bits, Wait_Delay);
}

HAL_StatusTypeDef I2C::Transmit_DMA(uint8_t *bits, int no_of_bits)
{
	return HAL_I2C_Master_Transmit_DMA(&hi2c1 , address, bits, no_of_bits);
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
	return  HAL_I2C_Master_Receive(& hi2c1, address, I2C_Buffer, noofbytes, Wait_Delay);
}

HAL_StatusTypeDef I2C::Receive_2_Buffer_DMA(int noofbytes)
{
	return  HAL_I2C_Master_Receive_DMA(&hi2c1, address, I2C_Buffer, noofbytes);
}



I2C::~I2C() {
	// TODO Auto-generated destructor stub
}

