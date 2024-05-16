/*
 * DIO_program.c
 *
 * Created: 8/6/2023 9:54:15 PM
 *  Author: Mazen.Atta
 */

#include "MCAL/DIO_interface.h"

void DIO_VidInitPin(DIO_Pin_type Copy_Pin, DIO_PinStatus_type Copy_PinMode)
{
    DIO_Port_type Local_Port = Copy_Pin / 8;
    u8 Local_u8Pin = Copy_Pin % 8;

    if (Copy_PinMode == OUTPUT)
    {
        switch (Local_Port)
        {
        case PA:
            SET_BIT(DDRA, Local_u8Pin);
            break;
        case PB:
            SET_BIT(DDRB, Local_u8Pin);
            break;
        case PC:
            SET_BIT(DDRC, Local_u8Pin);
            break;
        case PD:
            SET_BIT(DDRD, Local_u8Pin);
            break;
        default:
            break;
        }
    }
    else if (Copy_PinMode == INFREE)
    {
        switch (Local_Port)
        {
        case PA:
            CLR_BIT(DDRA, Local_u8Pin);
            CLR_BIT(PORTA, Local_u8Pin);
        case PB:
            break;
            CLR_BIT(DDRB, Local_u8Pin);
            CLR_BIT(PORTB, Local_u8Pin);
        case PC:
            break;
            CLR_BIT(DDRC, Local_u8Pin);
            CLR_BIT(PORTC, Local_u8Pin);
            break;
        case PD:
            CLR_BIT(DDRD, Local_u8Pin);
            CLR_BIT(PORTD, Local_u8Pin);
            break;
        default:
            break;
        }
    }

    else if (Copy_PinMode == INPLUP)
    {
        switch (Local_Port)
        {
        case PA:
            CLR_BIT(DDRA, Local_u8Pin);
            SET_BIT(PORTA, Local_u8Pin);
            break;
        case PB:
            CLR_BIT(DDRB, Local_u8Pin);
            SET_BIT(PORTB, Local_u8Pin);
            break;
        case PC:
            CLR_BIT(DDRC, Local_u8Pin);
            SET_BIT(PORTC, Local_u8Pin);
            break;
        case PD:
            CLR_BIT(DDRD, Local_u8Pin);
            SET_BIT(PORTD, Local_u8Pin);
            break;
        default:
            break;
        }
    }
}

void DIO_VidWritePin(DIO_Pin_type Copy_Pin, DIO_Voltage_type Copy_PinValue)
{
    DIO_Port_type Local_Port = Copy_Pin / 8;
    u8 Local_u8Pin = Copy_Pin % 8;

    if (Copy_PinValue == HIGH)
    {
        switch (Local_Port)
        {
        case PA:
            SET_BIT(PORTA, Local_u8Pin);
            break;
        case PB:
            SET_BIT(PORTB, Local_u8Pin);
            break;
        case PC:
            SET_BIT(PORTC, Local_u8Pin);
            break;
        case PD:
            SET_BIT(PORTD, Local_u8Pin);
            break;
        default:
            break;
        }
    }
    else if (Copy_PinValue == LOW)
    {
        switch (Local_Port)
        {
        case PA:
            CLR_BIT(PORTA, Local_u8Pin);
            break;

        case PB:
            CLR_BIT(PORTB, Local_u8Pin);
            break;

        case PC:
            CLR_BIT(PORTC, Local_u8Pin);
            break;
        case PD:
            CLR_BIT(PORTD, Local_u8Pin);
            break;
        default:
            break;
        }
    }
}

void DIO_VidTogglePin(DIO_Pin_type Copy_Pin)
{
    DIO_Port_type Local_Port = Copy_Pin / 8;
    u8 Local_u8Pin = Copy_Pin % 8;

    switch (Local_Port)
    {
    case PA:
        TOG_BIT(PORTA, Local_u8Pin);
        break;
    case PB:
        TOG_BIT(PORTB, Local_u8Pin);
        break;
    case PC:
        TOG_BIT(PORTC, Local_u8Pin);
        break;
    case PD:
        TOG_BIT(PORTD, Local_u8Pin);
        break;
    default:
        break;
    }
}

u8 DIO_u8GetPinValue(DIO_Pin_type Copy_Pin)
{
    DIO_Port_type Local_Port = Copy_Pin / 8;
    u8 Local_u8Pin = Copy_Pin % 8;

    switch (Local_Port)
    {
    case PA:
        return (GET_BIT(PINA, Local_u8Pin));
        break;
    case PB:
        return (GET_BIT(PINB, Local_u8Pin));
        break;
    case PC:
        return (GET_BIT(PINC, Local_u8Pin));
        break;
    case PD:
        return (GET_BIT(PIND, Local_u8Pin));
        break;
    default:
        break;
    }
    return -1;
}

void DIO_VidInitPort(DIO_Port_type Copy_Port, DIO_PortStatus_type Copy_PortMode)
{
    switch (Copy_Port)
    {
    case PA:
        DDRA = Copy_PortMode;
        break;
    case PB:
        DDRB = Copy_PortMode;
        break;
    case PC:
        DDRC = Copy_PortMode;
        break;
    case PD:
        DDRD = Copy_PortMode;
        break;
    default:
        break;
    }
}

void DIO_VidWritePort(DIO_Port_type Copy_Port, u8 Copy_u8PortValue)
{
    switch (Copy_Port)
    {
    case PA:
        PORTA = Copy_u8PortValue;
        break;
    case PB:
        PORTB = Copy_u8PortValue;
        break;
    case PC:
        PORTC = Copy_u8PortValue;
        break;
    case PD:
        PORTD = Copy_u8PortValue;
        break;
    default:
        break;
    }
}

u8 DIO_u8GetPortValue(DIO_Port_type Copy_Port)
{
    switch (Copy_Port)
    {
    case PA:
        return PINA;
        break;
    case PB:
        return PINB;
        break;
    case PC:
        return PINC;
        break;
    case PD:
        return PIND;
        break;
    default:
        break;
    }
    return -1;
}

void DIO_VidInit(void)
{
    DIO_Pin_type Pin;
    for (Pin = PinA_0; Pin < TOTAL_PINS; Pin++)
    {
        DIO_VidInitPin(Pin, DIO_PinStatusArray[Pin]);
    }
}
