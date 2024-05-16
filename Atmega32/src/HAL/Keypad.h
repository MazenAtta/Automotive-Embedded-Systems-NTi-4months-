/*
 * Keypad.h
 *
 * Created: 8/8/2023 7:56:33 PM
 *  Author: Mazen.Atta
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO_interface.h"

#define Keypad_NOT_PRESSED 101

#define Keypad_COL_SIZE 4
#define Keypad_ROW_SIZE 4
#define NULL 0

#define Keypad_U8COL0_PIN PinB_4
#define Keypad_U8COL1_PIN PinB_5
#define Keypad_U8COL2_PIN PinB_6
#define Keypad_U8COL3_PIN PinB_7

#define Keypad_U8ROW0_PIN PinB_0
#define Keypad_U8ROW1_PIN PinB_1
#define Keypad_U8ROW2_PIN PinB_2
#define Keypad_U8ROW3_PIN PinB_3

#define Keypad_U8ARR                                                                             \
    {                                                                                            \
        {'7', '8', '9', '/'}, {'4', '5', '6', '*'}, {'1', '2', '3', '-'}, { 'O', '0', '=', '+' } \
    }
#define Keypad_U8ColArray                                                          \
    {                                                                              \
        Keypad_U8COL0_PIN, Keypad_U8COL1_PIN, Keypad_U8COL2_PIN, Keypad_U8COL3_PIN \
    }
#define Keypad_U8RowArray                                                          \
    {                                                                              \
        Keypad_U8ROW0_PIN, Keypad_U8ROW1_PIN, Keypad_U8ROW2_PIN, Keypad_U8ROW3_PIN \
    }

void Keypad_VidInit(void);
u8 Keypad_u8GetEntry(void);

#endif /* KEYPAD_H_ */