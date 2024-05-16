/*
 * LCD.h
 *
 * Created: 8/8/2023 12:04:51 AM
 *  Author: Mazen.Atta
 */

#ifndef LCD_H_
#define LCD_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/DIO_interface.h"
#include "util/delay.h"

#define LCD_4BitMode 0
#define LCD_8BitMode 1

#define LCD_Mode LCD_4BitMode
/*******************************LCD Config*********************************/
#define LCD_PORT PC
#define RS PinC_0
#define RW PinC_1
#define EN PinC_2

#define D4 PinC_3
#define D5 PinC_4
#define D6 PinC_5
#define D7 PinC_6

/****************************LCD registers Commands***************************/
#define LCD_FUNC_SET_8BIT 0x38
#define LCD_FUNC_SET_4BIT 0x28

#define LCD_CLEAR_SCREEN 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_EntryMode 0x06

#define LCD_LINE1 0x00
#define LCD_LINE2 0x40
#define LCD_LINE3 0x14
#define LCD_LINE4 0x54

#define LCD_DISPLAY_ON 0x0C
#define LCD_DISPLAY_OFF 0x08

#define LCD_SHIFT_LEFT 0x18
#define LCD_SHIFT_RIGHT 0x1C

#define LCD_SHIFT_CURSOR_LEFT 0x10
#define LCD_SHIFT_CURSOR_RIGHT 0x14
#define LCD_FORCE_CURSOR_1ROW 0x80
#define LCD_FORCE_CURSOR_2ROW 0xC0

void LCD_VidInit();
void LCD_VidWriteCommand(u8 Copy_u8Command);
void LCD_VidWriteData(u8 Copy_u8Data);

void LCD_VidGoTo(u8 Copy_u8Row, u8 Copy_u8Col);
void LCD_VidWriteNumber(s64 Copy_u8Number);
void LCD_VidWriteNumber_4D(u16 Copy_u8Number);
void LCD_VidWriteNumber_3D(u16 Copy_u8Number);
void LCD_VidWriteNumber_2D(u16 Copy_u8Number);
void LCD_VidWriteNumberInBinary(u16 Copy_u8Number);
void LCD_VidWriteNumber_GoTo(s64 Copy_u8Number, u8 Copy_u8Row, u8 Copy_u8Col);
void LCD_VidWriteString(u8 *Copy_u8String);
void LCD_VidCreateSpecialCharacter(u8 *Copy_u8Pattern, u8 Copy_u8BlockNumber);
void LCD_VidWriteSpecialCharacter(u8 Copy_u8BlockNumber, u8 Copy_u8Row, u8 Copy_u8Col);

#endif /* LCD_H_ */