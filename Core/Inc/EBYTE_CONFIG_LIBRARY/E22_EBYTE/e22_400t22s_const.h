/*
 * e22_400t22s.h
 *
 *  Created on: Oct 11, 2024
 *      Author: sergijobvincev
 */

#ifndef INC_E22_EBYTE_E22_400T22S_CONST_H_
#define INC_E22_EBYTE_E22_400T22S_CONST_H_

#include "config_common_const.h"

/* Перечисление скорости UART */
typedef enum {
    UART_RATE_1200_e22_400_22 = 0b000,   // 1200 bps
    UART_RATE_2400_e22_400_22 = 0b001,   // 2400 bps
    UART_RATE_4800_e22_400_22 = 0b010,   // 4800 bps
    UART_RATE_9600_e22_400_22 = 0b011,   // 9600 bps (по умолчанию)
    UART_RATE_19200_e22_400_22 = 0b100,  // 19200 bps
    UART_RATE_38400_e22_400_22 = 0b101,  // 38400 bps
    UART_RATE_57600_e22_400_22 = 0b110,  // 57600 bps
    UART_RATE_115200_e22_400_22 = 0b111  // 115200 bps
} UART_Rate_e22_400_22_e;

/* Перечисление режима четности UART */
typedef enum {
    PARITY_8N1_e22_400_22 = 0b00,    // 8N1 (по умолчанию)
    PARITY_8O1_e22_400_22 = 0b01,    // 8O1
    PARITY_8E1_e22_400_22 = 0b10,    // 8E1
    PARITY_8N1_ALT_e22_400_22 = 0b11 // 8N1 (альтернатива)
} UART_Parity_e22_400_22_e;

/* Перечисление скорости передачи данных по воздуху */
typedef enum {
    AIR_RATE_2400_e22_400_22 = 0b010,   // 2400 bps (по умолчанию)
    AIR_RATE_4800_e22_400_22 = 0b011,   // 4800 bps
    AIR_RATE_9600_e22_400_22 = 0b100,   // 9600 bps
    AIR_RATE_19200_e22_400_22 = 0b101,  // 19200 bps
    AIR_RATE_38400_e22_400_22 = 0b110,  // 38400 bps
    AIR_RATE_62500_e22_400_22 = 0b111   // 62500 bps
} WirelessAirDataRate_e22_400_22_e;

/* Перечисление длины под-пакета */
typedef enum {
    SUB_PACKET_240_e22_400_22 = 0b00,   // 240 байт (по умолчанию)
    SUB_PACKET_128_e22_400_22 = 0b01,   // 128 байт
    SUB_PACKET_64_e22_400_22 = 0b10,    // 64 байта
    SUB_PACKET_32_e22_400_22 = 0b11     // 32 байта
} Sub_Packet_e22_400_22_e;

/* Включение/отключение мониторинга уровня шума RSSI */
typedef enum {
    RSSI_ENV_DISABLED_e22_400_22 = 0b0, // Мониторинг отключен (по умолчанию)
    RSSI_ENV_ENABLE_e22_400_22 = 0b1    // Мониторинг включен
} RSSI_Env_e22_400_22_e;

/* Переключение режимов через программное обеспечение */
typedef enum {
    SOFTWARE_MODE_DISABLED_22 = 0b0,   // Отключено (по умолчанию)
    SOFTWARE_MODE_ENABLE_22 = 0b1      // Включено
} SoftwareModeSwitch_e22_400_22_e;

/* Перечисление мощности передачи */
typedef enum {
    TX_POWER_22dBm_e22_400_22 = 0b00,   // 22 dBm (по умолчанию)
    TX_POWER_17dBm_e22_400_22 = 0b01,   // 17 dBm
    TX_POWER_13dBm_e22_400_22 = 0b10,   // 13 dBm
    TX_POWER_10dBm_e22_400_22 = 0b11    // 10 dBm
} TransmitPower_e22_400_22_e;

