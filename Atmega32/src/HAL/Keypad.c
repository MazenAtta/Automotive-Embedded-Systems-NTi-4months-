/*
 * Keypad.c
 *
 * Created: 8/8/2023 7:56:43 PM
 *  Author: Mazen.Atta
 */

#include "Keypad.h"

static u8 Global_u8KPDArr[Keypad_ROW_SIZE][Keypad_COL_SIZE] = Keypad_U8ARR;
static u8 Global_Keypad_u8RowArray[Keypad_ROW_SIZE] = Keypad_U8RowArray;
static u8 Global_Keypad_u8ColArray[Keypad_COL_SIZE] = Keypad_U8ColArray;

void Keypad_VidInit(void)
{
    DIO_VidWritePin(Global_Keypad_u8ColArray[0], HIGH);
    DIO_VidWritePin(Global_Keypad_u8ColArray[1], HIGH);
    DIO_VidWritePin(Global_Keypad_u8ColArray[2], HIGH);
    DIO_VidWritePin(Global_Keypad_u8ColArray[3], HIGH);
}
u8 Keypad_u8GetEntry(void)
{
    u8 Local_u8Val = NULL;
    u8 Local_u8KeyPressed = Keypad_NOT_PRESSED;

    for (u8 Local_u8ColIdx = NULL; Local_u8ColIdx < Keypad_COL_SIZE; Local_u8ColIdx++)

    {
        DIO_VidWritePin(Global_Keypad_u8ColArray[Local_u8ColIdx], LOW);

        for (u8 Local_u8RowIdx = NULL; Local_u8RowIdx < Keypad_ROW_SIZE; Local_u8RowIdx++)
        {
            Local_u8Val = DIO_u8GetPinValue(Global_Keypad_u8RowArray[Local_u8RowIdx]);
            if (Local_u8Val == LOW)
            {
                Local_u8KeyPressed = Global_u8KPDArr[Local_u8RowIdx][Local_u8ColIdx];
                while (Local_u8Val == LOW)
                {
                    Local_u8Val = DIO_u8GetPinValue(Global_Keypad_u8RowArray[Local_u8RowIdx]);
                }
                DIO_VidWritePin(Global_Keypad_u8ColArray[Local_u8ColIdx], HIGH);
                return Local_u8KeyPressed;
            }
        }
        DIO_VidWritePin(Global_Keypad_u8ColArray[Local_u8ColIdx], HIGH);
    }
    return Local_u8KeyPressed;
}
