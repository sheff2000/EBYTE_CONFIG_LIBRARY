/*
 * proshuvka_ebyte.h
 *
 *  Created on: Oct 11, 2024
 *      Author: sergijobvincev
 * THE MAIN FILE 
 *      Прошивка модулей EBYTE E22 / E32 на FPV
 * 	    с ипользованием библиотеки HAL
 * 		Для проекта в среде STM32CubeIDE
 * 		для STM32F407
 */

#ifndef INC_PROSHUVKA_EBYTE_H_
#define INC_PROSHUVKA_EBYTE_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "main.h"
// #include "global_enum.h"

// #include "E22_EBYTE/e22_400t22s_struct.h"
#include "E22_EBYTE/e22_230t22s_struct.h"
// #include "E22_EBYTE/e22_900t30d_struct.h"
// #include "E32_EBYTE/e32_170t30d_struct.h"

extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;

// Список доступных чипов для настройки
// Нужно для определения структуры регистров настройки 

typedef enum {
	E22_400T22S = 0x11,
	//E22_230T22S = 0x12,
	//E22_900T30D = 0x13,
	//E32_170T30D = 0x14,
	// E22_230T37S = 0x15,
	// E22_400T37S = 0x16
} SelectEbyteChip_e;

// Серия модуля 
// зависит вход в режим конфигурации и др.
typedef enum {
	E22 = 0x01,
	E32 = 0x02
} SelectEbyteType_e;

// набор структур настроечных регистров для каждой модели модуля
// храним все наборы, независимо от того какая у нас конкретно модель
// не знаю как сделать этот момент динамическим
typedef struct {
    //E22_400T22S_Registers_t e22_400_config;
    E22_230T22S_Registers_t e22_230_config;
    //E22_900T30D_Registers_t e22_900_config;
    //E32_170T30D_Registers_t e32_170_config;
} EbyteConfigUnion_t;

// набор статусов 
// для общей структуры чипа
// показывает его текущее состояние
typedef enum {
	STATUS_OK = 0,
	STATUS_BUSY = 1,
	STATUS_ERROR = 2,
	STATUS_CONFIG_MODE = 3,
	STATUS_STOP = 4,
} status_ebyte_e;

typedef struct {
	SelectEbyteType_e SelectEbyteType;
	SelectEbyteChip_e SelectEbyteChip;
	EbyteConfigUnion_t config;
	status_ebyte_e status;
} chipEbyte_t;
// перенастройка UART BoundRate = 9600
// включение модулей в режим CONFIG


// uint8_t proshuvka_start(SelectEbyteType_e selectEbyteType, SelectEbyteChip_e selectEbyteChip, EbyteConfigUnion_t *config, UART_HandleTypeDef *huartX);
// uint8_t proshuvka_custom(SelectEbyteType_e selectEbyteType, SelectEbyteChip_e selectEbyteChip, EbyteConfigUnion_t *config, UART_HandleTypeDef *huartX);


// void wait_aux_level(UART_HandleTypeDef *huartX);

// void ebyte_init_default(SelectEbyteChip_e selectEbyteChip, EbyteConfigUnion_t *config);
// uint8_t ebyte_send_config( SelectEbyteChip_e selectEbyteChip, EbyteConfigUnion_t *config, UART_HandleTypeDef *huartX);

// uint8_t _proshuvka_init_uart(SelectEbyteType_e selectEbyteType, SelectEbyteChip_e selectEbyteChip, UART_HandleTypeDef *huartX);
// uint8_t _proshuvka_work_uart(SelectEbyteType_e selectEbyteType, SelectEbyteChip_e selectEbyteChip, UART_HandleTypeDef *huartX);


// БАЗОВЫЕ НАСТРОЙКИ МОДУЛЕЙ - ПО УМОЛЧАНИЮ !!!!
// void init_e22_400t22s_default_config(E22_400T22S_Registers_t *config);
// void init_e22_230t22s_default_config(E22_230T22S_Registers_t *config);
// void init_e22_900t30d_default_config(E22_900T30D_Registers_t *config);
// void init_e32_170t30d_default_config(E32_170T30D_Registers_t *config);

// uint8_t send_config_e22_400t22s_over_uart(UART_HandleTypeDef *huart, E22_400T22S_Registers_t *config);
// uint8_t send_config_e22_230t22s_over_uart(UART_HandleTypeDef *huart, E22_230T22S_Registers_t *config);
//uint8_t send_config_e22_900t30d_over_uart(UART_HandleTypeDef *huart, E22_900T30D_Registers_t *config);
// uint8_t send_config_e32_170t30d_over_uart(UART_HandleTypeDef *huart, E32_170T30D_Registers_t *config);


// 220.125～ 236.125MHz
// uint8_t proshuvka_e22_200(UART_HandleTypeDef *huart3);

#endif /* INC_PROSHUVKA_EBYTE_H_ */
