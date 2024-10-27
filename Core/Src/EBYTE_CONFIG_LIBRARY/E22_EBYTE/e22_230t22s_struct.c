/*
 * e22_230t22s_struct.c
 *
 *  Created on: Oct 12, 2024
 *      Author: sergijobvincev
 */


#ifndef SRC_E22_EBYTE_E22_230T22S_STRUCT_C_
#define SRC_E22_EBYTE_E22_230T22S_STRUCT_C_

#include "main.h"
#include "/E22_EBYTE/e22_230t22s_struct.h"


uint8_t _set_ADDH_e22_230(ADDH_e *addh) {
	return *addh;
}
uint8_t _set_ADDL_e22_230(ADDL_e *addl) {
	return *addl;
}
uint8_t _set_NETID_e22_230(NETID_e *netid) {
	return *netid;
}
uint8_t _set_REG0_e22_230(E22_230T22S_REG0_t *reg0_config) {
    return (reg0_config->rate << 5) | (reg0_config->parity << 3) | (reg0_config->airRate);
}
uint8_t _set_REG1_e22_230(E22_230T22S_REG1_t *reg1_config) {
	return (reg1_config->subPacket << 6) | (reg1_config->rssiEnv << 5) | (reg1_config->softwareMode << 2) | (reg1_config->transmitPower);
}
uint8_t _set_REG2_e22_230(E22_230T22S_REG2_t *reg2_config) {
	return reg2_config->frequency;
}
uint8_t _set_REG3_e22_230(E22_230T22S_REG3_t *reg3_config) {
	return (reg3_config->rssiBytes << 7) | (reg3_config->transferMetod << 6) | (reg3_config->repeaterFunction << 5) | (reg3_config->lbt << 4) | (reg3_config->worMode << 3) | (reg3_config->worCycle);
}
uint8_t _set_CRYPT_H_e22_230(HightByteKey_e *hightByteKey) {
	return *hightByteKey;
}
uint8_t _set_CRYPT_L_e22_230(LowByteKey_e *lowByteKey) {
	return *lowByteKey;
}
void _get_READRegisters_e22_230(E22_230T22S_Registers_t *configRegisters) {
	configRegisters->READRegisters[0] = 0xFF;
}


#endif
