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

typedef struct {
	UART_Rate_e22_400_e rate;
	UART_Parity_e22_400_e parity;
	WirelessAirDataRate_e22_400_e airRate;
} E22_400T22S_REG0_t;

typedef struct {
	Sub_Packet_e22_400_e subPacket;
	RSSI_Env_e22_400_e rssiEnv;
	SoftwareModeSwitch_e22_400_e softwareMode;
	TransmitingPower_e22_400_e transmitPower;
} E22_400T22S_REG1_t;

typedef struct {
	ActualFrequency_e22_400_e frequency;
} E22_400T22S_REG2_t;

typedef struct {
	RSSIBytes_e22_400_e rssiBytes;
	TransferMethod_e22_400_e transferMetod;
	RepeaterFunction_e22_400_e repeaterFunction;
	LBTEnable_e22_400_e lbt;
	WORMode_e22_400_e worMode;
	WORCycleTime_e22_400_e worCycle;
} E22_400T22S_REG3_t;

typedef struct {
	ADDH_e ADDH;
	ADDL_e ADDL;
	NETID_e NETID;
	E22_400T22S_REG0_t REG0;
	E22_400T22S_REG1_t REG1;
	E22_400T22S_REG2_t REG2;
	E22_400T22S_REG3_t REG3;
	HightByteKey_e CRYPT_H;
	LowByteKey_e CRYPT_L;
	uint8_t READRegisters[12];
} E22_400T22S_Registers_t;


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
