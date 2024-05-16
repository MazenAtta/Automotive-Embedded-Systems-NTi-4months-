/**
 * The code contains various functions for swapping numbers, reversing a number, calculating factorial,
 * summing arrays, and searching for a value in an array.
 */

#include "stdio.h"
#include "stdlib.h"
#include "test.h"

void Swap1(int *Copy_u32PNum1, int *Copy_u32PNum2)
{
    int Loc_chartemp = *Copy_u32PNum1;
    *Copy_u32PNum1 = *Copy_u32PNum2;
    *Copy_u32PNum2 = Loc_chartemp;
}
void Swap2(int *Copy_u32PNum1, int *Copy_u32PNum2)
{
    *Copy_u32PNum1 = *Copy_u32PNum1 + *Copy_u32PNum2;
    *Copy_u32PNum2 = *Copy_u32PNum1 - *Copy_u32PNum2;
    *Copy_u32PNum1 = *Copy_u32PNum1 - *Copy_u32PNum2;
}
void Swap3(int *Copy_u32PNum1, int *Copy_u32PNum2)
{
    *Copy_u32PNum1 = *Copy_u32PNum1 ^ *Copy_u32PNum2;
    *Copy_u32PNum2 = *Copy_u32PNum1 ^ *Copy_u32PNum2;
    *Copy_u32PNum1 = *Copy_u32PNum1 ^ *Copy_u32PNum2;
}

int ReverseNum(int num)
{
    int Rnum = 0;
    while (num != 0)
    {
        int x = num % 10;
        num = num / 10;
        Rnum = Rnum * 10 + x;
    }
    printf("%d", Rnum);
    return Rnum;
}
int Factorial(int num)
{
    int i = 1, fact = 1;

    do
    {
        i++;
        fact = fact * i;
    } while (num != i);

    return fact;
}
int Factorial_recursive(int num)
{
    if (num != 1)
    {
        return num * Factorial_recursive(num - 1);
    }
    else
    {
        return 1;
    }
}

int *Array_sum(int *Arr1, int Arr1_Size, int *Arr2, int Arr2_Size)
{
    int MaxsSize = 0, MinSize = 0;

    if (Arr1_Size > Arr2_Size)
    {
        MaxsSize = Arr1_Size;
        MinSize = Arr2_Size;
    }
    else
    {
        MaxsSize = Arr2_Size;
        MinSize = Arr1_Size;
    }
    int *Arr3 = (int *)malloc(MaxsSize);

    for (int i = 0; i < MaxsSize; i++)
    {
        if (i < MinSize)
        {
            Arr3[i] = Arr1[i] + Arr2[i];
        }
        else
        {
            if (MinSize == Arr1_Size)
                Arr3[i] = Arr2[i];
            else
                Arr3[i] = Arr1[i];
        }
    }
    return Arr3;
}

void search()
{
    int arr[10];
    printf("enter 10 values");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", arr[i]);
    }
    for (int x = 0; x < 10; x++)
    {
        for (int i = 1; i < 10 - i; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                Swap1(&arr[i], &arr[i - 1]);
            }
        }
    }

    int value;
    printf("Enter a value to search for");
    for (int i = 0; i < 10; i++)
    {
    }
}

/*har Username(char *Copy_charStr)
{
    char check = 0;
    const char Local_charAdmin[5] = {"ADMIN"};
    const char Local_charUser[5] = {"USER"};

    for (char i = 0; i < 5; i++)
    {
        if (Copy_charStr[i] != Local_charAdmin[i])
        {
            check++;
            if (Copy_charStr[i] != Local_charUser[i])
            {

                return 0;
            }
        }
    }
    return check;
}

typedef struct Data
{
    int Salary;
    int Password;
    int ID;
    int Credit;
    int Taxes;

} Data;

Data data[5] = {{10, 20, 30, 40, 50}, {60, 70, 80, 90, 100}, {110, 120, 130, 140, 150}, {160, 170, 180, 190, 200}, {210, 220, 230, 240, 250}};

int main(void)
{
    while (1)
    {
        char arr[5], check;
        int pass = 0, Admin_pass = 100;
        printf("Enter User Name\n");
        scanf("%s", arr);
        check = Username(arr);

        if (check == 0)
        {
            printf("Enter the password\n");
            scanf("%d", &pass);
            if (pass == Admin_pass)
            {

                printf("Emp1 Salary = %d   Password = %d   ID = %d   Credit = %d   Taxes = %d\n", data[0].Salary, data[0].Password, data[0].ID, data[0].Credit, data[0].Taxes);
                printf("Emp2 Salary = %d   Password = %d   ID = %d   Credit = %d   Taxes = %d\n", data[1].Salary, data[1].Password, data[1].ID, data[1].Credit, data[1].Taxes);
                printf("Emp3 Salary = %d   Password = %d   ID = %d   Credit = %d   Taxes = %d\n", data[2].Salary, data[2].Password, data[2].ID, data[2].Credit, data[2].Taxes);
                printf("Emp4 Salary = %d   Password = %d   ID = %d   Credit = %d   Taxes = %d\n", data[3].Salary, data[3].Password, data[3].ID, data[3].Credit, data[3].Taxes);
                printf("Emp5 Salary = %d   Password = %d   ID = %d   Credit = %d   Taxes = %d\n", data[4].Salary, data[4].Password, data[4].ID, data[4].Credit, data[4].Taxes);
            }
            else
            {
                printf("Wrong Password");
            }
        }
        else if (check == 5)
        {
            printf("Enter the password\n");
            scanf("%d", &pass);

            if (pass == data[0].Password)
            {
                printf("Emp1 Salary = %d   Password = %d   ID = %d   Credit = %d   Taxes = %d\n", data[0].Salary, data[0].Password, data[0].ID, data[0].Credit, data[0].Taxes);
            }
            else if (pass == data[1].Password)
            {
                printf("Emp2 Salary = %d   Password = %d   ID = %d   Credit = %d   Taxes = %d\n", data[1].Salary, data[1].Password, data[1].ID, data[1].Credit, data[1].Taxes);
            }
            else if (pass == data[2].Password)
            {
                printf("Emp3 Salary = %d   Password = %d   ID = %d   Credit = %d   Taxes = %d\n", data[2].Salary, data[2].Password, data[2].ID, data[2].Credit, data[2].Taxes);
            }
            else if (pass == data[3].Password)
            {
                printf("Emp4 Salary = %d   Password = %d   ID = %d   Credit = %d   Taxes = %d\n", data[3].Salary, data[3].Password, data[3].ID, data[3].Credit, data[3].Taxes);
            }
            else if (pass == data[4].Password)
            {
                printf("Emp5 Salary = %d   Password = %d   ID = %d   Credit = %d   Taxes = %d\n", data[4].Salary, data[4].Password, data[4].ID, data[4].Credit, data[4].Taxes);
            }
            else
            {
                printf("Wrong Password\n");
            }
        }
        else
        {
            printf("Enter a valid username\n");
        }
    }
}
*/

int main(void)
{
    typedef enum
    {
        task1 = 0,
        task2 = 0,

    }tast_t;
    tast_t x = task2;
    tast_t y = task1;
    printf("%d   %d", x, y);

    return 0;
}