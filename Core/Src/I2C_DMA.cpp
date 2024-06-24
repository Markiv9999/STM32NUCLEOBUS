/*
 * I2C_DMA.cpp
 *
 *  Created on: Jun 21, 2024
 *      Author: vikra
 */

#include "I2C_DMA.h"

I2C_DMA::I2C_DMA(I2C_HandleTypeDef &hi2ctemp):I2C(hi2ctemp)
{

}

void Error_Handler()
{
//TODO
}


I2C::Status I2C_DMA::Transmit(uint16_t address,uint8_t (&bits)[], uint16_t no_of_bytes)
{
	HAL_StatusTypeDef temp;
	temp= HAL_I2C_Master_Transmit_DMA(&hi2c1 , address, bits, no_of_bytes);

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


I2C::Status I2C_DMA::Receive_2_Buffer(uint16_t address,uint8_t (&I2C_Buffer)[],uint16_t no_of_bytes)
{
	HAL_StatusTypeDef temp;
		temp= HAL_I2C_Master_Receive_DMA(&hi2c1, address, I2C_Buffer, no_of_bytes);

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

//****************************************INITIALIZATION**************************************************//


void I2C_DMA::Init()
{


	 /* DMA controller clock enable */
	  __HAL_RCC_DMA1_CLK_ENABLE();

	  /* DMA interrupt init */
	  /* DMA1_Channel6_IRQn interrupt configuration */
	  HAL_NVIC_SetPriority(DMA1_Channel6_IRQn, 1, 0);
	  HAL_NVIC_EnableIRQ(DMA1_Channel6_IRQn);
	  /* DMA1_Channel7_IRQn interrupt configuration */
	  HAL_NVIC_SetPriority(DMA1_Channel7_IRQn, 2, 0);
	  HAL_NVIC_EnableIRQ(DMA1_Channel7_IRQn);



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
	    Error_Handler();
	  }

	  /** Configure Analogue filter
	  */
	  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  /** Configure Digital filter
	  */
	  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
	  {
	    Error_Handler();
	  }

}




//**********************************MSP INITIALIZATION************************************************//

void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
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
	  Error_Handler();
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

	/* I2C1 DMA Init */
	/* I2C1_RX Init */
	hdma_i2c1_rx.Instance = DMA1_Channel7;
	hdma_i2c1_rx.Init.Request = DMA_REQUEST_3;
	hdma_i2c1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
	hdma_i2c1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
	hdma_i2c1_rx.Init.MemInc = DMA_MINC_ENABLE;
	hdma_i2c1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	hdma_i2c1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	hdma_i2c1_rx.Init.Mode = DMA_NORMAL;
	hdma_i2c1_rx.Init.Priority = DMA_PRIORITY_LOW;
	if (HAL_DMA_Init(&hdma_i2c1_rx) != HAL_OK)
	{
	  Error_Handler();
	}

	__HAL_LINKDMA(hi2c,hdmarx,hdma_i2c1_rx);

	/* I2C1_TX Init */
	hdma_i2c1_tx.Instance = DMA1_Channel6;
	hdma_i2c1_tx.Init.Request = DMA_REQUEST_3;
	hdma_i2c1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
	hdma_i2c1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
	hdma_i2c1_tx.Init.MemInc = DMA_MINC_ENABLE;
	hdma_i2c1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	hdma_i2c1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	hdma_i2c1_tx.Init.Mode = DMA_NORMAL;
	hdma_i2c1_tx.Init.Priority = DMA_PRIORITY_LOW;
	if (HAL_DMA_Init(&hdma_i2c1_tx) != HAL_OK)
	{
	  Error_Handler();
	}

	__HAL_LINKDMA(hi2c,hdmatx,hdma_i2c1_tx);

	/* I2C1 interrupt Init */
	HAL_NVIC_SetPriority(I2C1_EV_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
	HAL_NVIC_SetPriority(I2C1_ER_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);
	/* USER CODE BEGIN I2C1_MspInit 1 */

	/* USER CODE END I2C1_MspInit 1 */
	}

}


void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c)
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

    /* I2C1 DMA DeInit */
    HAL_DMA_DeInit(hi2c->hdmarx);
    HAL_DMA_DeInit(hi2c->hdmatx);

    /* I2C1 interrupt DeInit */
    HAL_NVIC_DisableIRQ(I2C1_EV_IRQn);
    HAL_NVIC_DisableIRQ(I2C1_ER_IRQn);
  /* USER CODE BEGIN I2C1_MspDeInit 1 */

  /* USER CODE END I2C1_MspDeInit 1 */
  }

}






I2C_DMA::~I2C_DMA() {
	// TODO Auto-generated destructor stub
}


