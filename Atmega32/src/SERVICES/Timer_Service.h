/*
 * Timer_Service.h
 *
 * Created: 8/12/2023 1:06:37 AM
 *  Author: Mazen.Atta
 */ 


#ifndef TIMER_SERVICE_H_
#define TIMER_SERVICE_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/Timer.h"
#include "MemMap.h"

void Timer0_OC_VidSetInterrupt_us(u8 Copy_u8time, void(*FPtr)(void));
void Timer1_PWM_VidMeasure(u32 *Copy_u16PFreq, u16 *Copy_u16Pduty);
void Func_VidOVF();
void Func_VidOC();

void Func_ICU(void);
void Timer1_PWM_VidMeasure(u32 *Copy_u16PFreq, u16 *Copy_u16Pduty);
u16 Timer1_ICU_u16GetValue();

#endif /* TIMER_SERVICE_H_ */