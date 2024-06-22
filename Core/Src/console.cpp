/*
 * console.c
 *
 *  Created on: Jun 12, 2024
 *      Author: vikra
 */

#include <console.h>



console::console(UART_HandleTypeDef huarttemp)
{
	huart=huarttemp;
}


void console::print(const char (&Msg)[])
{
	HAL_UART_Transmit(&huart, (uint8_t*) Msg, strlen((char*)Msg), HAL_MAX_DELAY);
}

/*
void console::check_ok(I2C::Status rettemp, const char (&operation_title_temp)[])
{

	char Error_Msg[20];
	char operation_title[50];
	strcpy(operation_title,operation_title_temp);
	switch(rettemp)
	{ 	case I2C::Status::OK:
			strcpy(Error_Msg,strcat(operation_title,":SUCCESS:OK \r\n"));
			break;

		case I2C::Status::ERROR:
			strcpy(Error_Msg,strcat(operation_title,":FAILED:ERROR\r\n"));
			break;

		case I2C::Status::BUSY:
			strcpy(Error_Msg,strcat(operation_title,":FAILED:BUSY\r\n"));
							break;
		case I2C::Status::TIMEOUT:
			strcpy(Error_Msg,strcat(operation_title,":FAILED:TIMEOUT\r\n"));
							break;
		case I2C::Status::SHOULD_NOT_HAPPEN:
			strcpy(Error_Msg,strcat(operation_title,":FAILED:SHOULD_NOT_HAPPEN\r\n"));
							break;
	}
	print((Error_Msg));
}

*/
console::~console()
{

}
