#ifndef __MPQ8645_H
#define __MPQ8645_H
#include "main.h"

#define MPQ8645_ADDR 0x30


#define OPERATION 0x1
#define ON_OFF_CONFIG 0x2
#define CLEAR_FAULTS 0x3
#define WRITE_PROTECT 0x10
#define STORE_USER_ALL 0x15
#define RESTORE_USER_ALL 0x16
#define CAPABILITY 0x19
#define VOUT_MODE 0x20
#define VOUT_COMMAND 0x21
#define VOUT_MAX 0x24
#define VOUT_MARGIN_HIGH 0x25
#define VOUT_MARGIN_LOW 0x26
#define VOUT_SCALE_LOOP 0x29
#define VOUT_MIN 0x2B
#define VIN_ON 0x35
#define VIN_OFF 0x36
#define IOUT_OC_FAULT_LIMIT 0x46
#define IOUT_OC_WARN_LIMIT 0x4A
#define OT_FAULT_LIMIT 0x4F
#define OT_WARN_LIMIT 0x51
#define VIN_OV_FAULT_LIMIT 0x55
#define VIN_OV_WARN_LIMIT 0x57
#define VIN_UV_WARN_LIMIT 0x58
#define TON_DELAY 0x60
#define TON_RISE 0x61
#define STATUS_BYTE 0x78
#define STATUS_WORD 0x79
#define STATUS_VOUT 0x7A
#define STATUS_IOUT 0x7B
#define STATUS_INPUT 0x7C
#define STATUS_TEMPERATURE 0x7D
#define STATUS_CML 0x7E
#define READ_VIN 0x88
#define READ_VOUT 0x8B
#define READ_IOUT 0x8C
#define READ_TEMPERATURE 0x8D
#define PMBUS_REVISION 0x98
#define MFR_ID 0x99
#define MFR_MODEL 0x9A
#define MFR_REVISION 0x9B
#define MFR_4_DIGIT 0x9D
#define MFR_CTRL_COMP 0xD0
#define MFR_CTRL_VOUT 0xD1
#define MFR_CTRL_OPS 0xD2
#define MFR_ADDR_PMBUS 0xD3
#define MFR_VOUT_OVP_FAULT_LIMIT 0xD4
#define MFR_OVP_NOCP_SET 0xD5
#define MFR_OT_OC_SET 0xD6
#define MFR_OC_PHASE_LIMIT 0xD7
#define MFR_HICCUP_ITV_SET 0xD8
#define MFR_PGOOD_ON_OFF 0xD9
#define MFR_VOUT_STEP 0xDA
#define MFR_LOW_POWER 0xE5
#define MFR_CTRL 0xEA



typedef struct
{
	int16_t Temp;
	float Vout;
	float Vin;
	float Iout;
}MPQ8645_ValueTypeDef;

typedef struct
{
	uint8_t COMM_ERROR;
	uint8_t VOUT_OV_FAULT;
	uint8_t VOUT_UV_FAULT;
	uint8_t VOUT_MAX_MIN;
	uint8_t IOUT_OC;
	uint8_t IOUT_OC_WARNING;
	uint8_t VIN_OV_FAULT;
	uint8_t VIN_OV_WARN;
	uint8_t VIN_UV_WARN;
	uint8_t VIN_UV_FAULT;
	uint8_t OT_FAULT;
	uint8_t OT_WARNING;

}MPQ8645_StatusTypeDef;

void MPQ8645_Init(void);
int16_t MPQ8645_GetTEMP(void);
float MPQ8645_GetVout(void);
float MPQ8645_GetVin(void);
void MPQ8645_GetValue(MPQ8645_ValueTypeDef *Get_Value);
void MPQ8645_GetStatus(MPQ8645_StatusTypeDef *GetStatus);

#endif