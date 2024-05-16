/*
 * WDT.h
 *
 * Created: 8/13/2023 10:32:55 AM
 *  Author: Mazen.Atta
 */

#ifndef WDT_H_
#define WDT_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MemMap.h"

typedef enum
{
    Scaler_16ms = 0,
    Scaler_32ms,
    Scaler_65ms,
    Scaler_130ms,
    Scaler_260ms,
    Scaler_520ms,
    Scaler_1000ms,
    Scaler_2100ms,
} WDT_TimeOut_type;


void WDT_VidSet(WDT_TimeOut_type Time_Out);
void WDT_VidStop(void);

#endif /* WDT_H_ */