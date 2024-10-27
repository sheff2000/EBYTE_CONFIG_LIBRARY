/*
 * proshuvka_ebyte.c
 *
 *  Created on: Oct 11, 2024
 *      Author: sergijobvincev
 */
#include "proshuvka_ebyte.h"

void wait_aux_level(UART_HandleTypeDef *huartX)
{
	if (huartX == &huart3)
	{
		while (HAL_GPIO_ReadPin(UART3_AUX_GPIO_Port, UART3_AUX_Pin) == GPIO_PIN_RESET)
		{

		}
	}
	if (huartX == &huart4)
	{
		while (HAL_GPIO_ReadPin(UART4_AUX_GPIO_Port, UART4_AUX_Pin) == GPIO_PIN_RESET)
		{

		}
	}
	if (huartX == &huart5)
	{

		while (HAL_GPIO_ReadPin(UART5_AUX_GPIO_Port, UART5_AUX_Pin) == GPIO_PIN_RESET)
		{

		}

	}
}

void ebyte_init_default( SelectEbyteChip_e selectEbyteChip, EbyteConfigUnion_t *config)
{
	if (selectEbyteChip == E22_400T22S)
	{
		init_e22_400t22s_default_config(&config->e22_400_config);
	}
	if (selectEbyteChip == E22_230T22S)
	{
		init_e22_230t22s_default_config(&config->e22_230_config);
	}
	if (selectEbyteChip == E22_900T30D)
	{
		init_e22_900t30d_default_config(&config->e22_900_config);
	}
	if (selectEbyteChip == E32_170T30D)
	{
		init_e32_170t30d_default_config(&config->e32_170_config);
	}
}

uint8_t ebyte_send_config( SelectEbyteChip_e selectEbyteChip, EbyteConfigUnion_t *config, UART_HandleTypeDef *huartX)
{
	if (selectEbyteChip == E22_400T22S)
	{
		if (send_config_e22_400t22s_over_uart(huartX, &config->e22_400_config) != 0)
		{
			return 1;
		}
	}
	if (selectEbyteChip == E22_230T22S)
	{
		if (send_config_e22_230t22s_over_uart(huartX, &config->e22_230_config) != 0)
		{
			return 1;
		}
	}
	if (selectEbyteChip == E22_900T30D)
	{
		if (send_config_e22_900t30d_over_uart(huartX, &config->e22_900_config) != 0)
		{
			return 1;
		}
	}
	if (selectEbyteChip == E32_170T30D)
	{
		if (send_config_e32_170t30d_over_uart(huartX, &config->e32_170_config) != 0)
		{
			return 1;
		}
	}
	return 0;
}

uint8_t proshuvka_start(SelectEbyteType_e selectEbyteType, SelectEbyteChip_e selectEbyteChip, EbyteConfigUnion_t *config, UART_HandleTypeDef *huartX)
{
	// ----- INIT UART + M0/M1 ---
	//HAL_Delay(1000);
	wait_aux_level(huartX);
	//HAL_Delay(10);
	_proshuvka_init_uart(selectEbyteType, selectEbyteChip, huartX);
	//HAL_Delay(500);
	wait_aux_level(huartX);
	HAL_Delay(500);
	// -------
	// ----- БАЗОВАЯ НАСТРОЙКА РЕГИСТРОВ ДЛЯ ЧИПА ------
	ebyte_init_default(selectEbyteChip, config);
	if (ebyte_send_config(selectEbyteChip, config, huartX) != 0)
	{
		return 1;
	}
	// --------------------------------------------------
	//HAL_Delay(500);
	wait_aux_level(huartX);
	HAL_Delay(500);
	_proshuvka_work_uart(selectEbyteType, selectEbyteChip, huartX);
	wait_aux_level(huartX);
	HAL_Delay(500);
	return 0;
}


