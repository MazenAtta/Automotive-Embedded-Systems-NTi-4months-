/*
 * Stepper.c
 *
 * Created: 8/7/2023 11:54:34 AM
 *  Author: Mazen.Atta
 */

#include "Stepper.h"

void DC_VidMotor_CW(void)
{
	DIO_VidWritePin(CW_PIN1, HIGH);
	DIO_VidWritePin(CW_PIN2, HIGH);
	DIO_VidWritePin(CCW_PIN1, LOW);
	DIO_VidWritePin(CCW_PIN2, LOW);
}
void DC_VidMotor_CCW(void)
{
	DIO_VidWritePin(CW_PIN1, LOW);
	DIO_VidWritePin(CW_PIN2, LOW);
	DIO_VidWritePin(CCW_PIN1, HIGH);
	DIO_VidWritePin(CCW_PIN2, HIGH);
}

void DC_VidMotor_SpeedControl(u8 Copy_u8SpeedPercentage)
{
	OCR0 = Copy_u8SpeedPercentage * 255 / 100;
}

void Stepper_VidBiPolar_CW(void)
{
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, HIGH);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, HIGH);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, HIGH);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, HIGH);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
}

void Stepper_VidBiPolar_CCW(void)
{
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, HIGH);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, HIGH);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, HIGH);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, HIGH);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
}

void Stepper_VidUniPolar_CW(void)
{
	DIO_VidWritePin(COIL1A_PIN, HIGH);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, HIGH);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, HIGH);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, HIGH);
	_delay_ms(STEPPER_DELAY);
}
void Stepper_VidUniPolar_CCW(void)
{
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, HIGH);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, HIGH);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, HIGH);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, HIGH);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
}

void Stepper_VidUniPolar_CW_HS(void)
{
	DIO_VidWritePin(COIL1A_PIN, HIGH);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, HIGH);
	DIO_VidWritePin(COIL2A_PIN, HIGH);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);

	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, HIGH);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, HIGH);
	DIO_VidWritePin(COIL1B_PIN, HIGH);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);

	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, HIGH);
	DIO_VidWritePin(COIL2B_PIN, LOW);
	_delay_ms(STEPPER_DELAY);

	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, HIGH);
	DIO_VidWritePin(COIL2B_PIN, HIGH);
	_delay_ms(STEPPER_DELAY);

	DIO_VidWritePin(COIL1A_PIN, LOW);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, HIGH);
	_delay_ms(STEPPER_DELAY);
	DIO_VidWritePin(COIL1A_PIN, HIGH);
	DIO_VidWritePin(COIL2A_PIN, LOW);
	DIO_VidWritePin(COIL1B_PIN, LOW);
	DIO_VidWritePin(COIL2B_PIN, HIGH);
	_delay_ms(STEPPER_DELAY);
}
