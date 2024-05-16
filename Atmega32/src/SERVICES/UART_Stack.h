/*
 * UART.h
 *
 * Created: 8/18/2023 10:54:55 AM
 *  Author: Mazen.Atta
 */

#ifndef UART_STACK_H
#define UART_STACK_H

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/UART.h"

#define STACK_SIZE 100

typedef enum
{
    STACK_FULL,
    STACK_EMPTY,
    DONE
}StackStatus_type;

StackStatus_type Stack_Push(u8 Copy_u8Data);
StackStatus_type Stack_Pop(u8 *Copy_u8PData);

#endif /*UART_STACK_H*/