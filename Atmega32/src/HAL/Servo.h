/*
 * Servo.h
 *
 * Created: 8/13/2023 10:44:55 PM
 *  Author: Mazen.Atta
 */

#ifndef SERVO_H_
#define SERVO_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO_interface.h"
#include "util/delay.h"

#define SERVO_PIN OCR1A

void Servo_VidInit();
void Servo_VidSetAngle(u8 Copy_u8Angle);

#endif /* SERVO_H_ */