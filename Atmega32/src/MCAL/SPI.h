/*
 * SPI.h
 *
 * Created: 8/19/2023 5:26:37 PM
 *  Author: Mazen.Atta
 */

#ifndef SIP_H_
#define SIP_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MemMap.h"


void SPI_VidInitMaster();
void SPI_VidInitSlave();


u8 SPI_u8SendReceive(u8 Copy_u8Data);
void SPI_VidSend_NoBlock(u8 Copy_u8Data);
u8 SPI_u8Receive_NoBlock(void);
u8 SPI_u8Receive_PeriodicCheck(u8 *Copy_u8PData);
void SPI_VidSetCallBack(void (*Copy_FPtr)(void));

void SPI_InterruptEnable();

#endif /*SIP_H_*/