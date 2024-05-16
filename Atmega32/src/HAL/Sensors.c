/*
 * Sensors.c
 *
 * Created: 8/10/2023 2:30:24 PM
 *  Author: Mazen.Atta
 */


#include "Sensors.h"

u16 Pot_u16Read(void)
{
    u16 Local_u16Read = ADC_u16Read(POT_CH);
    u16 Local_u16Volt = (((u32)5000 * Local_u16Read) / 1024);
    return Local_u16Volt;
}

u16 Temp_u16Read()
{
    u16 Local_u16Read = ADC_u16Read(LM35_CH);
    u16 Local_u16Temp = (((u32)5000 * Local_u16Read) / 1024);
    Local_u16Temp = Local_u16Temp / 10;
    return Local_u16Temp;
}
