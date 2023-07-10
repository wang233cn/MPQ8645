#ifndef __I2C_H
#define __I2C_H
#include "main.h"

typedef enum
{
  I2C_OK       = 0x00U,
  I2C_ERROR    = 0x01U,
  I2C_BUSY     = 0x02U,
  I2C_TIMEOUT  = 0x03U
} I2C_StatusTypeDef;

I2C_StatusTypeDef I2C_Read(uint8_t DEVaddr,uint8_t REGaddr,uint8_t *dataRead,uint16_t LENGTH);
I2C_StatusTypeDef I2C_Write(uint8_t DEVaddr,uint8_t REGaddr,uint8_t *dataWrite,uint16_t LENGTH);
#endif