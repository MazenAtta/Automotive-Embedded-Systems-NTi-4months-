/*
 * UART.h
 *
 * Created: 8/15/2023 10:32:55 AM
 *  Author: Mazen.Atta
 */

#include "UART.h"

static void (*UART_TX_FPtr)(void) = NULL_PTR;
static void (*UART_RX_FPtr)(void) = NULL_PTR;

void UART_VidInit(void)
{    
    // Set URSEL bit to write on UCSRC Register
     SET_BIT(UCSRC, URSEL);

    // Set Asynchoronous mode
    CLR_BIT(UCSRC, UMSEL);

    // Set 8_Bit Mode
    SET_BIT(UCSRC, UCSZ1);
    SET_BIT(UCSRC, UCSZ0);
    CLR_BIT(UCSRB, UCSZ2);

    // Set to one Stop bit
    CLR_BIT(UCSRC, USBS);

    // Set to No Parity
    CLR_BIT(UCSRC, UPM0);
    CLR_BIT(UCSRC, UPM1);


    // Set Baudrate to 9600
    UBRRL = 51;

    // Enable Transmitter
    SET_BIT(UCSRB, TXEN);

    // Enable Reciever
    SET_BIT(UCSRB, RXEN);
}

void UART_VidSend(u8 Copy_u8Data)
{
    while (!GET_BIT(UCSRA, UDRE))
        ;
    UDR = Copy_u8Data;
}
u8 UART_u8Receive(void)
{
    while (!GET_BIT(UCSRA, RXC))
        ;
    return UDR;
}

u8 UART_u8Send_NoBlock(u8 Copy_u8Data)
{
    if (GET_BIT(UCSRA, UDRE))
    {
        UDR = Copy_u8Data;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
u8 UART_u8Receive_NoBlock(u8 *Copy_u8Pdata)
{
    if (GET_BIT(UCSRA, RXC))
    {
        *Copy_u8Pdata = UDR;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void UART_VidSend_NoBlock(u8 Copy_u8Data)
{
    UDR = Copy_u8Data;
}
void UART_VidReceive_NoBlock(u8 *Copy_u8Pdata)
{
    *Copy_u8Pdata = UDR;
}

void UART_TX_InterruptEnable()
{
    SET_BIT(UCSRB, TXCIE);
}
void UART_TX_InterruptDisable()
{
    CLR_BIT(UCSRB, TXCIE);
}
void UART_RX_InterruptEnable()
{
    SET_BIT(UCSRB, RXCIE);
}
void UART_RX_InterruptDisable()
{
    CLR_BIT(UCSRB, RXCIE);
}

void UART_TX_VidSetCallBack(void (*Copy_FPtr)(void))
{
    if (Copy_FPtr != NULL_PTR)
    {
        UART_TX_FPtr = Copy_FPtr;
    }
}
void UART_RX_VidSetCallBack(void (*Copy_FPtr)(void))
{
    if (Copy_FPtr != NULL_PTR)
    {
        UART_RX_FPtr = Copy_FPtr;
    }
}

ISR(UART_TX_VECT)
{
    if (UART_TX_FPtr != NULL_PTR)
    {
        UART_TX_FPtr();
    }
}
ISR(UART_RX_VECT)
{
    if (UART_RX_FPtr != NULL_PTR)
    {
        UART_RX_FPtr();
    }
}