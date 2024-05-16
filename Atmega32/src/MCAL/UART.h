/*
 * UART.h
 *
 * Created: 8/15/2023 10:32:55 AM
 *  Author: Mazen.Atta
 */

#ifndef UART_H_
#define UART_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MemMap.h"

void UART_VidInit(void);

void UART_VidSend(u8 Copy_u8Data);
u8 UART_u8Receive(void);

u8 UART_u8Send_NoBlock(u8 Copy_u8Data);
u8 UART_u8Receive_NoBlock(u8 *Copy_u8Pdata);

void UART_VidSend_NoBlock(u8 Copy_u8Data);
void UART_VidReceive_NoBlock(u8 *Copy_u8Pdata);



void UART_TX_InterruptEnable();
void UART_TX_InterruptDisable();
void UART_RX_InterruptEnable();
void UART_RX_InterruptDisable();

void UART_TX_VidSetCallBack(void (*Copy_FPtr)(void));
void UART_RX_VidSetCallBack(void (*Copy_FPtr)(void));

#endif /* UART_H_ */