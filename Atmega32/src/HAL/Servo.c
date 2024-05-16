/*
 * Servo.h
 *
 * Created: 8/13/2023 10:44:55 PM
 *  Author: Mazen.Atta
 */

#include "Servo.h"

void Servo_VidInit()
{
    ICR1 = 19999;
    SERVO_PIN = 999;
}
void Servo_VidSetAngle(u8 Copy_u8Angle)
{
    if (Copy_u8Angle > 180)
    {
        Copy_u8Angle %= 180;
    }
    SERVO_PIN = (((u32)Copy_u8Angle * 1000) / 180 + 999);
}