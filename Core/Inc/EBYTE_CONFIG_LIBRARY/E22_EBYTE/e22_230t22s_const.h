/*
 * e22_230t22s_const.h
 *
 *  Created on: Oct 12, 2024
 *      Author: sergijobvincev
 * 
 * 
 *		[Frequency]：220.125~236.125MHz
 *		[Power]：22dBm
 *		[Distance]：5km
 *		[Interface]：UART
 *		[Weight]：2.3±0.1g
 *		[Introduction]：E22-230T22S is a wireless serial port module (UART) based on 
 *			SEMTECH's LoRa solution radio frequency chip. It has multiple transmission methods 
 *			and works in the (220.125MHz~236.125MHz) frequency band; it adopts a new generation 
 *			of LoRa spread spectrum technology, compared with SX1278 , longer distance, lower power 
 * 			consumption, and smaller size; supports air wake-up, wireless configuration, carrier monitoring, 
 * 			and relay networking functions.
*/

#ifndef INC_E22_EBYTE_E22_230T22S_CONST_H_
#define INC_E22_EBYTE_E22_230T22S_CONST_H_
#include "config_common_const.h"

typedef enum {  // REG0 765
    UART_RATE_1200_e22_230_22 = 0b000,
	UART_RATE_2400_e22_230_22 = 0b001,
	UART_RATE_4800_e22_230_22 = 0b010,
	UART_RATE_9600_e22_230_22 = 0b011,
	UART_RATE_19200_e22_230_22 = 0b100,
	UART_RATE_38400_e22_230_22 = 0b101,
	UART_RATE_57600_e22_230_22 = 0b110,
	UART_RATE_115200_e22_230_22 = 0b111
} UART_Rate_e22_230_22_e;

typedef enum { // REG0 43
    PARITY_8N1_e22_230_22 = 0b00,
    PARITY_8O1_e22_230_22 = 0b01,
    PARITY_8E1_e22_230_22 = 0b10,
    PARITY_8N1_ALT_e22_230_22 = 0b11
} UART_Parity_e22_230_22_e;

typedef enum {  // REG0 210
	//AIR_RATE_2400_e22_230 = 0b000,
	//AIR_RATE_2400_e22_230 = 0b001,
	//AIR_RATE_2400_e22_230 = 0b010,

	AIR_RATE_2400_e22_230_22 = 0b011,
	AIR_RATE_4800_e22_230_22 = 0b100,
	AIR_RATE_9600_e22_230_22 = 0b101,
	AIR_RATE_15600_e22_230_22 = 0b110,
	//AIR_RATE_15600_e22_230 = 0b111,
} WirelessAirDataRate_e22_230_22_e;

typedef enum { // REG1 76
	SUB_PACKET_240_e22_230_22 = 0b00,
	SUB_PACKET_128_e22_230_22 = 0b01,
	SUB_PACKET_64_e22_230_22 = 0b10,
	SUB_PACKET_32_e22_230_22 = 0b11
} Sub_Packet_e22_230_22_e;


// RSSI enable command (Sub packet setting,
// transmit power as default parameters,
// configuration mode): C0 04 01 20;
// After enabling, the command C0 C1 C2 C3 can be
// sent in the normal mode(mode 0) or WOR
// transmission mode (trasmitter in mode 1) to read
// the register;
// Register 0x00: current environmental noise RSSI;
// Register 0X01: RSSI at Last Data Received
// (Current channel noise is: dBm = -(256 - RSSI));
// Command format: C0 C1 C2 C3+start
// address+read length;
// Return: C1 + address + read length + read valid
// value;
// For example:
// Send: C0 C1 C2 C3 00 01
// Return: C1 00 01 RSSI (the address can only
// start from 00)
typedef enum { // REG1 5
	RSSI_ENV_DISABLED_e22_230_22 = 0b0,
	RSSI_ENV_ENABLE_e22_230_22 = 0b1
} RSSI_Env_e22_230_22_e;

// If you use Ebyte's host computer configuration
// software, this bit will be turned off
// automatically. If you don’t want to use the M0
// M1 pins to switch working modes, you can
// enable this function, and use specific serial port
// commands to switch modes.
// Format: C0 C1 C2 C3 02 + working mode
// Send C0 C1 C2 C3 02 00 to switch to transparent
// transmission mode
// Send C0 C1 C2 C3 02 01 to switch to WOR mode
// Send C0 C1 C2 C3 02 02 to switch to
// configuration mode
// Send C0 C1 C2 C3 02 03 to switch to sleep mode
// Return: C1 C2 C3 02 + working mode
// Note: After enabling this function, WOR mode
// and sleep mode only support 9600 baud rate

