/*
 * EXTI.h
 *
 * Created: 8/10/2023 10:26:21 PM
 *  Author: Mazen.Atta
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MemMap.h"

typedef enum
{
    EX_IN0,
    EX_IN1,
    EX_IN2,
} EXTI_Source_type;

/*Sense Control mode*/
typedef enum
{
    EXTI_LOWLEVEL,
    EXTI_FALLINGEDGE,
    EXTI_RISINGGEDGE,
    EXTI_ONCHANGE
} EXTI_TriggerEdge_type;


void EXTI_VidEnable(EXTI_Source_type Copy_Interrupt);
void EXTI_VidDisable(EXTI_Source_type Copy_Interrupt);
void EXTI_VidTriggerEdge(EXTI_Source_type Copy_Interrupt, EXTI_TriggerEdge_type Copy_Edge);
void EXTI_VidSetCallBack(EXTI_Source_type Copy_Interrupt, void (* Copy_FPtr)(void));

#endif /* EXTI_H_ */