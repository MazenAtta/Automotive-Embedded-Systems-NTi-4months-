/*
 * Timer.c
 *
 * Created: 8/11/2023 5:26:48 PM
 *  Author: Mazen.Atta
 */

#include "Timer.h"

/*************************************************Timer0**************************************************/

static void (*Global_OC0_FPtr)(void) = NULL_PTR;
static void (*Global_OVF0_FPtr)(void) = NULL_PTR;

void Timer0_VidInit(Timer0_Mode_type Copy_Timer0Mode, Timer0_Scaler_type Copy_Scaler, OC0Mode_type Copy_OC0Mode)
{
    switch (Copy_Timer0Mode)
    {
    case Timer0_Normal_Mode:
        CLR_BIT(TCCR0, WGM00);
        CLR_BIT(TCCR0, WGM01);
        break;
    case Timer0_PhaseCorrect_Mode:
        SET_BIT(TCCR0, WGM00);
        CLR_BIT(TCCR0, WGM01);
        break;
    case Timer0_CTC_Mode:
        CLR_BIT(TCCR0, WGM00);
        SET_BIT(TCCR0, WGM01);
        break;
    case Timer0_FastPWM_Mode:
        SET_BIT(TCCR0, WGM00);
        SET_BIT(TCCR0, WGM01);
        break;
    default:
        break;
    }

    TCCR0 &= 0xF8; // 0b11111000
    Copy_Scaler &= 0x07;
    TCCR0 |= Copy_Scaler;
    /* switch (Copy_Scaler)
     {
     case Timer0_Scaler_Stop:
         CLR_BIT(TCCR0, CS00);
         CLR_BIT(TCCR0, CS01);
         CLR_BIT(TCCR0, CS02);
         break;
     case Timer0_Scaler_1:
         SET_BIT(TCCR0, CS00);
         CLR_BIT(TCCR0, CS01);
         CLR_BIT(TCCR0, CS02);
         break;
     case Timer0_Scaler_8:
         CLR_BIT(TCCR0, CS00);
         SET_BIT(TCCR0, CS01);
         CLR_BIT(TCCR0, CS02);
         break;
     case Timer0_Scaler_64:
         SET_BIT(TCCR0, CS00);
         SET_BIT(TCCR0, CS01);
         CLR_BIT(TCCR0, CS02);
         break;
     case Timer0_Scaler_256:
         CLR_BIT(TCCR0, CS00);
         CLR_BIT(TCCR0, CS01);
         SET_BIT(TCCR0, CS02);
         break;
     case Timer0_Scaler_1024:
         SET_BIT(TCCR0, CS00);
         CLR_BIT(TCCR0, CS01);
         SET_BIT(TCCR0, CS02);
         break;
     case External0_Falling:
         CLR_BIT(TCCR0, CS00);
         SET_BIT(TCCR0, CS01);
         SET_BIT(TCCR0, CS02);
         break;
     case External0_Rising:
         SET_BIT(TCCR0, CS00);
         SET_BIT(TCCR0, CS01);
         SET_BIT(TCCR0, CS02);
         break;
     default:
         break;
     }
 */
    switch (Copy_OC0Mode)
    {
    case OC0_Disconnected:
        CLR_BIT(TCCR0, COM00);
        CLR_BIT(TCCR0, COM01);
        break;
    case OC0_Toggle:
        SET_BIT(TCCR0, COM00);
        CLR_BIT(TCCR0, COM01);
        break;
    case OC0_Non_Inverting:
        CLR_BIT(TCCR0, COM00);
        SET_BIT(TCCR0, COM01);
        break;
    case OC0_Inverting:
        SET_BIT(TCCR0, COM00);
        SET_BIT(TCCR0, COM01);
        break;
    default:
        break;
    }
}

void Timer0_OC_VidInterruptEnable(void)
{
    if (GET_BIT(TIFR, OCF0) == FALSE)
    {
        SET_BIT(TIMSK, OCIE0);
    }
}
void Timer0_OC_VidInterruptDisable(void)
{
    if (GET_BIT(TIFR, OCF0) == TRUE)
    {
        CLR_BIT(TIMSK, OCIE0);
    }
}
void Timer0_OVF_VidInterruptEnable(void)
{
    if (GET_BIT(TIFR, OCF0) == FALSE)
    {
        SET_BIT(TIMSK, TOIE0);
    }
}
void Timer0_OVF_VidInterruptDisable(void)
{
    if (GET_BIT(TIFR, OCF0) == TRUE)
    {
        CLR_BIT(TIMSK, TOIE0);
    }
}

