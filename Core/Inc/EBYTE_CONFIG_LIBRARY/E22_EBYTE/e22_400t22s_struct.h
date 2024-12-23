/*
 * e22_400t22s_struct.h
 *
 *  Created on: Oct 12, 2024
 *      Author: sergijobvincev
 */

#ifndef INC_E22_EBYTE_E22_400T22S_STRUCT_H_
#define INC_E22_EBYTE_E22_400T22S_STRUCT_H_

#include "main.h"
#include "e22_400t22s_const.h"
#include <stdio.h>

// Структура для регистра REG0: параметры UART и скорость передачи данных по воздуху
typedef struct {
    UART_Rate_e22_400_22_e rate;             // Скорость UART
    UART_Parity_e22_400_22_e parity;         // Режим четности UART
    WirelessAirDataRate_e22_400_22_e airRate;// Скорость передачи данных по воздуху
} E22_400T22S_REG0_t;

// Структура для регистра REG1: под-пакеты, RSSI и мощность передачи
typedef struct {
    Sub_Packet_e22_400_22_e subPacket;       // Размер под-пакета
    RSSI_Env_e22_400_22_e rssiEnv;           // Включение мониторинга RSSI
    SoftwareModeSwitch_e22_400_22_e softwareMode; // Программное управление режимами
    TransmitPower_e22_400_22_e transmitPower;// Мощность передачи
} E22_400T22S_REG1_t;

// Структура для регистра REG2: управление частотой
typedef struct {
    ActualFrequency_e22_400_22_e frequency;  // Частота канала
} E22_400T22S_REG2_t;

// Структура для регистра REG3: RSSI, режимы передачи и ретрансляции
typedef struct {
    RSSIBytes_e22_400_22_e rssiBytes;        // Включение передачи байта RSSI
    TransferMethod_e22_400_22_e transferMethod; // Метод передачи (прозрачный/фиксированный)
    RepeaterFunction_e22_400_22_e repeaterFunction; // Функция ретранслятора
    LBTEnable_e22_400_22_e lbt;              // Включение функции LBT
    WORMode_e22_400_22_e worMode;            // Режим WOR
    WORCycleTime_e22_400_22_e worCycle;      // Период WOR
} E22_400T22S_REG3_t;

// Полная структура всех регистров
typedef struct {
    ADDH_e ADDH;                             // Старший байт адреса
    ADDL_e ADDL;                             // Младший байт адреса
    NETID_e NETID;                           // Сетевой ID
    E22_400T22S_REG0_t REG0;                 // Регистры параметров UART и воздуха
    E22_400T22S_REG1_t REG1;                 // Регистры RSSI, под-пакетов и мощности
    E22_400T22S_REG2_t REG2;                 // Регистры частоты
    E22_400T22S_REG3_t REG3;                 // Регистры передачи и функций
    HightByteKey_e CRYPT_H;                  // Старший байт ключа шифрования
    LowByteKey_e CRYPT_L;                    // Младший байт ключа шифрования
    uint8_t READRegisters[12];               // Буфер для чтения всех регистров (12 байт)
} E22_400T22S_Registers_t;

// Прототипы функций для установки регистров
uint8_t _set_ADDH_e22_400(ADDH_e *addh);
uint8_t _set_ADDL_e22_400(ADDL_e *addl);
uint8_t _set_NETID_e22_400(NETID_e *netid);
uint8_t _set_REG0_e22_400(E22_400T22S_REG0_t *reg0_config);
uint8_t _set_REG1_e22_400(E22_400T22S_REG1_t *reg1_config);
uint8_t _set_REG2_e22_400(E22_400T22S_REG2_t *reg2_config);
uint8_t _set_REG3_e22_400(E22_400T22S_REG3_t *reg3_config);
uint8_t _set_CRYPT_H_e22_400(HightByteKey_e *hightByteKey);
uint8_t _set_CRYPT_L_e22_400(LowByteKey_e *lowByteKey);
void _get_READRegisters_e22_400(E22_400T22S_Registers_t *configRegisters);

#endif /* INC_E22_EBYTE_E22_400T22S_STRUCT_H_ */