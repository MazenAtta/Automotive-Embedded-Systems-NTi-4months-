/*
 * ADC.h
 *
 * Created: 8/20/2023 11:43:27 PM
 *  Author: Mazen.Atta
 */

#ifndef ADC_H_
#define ADC_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MemMap.h"

typedef enum
{
   ADC_Vref_AVCC,
   ADC_Vref_AREF,
   ADC_Vref_256
} ADC_Vref_type;

typedef enum
{
   ADC_SCALER_2 = 1,
   ADC_SCALER_4,
   ADC_SCALER_8,
   ADC_SCALER_16,
   ADC_SCALER_32,
   ADC_SCALER_64,
   ADC_SCALER_128,
} ADC_Scaler_type;

typedef enum
{
   ADC_CH0 = 0,
   ADC_CH1,
   ADC_CH2,
   ADC_CH3,
   ADC_CH4,
   ADC_CH5,
   ADC_CH6,
   ADC_CH7,
   ADC_CH8,
   ADC_CH9,
   ADC_CH10,
   ADC_CH11,
   ADC_CH12,
   ADC_CH13,
   ADC_CH14,
   ADC_CH15,
   ADC_CH16,
   ADC_CH17,
   ADC_CH18,
   ADC_CH19,
   ADC_CH20,
   ADC_CH21,
   ADC_CH22,
   ADC_CH23,
   ADC_CH24,
   ADC_CH25,
   ADC_CH26,
   ADC_CH27,
   ADC_CH28,

} ADC_Channel_type;

#define ADJUST_RIGHT 1
#define ADJUST_LEFT 0

#define ADC_READ_ADJUST ADJUST_RIGHT

void ADC_VidInit(ADC_Vref_type Copy_Vref, ADC_Scaler_type Copy_Scaler);
u16 ADC_u16Read(ADC_Channel_type Copy_Channel);
void ADC_VidStartConversion(ADC_Channel_type Copy_Channel);
u16 ADC_u16GetRead();
u16 ADC_u16GetReadNoBloack(u16 *Ptr_u16data);
void ADC_VidSetCallBack(void (*Copy_FPtr)(void));

#endif /* ADC_H_ */