void Timer0_OC_VidSetCallBack(void (*Copy_FPtr)(void))
{
    if (Copy_FPtr != NULL_PTR)
    {
        Global_OC0_FPtr = Copy_FPtr;
    }
}
void Timer0_OVF_VidSetCallBack(void (*Copy_FPtr)(void))
{
    if (Copy_FPtr != NULL_PTR)
    {
        Global_OVF0_FPtr = Copy_FPtr;
    }
}

ISR(TIMR0_OC_VECT)
{
    if (Global_OC0_FPtr != NULL_PTR)
    {
        Global_OC0_FPtr();
    }
}
ISR(TIMR0_OVF_VECT)
{
    if (Global_OVF0_FPtr != NULL_PTR)
    {

        Global_OVF0_FPtr();
    }
}
/*************************************************Timer1**************************************************/

static void (*Global_ICU1_FPtr)(void) = NULL_PTR;
static void (*Global_OCA1_FPtr)(void) = NULL_PTR;
static void (*Global_OCB1_FPtr)(void) = NULL_PTR;
static void (*Global_OVF1_FPtr)(void) = NULL_PTR;


void Timer1_ICU_VidEdge(ICU_Edge_type Copy_Edge)
{
    switch (Copy_Edge)
    {
    case FALLING:
        CLR_BIT(TCCR1B, ICES1);
        break;

    case RISING:
        SET_BIT(TCCR1B, ICES1);
        break;

    default:
        break;
    }
}

void Timer1_VidInit(Timer1_Mode_type Copy_Timer1Mode, Timer1_Scaler_type Copy_Scaler, OC1AMode_type Copy_OC1AMode, OC1BMode_type Copy_OC1BMode)
{

    switch (Copy_Timer1Mode)
    {
    case Timer1_Normal_Mode:
        CLR_BIT(TCCR1A, WGM10);
        CLR_BIT(TCCR1A, WGM11);
        CLR_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        break;
    case Timer1_PhaseCorrect_8bit_Mode:
        SET_BIT(TCCR1A, WGM10);
        CLR_BIT(TCCR1A, WGM11);
        CLR_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        break;
    case Timer1_PhaseCorrect_9bit_Mode:
        CLR_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        CLR_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        break;
    case Timer1_PhaseCorrect_10bit_Mode:
        SET_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        CLR_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        break;
    case Timer1_CTC_OCRA_Immediate_Mode:
        CLR_BIT(TCCR1A, WGM10);
        CLR_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        break;
    case Timer1_FastPWM_8bit_Mode:
        SET_BIT(TCCR1A, WGM10);
        CLR_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        break;
    case Timer1_FastPWM_9bit_Mode:
        CLR_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        break;
    case Timer1_FastPWM_10bit_Mode:
        SET_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        CLR_BIT(TCCR1B, WGM13);
        break;
    case Timer1_PWM_ICR_BOTTOM_Mode:
        CLR_BIT(TCCR1A, WGM10);
        CLR_BIT(TCCR1A, WGM11);
        CLR_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        break;
    case Timer1_PWM_OCRA_BOTTOM_Mode:
        SET_BIT(TCCR1A, WGM10);
        CLR_BIT(TCCR1A, WGM11);
        CLR_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        break;
    case Timer1_PWM_ICR_TOP_Mode:
        CLR_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        CLR_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        break;
    case Timer1_PWM_OCRA_TOP_Mode:
        SET_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        CLR_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        break;
    case Timer1_CTC_ICR_Immediate_Mode:
        CLR_BIT(TCCR1A, WGM10);
        CLR_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        break;
    case Timer1_FastPWM_ICR_Mode:
    
        CLR_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        break;
    case Timer1_FastPWM_OCRA_Mode:
        SET_BIT(TCCR1A, WGM10);
        SET_BIT(TCCR1A, WGM11);
        SET_BIT(TCCR1B, WGM12);
        SET_BIT(TCCR1B, WGM13);
        break;
    default:
        break;
    }

    TCCR1B &= 0xF8;
    Copy_Scaler &= 0x07;
    TCCR1B |= Copy_Scaler;

    switch (Copy_OC1AMode)
    {
    case OC1A_Disconnected:
        CLR_BIT(TCCR1A, COM1A0);
        CLR_BIT(TCCR1A, COM1A1);
        break;
    case OC1A_Toggle:
        SET_BIT(TCCR1A, COM1A0);
        CLR_BIT(TCCR1A, COM1A1);
        break;
    case OC1A_Non_Inverting:
        CLR_BIT(TCCR1A, COM1A0);
        SET_BIT(TCCR1A, COM1A1);
        break;
    case OC1A_Inverting:
        SET_BIT(TCCR1A, COM1A0);
        SET_BIT(TCCR1A, COM1A1);
        break;
    default:
        break;
    }

    switch (Copy_OC1BMode)
    {
    case OC1B_Disconnected:
        CLR_BIT(TCCR1A, COM1B0);
        CLR_BIT(TCCR1A, COM1B1);
        break;
    case OC1B_Toggle:
        SET_BIT(TCCR1A, COM1B0);
        CLR_BIT(TCCR1A, COM1B1);
        break;
    case OC1B_Non_Inverting:
        CLR_BIT(TCCR1A, COM1B0);
        SET_BIT(TCCR1A, COM1B1);
        break;
    case OC1B_Inverting:
        SET_BIT(TCCR1A, COM1B0);
        SET_BIT(TCCR1A, COM1B1);
        break;
    default:
        break;
    }
}

