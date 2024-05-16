/*
 * 0_TestAtmel.c
 *
 * Created: 8/6/2023 9:30:32 PM
 * Author : Mazen.Atta
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MemMap.h"
#include "MCAL/DIO_interface.h"
#include "MCAL/EXTI.h"
#include "MCAL/ADC.h"
#include "MCAL/Timer.h"
#include "MCAL/UART.h"
#include "MCAL/SPI.h"
#include "MCAL/WDT.h"
#include "HAL/LCD.h"
#include "HAL/Keypad.h"
#include "HAL/Servo.h"
#include "HAL/Stepper.h"
#include "HAL/Sensors.h"
#include "HAL/DHT.h"
#include "util/delay.h"

int main(void)
{
    u8 Local_u8GetEntry = Keypad_NOT_PRESSED, Local_u8Operation = 0;
    u16 Local_u16Num1 = 0, Local_u16Num2 = 0, Local_u16Num2_Flag = 0, Local_u16Operation_Flag = 0;
    DIO_VidInit();
    LCD_VidInit();
    Keypad_VidInit();

    while (1)
    {
        Local_u8GetEntry = Keypad_u8GetEntry();
        if (Local_u8GetEntry != Keypad_NOT_PRESSED && Local_u8GetEntry != '=' && Local_u8GetEntry != 'O')
        {
            if (Local_u16Num2_Flag == 0 && Local_u16Operation_Flag == 0)
            {
                if (Local_u8GetEntry != '+' && Local_u8GetEntry != '-' && Local_u8GetEntry != '/' && Local_u8GetEntry != '*')
                {
                    LCD_VidWriteData(Local_u8GetEntry);
                    Local_u16Num1 = (Local_u16Num1 * 10) + (Local_u8GetEntry - '0');
                }
                else
                {
                    Local_u16Operation_Flag = 1;
                }
            }
            else if (Local_u16Num2_Flag == 0 && Local_u16Operation_Flag == 1)
            {
                LCD_VidWriteData(Local_u8GetEntry);
                Local_u8Operation = Local_u8GetEntry;
                Local_u16Num2_Flag = 1;
            }
            else if (Local_u16Num2_Flag == 1 && Local_u16Operation_Flag == 1)
            {
                LCD_VidWriteData(Local_u8GetEntry);

                Local_u16Num2 = (Local_u16Num2 * 10) + (Local_u8GetEntry - '0');
            }
        }
        else if (Local_u8GetEntry != Keypad_NOT_PRESSED && Local_u8GetEntry == '=' && Local_u8GetEntry != 'O')
        {
            LCD_VidWriteData('=');

            switch (Local_u8Operation)
            {
            case '+':
                LCD_VidWriteNumber_4D((Local_u16Num2 + Local_u16Num1));
                break;
            case '-':

                if ((Local_u16Num1 - Local_u16Num2) < 0)
                {
                    LCD_VidWriteData('-');
                    LCD_VidWriteNumber_4D((Local_u16Num2 - Local_u16Num1));
                }
                else
                {
                    LCD_VidWriteNumber_4D((Local_u16Num1 - Local_u16Num2));
                }
                break;
            case '*':

                LCD_VidWriteNumber_4D((Local_u16Num1 * Local_u16Num2));

                break;
            case '/':

                LCD_VidWriteNumber_4D((Local_u16Num1 / Local_u16Num2));
                break;
            default:
                break;
            }
        }
        if (Local_u8GetEntry != Keypad_NOT_PRESSED && Local_u8GetEntry != '=' && Local_u8GetEntry == 'O')
        {
            LCD_VidWriteCommand(LCD_CLEAR_SCREEN);
            Local_u16Num1 = 0;
            Local_u16Num2 = 0;
            Local_u8Operation = 0;
            Local_u16Num2_Flag = 0;
            Local_u16Operation_Flag = 0;
        }
    }
}

/*int main(void)
{
    u16 ADC_Read = 0;

    u8 arr1[] =
        {
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x10,
            0x00};
    u8 arr2[] =
        {
            0x00,
            0x00,
            0x00,
            0x00,
            0x00,
            0x18,
            0x18,
            0x00};
    u8 arr3[] =
        {
            0x00,
            0x00,
            0x00,
            0x00,
            0x1C,
            0x1C,
            0x1C,
            0x00};
    u8 arr4[] =
        {
            0x00,
            0x00,
            0x00,
            0x1E,
            0x1E,
            0x1E,
            0x1E,
            0x00};
    u8 arr5[] =
        {
            0x00,
            0x00,
            0x1F,
            0x1F,
            0x1F,
            0x1F,
            0x1F,
            0x00};
    u8 arr6[] =
        {
            0x00,
            0x1F,
            0x1F,
            0x1F,
            0x1F,
            0x1F,
            0x1F,
            0x00};
    u8 arr7[] =
        {
            0x1F,
            0x1F,
            0x1F,
            0x1F,
            0x1F,
            0x1F,
            0x1F,
            0x00};

    DIO_VidInit();

    LCD_VidInit();
    ADC_VidInit(ADC_Vref_AVCC, ADC_SCALER_64);

    LCD_VidCreateSpecialCharacter(arr1, 0);
    LCD_VidCreateSpecialCharacter(arr2, 1);
    LCD_VidCreateSpecialCharacter(arr3, 2);
    LCD_VidCreateSpecialCharacter(arr4, 3);
    LCD_VidCreateSpecialCharacter(arr5, 4);
    LCD_VidCreateSpecialCharacter(arr6, 5);
    LCD_VidCreateSpecialCharacter(arr7, 6);

    LCD_VidGoTo(0, 0);
    LCD_VidWriteString("Volume");
    while (1)
    {
        ADC_Read = ADC_u16Read(ADC_CH0);
        LCD_VidGoTo(3, 0);
        LCD_VidWriteNumber_4D(ADC_Read);

        if (ADC_Read >= 0 && ADC_Read <= 146)
        {
            LCD_VidWriteSpecialCharacter(0, 1, 0);
            LCD_VidWriteString("        ");
        }
        else if (ADC_Read > 146 && ADC_Read <= 293)
        {
            LCD_VidWriteSpecialCharacter(1, 1, 1);
            LCD_VidWriteString("        ");
        }
        else if (ADC_Read > 293 && ADC_Read <= 439)
        {
            LCD_VidWriteSpecialCharacter(2, 1, 2);
            LCD_VidWriteString("        ");
        }
        else if (ADC_Read > 439 && ADC_Read <= 585)
        {
            LCD_VidWriteSpecialCharacter(3, 1, 3);
            LCD_VidWriteString("        ");
        }
        else if (ADC_Read > 585 && ADC_Read <= 731)
        {
            LCD_VidWriteSpecialCharacter(4, 1, 4);
            LCD_VidWriteString("        ");
        }
        else if (ADC_Read > 731 && ADC_Read <= 878)
        {
            LCD_VidWriteSpecialCharacter(5, 1, 5);
            LCD_VidWriteString("        ");
        }
        else if (ADC_Read > 878 && ADC_Read <= 1023)
        {
            LCD_VidWriteSpecialCharacter(6, 1, 6);
            LCD_VidWriteString("        ");
        }
    }
}
*/
/*
#define Booting 0
#define Password_Scan 1
#define Correct_Password 2
#define Wrong_Password 3
#define Mode_Select 4
#define Breach_Detected 5
#define Manual_Mode 6
#define Automatic_Mode 7

void PUMP_VidTimer(void);
u8 Password_compare(u8 *Copy_u8Str);
u8 Global_u8Counter = 0;

int main(void)
{
    u16 Local_u16Temp = 0, Local_u16Pot = 0;
    u8 Local_u8PressedKey = 0, Local_u8StartingFlag = 0, Local_u8ArrIdx = 0, Local_u8PassArr[4] = {0}, Local_u8Check = 0, Local_u8ClearFlag = 0, Local_u8PumpSpeed = 0;
    s8 Local_u8Entries = 3;
    u8 arr1[] = "System Booting", arr2[] = "System On", arr3[] = "Enter Pass:", arr4[] = "Password Tries 3";
    u8 arr5[] = "Correct Password", arr6[] = "Welcome", arr7[] = "Opening Door:", arr8[] = "Select Mode", arr9[] = "1-Automatic Mode";
    u8 arr10[] = "2-Manual Mode", arr11[] = "Wrong Pass", arr12[] = "Breach Detected", arr13[] = "Calling 911", arr14[] = "Manual Mode";
    u8 arr15[] = "Set The Pumps Speed", arr16[] = "Temp:", arr17[] = "Pump Speed:", arr18[] = "Automatic Mode", arr19[] = "    ";
    DIO_VidInit();
    LCD_VidInit();
    ADC_VidInit(ADC_Vref_AVCC, ADC_SCALER_64);
    Keypad_VidInit();
    Timer0_VidInit(Timer0_FastPWM_Mode, Timer0_Scaler_8, OC0_Non_Inverting);
    Timer1_VidInit(Timer1_FastPWM_ICR_Mode, Timer1_Scaler_8, OC1A_Non_Inverting, OC1B_Non_Inverting);
    //  Timer1_OCA_VidInterruptEnable();
    //  Timer1_OCA_VidSetCallBack(PUMP_VidTimer);
    Servo_VidInit();

    LCD_VidGoTo(0, 2);
    LCD_VidWriteString(arr1);
    LCD_VidGoTo(2, 0);
    LCD_VidWriteData('>');
    LCD_VidGoTo(2, 19);
    LCD_VidWriteData('>');

    for (u8 i = 1; i < 19; i++)
    {

        LCD_VidGoTo(2, i);
        LCD_VidWriteData('>');
        _delay_ms(25);
    }

    while (1)
    {
        switch (Local_u8StartingFlag)
        {
        case Booting:
            LCD_VidWriteCommand(LCD_CLEAR_SCREEN);
            LCD_VidGoTo(0, 5);
            LCD_VidWriteString(arr2);
            LCD_VidGoTo(2, 0);
            LCD_VidWriteString(arr3);
            LCD_VidGoTo(3, 0);
            LCD_VidWriteString(arr4);

            Local_u8StartingFlag = Password_Scan;
            break;

        case Password_Scan:
            if (Local_u8Entries > 0 && Local_u8ClearFlag == 0)
            {
                LCD_VidGoTo(2, 12);
                LCD_VidWriteString(arr19);
                Local_u8ClearFlag = 1;
            }
            Local_u8PressedKey = Keypad_u8GetEntry();
            if (Local_u8PressedKey != Keypad_NOT_PRESSED && Local_u8ArrIdx < 4)
            {

                Local_u8PassArr[Local_u8ArrIdx] = Local_u8PressedKey;
                LCD_VidGoTo(2, 12 + Local_u8ArrIdx);
                LCD_VidWriteData(Local_u8PassArr[Local_u8ArrIdx]);
                _delay_ms(50);
                LCD_VidGoTo(2, 12 + Local_u8ArrIdx);
                LCD_VidWriteData('*');
                Local_u8ArrIdx++;
            }
            else if (Local_u8ArrIdx == 4)
            {
                Local_u8Check = Password_compare(Local_u8PassArr);
                if (Local_u8Check == TRUE)
                {
                    Local_u8StartingFlag = Correct_Password;
                    DIO_VidWritePin(PinA_3, LOW);
                    DIO_VidWritePin(PinA_4, LOW);
                    DIO_VidWritePin(PinA_5, LOW);

                    DIO_VidWritePin(PinA_6, HIGH);
                }
                else if (Local_u8Check == FALSE)
                {

                    Local_u8Entries--;
                    LCD_VidGoTo(3, 15);
                    LCD_VidWriteNumber(Local_u8Entries);
                    Local_u8ArrIdx = 0;
                    Local_u8ClearFlag = 0;
                    if (Local_u8Entries == 0)
                    {
                        Local_u8StartingFlag = Wrong_Password;
                    }
                }
            }
            break;

        case Correct_Password:

            LCD_VidWriteCommand(LCD_CLEAR_SCREEN);
            LCD_VidGoTo(0, 2);
            LCD_VidWriteString(arr5);
            _delay_ms(100);

            LCD_VidWriteCommand(LCD_CLEAR_SCREEN);
            LCD_VidGoTo(0, 6);
            LCD_VidWriteString(arr6);
            LCD_VidGoTo(2, 0);
            LCD_VidWriteString(arr7);
            for (u8 i = 13; i < 20; i++)
            {
                LCD_VidGoTo(2, i);
                LCD_VidWriteData('>');
                _delay_ms(25);
            }
            Servo_VidSetAngle(90);
            Local_u8StartingFlag = Mode_Select;
            LCD_VidWriteCommand(LCD_CLEAR_SCREEN);
            LCD_VidGoTo(0, 4);
            LCD_VidWriteString(arr8);
            LCD_VidGoTo(1, 0);
            LCD_VidWriteString(arr9);
            LCD_VidGoTo(2, 0);
            LCD_VidWriteString(arr10);
            break;
        case Wrong_Password:

            LCD_VidWriteCommand(LCD_CLEAR_SCREEN);
            LCD_VidGoTo(0, 4);
            LCD_VidWriteString(arr11);
            _delay_ms(100);
            LCD_VidWriteCommand(LCD_CLEAR_SCREEN);
            LCD_VidGoTo(0, 2);
            LCD_VidWriteString(arr12);
            LCD_VidGoTo(1, 2);
            LCD_VidWriteString(arr13);
            for (u8 i = 13; i < 20; i++)
            {
                LCD_VidGoTo(1, i);
                LCD_VidWriteData('>');
                _delay_ms(10);
            }
            Local_u8StartingFlag = Breach_Detected;
            break;
        case Mode_Select:
            Local_u8PressedKey = Keypad_u8GetEntry();

            if (Local_u8PressedKey == '2')
            {
                Local_u8StartingFlag = Manual_Mode;

                LCD_VidWriteCommand(LCD_CLEAR_SCREEN);
                LCD_VidGoTo(0, 4);
                LCD_VidWriteString(arr14);
                LCD_VidGoTo(1, 0);
                LCD_VidWriteString(arr15);
                LCD_VidGoTo(2, 0);
                LCD_VidWriteString(arr16);
                LCD_VidGoTo(3, 0);
                LCD_VidWriteString(arr17);
            }
            else if (Local_u8PressedKey == '1')
            {
                Local_u8StartingFlag = Automatic_Mode;
                LCD_VidWriteCommand(LCD_CLEAR_SCREEN);
                LCD_VidGoTo(0, 3);
                LCD_VidWriteString(arr18);
                LCD_VidGoTo(2, 0);
                LCD_VidWriteString(arr16);
                LCD_VidGoTo(3, 0);
                LCD_VidWriteString(arr17);
            }
            break;
        case Automatic_Mode:

            Local_u16Temp = Temp_u16Read();
            if (Local_u16Temp >= 10 && Local_u16Temp <= 20)
            {
                Local_u8PumpSpeed = 25;
                DC_VidMotor_SpeedControl(Local_u8PumpSpeed);
            }
            else if (Local_u16Temp > 20 && Local_u16Temp <= 30)
            {
                Local_u8PumpSpeed = 50;
                DC_VidMotor_SpeedControl(Local_u8PumpSpeed);
            }
            else if (Local_u16Temp > 30 && Local_u16Temp <= 40)
            {
                Local_u8PumpSpeed = 75;
                DC_VidMotor_SpeedControl(Local_u8PumpSpeed);
            }
            else if (Local_u16Temp > 40)
            {
                Local_u8PumpSpeed = 100;
                DC_VidMotor_SpeedControl(Local_u8PumpSpeed);
            }
            LCD_VidGoTo(2, 6);
            LCD_VidWriteNumber_2D(Local_u16Temp);
            LCD_VidWriteData('C');
            LCD_VidGoTo(3, 11);
            LCD_VidWriteNumber_3D(Local_u8PumpSpeed);
            LCD_VidWriteData('%');
            break;
        case Manual_Mode:
            Local_u16Temp = Temp_u16Read();
            LCD_VidGoTo(2, 6);
            LCD_VidWriteNumber_2D(Local_u16Temp);
            LCD_VidWriteData('C');
            Local_u16Pot = ADC_u16Read(ADC_CH0);
            Local_u8PumpSpeed = (((u32)Local_u16Pot * 100) / 1023);
            DC_VidMotor_SpeedControl(Local_u8PumpSpeed);
            LCD_VidGoTo(3, 11);
            LCD_VidWriteNumber_3D(Local_u8PumpSpeed);
            LCD_VidWriteData('%');
            break;

        case Breach_Detected:
            DIO_VidWritePin(PinA_2, HIGH);
            _delay_ms(100);
            DIO_VidWritePin(PinA_3, HIGH);
            DIO_VidWritePin(PinA_4, HIGH);
            DIO_VidWritePin(PinA_5, HIGH);
            _delay_ms(100);
            DIO_VidWritePin(PinA_3, LOW);
            DIO_VidWritePin(PinA_4, LOW);
            DIO_VidWritePin(PinA_5, LOW);
            break;
        default:
            break;
        }
    }
}

void PUMP_VidTimer(void)
{
    Global_u8Counter++;
}

u8 Password_compare(u8 *Copy_u8Str)
{
    const u8 Local_u8PassArr[4] = {'1', '6', '1', '8'};
    for (u8 i = 0; i < 4; i++)
    {
        if (Copy_u8Str[i] != Local_u8PassArr[i])
        {
            return FALSE;
        }
    }
    return TRUE;
}*/
/*ADC Display*/
/*int main(void)
{
    u16 value = 0;
    SET_BIT(ADCSRA, ADIE);

    DIO_VidInit();
    LCD_VidINIT();
    ADC_VidINIT(ADC_Vref_AVCC, ADC_SCALER_64);

    //  EXTI_TriggerEdge(EX_IN0, EXTI_ONCHANGE);
    //  EXTI_Enable(EX_IN0);
    //sei();

    LCD_VidWriteString("ADC : ");

    while (1)
    {
        value = ADC_u16Read(ADC_CH0);
        LCD_VidGoTo(0,6);
        LCD_VidWriteNumber_4D(value);
    }
}
*/