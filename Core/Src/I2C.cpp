/*
 * I2C.cpp
 *
 *  Created on: Jun 6, 2024
 *      Author: vikra
 */

#include "I2C.h"
//Select I2C instance no from {1,2,3} (STM32NucleoL476 has 3 instances I2C1, I2C2, I2C3) and mode from {1=normal(100kbps), 2=fastmode(400kbps), 3=fastmodeplus(1Mbps)}

I2C::I2C( I2C_HandleTypeDef hi2c, uint32_t delay )
{

hi2c1=hi2c;
Wait_Delay=delay;

}

I2C::I2C( I2C & i2ctemp )
{
//Copy constructor
	hi2c1=i2ctemp.hi2c1;
	Wait_Delay=i2ctemp.Wait_Delay;
}

I2C_STATUS I2C::Transmit(uint16_t address,uint8_t (&bits)[], uint16_t no_of_bytes)
{
	HAL_StatusTypeDef temp;
	temp= HAL_I2C_Master_Transmit(&hi2c1 , address, bits, no_of_bytes, Wait_Delay);

	switch(temp)
	{
		case HAL_OK:
			return I2C_STATUS::OK;
			break;

		case HAL_ERROR:
			return I2C_STATUS::ERROR;
			break;

		case HAL_BUSY:
			return I2C_STATUS::BUSY;
			break;

		case HAL_TIMEOUT:
			return I2C_STATUS::TIMEOUT;
			break;
	}

	return I2C_STATUS::SHOULD_NOT_HAPPEN;
}



I2C_STATUS I2C::Receive_2_Buffer(uint16_t address,uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes)
{
	HAL_StatusTypeDef temp;
		temp= HAL_I2C_Master_Receive(&hi2c1, address, I2C_Buffer, no_of_bytes, Wait_Delay);

		switch(temp)
		{
			case HAL_OK:
				return I2C_STATUS::OK;
				break;

			case HAL_ERROR:
				return I2C_STATUS::ERROR;
				break;

			case HAL_BUSY:
				return I2C_STATUS::BUSY;
				break;

			case HAL_TIMEOUT:
				return I2C_STATUS::TIMEOUT;
				break;
		}

		return I2C_STATUS::SHOULD_NOT_HAPPEN;
}




I2C::~I2C() {
	// TODO Auto-generated destructor stub
}





/*Commented out implementations, for ease of future modifications

I2C::I2C(int I2CInstanceNo, int mode,UART_HandleTypeDef huart2, I2C_HandleTypeDef hi2c, uint32_t delay ) {



	/*

	char* Error_Msg[25];
	sprintf((char*)Error_Msg,
									"%u, %u \r\n",
									((int)I2CInstanceNo),
									((int)mode));
	HAL_UART_Transmit(&huart2, (uint8_t*) Error_Msg, strlen((char*)Error_Msg), HAL_MAX_DELAY);
	huart=huart2;
	  //Select appropriate Instance
      switch(I2CInstanceNo)
		  {
		  	  case 1:
		  		sprintf((char*)Error_Msg,
		  											"instance set succefully \r\n",
		  											((int)I2CInstanceNo),
		  											((int)mode));
		  		  hi2c1.Instance = I2C1;
		  		HAL_UART_Transmit(&huart2, (uint8_t*) Error_Msg, strlen((char*)Error_Msg), HAL_MAX_DELAY);
		  		  break;

		  	  case 2:
		  		  hi2c1.Instance = I2C2;
		  		  break;

		  	  case 3:
		  		  hi2c1.Instance = I2C3;
		  		  break;
		  }

      //Select Appropriate mode
      switch(mode)
     		  {	  //Select correct timing - here they are set to ones provided by STM32CubeIde
     		  	  case 1:
     		  		  hi2c1.Init.Timing = 0x10909CEC;
     		  		  break;

     		  	  case 2:
     		  		  hi2c1.Init.Timing = 0x00702991;
     		  		  break;

     		  	  case 3:
     		  		  hi2c1.Init.Timing = 0x00300F33;
     		  		  //Activate FastModePlus on selected I2C Instance
     		  		  switch(I2CInstanceNo)
     		  				  {
     		  				  	  case 1:
     		  				  		  HAL_I2CEx_EnableFastModePlus(I2C_FASTMODEPLUS_I2C1);
     		  				  		  break;

     		  				  	  case 2:
     		  				  		  HAL_I2CEx_EnableFastModePlus(I2C_FASTMODEPLUS_I2C2);
     		  				  		  break;

     		  				  	  case 3:
     		  				  		  HAL_I2CEx_EnableFastModePlus(I2C_FASTMODEPLUS_I2C3);
     		  				  		  break;
     		  				  }

     		  		  break;




     		  }

      //Set Other Parameters common to all modes and instances
      Wait_Delay=delay;
	  hi2c1.Init.OwnAddress1 = 0;
	  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	  hi2c1.Init.OwnAddress2 = 0;
	  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
	  {
		  sprintf((char*)Error_Msg,
		       		  				  											"Init Failed \r\n",
		       		  				  											((int)I2CInstanceNo),
		       		  				  											((int)mode));

		       		  				  		HAL_UART_Transmit(&huart2, (uint8_t*) Error_Msg, strlen((char*)Error_Msg), HAL_MAX_DELAY);
	    Error_Handler();
	  }

	   Configure Analogue filter

	  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	  {
		  sprintf((char*)Error_Msg,
		 		       		  				  											"Analog Filter Failed",
		 		       		  				  											((int)I2CInstanceNo),
		 		       		  				  											((int)mode));

		 		       		  				  		HAL_UART_Transmit(&huart2, (uint8_t*) Error_Msg, strlen((char*)Error_Msg), HAL_MAX_DELAY);
	    Error_Handler();
	  }

	  Configure Digital filter

	  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
	  {
		  sprintf((char*)Error_Msg,
		 		       		  				  											"Digital Filter Failed \r\n",
		 		       		  				  											((int)I2CInstanceNo),
		 		       		  				  											((int)mode));

		 		       		  				  		HAL_UART_Transmit(&huart2, (uint8_t*) Error_Msg, strlen((char*)Error_Msg), HAL_MAX_DELAY);
	    Error_Handler();

	  }
}
*/




