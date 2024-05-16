/*
 * Stepper.h
 *
 * Created: 8/7/2023 11:54:55 AM
 *  Author: Mazen.Atta
 */

#ifndef STEPPER_H_
#define STEPPER_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO_interface.h"
#include "util/delay.h"

/******************DC Motor Configration***********************/
#define CW_PIN1 PinA_0
#define CW_PIN2 PinA_1
#define CCW_PIN1 PinA_2
#define CCW_PIN2 PinA_3

/******************Stepper Configration***********************/
#define COIL1A_PIN PinA_0
#define COIL2A_PIN PinA_1
#define COIL1B_PIN PinA_2
#define COIL2B_PIN PinA_3
#define STEPPER_DELAY 2000

void DC_VidMotor_CW(void);
void DC_VidMotor_CCW(void);

void DC_VidMotor_SpeedControl(u8 Copy_u8SpeedPercentage);

void Stepper_VidBiPolar_CW(void);
void Stepper_VidBiPolar_CCW(void);

void Stepper_VidUniPolar_CW(void);
void Stepper_VidUniPolar_CCW(void);

void Stepper_VidUniPolar_CW_HS(void);

#endif /* STEPPER_H_ */