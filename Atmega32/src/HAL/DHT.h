/*
 * DHT.h
 *
 * Created: 8/21/2023 7:56:33 PM
 *  Author: Mazen.Atta
 */

#ifndef DHT_H_
#define DHT_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO_interface.h"
#include "MCAL/Timer.h"
#include "HAL/LCD.h"
#include "util/delay.h"

u8 DHT_u8Init(DIO_Pin_type Copy_u8Pin);
u8 DHT_u8Read(DIO_Pin_type Copy_u8Pin, f64 *Copy_u8Temp,f64 *Copy_u8Hum);

#endif /*DHT_H_*/