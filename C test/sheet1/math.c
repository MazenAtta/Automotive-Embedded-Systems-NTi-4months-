
int sum_betweenAllnumbers(int num1, int num2)
{
    unsigned int num, sum;
    num = num1 - num2 + 1;
    sum = (num) * (num1 + num2) / 2;
    return sum;
}

void Swap(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int get_power(int num, int power)
{
    int i = 0, res = 0;
    for (i; i < power; i++)
    {
        res = res * num;
    }
    return res;
}

int get_fact(int num)
{
    int i = 1, fact = 1;
    for (i; i <= num; i++)
    {
        fact = fact * i;
    }
    return fact;
}

int IsPrime(int num)
{
    int i, rem = 0;

    for (i = 2; i < num; i++)
    {
        rem = num % i;
        if (rem == 0)
        {
            return -1;
        }
    }
    return 1;
}

int IsSquare(int num)
{
    int i = 0, check = 0;

    for (i; i < num; i++)
    {
        check = i * i;
        if (check == num)
        {
            return i;
        }
    }
    return 0;
}

int IsBaseOfTwo(int num)
{
    int i = 0, check = 1;

    for (i; i < num; i++)
    {
        check = check * 2;
        if (check == num)
        {
            return 1;
        }
        if (check > num)
        {
            return 0;
        }
    }
}

int Check_powerofThree(int num)
{
    int i = 0, check = 1;

    for (i; i < num; i++)
    {
        check = check * 3;
        if (check == num)
        {
            return 0;
        }
        if (check > num)
        {
            return 1;
        }
    }
}

int sum_of_decimal(int num)
{
    int i = 0, rem = 0, sum = 0;

    while (num > 0)
    {
        rem = num % 10;
        num = num / 10;
        sum = sum + rem;
    }
    return sum;
}

int Circle(double *Area, double *Circumference)
{
    double r, pi = 3.14;
    *Area = pi * r * r;
    *Circumference = 2 * pi * r;
}

int reverseDecimal(int num)
{
    int n1 = 0, rem = 0, c = 0;

    while (n1)
    {
        rem = n1 % 10;
        n1 = n1 / 10;
        num = num * 10 + rem;
    }
    return num;
}
int numberofOnes(int *n, int num)
{
    unsigned int c = 0;
    *n = num;
    while (num)
    {
        if ((num & 1) == 1)
        {
            c++;
        }
        num = (num >> 1);
    }
    return num;
}

void printBinary(int num)
{
    int i, rem = 0, c = 0;

    for (i = 31; i >= 0; i--)
    {
        if ((num >> i) & 1)
        {
            printf("%d", 1);
        }
        else
        {
            printf("%d", 0);
        }
    }
}
void printReverseBinary(int num)
{
    int num2, i, j = 31;

    for (i = 0; i <= 31; i++)
    {
        if (num >> i & 1)
        {
            num2 = num2 | (1 << j);
        }
        j--;
    }
    printBinary(num2);
}

int Set_Bit(int num, int Bit_num)
{
    num = (1 << Bit_num) | num;
    return num;
}

int Clear_Bit(int num, int Bit_num)
{
    num = (~(1 << Bit_num)) & num;
    return num;
}

int Toggle_Bit(int num, int Bit_num)
{
    num = (1 << Bit_num) ^ num;
    return num;
}

int Read_Bit(int num, int Bit_num)
{
    num = (num >> Bit_num) & 1;
    return num;
}

void print_pattern_1(int x)
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = i; j > 0; j--)
        {
            printf("*");
        }
        printf("\n");
    }
}

void print_pattern_2(int x)
{
    int i, j;
    for (i = x; i > 0; i--)
    {
        for (j = i; j > 0; j--)
        {
            printf("*");
        }
        printf("\n");
    }
}
void print_pattern_3(int x)
{
    int i, j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x; j++)
        {
            if (j == i || j == (x - i - 1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void print_pattern_4(int x)
{
    int i, j;
    for (i = 1; i <= x; i++)
    {
        for (j = 1; j <= (x * 2 - 1); j++)
        {
            if (j >= x - (i - 1) && j <= x + (i - 1))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int max_zeros_in_binary(int x)
{
    int i, c = 0, flag = 0, max = 0;
    for (i = 0; i < 32; i++)
    {
        if (x >> i & 1)
        {
            if (max < c)
            {
                max = c;
                c = 0;
            }
            flag = 1;
        }
        else if (flag == 1 && (x >> i & 1) == 0)
        {
            c++;
        }
    }
    return max;
}

int max_A_XOR_B(int x, int y, int *n1, int *n2)
{
    int i, j, r, max = 0;
    for (i = x; i < y; i++)
    {
        for (j = i; j < y; j++)
        {
            r = i ^ j;
            if (r >= max)
            {
                max = r;
                *n1 = i;
                *n2 = j;
            }
        }
    }
    return max;
}

int Fibonacci_num(int index)
{
    int num1 = 0, num2 = 1, sum = 0;
    if (index == 0)
    {
        return 0;
    }
    if (index == 1)
    {

        return 1;
    }
    for (int i = 1; i < index; i++)
    {
        sum = num1 + num2;
        num1 = num2;
        num2 = sum;
    }
    return sum;
}