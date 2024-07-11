/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

#include "TMP100.h"
#include "UartConsole.h"
#include "BoardInit.h"
#define TMP_Address_100 0x48<<1



I2C::Status ret;




int main(void)
{
  //Initialize the board:SysClock, GPIO, LEDS.
  BoardInit();

  /*Define and Initialize Peripherals*/

  //Console UART
  UartConsole con1;
  con1.Init();

  //TMP100 I2C
  I2C i2c_obj(1);
  i2c_obj.Init();
  TMP100 TestSensor(TMP_Address_100, i2c_obj);

  //Temporary variables to hold temperature and Error Messages
  double temp;
  char Error_Msg[40];

  //Initialize the Sensor
  ret=TestSensor.Initialize();

  if ( ret != I2C::Status::OK )
  {
	  strcpy((char*)Error_Msg, "Error Setting Config\r\n");
  }
  else
  {
	  strcpy((char*)Error_Msg, "Config Set\r\n");
  }

  con1.print(Error_Msg);

  //Select Temperature Registry and check if the selection succeeded
  ret=TestSensor.Select_Temp_Registry();

  if ( ret != I2C::Status::OK )
  {
	  strcpy((char*)Error_Msg, "Error Setting Temp Reg\r\n");
  }
  else
  {
	  strcpy((char*)Error_Msg, "Temp Reg Set\r\n");
  }

  con1.print(Error_Msg);

  while (1)
  {
	  //Read Temperature from Sensor
	  ret=TestSensor.Get_Temperature(temp);
	  if ( ret != I2C::Status::OK )
	  {
		  strcpy((char*)Error_Msg, "Error Getting Temp\r\n");
	  }
	  else
	  {
		  // Convert temperature to decimal format
		  temp *= 100;
		  sprintf( (char*) Error_Msg,"%u.%u C\r\n",( (unsigned int) temp / 100 ),( (unsigned int) temp % 100) );
	  }
	  con1.print(Error_Msg);
  }

}




/* USER CODE BEGIN 4 */

/* USER CODE END 4 */


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
