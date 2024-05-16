/*
 * DIO_interface.h
 *
 * Created: 8/6/2023 9:55:04 PM
 *  Author: Mazen.Atta
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MemMap.h"

#define CONC(B7,B6,B5,B4,B3,B2,B1,B0)               CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)
#define CONC_HELPER(B7,B6,B5,B4,B3,B2,B1,B0)        0b##B7##B6##B5##B4##B3##B2##B1##B0

typedef enum
{
	PinA_0,
	PinA_1,
	PinA_2,
	PinA_3,
	PinA_4,
	PinA_5,
	PinA_6,
	PinA_7,

	PinB_0,
	PinB_1,
	PinB_2,
	PinB_3,
	PinB_4,
	PinB_5,
	PinB_6,
	PinB_7,

	PinC_0,
	PinC_1,
	PinC_2,
	PinC_3,
	PinC_4,
	PinC_5,
	PinC_6,
	PinC_7,

	PinD_0,
	PinD_1,
	PinD_2,
	PinD_3,
	PinD_4,
	PinD_5,
	PinD_6,
	PinD_7,

	TOTAL_PINS = 32,

} DIO_Pin_type;

typedef enum
{
	LOW = 0,
	HIGH,
	PORT_LOW = 0x00,
	PORT_HIGH = 0xFF,
} DIO_Voltage_type;

typedef enum
{
	OUTPUT,
	INFREE,
	INPLUP,
} DIO_PinStatus_type;

typedef enum
{
	PORT_OUTPUT = 0xFF,
	PORT_INPUT = 0x00,
} DIO_PortStatus_type;

typedef enum
{
	PA = 0,
	PB,
	PC,
	PD,
} DIO_Port_type;

void DIO_VidInitPin(DIO_Pin_type Copy_Pin, DIO_PinStatus_type Copy_PinMode);
void DIO_VidWritePin(DIO_Pin_type Copy_Pin, DIO_Voltage_type Copy_PinValue);
void DIO_VidTogglePin(DIO_Pin_type Copy_Pin);
u8 DIO_u8GetPinValue(DIO_Pin_type Copy_Pin);

void DIO_VidInitPort(DIO_Port_type Copy_Port, DIO_PortStatus_type Copy_PortMode);
void DIO_VidWritePort(DIO_Port_type Copy_Port, u8 Copy_u8PortValue);
u8 DIO_u8GetPortValue(DIO_Port_type Copy_Port);

extern const DIO_Pin_type DIO_PinStatusArray[TOTAL_PINS];
void DIO_VidInit(void);
#endif /* DIO_INTERFACE_H_ */