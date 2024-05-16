/*
 * SPI.h
 *
 * Created: 8/19/2023 5:26:37 PM
 *  Author: Mazen.Atta
 */

#include "SPI.h"

static void (*Global_SPI_FPtr)(void) = NULL_PTR;

void SPI_VidInitMaster()
{
    // Set Most Significant bit to be sent first

    // CLock

    // Polarity

    // Phase

    // Set Master Mode
    SET_BIT(SPCR, MSTR);

    // Enable SPI
    SET_BIT(SPCR, SPE);
}
void SPI_VidInitSlave()
{
    // Set Least Significant bit to be sent first

    // CLock

    // Polarity

    // Phase

    // Set Slave Mode
    CLR_BIT(SPCR, MSTR);

    // Enable SPI
    SET_BIT(SPCR, SPE);
}

u8 SPI_u8SendReceive(u8 Copy_u8Data)
{
    SPDR = Copy_u8Data;
    while ((!GET_BIT(SPSR, SPIF)))
        ;
    return SPDR;
}

void SPI_VidSend_NoBlock(u8 Copy_u8Data)
{
    SPDR = Copy_u8Data;
}
u8 SPI_u8Receive_NoBlock(void)
{
    return SPDR;
}

u8 SPI_u8Receive_PeriodicCheck(u8 *Copy_u8PData)
{
    if (GET_BIT(SPSR, SPIF))
    {
        *Copy_u8PData = SPDR;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void SPI_InterruptEnable()
{
    SET_BIT(SPCR, SPIE);
}
void SPI_InterruptDisable()
{
    CLR_BIT(SPCR, SPIE);
}

void SPI_VidSetCallBack(void (*Copy_FPtr)(void))
{
    if (Copy_FPtr != NULL_PTR)
    {
        Global_SPI_FPtr = Copy_FPtr;
    }
}

ISR(SPI_STC_VECT)
{
    if (Global_SPI_FPtr != NULL_PTR)
    {
        Global_SPI_FPtr();
    }
}