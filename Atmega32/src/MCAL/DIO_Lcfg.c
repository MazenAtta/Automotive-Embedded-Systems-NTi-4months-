/*
 * DIO_Lcfg.c
 *
 * Created: 8/6/2023 9:56:02 PM
 *  Author: Mazen.Atta
 */
#include "LIB/STD_TYPES.h"
#include "DIO_interface.h"

const DIO_Pin_type DIO_PinStatusArray[TOTAL_PINS] =
	{
		INPLUP, /*Port A *** Pin 0*/ /*Output*/
		INPLUP, /*Port A *** Pin 1*/ /*Output*/
		OUTPUT, /*Port A *** Pin 2*/ /*Output*/
		OUTPUT, /*Port A *** Pin 3*/ /*Output*/
		OUTPUT, /*Port A *** Pin 4*/ /*Output*/
		OUTPUT, /*Port A *** Pin 5*/ /*Output*/
		OUTPUT, /*Port A *** Pin 6*/ /*Output*/
		OUTPUT, /*Port A *** Pin 7*/ /*Output*/
		INPLUP, /*Port B *** Pin 0*/ /*Output*/
		INPLUP, /*Port B *** Pin 1*/ /*Output*/
		INPLUP, /*Port B *** Pin 2*/ /*Output*/
		INPLUP, /*Port B *** Pin 3*/ /*Output*/
		OUTPUT, /*Port B *** Pin 4*/ /*Output*/
		OUTPUT, /*Port B *** Pin 5*/ /*Output*/
		OUTPUT, /*Port B *** Pin 6*/ /*Output*/
		OUTPUT, /*Port B *** Pin 7*/ /*Output*/
		OUTPUT, /*Port A *** Pin 0*/ /*Output*/
		OUTPUT, /*Port C *** Pin 1*/ /*Output*/
		OUTPUT, /*Port C *** Pin 2*/ /*Output*/
		OUTPUT, /*Port C *** Pin 3*/ /*Output*/
		OUTPUT, /*Port C *** Pin 4*/ /*Output*/
		OUTPUT, /*Port C *** Pin 5*/ /*Output*/
		OUTPUT, /*Port C *** Pin 6*/ /*Output*/
		INPLUP, /*Port C *** Pin 7*/ /*Output*/
		OUTPUT, /*Port D *** Pin 0*/ /*Output*/
		OUTPUT, /*Port D *** Pin 1*/ /*Output*/
		OUTPUT, /*Port D *** Pin 2*/ /*Output*/
		OUTPUT, /*Port D *** Pin 3*/ /*Output*/
		OUTPUT, /*Port D *** Pin 4*/ /*Output*/
		OUTPUT, /*Port D *** Pin 5*/ /*Output*/
		OUTPUT, /*Port D *** Pin 6*/ /*Output*/
		OUTPUT, /*Port D *** Pin 7*/ /*Output*/
};