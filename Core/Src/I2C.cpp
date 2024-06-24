/*
 * I2C.cpp
 *
 *  Created on: Jun 6, 2024
 *      Author: vikra
 */

#include "I2C.h"
//Select I2C instance no from {1,2,3} (STM32NucleoL476 has 3 instances I2C1, I2C2, I2C3) and mode from {1=normal(100kbps), 2=fastmode(400kbps), 3=fastmodeplus(1Mbps)}

I2C::I2C(I2C_HandleTypeDef &hi2ctemp, uint32_t delay):hi2c1(hi2ctemp)
{

Wait_Delay=delay;

}


void I2C::Init()
{

	  hi2c1.Instance = I2C1;
	  hi2c1.Init.Timing = 0x10909CEC;
	  hi2c1.Init.OwnAddress1 = 0;
	  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	  hi2c1.Init.OwnAddress2 = 0;
	  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
	  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
	  {
	    //Error_Handler();
	  }

	  /** Configure Analogue filter
	  */
	  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	  {
	    //Error_Handler();
	  }

	  /** Configure Digital filter
	  */
	  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
	  {
	   // Error_Handler();
	  }




}

I2C::Status I2C::Transmit(uint16_t address,uint8_t (&bits)[], uint16_t no_of_bytes)
{
	HAL_StatusTypeDef temp;
	temp= HAL_I2C_Master_Transmit(&hi2c1 , address, bits, no_of_bytes, Wait_Delay);

	switch(temp)
	{
		case HAL_OK:
			return Status::OK;
			break;

		case HAL_ERROR:
			return Status::ERROR;
			break;

		case HAL_BUSY:
			return Status::BUSY;
			break;

		case HAL_TIMEOUT:
			return Status::TIMEOUT;
			break;
	}

	return Status::SHOULD_NOT_HAPPEN;
}



I2C::Status I2C::Receive_2_Buffer(uint16_t address,uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes)
{
	HAL_StatusTypeDef temp;
		temp= HAL_I2C_Master_Receive(&hi2c1, address, I2C_Buffer, no_of_bytes, Wait_Delay);

		switch(temp)
		{
			case HAL_OK:
				return Status::OK;
				break;

			case HAL_ERROR:
				return Status::ERROR;
				break;

			case HAL_BUSY:
				return Status::BUSY;
				break;

			case HAL_TIMEOUT:
				return Status::TIMEOUT;
				break;
		}

		return Status::SHOULD_NOT_HAPPEN;
}




I2C::~I2C() {
	// TODO Auto-generated destructor stub
}





/***************************************MSP_INIT*******************************************************/
//When using rename to HAL_I2C_MspDeInit
void HAL_I2C_MspInit_Blocking(I2C_HandleTypeDef* hi2c)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hi2c->Instance==I2C1)
  {
  /* USER CODE BEGIN I2C1_MspInit 0 */

  /* USER CODE END I2C1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
    PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
     // Error_Handler();
    }

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**I2C1 GPIO Configuration
    PB8     ------> I2C1_SCL
    PB9     ------> I2C1_SDA
    */
    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* Peripheral clock enable */
    __HAL_RCC_I2C1_CLK_ENABLE();
  /* USER CODE BEGIN I2C1_MspInit 1 */

  /* USER CODE END I2C1_MspInit 1 */
  }

}

/**
* @brief I2C MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspDeInit_Blocking(I2C_HandleTypeDef* hi2c)
{
  if(hi2c->Instance==I2C1)
  {
  /* USER CODE BEGIN I2C1_MspDeInit 0 */

  /* USER CODE END I2C1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C1_CLK_DISABLE();

    /**I2C1 GPIO Configuration
    PB8     ------> I2C1_SCL
    PB9     ------> I2C1_SDA
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_8);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_9);

  /* USER CODE BEGIN I2C1_MspDeInit 1 */

  /* USER CODE END I2C1_MspDeInit 1 */
  }

}
