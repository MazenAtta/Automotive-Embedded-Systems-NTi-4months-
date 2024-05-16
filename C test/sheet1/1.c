
#include "stdio.h"
#include "stdlib.h"
#include "array.c"
#include "string.c"

int main()
{

    int x = 5, y = 7, z;
    double i = -14.5;
    z = i * 10;
    int ar1[10] = {10, 1, 5, 4, 60, 9, 8, -8, 30, 10};
    int ar2[] = {100, 90, 0, 70, 60, 50, 0, 30, 20, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    char ar3[100];
     FloatToString(-140.5, ar3);
     String_Print(ar3);

}
