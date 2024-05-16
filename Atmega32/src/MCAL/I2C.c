/*
 * I2C.c
 *
 * Created: 8/20/2023 11:43:27 PM
 *  Author: Mazen.Atta
 */

#include "I2C.h"

void I2C_VidInit(void)
{
    // I2C Initialization
    //  Set Bitrate : 400.00 Hz
    TWBR = 72;

    // I2C Slave Adress 0x02
    // General Call : off
    TWAR = 0x02; // 0b00000010

    // Generate Acknoledge Pulse : on
    // TWI interrupt : off
    TWCR = 0x44;

    // Set Prescaler to 4
    TWSR = 0x01;
}
void I2C_VidStart(void)
{
    // Send Start Condition
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    // Wait till the flag is set
    while (!(GET_BIT(TWCR, TWINT)))
        ;
}
void I2C_VidStop(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}
void I2C_VidWrite(u8 Copy_u8Data)
{
    // Load data to I2C Register
    TWDR = Copy_u8Data;

    // Send Data
    TWCR = (1 << TWINT) | (1 << TWEN);

    // wait till flag is set
    while (!(TWCR & (1 << TWINT)))
        ;
}
u8 I2C_VidRead_ACK(void)
{
    // Enable ACK
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);

    // wait till flag is set
    while (!(TWCR & (1 << TWINT)))
        ;

    // Read Data
    return TWDR;
}
u8 I2C_VidRead_NACK(void)
{
    // Enable ACK
    TWCR = (1 << TWINT) | (1 << TWEN);

    // wait till flag is set
    while (!(TWCR & (1 << TWINT)))
        ;

    // Read Data
    return TWDR;
}
u8 I2C_VidGetStatus(void)
{
    //
    u8 Local_u8Status = 0;
    Local_u8Status = TWSR & I2C_NO_INFO;
    return Local_u8Status;
}
u8 I2C_VidSendMaster(u8 Copy_u8Address, u8 Copy_u8Data)
{
    u8 Local_u8Status = 0;
    I2C_VidStart();
    Local_u8Status = I2C_VidGetStatus();
    if (Local_u8Status != I2C_START)
    {
        return 0;
    }
    I2C_VidWrite((Copy_u8Address << 1 | 0));
    Local_u8Status = I2C_VidGetStatus();
    if (Local_u8Status != I2C_MT_SLA_ACK)
    {
        return 0;
    }
    I2C_VidWrite(Copy_u8Data);
    if (Local_u8Status != I2C_MT_DATA_ACK)
    {
        return 0;
    }
    return 1;
}
u8 I2C_VidSendMasterString(u8 Copy_u8Address, u8 *Copy_u8Str)
{
    u8 Local_u8Status = 0;
    I2C_VidStart();
    Local_u8Status = I2C_VidGetStatus();
    if (Local_u8Status != I2C_START)
    {
        return 0;
    }
    I2C_VidWrite((Copy_u8Address << 1 | 0));
    Local_u8Status = I2C_VidGetStatus();
    if (Local_u8Status != I2C_MT_SLA_ACK)
    {
        return 0;
    }
    for (u8 i = 0; Copy_u8Str[i] != '\0'; i++)
    {
        I2C_VidWrite(Copy_u8Str[i]);
        if (Local_u8Status != I2C_MT_DATA_ACK)
        {
            return 0;
        }
    }
    I2C_VidStop();
    return 1;
}