typedef enum { // REG1 2
	SOFTWARE_MODE_DISABLED_e22_230_22 = 0b0,
	SOFTWARE_MODE_ENABLE_e22_230_22 = 0b1
} SoftwareModeSwitch_e22_230_22_e;

typedef enum { // REG1 10
	TX_POWER_22dBm_e22_230_22 = 0b00,
	TX_POWER_17dBm_e22_230_22 = 0b01,
	TX_POWER_13dBm_e22_230_22 = 0b10,
	TX_POWER_10dBm_e22_230_22 = 0b11
} TransmitingPower_e22_230_22_e;

// Channel Control (CH)
// 0-64 respectively represent a total of 65 channels
typedef enum {
	// CHANNEL NUMBER
	// 220.125 + CH * 0.25 MHz
	// 236.125
	FREQUENCY_220_e22_230_22 = 0,  
	FREQUENCY_221_e22_230_22 = 4,  
	FREQUENCY_222_e22_230_22 = 8,
	FREQUENCY_223_e22_230_22 = 12,
	FREQUENCY_224_e22_230_22 = 16,
	FREQUENCY_225_e22_230_22 = 20,
	FREQUENCY_226_e22_230_22 = 24,
	FREQUENCY_227_e22_230_22 = 28,
	FREQUENCY_228_e22_230_22 = 32,
	FREQUENCY_229_e22_230_22 = 36,
	FREQUENCY_230_e22_230_22 = 40,
	FREQUENCY_231_e22_230_22 = 44,
	FREQUENCY_232_e22_230_22 = 48,
	FREQUENCY_233_e22_230_22 = 52,
	FREQUENCY_234_e22_230_22 = 56,
	FREQUENCY_235_e22_230_22 = 60,
	FREQUENCY_236_e22_230_22 = 64
} ActualFrequency_e22_230_22_e;

typedef enum {
	// After enabled, when the module receives the
	// wireless data, it will follow an RSSI strength byte
	// after output via the serial port TXD
	RSSI_BYTES_DISABLED_e22_230_22 = 0b0,
	RSSI_BYTES_ENABLE_e22_230_22 = 0b1
} RSSIBytes_e22_230_22_e;

typedef enum {
	// During fixed-point transmission, the module will
	// identify the first three bytes of serial port data as:
	// address high + address low + channel, and use
	// them as wireless transmission targets.
	TRASPARENT_e22_230_22 = 0b0,   // default
	FIXED_POINT_e22_230_22 = 0b1
} TransferMethod_e22_230_22_e;

typedef enum {
	// After the repeater function is enabled, if the target
	// address is not the module itself, the module will
	// start a forwarding ;
	// In order to prevent data from being transmitted
	// back, it is recommended to use it in conjunction
	// with fixed-point mode ; that is, the destination
	// address and source address are different.
	REPITER_DISABLED_e22_230_22 = 0b0,
	REPITER_ENABLE_e22_230_22 = 0b1
} RepeaterFunction_e22_230_22_e;

typedef enum {
	LBT_DISABLED_e22_230_22 = 0b0,
	LBT_ENABLE_e22_230_22 = 0b1
} LBTEnable_e22_230_22_e;

typedef enum {
	// When enabled, wireless data will be monitored
	// before transmission, which can avoid interference
	// to a certain extent, but may cause data delays;
	// The maximum dwell time of LBT is 2 seconds.
	// The wireless data will be transmitted forcibly after
	// 2 seconds.
	WOR_MODE_RECIVER_e22_230_22 = 0b0, // default
	WOR_MODE_TRANSMITER_e22_230_22 = 0b1
} WORMode_e22_230_22_e;

typedef enum {
	WOR_CYCLE_500ms_e22_230_22 = 0b000,
	WOR_CYCLE_1000ms_e22_230_22 = 0b001,
	WOR_CYCLE_1500ms_e22_230_22 = 0b010,
	WOR_CYCLE_2000ms_e22_230_22 = 0b011,
	WOR_CYCLE_2500ms_e22_230_22 = 0b100,
	WOR_CYCLE_3000ms_e22_230_22 = 0b101,
	WOR_CYCLE_3500ms_e22_230_22 = 0b110,
	WOR_CYCLE_4000ms_e22_230_22 = 0b111
} WORCycleTime_e22_230_22_e;

// 80H~86H Read PID 
// Product information 7 bytes Product information 7 bytes

#endif /* INC_E22_EBYTE_E22_230T22S_CONST_H_ */
