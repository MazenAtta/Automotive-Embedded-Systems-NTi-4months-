/*
 * Sensors.h
 *
 * Created: 8/10/2023 2:30:37 PM
 *  Author: Mazen.Atta
 */

#ifndef SENSORS_H_
#define SENSORS_H_

#include "LIB/STD_TYPES.h"
#include "MCAL/ADC.h"

#define POT_CH ADC_CH0
#define LM35_CH ADC_CH1

u16 Pot_u16Read(void);
u16 Temp_u16Read(void);
#endif /* SENSORS_H_ */