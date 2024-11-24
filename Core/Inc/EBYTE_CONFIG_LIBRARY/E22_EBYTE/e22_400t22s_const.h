/*
 * e22_400t22s.h
 *
 *  Created on: Oct 11, 2024
 *      Author: sergijobvincev
 */

#ifndef INC_E22_EBYTE_E22_400T22S_CONST_H_
#define INC_E22_EBYTE_E22_400T22S_CONST_H_
#include "config_common_const.h"


typedef enum {
    UART_RATE_1200_e22_400 = 0b000,
	UART_RATE_2400_e22_400 = 0b001,
	UART_RATE_4800_e22_400 = 0b010,
	UART_RATE_9600_e22_400 = 0b011,
	UART_RATE_19200_e22_400 = 0b100,
	UART_RATE_38400_e22_400 = 0b101,
	UART_RATE_57600_e22_400 = 0b110,
	UART_RATE_115200_e22_400 = 0b111
} UART_Rate_e22_400_e;

typedef enum {
    PARITY_8N1_e22_400 = 0b00,
    PARITY_8O1_e22_400 = 0b01,
    PARITY_8E1_e22_400 = 0b10,
    PARITY_8N1_ALT_e22_400 = 0b11
} UART_Parity_e22_400_e;

typedef enum {
	//AIR_RATE_2400_e22_400 = 0b000,
	//AIR_RATE_2400_e22_400 = 0b001,
	AIR_RATE_2400_e22_400 = 0b010,
	AIR_RATE_4800_e22_400 = 0b011,
	AIR_RATE_9600_e22_400 = 0b100,
	AIR_RATE_19200_e22_400 = 0b101,
	AIR_RATE_38400_e22_400 = 0b110,
	AIR_RATE_62500_e22_400 = 0b111
} WirelessAirDataRate_e22_400_e;

typedef enum {
	SUB_PACKET_240_e22_400 = 0b00,
	SUB_PACKET_128_e22_400 = 0b01,
	SUB_PACKET_64_e22_400 = 0b10,
	SUB_PACKET_32_e22_400 = 0b11
} Sub_Packet_e22_400_e;

typedef enum {
	RSSI_ENV_DISABLED_e22_400 = 0b0,
	RSSI_ENV_ENABLE_e22_400 = 0b1
} RSSI_Env_e22_400_e;

typedef enum {
	RESERVE_2BIT = 0b00
} Reserve_2bit_e;

typedef enum {
	SOFTWARE_MODE_DISABLED = 0b0,
	SOFTWARE_MODE_ENABLE = 0b1
} SoftwareModeSwitch_e22_400_e;

typedef enum {
	TX_POWER_22dBm_e22_400 = 0b00,
	TX_POWER_17dBm_e22_400 = 0b01,
	TX_POWER_13dBm_e22_400 = 0b10,
	TX_POWER_10dBm_e22_400 = 0b11
} TransmitingPower_e22_400_e;

typedef enum {
	// CHANNEL NUMBER
	// 410.125 + CH * 1 MHz
	// 410.125 ～ 493.125MHz
	FREQUENCY_410_e22_400 = 0,
	FREQUENCY_415_e22_400 = 5,
	FREQUENCY_420_e22_400 = 10,
	FREQUENCY_425_e22_400 = 15,
	FREQUENCY_430_e22_400 = 20,
	FREQUENCY_435_e22_400 = 25,
	FREQUENCY_440_e22_400 = 30,
	FREQUENCY_441_e22_400 = 31,
	FREQUENCY_442_e22_400 = 32,
	FREQUENCY_443_e22_400 = 33,
	FREQUENCY_445_e22_400 = 35,
	FREQUENCY_450_e22_400 = 40,
	FREQUENCY_455_e22_400 = 45,
	FREQUENCY_460_e22_400 = 50,
	FREQUENCY_465_e22_400 = 55,
	FREQUENCY_470_e22_400 = 60,
	FREQUENCY_475_e22_400 = 65,
	FREQUENCY_480_e22_400 = 70,
	FREQUENCY_485_e22_400 = 75,
	FREQUENCY_490_e22_400 = 80,
	FREQUENCY_493_e22_400 = 83
} ActualFrequency_e22_400_e;

typedef enum {
	// After enabled, when the module receives the
	// wireless data, it will follow an RSSI strength byte
	// after output via the serial port TXD
	RSSI_BYTES_DISABLED_e22_400 = 0b0,
	RSSI_BYTES_ENABLE_e22_400 = 0b1
} RSSIBytes_e22_400_e;

typedef enum {
	// During fixed-point transmission, the module will
	// identify the first three bytes of serial port data as:
	// address high + address low + channel, and use
	// them as wireless transmission targets.
	TRASPARENT_e22_400 = 0b0,
	FIXED_POINT_e22_400 = 0b1
} TransferMethod_e22_400_e;

typedef enum {
	// After the repeater function is enabled, if the target
	// address is not the module itself, the module will
	// start a forwarding ;
	// In order to prevent data from being transmitted
	// back, it is recommended to use it in conjunction
	// with fixed-point mode ; that is, the destination
	// address and source address are different.
	REPITER_DISABLED_e22_400 = 0b0,
	REPITER_ENABLE_e22_400 = 0b1
} RepeaterFunction_e22_400_e;

typedef enum {
	LBT_DISABLED_e22_400 = 0b0,
	LBT_ENABLE_e22_400 = 0b1
} LBTEnable_e22_400_e;

typedef enum {
	// When enabled, wireless data will be monitored
	// before transmission, which can avoid interference
	// to a certain extent, but may cause data delays;
	// The maximum dwell time of LBT is 2 seconds.
	// The wireless data will be transmitted forcibly after
	// 2 seconds.
	WOR_MODE_RECIVER_e22_400 = 0b0, // default
	WOR_MODE_TRANSMITER_e22_400 = 0b1
} WORMode_e22_400_e;

typedef enum {
	WOR_CYCLE_500ms_e22_400 = 0b000,
	WOR_CYCLE_1000ms_e22_400 = 0b001,
	WOR_CYCLE_1500ms_e22_400 = 0b010
} WORCycleTime_e22_400_e;


#endif /* INC_E22_EBYTE_E22_400T22S_CONST_H_ */
