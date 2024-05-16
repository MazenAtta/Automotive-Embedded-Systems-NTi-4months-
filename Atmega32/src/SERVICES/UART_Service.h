/*
 * UART.h
 *
 * Created: 8/15/2023 10:32:55 AM
 *  Author: Mazen.Atta
 */
#ifndef UART_SERVICE_H_
#define UART_SERVICE_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/UART.h"

void UART_VidSendString(u8 *Copy_u8Str);
u8 *UART_u8ReceiveString(void);
void UART_VidReceiveString(u8 *Copy_u8StrArray);

void UART_VidSendString_CS(u8 *Copy_u8Str);
u8 UART_VidReceiveString_CS(u8 *Copy_u8StrArray);

u8 u8GetFlag();
void VidSetFlag();
void VidClrFlag();

void UART_VidSendData_Asynch(u8 *Copy_u8Data);
void UART_VidReceiveData_Asynch(u8 *Copy_u8Pdata);

void UART_TX_InterruptFunc(void);
void UART_RX_InterruptFunc(void);

void UART_VidSendData_Asynch(u8 *Copy_u8PData);
void UART_VidReceiveData_Asynch(u8 *Copy_u8PData);

void UART_VidSendNumber(u32 Copy_u32Number);
u32 UART_VidReceiveNumber();

#endif /*UART_SERVICE_H*/