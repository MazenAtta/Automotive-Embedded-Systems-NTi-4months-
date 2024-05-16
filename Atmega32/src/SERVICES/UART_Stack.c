/*
 * UART.h
 *
 * Created: 8/18/2023 10:54:55 AM
 *  Author: Mazen.Atta
 */
#include "UART_Stack.h"

static u8 Stack[STACK_SIZE] = {NULL};
static u8 SP = NULL;

StackStatus_type Stack_Push(u8 Copy_u8Data)
{
    if (SP == STACK_SIZE)
    {
        return STACK_FULL;
    }

    Stack[SP] = Copy_u8Data;
    SP++;
    return DONE;
}
StackStatus_type Stack_Pop(u8 *Copy_u8PData)
{
    if (SP == NULL)
    {
        return STACK_EMPTY;
    }
    SP--;
    *Copy_u8PData = Stack[SP];
    return DONE;
}
