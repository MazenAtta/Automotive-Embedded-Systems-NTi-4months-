/*
 * UART.h
 *
 * Created: 8/15/2023 10:32:55 AM
 *  Author: Mazen.Atta
 */
#include "UART_Service.h"

static u8 *Global_PsendData, *Global_PreceiveData;
static volatile u8 Global_u8Flag;

void UART_VidSendString(u8 *Copy_u8Str)
{
    for (u8 i = 0; Copy_u8Str[i] != '\0'; i++)
    {
        UART_VidSend(Copy_u8Str[i]);
    }
    UART_VidSend('\0');
}
u8 *UART_u8ReceiveString(void)
{
    static u8 *Copy_u8Str;

    Copy_u8Str[0] = UART_u8Receive();
    for (u8 i = 0; Copy_u8Str[i] != '\0'; i++)
    {
        Copy_u8Str[i + 1] = UART_u8Receive();
    }
    return Copy_u8Str;
}
void UART_VidReceiveString(u8 *Copy_u8StrArray)
{

    Copy_u8StrArray[0] = UART_u8Receive();
    for (u8 i = 0; Copy_u8StrArray[i] != '\0'; i++)
    {
        Copy_u8StrArray[i + 1] = UART_u8Receive();
    }
}
void UART_VidSendString_CS(u8 *Copy_u8Str)
{
    u8 i = 0;
    u16 Local_u16Sum = 0;
    for (; Copy_u8Str[i] != '\0'; i++)
    {
        Local_u16Sum = Local_u16Sum + Copy_u8Str[i];
    }
    UART_VidSend(i);

    for (i = 0; Copy_u8Str[i] != '\0'; i++)
    {
        UART_VidSend(Copy_u8Str[i]);
    }
    UART_VidSend(Local_u16Sum);
    UART_VidSend(Local_u16Sum >> 8);
}
u8 UART_VidReceiveString_CS(u8 *Copy_u8StrArray)
{
    u8 i = 0, Local_u8Lens = 0, Local_u8Byte1 = 0, Local_u8Byte2 = 0;
    u16 Local_u16Sum = 0, Local_u16Sum_Rec = 0;

    Local_u8Lens = UART_u8Receive();

    for (; i < Local_u8Lens; i++)
    {
        Copy_u8StrArray[i + 1] = UART_u8Receive();
        Local_u16Sum = Local_u16Sum + Copy_u8StrArray[i];
    }
    Local_u8Lens = UART_u8Receive();
    Local_u8Byte1 = UART_u8Receive();
    Local_u8Byte2 = UART_u8Receive();
    Local_u16Sum_Rec = Local_u8Byte1 | (u16)(Local_u8Byte2 << 8);
    if (Local_u16Sum_Rec == Local_u16Sum)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
void UART_VidSendNumber(u32 Copy_u32Number)
{

    /*Bit wise Operation*/
    UART_VidSend((u8)Copy_u32Number);
    UART_VidSend((u8)(Copy_u32Number >> 8));
    UART_VidSend((u8)(Copy_u32Number >> 16));
    UART_VidSend((u8)(Copy_u32Number >> 24));

    /*Pointer*/
    /*u8 *Local_u8PNumber = &Copy_u32Number;

     UART_VidSend(*(Local_u8PNumber + 0));
     UART_VidSend(*(Local_u8PNumber + 1));
     UART_VidSend(*(Local_u8PNumber + 2));
     UART_VidSend(*(Local_u8PNumber + 3));*/
    /*C*/
    /* u8 Local_u8Reminder = 0, Local_u8NumArr[100], i = 0;

     for (i = 0; Local_u32Number != 0; i++)
     {
         Local_u8Reminder = Local_u32Number % 10;
         Local_u32Number = Local_u32Number / 10;
         Local_u8NumArr[i] = (Local_u8Reminder + '0');
     }
     for (; i >= 0; i--)
     {
         UART_VidSend(Local_u8NumArr[i]);
     }*/
}
u32 UART_VidReceiveNumber()
{
    u32 Local_u32Number = 0;
    u8 Local_u8Byte1, Local_u8Byte2, Local_u8Byte3, Local_u8Byte4;
    Local_u8Byte1 = UART_u8Receive();
    Local_u8Byte2 = UART_u8Receive();
    Local_u8Byte3 = UART_u8Receive();
    Local_u8Byte4 = UART_u8Receive();

    /*Bit wise Operation*/
    Local_u32Number = Local_u8Byte1 | (u32)Local_u8Byte2 << 8 | (u32)Local_u8Byte3 << 16 | (u32)Local_u8Byte4 << 24;

    /*Pointer*/
    /*u8 *Local_u32PNum = &Local_u32Number;

    *(Local_u32PNum + 0) = Local_u8Byte1;
    *(Local_u32PNum + 1) = Local_u8Byte2;
    *(Local_u32PNum + 2) = Local_u8Byte3;
    *(Local_u32PNum + 3) = Local_u8Byte4;*/

    /*C*/
    /*u8 Local_u8Number = 0, Local_u8NumArr[100], i    = 0;
    Local_u8NumArr[i] = UART_u8Receive();
    for (i = 0; Local_u8NumArr[i] != '\r'; i++)
    {
        Local_u8NumArr[i + 1] = UART_u8Receive();
    }
    Local_u8NumArr[i] = '\0';
    for (; i >= 0; i--)
    {
        Local_u8Number = (Local_u8NumArr[i] - '0') + (Local_u8Number * 10);
    }
    return Local_u8Number;*/
    return Local_u32Number;
}

u8 u8GetFlag()
{
    return Global_u8Flag;
}
void VidSetFlag()
{
    Global_u8Flag = 1;
}
void VidClrFlag()
{
    Global_u8Flag = 0;
}

void UART_TX_InterruptFunc(void)
{
    static u8 i = 1;
    if (Global_PsendData[i] != NULL)
    {
        UART_VidSend_NoBlock(Global_PsendData[i]);
        i++;
    }
    else
    {
        i = 1;
    }
}
void UART_RX_InterruptFunc(void)
{
    static u8 i = 0;
    UART_VidReceive_NoBlock(&Global_PreceiveData[i]);
    i++;

    if (Global_PreceiveData[i] != '\r')
    {
        Global_u8Flag = 1;
    }
}
void UART_VidSendData_Asynch(u8 *Copy_u8PData)
{
    UART_TX_InterruptEnable();
    Global_PsendData = Copy_u8PData;
    UART_TX_VidSetCallBack(UART_TX_InterruptFunc);
    UART_VidSend_NoBlock(Global_PsendData[0]);
}
void UART_VidReceiveData_Asynch(u8 *Copy_u8PData)
{

    UART_RX_InterruptEnable();
    Global_PreceiveData = Copy_u8PData;

    UART_RX_VidSetCallBack(UART_RX_InterruptFunc);
}