void Timer1_ICU_VidInterruptEnable(void)
{
    if (GET_BIT(TIFR, ICF1) == FALSE)
    {
        SET_BIT(TIMSK, TICIE1);
    }
}
void Timer1_ICU_VidInterruptDisable(void)
{
    if (GET_BIT(TIFR, ICF1) == TRUE)
    {
        CLR_BIT(TIMSK, TICIE1);
    }
}
void Timer1_OCA_VidInterruptEnable(void)
{
    if (GET_BIT(TIFR, OCF1A) == FALSE)
    {
        SET_BIT(TIMSK, OCIE1A);
    }
}
void Timer1_OCA_VidInterruptDisable(void)
{
    if (GET_BIT(TIFR, OCF1A) == TRUE)
    {
        CLR_BIT(TIMSK, OCIE1A);
    }
}
void Timer1_OCB_VidInterruptEnable(void)
{
    if (GET_BIT(TIFR, OCF1B) == FALSE)
    {
        SET_BIT(TIMSK, OCIE1B);
    }
}
void Timer1_OCB_VidInterruptDisable(void)
{
    if (GET_BIT(TIFR, OCF1B) == TRUE)
    {
        CLR_BIT(TIMSK, OCIE1B);
    }
}
void Timer1_OVF_VidInterruptEnable(void)
{
    if (GET_BIT(TIFR, TOV1) == FALSE)
    {
        SET_BIT(TIMSK, TOIE1);
    }
}
void Timer1_OVF_VidInterruptDisable(void)
{
    if (GET_BIT(TIFR, TOV1) == TRUE)
    {
        CLR_BIT(TIMSK, TOIE1);
    }
}

void Timer1_ICU_VidSetCallBack(void (*Copy_FPtr)(void))
{
    if (Copy_FPtr != NULL_PTR)
    {
        Global_ICU1_FPtr = Copy_FPtr;
    }
}
void Timer1_OCA_VidSetCallBack(void (*Copy_FPtr)(void))
{
    if (Copy_FPtr != NULL_PTR)
    {
        Global_OCA1_FPtr = Copy_FPtr;
    }
}
void Timer1_OCB_VidSetCallBack(void (*Copy_FPtr)(void))
{
    if (Copy_FPtr != NULL_PTR)
    {
        Global_OCB1_FPtr = Copy_FPtr;
    }
}
void Timer1_OVF_VidSetCallBack(void (*Copy_FPtr)(void))
{
    if (Copy_FPtr != NULL_PTR)
    {
        Global_OVF1_FPtr = Copy_FPtr;
    }
}

ISR(TIMR1_ICU_VECT)
{
    if (Global_ICU1_FPtr != NULL_PTR)
    {
        Global_ICU1_FPtr();
    }
}
ISR(TIMR1_OCA_VECT)
{
    if (Global_OCA1_FPtr != NULL_PTR)
    {
        Global_OCA1_FPtr();
    }
}
ISR(TIMR1_OCB_VECT)
{
    if (Global_OCB1_FPtr != NULL_PTR)
    {
        Global_OCB1_FPtr();
    }
}
ISR(TIMR1_OVF_VECT)
{
    if (Global_OVF1_FPtr != NULL_PTR)
    {
        Global_OVF1_FPtr();
    }
}

/***********************************************Timer2*************************************************/

void Timer_Reset()
{
    SET_BIT(SFIOR, PSR10);
}
