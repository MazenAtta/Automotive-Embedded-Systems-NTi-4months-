#include "stdio.h"
#include "stdlib.h"
#include "array.c"
#include "string.c"

int x, max, min;
void get_num(int n)
{
    x = n;
    min = 0x7FFFFFFF;
    max = 0;
    if (x > max)
    {
        max = x;
    }
    if (x < min)
    {
        min = x;
    }
}
int get_max(void)
{
    return max;
}
int get_min(void)
{
    return min;
}