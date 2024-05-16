/*
 * ADC.c
 *
 * Created: 8/8/2023 11:43:15 PM
 *  Author: Mazen.Atta
 */

#include "ADC.h"

static u8 Global_u8ReadFlag = 0;
static void (*Global_EXTI0_FPtr)(void) = NULL_PTR;

void ADC_VidInit(ADC_Vref_type Copy_Vref, ADC_Scaler_type Copy_Scaler)
{
	// VREF
	switch (Copy_Vref)
	{
	case ADC_Vref_AVCC:
		SET_BIT(ADMUX, REFS0);
		CLR_BIT(ADMUX, REFS1);
		break;
	case ADC_Vref_AREF:
		CLR_BIT(ADMUX, REFS0);
		CLR_BIT(ADMUX, REFS1);
		break;
	case ADC_Vref_256:
		SET_BIT(ADMUX, REFS0);
		SET_BIT(ADMUX, REFS1);
		break;
	default:
		break;
	}

	// CLOCK
	ADCSRA = (ADCSRA & 0xF8);
	Copy_Scaler = Copy_Scaler & 0x07;
	ADCSRA = (ADCSRA | Copy_Scaler);

	// ENABLE
	SET_BIT(ADCSRA, ADEN);

#if ADC_READ_ADJUST == ADJUST_RIGHT

	// Read Adjust Right
	CLR_BIT(ADMUX, ADLAR);

#elif ADC_READ_ADJUST == ADJUST_LEFT

	// Read Adjust Left
	SET_BIT(ADMUX, ADLAR);

#endif
}

u16 ADC_u16Read(ADC_Channel_type Copy_Channel)
{
	// Select Channel
	ADMUX = ADMUX & 0xE0;
	ADMUX = ADMUX | Copy_Channel;

	// Start Conversion
	SET_BIT(ADCSRA, ADSC);

	// polling (busy wait) till Conversion Stops
	while (GET_BIT(ADCSRA, ADSC))
		;

	// ADC Read for Adjusted Left
	// u16 Local_u16ADC =  (u16)ADCH<<2 | ADCL;

	// ADC Read for Adjusted Right
	// u16 Local_u16ADC =  (u16)ADCH<<8 | ADCL;

	return ADC;
}

void ADC_VidStartConversion(ADC_Channel_type Copy_Channel)
{
	if (Global_u8ReadFlag == 0)
	{
		// Select Channel
		ADMUX = ADMUX & 0xE0;
		ADMUX = ADMUX | Copy_Channel;

		// Start Conversion
		SET_BIT(ADCSRA, ADSC);
		Global_u8ReadFlag = 1;
	}
}

u16 ADC_u16GetRead()
{
	// polling (busy wait )till Conversion Stops
	while (GET_BIT(ADCSRA, ADSC))
		;

	// Return ADC Read for Adjusted Left
	// u16 Local_u16ADC =  ADCH | (u16)ADCL;

	// Return ADC Read for Adjusted Right
	// u16 Local_u16ADC =  ADCL | (u16)ADCH<<8;
	Global_u8ReadFlag = 0;
	return ADC;
}

u16 ADC_u16GetReadNoBloack(u16 *Ptr_u16data)
{
	if (GET_BIT(ADCSRA, ADSC) == FALSE) // periodic checking till ADC finishes converion
	{
		*Ptr_u16data = ADC;
		Global_u8ReadFlag = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}
void ADC_VidSetCallBack(void (*Copy_FPtr)(void))
{
	Global_EXTI0_FPtr = Copy_FPtr;
}

ISR(ADC_VECT)
{
	if (Global_EXTI0_FPtr != NULL_PTR)
	{
		Global_EXTI0_FPtr();
	}
}