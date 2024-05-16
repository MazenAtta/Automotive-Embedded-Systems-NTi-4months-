
#include "EXTI.h"

static void (*Global_EXTI0_FPtr)(void) = NULL_PTR;
static void (*Global_EXTI1_FPtr)(void) = NULL_PTR;
static void (*Global_EXTI2_FPtr)(void) = NULL_PTR;

void EXTI_VidEnable(EXTI_Source_type Copy_Interrupt)
{
    switch (Copy_Interrupt)
    {
    case EX_IN0:
        SET_BIT(GICR, INT0);
        break;
    case EX_IN1:
        SET_BIT(GICR, INT1);

        break;
    case EX_IN2:
        SET_BIT(GICR, INT2);
        break;
    default:
        break;
    }
}
void EXTI_VidDisable(EXTI_Source_type Copy_Interrupt)
{
    switch (Copy_Interrupt)
    {
    case EX_IN0:
        CLR_BIT(GICR, INT0);
        break;
    case EX_IN1:
        CLR_BIT(GICR, INT1);

        break;
    case EX_IN2:
        CLR_BIT(GICR, INT2);
        break;
    default:
        break;
    }
}
void EXTI_VidTriggerEdge(EXTI_Source_type Copy_Interrupt, EXTI_TriggerEdge_type Copy_Edge)
{
    switch (Copy_Interrupt)
    {
    case EX_IN0:
        switch (Copy_Edge)
        {
        case EXTI_LOWLEVEL:
            CLR_BIT(MCUCR, ISC00_BIT);
            CLR_BIT(MCUCR, ISC01_BIT);
            break;
        case EXTI_FALLINGEDGE:
            CLR_BIT(MCUCR, ISC00_BIT);
            SET_BIT(MCUCR, ISC01_BIT);
            break;
        case EXTI_RISINGGEDGE:
            SET_BIT(MCUCR, ISC00_BIT);
            SET_BIT(MCUCR, ISC01_BIT);
            break;
        case EXTI_ONCHANGE:
            SET_BIT(MCUCR, ISC00_BIT);
            CLR_BIT(MCUCR, ISC01_BIT);
            break;

        default:
            break;
        }
        break;
    case EX_IN1:
        switch (Copy_Edge)
        {
        case EXTI_LOWLEVEL:
            CLR_BIT(MCUCR, ISC10_BIT);
            CLR_BIT(MCUCR, ISC11_BIT);
            break;
        case EXTI_FALLINGEDGE:
            CLR_BIT(MCUCR, ISC10_BIT);
            SET_BIT(MCUCR, ISC11_BIT);
            break;
        case EXTI_RISINGGEDGE:
            SET_BIT(MCUCR, ISC10_BIT);
            SET_BIT(MCUCR, ISC11_BIT);
            break;
        case EXTI_ONCHANGE:
            SET_BIT(MCUCR, ISC10_BIT);
            CLR_BIT(MCUCR, ISC11_BIT);
            break;

        default:
            break;
        }
        break;

    case EX_IN2:
        switch (Copy_Edge)
        {
        case EXTI_LOWLEVEL:
            break;
        case EXTI_FALLINGEDGE:
            CLR_BIT(MCUCSR, ISC2_BIT);
            break;
        case EXTI_RISINGGEDGE:
            SET_BIT(MCUCSR, ISC2_BIT);
            break;
        case EXTI_ONCHANGE:
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
void EXTI_VidSetCallBack(EXTI_Source_type Copy_Interrupt, void (*Copy_EXTI_FPtr)(void))
{
    switch (Copy_Interrupt)
    {
    case EX_IN0:
        Global_EXTI0_FPtr = Copy_EXTI_FPtr;
        break;
    case EX_IN1:
        Global_EXTI1_FPtr = Copy_EXTI_FPtr;

        break;
    case EX_IN2:
        Global_EXTI2_FPtr = Copy_EXTI_FPtr;
        break;
    default:
        break;
    }
}

ISR(INT0_VECT)
{
    if (Global_EXTI0_FPtr != NULL_PTR)
    {
        Global_EXTI0_FPtr();
    }
}
ISR(INT1_VECT)
{
    if (Global_EXTI1_FPtr != NULL_PTR)
    {
        Global_EXTI1_FPtr();
    }
}
ISR(INT2_VECT)
{
    if (Global_EXTI2_FPtr != NULL_PTR)
    {
        Global_EXTI2_FPtr();
    }
}