uint8_t proshuvka_custom(SelectEbyteType_e selectEbyteType, SelectEbyteChip_e selectEbyteChip, EbyteConfigUnion_t *config, UART_HandleTypeDef *huartX)
{
	// ----- INIT UART + M0/M1 ---
	//HAL_Delay(1000);
	wait_aux_level(huartX);
	//HAL_Delay(10);
	_proshuvka_init_uart(selectEbyteType, selectEbyteChip, huartX);
	HAL_Delay(100);
	wait_aux_level(huartX);
	//HAL_Delay(500);
	// -------
	// ----- БАЗОВАЯ НАСТРОЙКА РЕГИСТРОВ ДЛЯ ЧИПА ------
	if (ebyte_send_config(selectEbyteChip, config, huartX) != 0)
	{
		return 1;
	}
	// --------------------------------------------------
	//HAL_Delay(500);
	wait_aux_level(huartX);
	HAL_Delay(100);
	_proshuvka_work_uart(selectEbyteType, selectEbyteChip, huartX);
	wait_aux_level(huartX);
	HAL_Delay(100);
	return 0;
}


uint8_t _proshuvka_init_uart(SelectEbyteType_e selectEbyteType, SelectEbyteChip_e selectEbyteChip, UART_HandleTypeDef *huartX)
{
	huartX->Init.BaudRate = 9600;
	if (HAL_UART_Init(huartX) != HAL_OK)
	{
		return 1;
	}

	if (selectEbyteType == E22)
	{
		if( huartX == &huart3)
		{
			HAL_GPIO_WritePin(UART3_M0_GPIO_Port, UART3_M0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(UART3_M1_GPIO_Port, UART3_M1_Pin, GPIO_PIN_SET);

		}
		if( huartX == &huart4)
		{
			HAL_GPIO_WritePin(UART4_M0_GPIO_Port, UART4_M0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(UART4_M1_GPIO_Port, UART4_M1_Pin, GPIO_PIN_SET);

		}
		if( huartX == &huart5)
		{
			HAL_GPIO_WritePin(UART5_M0_GPIO_Port, UART5_M0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(UART5_M1_GPIO_Port, UART5_M1_Pin, GPIO_PIN_SET);
		}
	} else if (selectEbyteType == E32)
	{
		if( huartX == &huart3)
		{
			HAL_GPIO_WritePin(UART3_M0_GPIO_Port, UART3_M0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(UART3_M1_GPIO_Port, UART3_M1_Pin, GPIO_PIN_SET);
		}
		if( huartX == &huart4)
		{
			HAL_GPIO_WritePin(UART4_M0_GPIO_Port, UART4_M0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(UART4_M1_GPIO_Port, UART4_M1_Pin, GPIO_PIN_SET);
		}
		if( huartX == &huart5)
		{
			HAL_GPIO_WritePin(UART5_M0_GPIO_Port, UART5_M0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(UART5_M1_GPIO_Port, UART5_M1_Pin, GPIO_PIN_SET);
		}
	}


	return 0;
}

uint8_t _proshuvka_work_uart(SelectEbyteType_e selectEbyteType, SelectEbyteChip_e selectEbyteChip, UART_HandleTypeDef *huartX)
{
	huartX->Init.BaudRate = 115200;
	if (HAL_UART_Init(huartX) != HAL_OK)
	{
		return 1;
	}

	if (selectEbyteType == E22)
	{
		if( huartX == &huart3)
		{
			HAL_GPIO_WritePin(UART3_M0_GPIO_Port, UART3_M0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(UART3_M1_GPIO_Port, UART3_M1_Pin, GPIO_PIN_RESET);
		}
		if( huartX == &huart4)
		{
			HAL_GPIO_WritePin(UART4_M0_GPIO_Port, UART4_M0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(UART4_M1_GPIO_Port, UART4_M1_Pin, GPIO_PIN_RESET);
		}
		if( huartX == &huart5)
		{
			HAL_GPIO_WritePin(UART5_M0_GPIO_Port, UART5_M0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(UART5_M1_GPIO_Port, UART5_M1_Pin, GPIO_PIN_RESET);
		}
	} else if (selectEbyteType == E32)
	{
		if( huartX == &huart3)
		{
			HAL_GPIO_WritePin(UART3_M0_GPIO_Port, UART3_M0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(UART3_M1_GPIO_Port, UART3_M1_Pin, GPIO_PIN_RESET);
		}
		if( huartX == &huart4)
		{
			HAL_GPIO_WritePin(UART4_M0_GPIO_Port, UART4_M0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(UART4_M1_GPIO_Port, UART4_M1_Pin, GPIO_PIN_RESET);
		}
		if( huartX == &huart5)
		{
			HAL_GPIO_WritePin(UART5_M0_GPIO_Port, UART5_M0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(UART5_M1_GPIO_Port, UART5_M1_Pin, GPIO_PIN_RESET);
		}
	}


	return 0;
}


void init_e22_400t22s_default_config(E22_400T22S_Registers_t *config) {
	config->ADDH = ADDH_STANDART;
	config->ADDL = ADDL_STANDART;
	config->NETID = NETID_STANDART;
	config->REG0.rate = UART_RATE_115200_e22_400;
	config->REG0.parity = PARITY_8N1_e22_400;
	config->REG0.airRate = AIR_RATE_9600_e22_400;
	config->REG1.subPacket = SUB_PACKET_32_e22_400;
	config->REG1.rssiEnv = RSSI_ENV_DISABLED_e22_400;
	config->REG1.softwareMode = SOFTWARE_MODE_DISABLED;
	config->REG1.transmitPower = TX_POWER_22dBm_e22_400;
	config->REG2.frequency = FREQUENCY_470_e22_400;
	config->REG3.rssiBytes = RSSI_BYTES_ENABLE_e22_400;
	config->REG3.transferMetod = TRASPARENT_e22_400;
	config->REG3.repeaterFunction = REPITER_DISABLED_e22_400;
	config->REG3.lbt = LBT_DISABLED_e22_400;
	config->REG3.worMode = WOR_MODE_RECIVER_e22_400;
	config->REG3.worCycle = WOR_CYCLE_500ms_e22_400;
	config->CRYPT_H = HIGHT_BYTE_KEY_V0;
	config->CRYPT_L = LOW_BYTE_KEY_v1;

}

void init_e22_230t22s_default_config(E22_230T22S_Registers_t *config) {

	config->ADDH = ADDH_STANDART;
	config->ADDL = ADDL_STANDART;
	config->NETID = NETID_STANDART;
	config->REG0.airRate = AIR_RATE_9600_e22_230;
	config->REG0.parity = PARITY_8N1_e22_230;
	config->REG0.rate = UART_RATE_115200_e22_230;
	config->REG1.rssiEnv = RSSI_ENV_DISABLED_e22_230;
	config->REG1.softwareMode = SOFTWARE_MODE_DISABLED_e22_230;
	config->REG1.subPacket = SUB_PACKET_32_e22_230;
	config->REG1.transmitPower = TX_POWER_22dBm_e22_230;
	config->REG2.frequency = FREQUENCY_232_e22_230;
	config->REG3.lbt = LBT_DISABLED_e22_230;
	config->REG3.repeaterFunction = REPITER_DISABLED_e22_230;
	config->REG3.rssiBytes = RSSI_BYTES_ENABLE_e22_230;
	config->REG3.transferMetod = TRASPARENT_e22_230;
	config->REG3.worCycle = WOR_CYCLE_500ms_e22_230;
	config->REG3.worMode = WOR_MODE_RECIVER_e22_230;
	config->CRYPT_H = HIGHT_BYTE_KEY_V0;
	config->CRYPT_L = LOW_BYTE_KEY_v1;
}
void init_e22_900t30d_default_config(E22_900T30D_Registers_t *config) {
    config->ADDH = ADDH_STANDART;
    config->ADDL = ADDL_STANDART;
    config->NETID = NETID_STANDART;
    config->REG0.rate = UART_RATE_115200_e22_900;
    config->REG0.parity = PARITY_8N1_e22_900;
    config->REG0.airRate = AIR_RATE_9600_e22_900;
    config->REG1.subPacket = SUB_PACKET_32_e22_900;
    config->REG1.rssiEnv = RSSI_ENV_DISABLED_e22_900;
    config->REG1.softwareMode = SOFTWARE_MODE_DISABLED_e22_900;
    config->REG1.transmitPower = TX_POWER_30dBm_e22_900;
    config->REG2.frequency = FREQUENCY_900_e22_900;
    config->REG3.rssiBytes = RSSI_BYTES_DISABLED_e22_900;
    config->REG3.transferMetod = TRASPARENT_e22_900;
    config->REG3.repeaterFunction = REPITER_DISABLED_e22_900;
    config->REG3.lbt = LBT_DISABLED_e22_900;
    config->REG3.worMode = WOR_MODE_RECIVER_e22_900;
    config->REG3.worCycle = WOR_CYCLE_500ms_e22_900;
    config->CRYPT_H = HIGHT_BYTE_KEY_V0;
    config->CRYPT_L = LOW_BYTE_KEY_v1;
}

void init_e32_170t30d_default_config(E32_170T30D_Registers_t *config) {
	// 0x0 0x1 0x3c 0x28 0x44
    config->HEAD = 0xC0;
	config->ADDH = ADDH_STANDART;
    config->ADDL = ADDL_STANDART;
    config->SPED.parity = PARITY_8N1_e32_170;
    config->SPED.rate = UART_RATE_115200_e32_170;
    config->SPED.airRate = AIR_RATE_4800_e32_170;
    config->CHAN.frequency = FREQUENCY_170_e32_170;
    config->OPTIONS.transferMetod = TRASPARENT_e32_170;
    config->OPTIONS.ioDriveMode = TX_RX_PULL_e32_170;
    config->OPTIONS.wor = WOR_CYCLE_250ms_e32_170;
    config->OPTIONS.fec = FEC_OFF_e32_170;
    config->OPTIONS.txPower = TX_POWER_30dBm_e32_170;

}



uint8_t send_config_e22_400t22s_over_uart(UART_HandleTypeDef *huart, E22_400T22S_Registers_t *config) {
    uint8_t bufferKod400[12];

    // Заполняем заголовок
    bufferKod400[0] = 0xC0;
    bufferKod400[1] = 0x00;
    bufferKod400[2] = 0x09;

    // Записываем данные из структуры
    bufferKod400[3] = _set_ADDH_e22_400(&config->ADDH);
    bufferKod400[4] = _set_ADDL_e22_400(&config->ADDL);
    bufferKod400[5] = _set_NETID_e22_400(&config->NETID);
    bufferKod400[6] = _set_REG0_e22_400(&config->REG0);
    bufferKod400[7] = _set_REG1_e22_400(&config->REG1);
    bufferKod400[8] = _set_REG2_e22_400(&config->REG2);
    bufferKod400[9] = _set_REG3_e22_400(&config->REG3);
    bufferKod400[10] = _set_CRYPT_H_e22_400(&config->CRYPT_H);
    bufferKod400[11] = _set_CRYPT_L_e22_400(&config->CRYPT_L);

    // Передаем данные по UART
    if (HAL_UART_Transmit(huart, bufferKod400, 12, 100) != HAL_OK)
    {
    	return 1;
    }

    return 0;
}

uint8_t send_config_e22_230t22s_over_uart(UART_HandleTypeDef *huart, E22_230T22S_Registers_t *config) {
    uint8_t bufferKod200[12];

    // Заполняем заголовок
    bufferKod200[0] = 0xC0;
    bufferKod200[1] = 0x00;
    bufferKod200[2] = 0x09;

    // Записываем данные из структуры
    bufferKod200[3] = _set_ADDH_e22_230(&config->ADDH);
    bufferKod200[4] = _set_ADDL_e22_230(&config->ADDL);
    bufferKod200[5] = _set_NETID_e22_230(&config->NETID);
    bufferKod200[6] = _set_REG0_e22_230(&config->REG0);
    bufferKod200[7] = _set_REG1_e22_230(&config->REG1);
    bufferKod200[8] = _set_REG2_e22_230(&config->REG2);
    bufferKod200[9] = _set_REG3_e22_230(&config->REG3);
    bufferKod200[10] = _set_CRYPT_H_e22_230(&config->CRYPT_H);
    bufferKod200[11] = _set_CRYPT_L_e22_230(&config->CRYPT_L);

    // Передаем данные по UART
    if (HAL_UART_Transmit(huart, bufferKod200, 12, 100) != HAL_OK)
    {
    	return 1;
    }

    return 0;
}

uint8_t send_config_e22_900t30d_over_uart(UART_HandleTypeDef *huart, E22_900T30D_Registers_t *config) {
    uint8_t bufferKod[12];

    // Заполняем заголовок
    bufferKod[0] = 0xC0;
    bufferKod[1] = 0x00;
    bufferKod[2] = 0x09;

    // Записываем данные из структуры
    bufferKod[3] = _set_ADDH_e22_900(&config->ADDH);
    bufferKod[4] = _set_ADDL_e22_900(&config->ADDL);
    bufferKod[5] = _set_NETID_e22_900(&config->NETID);
    bufferKod[6] = _set_REG0_e22_900(&config->REG0);
    bufferKod[7] = _set_REG1_e22_900(&config->REG1);
    bufferKod[8] = _set_REG2_e22_900(&config->REG2);
    bufferKod[9] = _set_REG3_e22_900(&config->REG3);
    bufferKod[10] = _set_CRYPT_H_e22_900(&config->CRYPT_H);
    bufferKod[11] = _set_CRYPT_L_e22_900(&config->CRYPT_L);

    // Передаем данные по UART
    if (HAL_UART_Transmit(huart, bufferKod, 12, 100) != HAL_OK)
    {
    	return 1;
    }

    return 0;
}

uint8_t send_config_e32_170t30d_over_uart(UART_HandleTypeDef *huart, E32_170T30D_Registers_t *config) {
    uint8_t bufferKod170[12];

    // Записываем данные из структуры
    bufferKod170[0] = _set_HEAD_e32_170();
    bufferKod170[1] = _set_ADDH_e32_170(&config->ADDH);
    bufferKod170[2] = _set_ADDL_e32_170(&config->ADDL);
    bufferKod170[3] = _set_SPED_e32_170(&config->SPED);
    bufferKod170[4] = _set_CHAN_e32_170(&config->CHAN);
    bufferKod170[5] = _set_OPTIONS_e32_170(&config->OPTIONS);

    // Передаем данные по UART
    if (HAL_UART_Transmit(huart, bufferKod170, 6, 100) != HAL_OK)
    {
    	return 1;
    }

    return 0;
}

uint8_t proshuvka_init2(UART_HandleTypeDef *huart3, UART_HandleTypeDef *huart4, UART_HandleTypeDef *huart5)
{
	// SET UART Bound Rate = 9600
	huart3->Init.BaudRate = 9600;
	huart4->Init.BaudRate = 9600;
	huart5->Init.BaudRate = 9600;

	if (HAL_UART_Init(huart3) != HAL_OK)
	{
		return 1;
	}
	if (HAL_UART_Init(huart4) != HAL_OK)
	{
		return 1;
	}
	if (HAL_UART_Init(huart5) != HAL_OK)
	{
		return 1;
	}

	// SET MODE EBYTE - CONFIG

	// E22-200
	HAL_GPIO_WritePin(UART3_M0_GPIO_Port, UART3_M0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(UART3_M1_GPIO_Port, UART3_M1_Pin, GPIO_PIN_SET);

	// E22-400
	HAL_GPIO_WritePin(UART4_M0_GPIO_Port, UART4_M0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(UART4_M1_GPIO_Port, UART4_M1_Pin, GPIO_PIN_SET);

	// E22-900
	HAL_GPIO_WritePin(UART5_M0_GPIO_Port, UART5_M0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(UART5_M1_GPIO_Port, UART5_M1_Pin, GPIO_PIN_SET);

	HAL_Delay(1000);

	// E22-200T37S / E22-200T22S
	// 228.875 MHz
	// UART - 115 200    UART 3
	// Air rate - 9600
	// buffer - 32 bytes
	// addres - 20
	// channel - 35
	// net id - 1
	// key - 0

	uint8_t bufferKod200[20];

	bufferKod200[0] = 0xC0;
	bufferKod200[1] = 0x00; // start addr
	bufferKod200[2] = 0x09;  // count bytes

	bufferKod200[3] = 0x00;
	bufferKod200[4] = 0x14;
	bufferKod200[5] = 0x01;
	bufferKod200[6] = 0xE5;
	bufferKod200[7] = 0xC0;
	bufferKod200[8] = 0x23;   // channel
	bufferKod200[9] = 0x00;
	bufferKod200[10] = 0x00;
	bufferKod200[11] = 0x00;

	if (HAL_UART_Transmit(huart3, bufferKod200, 12, 300) != HAL_OK)
	{
		return 1;
	}
	HAL_Delay(1000);

	// E22-400T37S / E22-400T22S
	// 445.125 MHz
	// UART - 115 200
	// Air rate - 9600
	// buffer - 32 bytes
	// addres - 20
	// channel - 35
	// net id - 1
	// key - 0

	uint8_t bufferKod400[20];

	bufferKod400[0] = 0xC0;
	bufferKod400[1] = 0x00; // start addr
	bufferKod400[2] = 0x09;  // count bytes

	bufferKod400[3] = 0x00;
	bufferKod400[4] = 0x23;  // low byte addres  35 = 0x23
	bufferKod400[5] = 0x02;  // NET ID   2
	bufferKod400[6] = 0xE4;
	bufferKod400[7] = 0xC0;
	bufferKod400[8] = 0x1F;  // 14 - 430.125 MHz // channel 60 =  0x3c - 470.125 MHz  /// 0x23 old value
	bufferKod400[9] = 0x00;
	bufferKod400[10] = 0x00;
	bufferKod400[11] = 0x00;

	if (HAL_UART_Transmit(huart4, bufferKod400, 12, 300) != HAL_OK)
	{
		return 1;
	}
	HAL_Delay(1000);


	uint8_t bufferKod900[20];

	bufferKod900[0] = 0xC0;
	bufferKod900[1] = 0x00; // start addr
	bufferKod900[2] = 0x09;  // count bytes

	bufferKod900[3] = 0x00;
	bufferKod900[4] = 0x0F;
	bufferKod900[5] = 0x01;
	bufferKod900[6] = 0xE4;
	bufferKod900[7] = 0xC0;
	bufferKod900[8] = 0x2D;   // channel
	bufferKod900[9] = 0x00;
	bufferKod900[10] = 0x00;
	bufferKod900[11] = 0x01;

	if (HAL_UART_Transmit(huart5, bufferKod900, 12, 300) != HAL_OK)
	{
		return 1;
	}
	HAL_Delay(1000);

	huart3->Init.BaudRate = 115200;
	huart4->Init.BaudRate = 115200;
	huart5->Init.BaudRate = 115200;

	if (HAL_UART_Init(huart3) != HAL_OK)
	{
		return 1;
	}
	if (HAL_UART_Init(huart4) != HAL_OK)
	{
		return 1;
	}
	if (HAL_UART_Init(huart5) != HAL_OK)
	{
		return 1;
	}

	// E22-200
	HAL_GPIO_WritePin(UART3_M0_GPIO_Port, UART3_M0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(UART3_M1_GPIO_Port, UART3_M1_Pin, GPIO_PIN_RESET);

	// E22-400
	HAL_GPIO_WritePin(UART4_M0_GPIO_Port, UART4_M0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(UART4_M1_GPIO_Port, UART4_M1_Pin, GPIO_PIN_RESET);

	// E22-900
	HAL_GPIO_WritePin(UART5_M0_GPIO_Port, UART5_M0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(UART5_M1_GPIO_Port, UART5_M1_Pin, GPIO_PIN_RESET);

	return 0;
}
