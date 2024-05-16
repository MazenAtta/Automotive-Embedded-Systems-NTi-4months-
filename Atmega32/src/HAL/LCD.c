/*
 * LCD.c
 *
 * Created: 8/8/2023 12:05:05 AM
 *  Author: Mazen.Atta
 */


#include "LCD.h"

#if (LCD_Mode == LCD_8BitMode)

void LCD_VidWriteCommand(u8 Copy_u8Command)
{
	DIO_VidWritePin(RS, LOW);
	DIO_VidWritePin(RW, LOW);
	DIO_VidWritePort(LCD_PORT, Copy_u8Command);
	DIO_VidWritePin(EN, HIGH);
	_delay_ms(1);
	DIO_VidWritePin(EN, LOW);
	_delay_ms(1);
}
void LCD_VidWriteData(u8 Copy_u8Data)
{
	DIO_VidWritePin(RS, HIGH);
	DIO_VidWritePin(RW, LOW);
	DIO_VidWritePort(LCD_PORT, Copy_u8Data);
	DIO_VidWritePin(EN, HIGH);
	_delay_ms(1);
	DIO_VidWritePin(EN, LOW);
	_delay_ms(1);
}
void LCD_VidInit()
{
	_delay_ms(35);

	LCD_VidWriteCommand(LCD_FUNC_SET_8BIT);
	_delay_ms(1);

	LCD_VidWriteCommand(LCD_DISPLAY_ON);
	_delay_ms(1);

	LCD_VidWriteCommand(LCD_CLEAR_SCREEN);
	_delay_ms(2);
	LCD_VidWriteCommand(LCD_EntryMode);
}

#elif (LCD_Mode == LCD_4BitMode)

void LCD_VidWriteCommand(u8 Copy_u8Command)
{
	DIO_VidWritePin(RS, LOW);
	DIO_VidWritePin(RW, LOW);

	DIO_VidWritePin(D4, (GET_BIT(Copy_u8Command, 4)));
	DIO_VidWritePin(D5, (GET_BIT(Copy_u8Command, 5)));
	DIO_VidWritePin(D6, (GET_BIT(Copy_u8Command, 6)));
	DIO_VidWritePin(D7, (GET_BIT(Copy_u8Command, 7)));

	DIO_VidWritePin(EN, HIGH);
	_delay_ms(1);
	DIO_VidWritePin(EN, LOW);
	_delay_ms(1);

	DIO_VidWritePin(D4, (GET_BIT(Copy_u8Command, 0)));
	DIO_VidWritePin(D5, (GET_BIT(Copy_u8Command, 1)));
	DIO_VidWritePin(D6, (GET_BIT(Copy_u8Command, 2)));
	DIO_VidWritePin(D7, (GET_BIT(Copy_u8Command, 3)));

	DIO_VidWritePin(EN, HIGH);
	_delay_ms(1);
	DIO_VidWritePin(EN, LOW);
	_delay_ms(1);
}
void LCD_VidWriteData(u8 Copy_u8Data)
{
	DIO_VidWritePin(RS, HIGH);
	DIO_VidWritePin(RW, LOW);
	DIO_VidWritePin(D4, (GET_BIT(Copy_u8Data, 4)));
	DIO_VidWritePin(D5, (GET_BIT(Copy_u8Data, 5)));
	DIO_VidWritePin(D6, (GET_BIT(Copy_u8Data, 6)));
	DIO_VidWritePin(D7, (GET_BIT(Copy_u8Data, 7)));

	DIO_VidWritePin(EN, HIGH);
	_delay_ms(1);
	DIO_VidWritePin(EN, LOW);
	_delay_ms(1);

	DIO_VidWritePin(D4, (GET_BIT(Copy_u8Data, 0)));
	DIO_VidWritePin(D5, (GET_BIT(Copy_u8Data, 1)));
	DIO_VidWritePin(D6, (GET_BIT(Copy_u8Data, 2)));
	DIO_VidWritePin(D7, (GET_BIT(Copy_u8Data, 3)));

	DIO_VidWritePin(EN, HIGH);
	_delay_ms(1);
	DIO_VidWritePin(EN, LOW);
	_delay_ms(1);
}
void LCD_VidInit()
{
	LCD_VidWriteCommand(LCD_RETURN_HOME);
	_delay_ms(1);

	LCD_VidWriteCommand(LCD_FUNC_SET_4BIT);
	_delay_ms(1);

	LCD_VidWriteCommand(LCD_DISPLAY_ON);
	_delay_ms(1);

	LCD_VidWriteCommand(LCD_CLEAR_SCREEN);
	_delay_ms(2);
	LCD_VidWriteCommand(LCD_EntryMode);
	_delay_ms(2);
}

