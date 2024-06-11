/*
 * TMP100.cpp
 *
 *  Created on: Jun 7, 2024
 *      Author: vikra
 */

#include "TMP100.h"

TMP100::TMP100(I2C a(int I2CInstanceNo, int mode, uint32_t delay)) : i2c(a)
	// TODO Auto-generated constructor stub

}



void TMP100::Set_Config(uint8_t settings)
{
// Select config registry and overwrite bits
uint8_t config[2]= {TMP_100_Config_Registry_Address, settings};

ret=i2c.Transmit(config, 2);

if ( ret != HAL_OK )
	     {
	       strcpy((char*)Error_Msg, "Error Setting Registry\r\n");
	     }
		else
		{
			strcpy((char*)Error_Msg, "Config Success\r\n");
		}
if (Print_Flag==true)
			HAL_UART_Transmit(&huart, (uint8_t*) Error_Msg, strlen((char*)Error_Msg), HAL_MAX_DELAY);

}

double TMP100::Get_Temperature()
{   // Select temperature registry
	uint8_t config = TMP_100_Temp_Registry_Address;

	ret=i2c.Transmit(&config, 1);
	//
	if ( ret != HAL_OK )
		 {
		   strcpy((char*)Error_Msg, "Error TX\r\n");
		   if (Print_Flag==true)
			   HAL_UART_Transmit(&huart, (uint8_t*) Error_Msg, strlen((char*)Error_Msg), HAL_MAX_DELAY);
		   return 0;

		 }
	else
		{
			// Read 2 bytes from the temperature register to i2c object buffer
			ret = i2c.Receive_2_Buffer(2);

		   if ( ret != HAL_OK )
		   {
			 strcpy((char*)Error_Msg, "Error Rx\r\n");
		   }
		   else
		   {
			 //Combine the bytes from i2c internal buffer to temperature as signed integer
			 val = ((int16_t)i2c.I2C_Buffer[0] << 4) | (i2c.I2C_Buffer[1] >> 4);

			 // Convert to 2's complement, since temperature can be negative
			 if ( val > 0x7FF ) {
			   val |= 0xF000;
			 }

			 // Convert to float temperature value (Celsius)
			 Temp_C = val * 0.0625;

			 // Convert temperature to decimal format
			 Temp_C *= 100;
			 sprintf((char*)Error_Msg,
				   "%u.%u C\r\n",
				   ((unsigned int)Temp_C / 100),
				   ((unsigned int)Temp_C % 100));
			 }
		   if (Print_Flag==true)
			   HAL_UART_Transmit(&huart, (uint8_t*) Error_Msg, strlen((char*)Error_Msg), HAL_MAX_DELAY);

	}
	//Undoing convertion to return correct value
return (Temp_C/100);
}


void TMP100::Set_Config_DMA(uint8_t settings)
{
// Select config registry and overwrite bits
uint8_t config[2]= {TMP_100_Config_Registry_Address, settings};

ret=i2c.Transmit_DMA(config, 2);


if ( ret != HAL_OK )
	     {
	       strcpy((char*)Error_Msg, "Error Setting Registry\r\n");
	     }
else
		{
			strcpy((char*)Error_Msg, "Config Success\r\n");
		}

if (Print_Flag==true)
			HAL_UART_Transmit(&huart, (uint8_t*) Error_Msg, strlen((char*)Error_Msg), HAL_MAX_DELAY);

}

double TMP100::Get_Temperature_DMA()
{   // Select temperature registry
	uint8_t config = TMP_100_Temp_Registry_Address;
	//Can possibly use sequential transmit here to improve performance
	ret=i2c.Transmit_DMA(&config, 1);
	//
	if ( ret != HAL_OK )
		 {
		   strcpy((char*)Error_Msg, "Error TX\r\n");
		   if (Print_Flag==true)
			   HAL_UART_Transmit(&huart, (uint8_t*) Error_Msg, strlen((char*)Error_Msg), HAL_MAX_DELAY);
		   return 0;

		 }
	else
		{
			// Read 2 bytes from the temperature register to i2c object buffer
			ret = i2c.Receive_2_Buffer_DMA(2);
			// Wait for DMA to complete

		   if ( ret != HAL_OK )
		   {
			 strcpy((char*)Error_Msg, "Error Rx\r\n");
		   }
		   else
		   {
			 //Combine the bytes from i2c internal buffer to temperature as signed integer
			 val = ((int16_t)i2c.I2C_Buffer[0] << 4) | (i2c.I2C_Buffer[1] >> 4);

			 // Convert to 2's complement, since temperature can be negative
			 if ( val > 0x7FF ) {
			   val |= 0xF000;
			 }

			 // Convert to float temperature value (Celsius)
			 Temp_C = val * 0.0625;

			 // Convert temperature to decimal format
			 Temp_C *= 100;
			 sprintf((char*)Error_Msg,
				   "%u.%u C\r\n",
				   ((unsigned int)Temp_C / 100),
				   ((unsigned int)Temp_C % 100));
			 }
		   if (Print_Flag==true)
			   HAL_UART_Transmit(&huart, (uint8_t*) Error_Msg, strlen((char*)Error_Msg), HAL_MAX_DELAY);

		}
	//Undoing convertion to return correct value
return (Temp_C/100);
}




TMP100::~TMP100() {
	// TODO Auto-generated destructor stub
}