/* Перечисление частот */
typedef enum {
    FREQUENCY_410_e22_400_22 = 0,   // 410.125 MHz
    FREQUENCY_411_e22_400_22 = 1,   // 411.125 MHz
    FREQUENCY_412_e22_400_22 = 2,   // 412.125 MHz
    FREQUENCY_413_e22_400_22 = 3,   // 413.125 MHz
    FREQUENCY_414_e22_400_22 = 4,   // 414.125 MHz
    FREQUENCY_415_e22_400_22 = 5,   // 415.125 MHz
    FREQUENCY_416_e22_400_22 = 6,   // 416.125 MHz
    FREQUENCY_417_e22_400_22 = 7,   // 417.125 MHz
    FREQUENCY_418_e22_400_22 = 8,   // 418.125 MHz
    FREQUENCY_419_e22_400_22 = 9,   // 419.125 MHz
    FREQUENCY_420_e22_400_22 = 10,  // 420.125 MHz
    FREQUENCY_425_e22_400_22 = 15,  // 425.125 MHz
    FREQUENCY_430_e22_400_22 = 20,  // 430.125 MHz
    FREQUENCY_435_e22_400_22 = 25,  // 435.125 MHz
    FREQUENCY_440_e22_400_22 = 30,  // 440.125 MHz
    FREQUENCY_445_e22_400_22 = 35,  // 445.125 MHz
    FREQUENCY_450_e22_400_22 = 40,  // 450.125 MHz
    FREQUENCY_455_e22_400_22 = 45,  // 455.125 MHz
    FREQUENCY_460_e22_400_22 = 50,  // 460.125 MHz
    FREQUENCY_465_e22_400_22 = 55,  // 465.125 MHz
    FREQUENCY_470_e22_400_22 = 60,  // 470.125 MHz
    FREQUENCY_475_e22_400_22 = 65,  // 475.125 MHz
    FREQUENCY_480_e22_400_22 = 70,  // 480.125 MHz
    FREQUENCY_485_e22_400_22 = 75,  // 485.125 MHz
    FREQUENCY_490_e22_400_22 = 80,  // 490.125 MHz
    FREQUENCY_493_e22_400_22 = 83   // 493.125 MHz
} ActualFrequency_e22_400_22_e;
/* Настройка вывода байтов RSSI */
typedef enum {
    RSSI_BYTES_DISABLED_e22_400_22 = 0b0, // Отключено (по умолчанию)
    RSSI_BYTES_ENABLE_e22_400_22 = 0b1    // Включено
} RSSIBytes_e22_400_22_e;

/* Методы передачи данных */
typedef enum {
    TRANSFER_TRANSPARENT_e22_400_22 = 0b0, // Прозрачная передача (по умолчанию)
    TRANSFER_FIXED_POINT_e22_400_22 = 0b1  // Фиксированная передача
} TransferMethod_e22_400_22_e;

/* Включение функции ретранслятора */
typedef enum {
    REPEATER_DISABLED_e22_400_22 = 0b0, // Отключено (по умолчанию)
    REPEATER_ENABLE_e22_400_22 = 0b1    // Включено
} RepeaterFunction_e22_400_22_e;

/* Включение функции LBT (Listen Before Talk) */
typedef enum {
    LBT_DISABLED_e22_400_22 = 0b0, // Отключено (по умолчанию)
    LBT_ENABLE_e22_400_22 = 0b1    // Включено
} LBTEnable_e22_400_22_e;

/* Режимы WOR (Wake on Radio) */
typedef enum {
    WOR_MODE_RECEIVER_e22_400_22 = 0b0,    // Приемник WOR (по умолчанию)
    WOR_MODE_TRANSMITTER_e22_400_22 = 0b1 // Передатчик WOR
} WORMode_e22_400_22_e;

/* Периоды WOR */
typedef enum {
    WOR_CYCLE_500ms_e22_400_22 = 0b000,  // 500 мс
    WOR_CYCLE_1000ms_e22_400_22 = 0b001, // 1000 мс
    WOR_CYCLE_1500ms_e22_400_22 = 0b010, // 1500 мс
    WOR_CYCLE_2000ms_e22_400_22 = 0b011, // 2000 мс
    WOR_CYCLE_4000ms_e22_400_22 = 0b111  // 4000 мс
} WORCycleTime_e22_400_22_e;

#endif /* INC_E22_EBYTE_E22_400T22S_CONST_H_ */