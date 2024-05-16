/*
 * Timer_Service.h
 *
 * Created: 8/12/2023 1:06:37 AM
 *  Author: Mazen.Atta
 */

#include "Timer_Service.h"

static u8 Global_OC_u8Counter = 0;
static u8 Global_OVF_u8Counter = 0;
void (*Global_OC_FPtr)(void) = NULL_PTR;
void (*Global_OVF_FPtr)(void) = NULL_PTR;
void Func_VidOC();
void Func_VidOVF();

void Timer0_OC_VidSetInterrupt_us(u8 Copy_u8time, void (*Local_FPtr)(void))
{
        Global_OC_u8Counter = Copy_u8time / 100;
        OCR0 = 99;
        if (Local_FPtr != NULL_PTR)
        {
                Global_OC_FPtr = Local_FPtr;
        }
        Timer0_OC_VidSetCallBack(Func_VidOC);
        Timer0_OC_VidInterruptEnable();
}

void Timer0_OVF_VidSetInterrupt_us(u8 Copy_u8time, void (*Local_FPtr)(void))
{
        Global_OVF_u8Counter = Copy_u8time / 100;
        TCNT0 = 156;
        if (Local_FPtr != NULL_PTR)
        {
                Global_OVF_FPtr = Local_FPtr;
        }
        Timer0_OC_VidSetCallBack(Func_VidOVF);
        Timer0_OC_VidInterruptEnable();
}

void Func_VidOC()
{
        static u8 Local_u8Counter = 0;

        if (Global_OC_u8Counter == Local_u8Counter)
        {
                Global_OC_FPtr();
        }
        Local_u8Counter++;
}

void Func_VidOVF()

{
        static u8 Local_u8Counter = 0;

        if (Global_OVF_u8Counter == Local_u8Counter)
        {
                Global_OVF_FPtr();
        }
        Local_u8Counter++;
}

/***************************************ICU Service****************************************/
static u8 Global_u8Flag = 0, Global_u8T1 = 0, Global_u8T2 = 0, Global_u8T3 = 0;

void Func_ICU(void)
{
        if (Global_u8Flag == 0)
        {
                Global_u8T1 = ICR1;
                Timer1_ICU_VidEdge(FALLING);
                Global_u8Flag = 1;
        }
        else if (Global_u8Flag == 1)
        {
                Global_u8T2 = ICR1;
                Timer1_ICU_VidEdge(RISING);
                Global_u8Flag = 2;
        }
        else if (Global_u8Flag == 2)
        {
                Global_u8T3 = ICR1;
                Timer1_ICU_VidInterruptEnable();
                Global_u8Flag = 3;
        }
}
void Timer1_PWM_VidMeasure(u32 *Copy_u16PFreq, u16 *Copy_u16Pduty)
{
        u16 Local_u16Ton = 0, Local_u16Toff = 0, Local_u16Tt = 0;
        TCNT1 = 0;
        Timer1_ICU_VidSetCallBack(Func_ICU);
        Timer1_ICU_VidEdge(RISING);
        Timer1_ICU_VidInterruptEnable();
        Global_u8Flag = 0;
        while (Global_u8Flag < 3)
                ;
        Local_u16Ton = Global_u8T2 - Global_u8T1;
        Local_u16Toff = Global_u8T3 - Global_u8T2;
        Local_u16Tt = Local_u16Ton + Local_u16Toff;
        *Copy_u16Pduty = (Local_u16Ton * 100) / Local_u16Tt;
        *Copy_u16PFreq = 1000000 / Local_u16Tt;
}
u16 Timer1_ICU_u16GetValue()
{
        return ICR1;
}