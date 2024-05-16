/*
 * I2C.h
 *
 * Created: 8/8/2023 11:43:27 PM
 *  Author: Mazen.Atta
 */

#ifndef I2C_H_
#define I2C_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MemMap.h"

#define I2C_START 0x08

#define I2C_REP_START 0x10

#define I2C_MT_SLA_ACK 0x18

#define I2C_MT_SLA_NACK 0x20

#define I2C_MT_DATA_ACK 0x28

#define I2C_MT_DATA_NACK 0x30

#define I2C_MT_ARB_LOST 0x38

#define I2C_MR_ARB_LOST 0x38

#define I2C_MR_SLA_ACK 0x40

#define I2C_MR_SLA_NACK 0x48

#define I2C_MR_DATA_ACK 0x50

#define I2C_MR_DATA_NACK 0x58

#define I2C_ST_SLA_ACK 0xA8

#define I2C_ST_ARB_LOST_SLA_ACK 0xB0

#define I2C_ST_DATA_ACK 0xB8

#define I2C_ST_DATA_NACK 0xC0

#define I2C_ST_LAST_DATA 0xC8

#define I2C_SR_SLA_ACK 0x60

#define I2C_SR_ARB_LOST_SLA_ACK 0x68

#define I2C_SR_GCALL_ACK 0x70

#define I2C_SR_ARB_LOST_GCALL_ACK 0x78

#define I2C_SR_DATA_ACK 0x80

#define I2C_SR_DATA_NACK 0x88

#define I2C_SR_GCALL_DATA_ACK 0x90

#define I2C_SR_GCALL_DATA_NACK 0x98

#define I2C_SR_STOP 0xA0

#define I2C_NO_INFO 0xF8

#define I2C_BUS_ERROR 0x00

#define I2C_STATUS_MASK

#define I2C_STATUS (TWSR & I2C_STATUS_MASK)

void I2C_VidInit(void);
void I2C_VidStart(void);
void I2C_VidStop(void);
void I2C_VidWrite(u8 Copy_u8Data);
u8 I2C_VidRead_ACK(void);
u8 I2C_VidRead_NACK(void);
u8 I2C_VidGetStatus(void);
u8 I2C_VidSendMaster(u8 Copy_u8Address, u8 Copy_u8Data);
u8 I2C_VidSendMasterString(u8 Copy_u8Address, u8 *Copy_u8Str);

#endif /*I2C_H_*/