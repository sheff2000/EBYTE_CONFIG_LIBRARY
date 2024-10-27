/*
 * e22_common_const.h
 *
 *  Created on: Oct 12, 2024
 *      Author: sergijobvincev
 */

#ifndef INC_E22_EBYTE_E22_COMMON_CONST_H_
#define INC_E22_EBYTE_E22_COMMON_CONST_H_

typedef enum {
	ADDH_STANDART = 0
} ADDH_e;

typedef enum {
	ADDL_STANDART = 1,
	ADDL_TX_MASTER = 5,
	ADDL_RX_SLAVE = 5
} ADDL_e;

typedef enum {
	NETID_STANDART = 1,
	NETID_1 = 1,
	NETID_ROJ = 11,
	NETID_2 = 2,
	NETID_10 = 10
} NETID_e;

typedef enum {
	HIGHT_BYTE_KEY_V0 = 0
} HightByteKey_e;

typedef enum {
	LOW_BYTE_KEY_v0 = 0,
	LOW_BYTE_KEY_v1 = 1,
	LOW_BYTE_KEY_v5 = 5,
	LOW_BYTE_KEY_v10 = 10,
	LOW_BYTE_KEY_v100 = 100,
	LOW_BYTE_KEY_v120 = 120,
} LowByteKey_e;

#endif /* INC_E22_EBYTE_E22_COMMON_CONST_H_ */