#endif

/**********************************************LCD Services*********************************************/

void LCD_VidGoTo(u8 Copy_u8Row, u8 Copy_u8Col)
{
	const u16 arr[4] = {0x00, 0x40, 0x14, 0x54};

	LCD_VidWriteCommand(0x80 + arr[Copy_u8Row] + Copy_u8Col);

	/*switch (Copy_u8Row)
	{
	case 0:
		LCD_SendCommand(0x80 + 0x00 + Copy_u8Col);
		break;
	case 1:
		LCD_SendCommand(0x80 + 0x40 + Copy_u8Col);
		break;
	case 2:
		LCD_SendCommand(0x80 + 0x14 + Copy_u8Col);
		break;
	case 3:
		LCD_SendCommand(0x80 + 0x54 + Copy_u8Col);
		break;
	default:
		break;
	}*/
}
void LCD_VidWriteString(u8 *Copy_u8String)
{
	for (u8 i = 0; Copy_u8String[i] != '\0'; i++)
	{
		LCD_VidWriteData(Copy_u8String[i]);
	}
}
void LCD_VidWriteNumberInBinary(u16 Copy_u8Number)
{
	s8 i, flag = 0;
	for (i = 15; i >= 0; i--)
	{
		if (flag == 0)
		{
			if (GET_BIT(Copy_u8Number, i) == 1)
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			LCD_VidWriteData((GET_BIT(Copy_u8Number, i) + '0'));
		}
	}
}
void LCD_VidWriteNumber(s64 Copy_u8Number)
{
	u32 i = 0, j = 0;
	u8 str[100], temp;
	if (Copy_u8Number == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return;
	}
	if (Copy_u8Number < 0)
	{
		Copy_u8Number = Copy_u8Number * -1;
		str[0] = '-';
		j = 1;
		i = 1;
	}
	while (Copy_u8Number != 0)
	{
		str[i] = Copy_u8Number % 10 + '0';
		Copy_u8Number = Copy_u8Number / 10;
		i++;
	}
	str[i] = '\0';
	i--;

	for (; j < i; j++)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		i--;
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		LCD_VidWriteData(str[i]);
	}
}
void LCD_VidWriteNumber_4D(u16 Copy_u8Number)
{
	if (Copy_u8Number < 0)
	{
		LCD_VidWriteData('-');
	}
	LCD_VidWriteData(((Copy_u8Number % 10000) / 1000 + '0'));
	LCD_VidWriteData(((Copy_u8Number % 1000) / 100 + '0'));
	LCD_VidWriteData(((Copy_u8Number % 100) / 10 + '0'));
	LCD_VidWriteData(((Copy_u8Number % 10) / 1 + '0'));
}
void LCD_VidWriteNumber_3D(u16 Copy_u8Number)
{
	if (Copy_u8Number < 0)
	{
		LCD_VidWriteData('-');
	}
	LCD_VidWriteData(((Copy_u8Number % 1000) / 100 + '0'));
	LCD_VidWriteData(((Copy_u8Number % 100) / 10 + '0'));
	LCD_VidWriteData(((Copy_u8Number % 10) / 1 + '0'));
}
void LCD_VidWriteNumber_2D(u16 Copy_u8Number)
{
	if (Copy_u8Number < 0)
	{
		LCD_VidWriteData('-');
	}
	LCD_VidWriteData(((Copy_u8Number % 100) / 10 + '0'));
	LCD_VidWriteData(((Copy_u8Number % 10) / 1 + '0'));
}
void LCD_VidWriteNumber_GoTo(s64 Copy_u8Number, u8 Copy_u8Row, u8 Copy_u8Col)
{
	LCD_VidGoTo(Copy_u8Row, Copy_u8Col);
	LCD_VidWriteNumber(Copy_u8Number);
}
void LCD_VidCreateSpecialCharacter(u8 *Copy_u8Pattern, u8 Copy_u8BlockNumber)
{
	u8 Local_u8Address = 0;
	Local_u8Address = 8 * Copy_u8BlockNumber;
	LCD_VidWriteCommand(0x40 + Local_u8Address);
	for (u8 i = 0; i < 7; i++)
	{
		LCD_VidWriteData(Copy_u8Pattern[i]);
	}
}
void LCD_VidWriteSpecialCharacter(u8 Copy_u8BlockNumber, u8 Copy_u8Row, u8 Copy_u8Col)
{
	LCD_VidGoTo(Copy_u8Row, Copy_u8Col);
	LCD_VidWriteData(Copy_u8BlockNumber);
}
