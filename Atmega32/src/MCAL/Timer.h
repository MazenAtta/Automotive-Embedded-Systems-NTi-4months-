/*
 * Timer.h
 *
 * Created: 8/11/2023 5:26:37 PM
 *  Author: Mazen.Atta
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MemMap.h"
/*************************************************Timer0**************************************************/
typedef enum
{
    Timer0_Scaler_Stop = 0,
    Timer0_Scaler_1,
    Timer0_Scaler_8,
    Timer0_Scaler_64,
    Timer0_Scaler_256,
    Timer0_Scaler_1024,
    External0_Falling,
    External0_Rising,

} Timer0_Scaler_type;

typedef enum
{
    Timer0_Normal_Mode = 0,
    Timer0_PhaseCorrect_Mode,
    Timer0_CTC_Mode,
    Timer0_FastPWM_Mode,

} Timer0_Mode_type;

typedef enum
{
    OC0_Disconnected = 0,
    OC0_Toggle,
    OC0_Non_Inverting,
    OC0_Inverting,

} OC0Mode_type;

void Timer0_VidInit(Timer0_Mode_type Copy_Mode, Timer0_Scaler_type Copy_Scaler, OC0Mode_type Copy_OC0Mode);
void Timer0_OC_VidInterruptEnable(void);
void Timer0_OC_VidInterruptDisable(void);
void Timer0_OVF_VidInterruptEnable(void);
void Timer0_OVF_VidInterruptDisable(void);
void Timer0_OC_VidSetCallBack(void (*Copy_FPtr)(void));
void Timer0_OVF_VidSetCallBack(void (*Copy_FPtr)(void));

/*************************************************Timer1**************************************************/

typedef enum
{
    Timer1_Scaler_Stop = 0,
    Timer1_Scaler_1,
    Timer1_Scaler_8,
    Timer1_Scaler_64,
    Timer1_Scaler_256,
    Timer1_Scaler_1024,
    External1_Falling,
    External1_Rising,

} Timer1_Scaler_type;

typedef enum
{
    Timer1_Normal_Mode = 0,
    Timer1_PhaseCorrect_8bit_Mode,
    Timer1_PhaseCorrect_9bit_Mode,
    Timer1_PhaseCorrect_10bit_Mode,
    Timer1_CTC_OCRA_Immediate_Mode,
    Timer1_FastPWM_8bit_Mode,
    Timer1_FastPWM_9bit_Mode,
    Timer1_FastPWM_10bit_Mode,
    Timer1_PWM_ICR_BOTTOM_Mode,
    Timer1_PWM_OCRA_BOTTOM_Mode,
    Timer1_PWM_ICR_TOP_Mode,
    Timer1_PWM_OCRA_TOP_Mode,
    Timer1_CTC_ICR_Immediate_Mode,
    Timer1_FastPWM_ICR_Mode,
    Timer1_FastPWM_OCRA_Mode,
} Timer1_Mode_type;

typedef enum
{
    OC1A_Disconnected = 0,
    OC1A_Toggle,
    OC1A_Non_Inverting,
    OC1A_Inverting,

} OC1AMode_type;

typedef enum
{
    OC1B_Disconnected = 0,
    OC1B_Toggle,
    OC1B_Non_Inverting,
    OC1B_Inverting,

} OC1BMode_type;

typedef enum
{
    FALLING = 0,
    RISING,
} ICU_Edge_type;

u16 Timer1_ICU_u16GetValue();
void Timer1_ICU_VidEdge(ICU_Edge_type Copy_Edge);

void Timer1_VidInit(Timer1_Mode_type Copy_Timer1Mode, Timer1_Scaler_type Copy_Scaler, OC1AMode_type Copy_OC1AMode, OC1BMode_type Copy_OC1BMode);

void Timer1_ICU_VidInterruptEnable(void);
void Timer1_ICU_VidInterruptDisable(void);
void Timer1_OCA_VidInterruptEnable(void);
void Timer1_OCA_VidInterruptDisable(void);
void Timer1_OCB_VidInterruptEnable(void);
void Timer1_OCB_VidInterruptDisable(void);
void Timer1_OVF_VidInterruptEnable(void);
void Timer1_OVF_VidInterruptDisable(void);

void Timer1_ICU_VidSetCallBack(void (*Copy_FPtr)(void));
void Timer1_OCA_VidSetCallBack(void (*Copy_FPtr)(void));
void Timer1_OCB_VidSetCallBack(void (*Copy_FPtr)(void));
void Timer1_OVF_VidSetCallBack(void (*Copy_FPtr)(void));

void Timer_VidReset();
#endif /* TIMER_H_ */