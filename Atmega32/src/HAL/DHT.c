/*
 * DHT.c
 *
 * Created: 8/21/2023 7:56:33 PM
 *  Author: Mazen.Atta
 */

#include "DHT.h"

u8 DHT_u8Init(DIO_Pin_type Copy_u8Pin)
{
    DIO_VidInitPin(Copy_u8Pin, OUTPUT);
    DIO_VidWritePin(Copy_u8Pin, HIGH);
    _delay_us(40);
    DIO_VidInitPin(Copy_u8Pin, OUTPUT);
    DIO_VidWritePin(Copy_u8Pin, LOW);
    _delay_us(1500);
    DIO_VidInitPin(Copy_u8Pin, INPLUP);
    _delay_us(40);

    if (!DIO_u8GetPinValue(Copy_u8Pin))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
u8 DHT_u8Read(DIO_Pin_type Copy_u8Pin, f64 *Copy_u8Temp, f64 *Copy_u8Hum)
{
    u8 Local_u8Temp = 0, Local_u8Hum = 0;
    // Send Signal to DHT
    DIO_VidInitPin(Copy_u8Pin, INPLUP);
    //DIO_VidWritePin(Copy_u8Pin, HIGH);
    _delay_us(40);


    // Wait till DHT detects signal
    _delay_us(1500);

    // Receive Response Signal from DHT
    DIO_VidWritePin(Copy_u8Pin, HIGH);
    // Wait till response signal is sent
    _delay_us(40);

    // Booling till response signal ends
    while (!DIO_u8GetPinValue(Copy_u8Pin))
        ;
    // Booling till DHT prepares to send Data
    while (DIO_u8GetPinValue(Copy_u8Pin))
        ;

    // For loop to Save integral part of Humidity into Variable
    for (s8 i = 7; i >= 0; i--)
    {
        // Booling Till Data Signal is sent
        while (!DIO_u8GetPinValue(Copy_u8Pin))
            ;

        // Wait for 0 bit signal to end (26 to 28 us)
        _delay_us(35);

        // If data Signal still on then Data bit is 1
        if (DIO_u8GetPinValue(Copy_u8Pin))
        {
            // Store the Data bit
            Local_u8Hum |= ((0x01) << (i));

            // Wait till the signal ends (70 us)
            while (DIO_u8GetPinValue(Copy_u8Pin))
                ;
        }
    }
    // Store the integral part
    *(Copy_u8Temp + 0) = Local_u8Hum;
    return 1;
}