#include "stdio.h"
#include "stdlib.h"

void main()
{

    int n1 = 0, i, rem = 0, c = 0;
    printf("please enter a number\n");
    scanf("%d", &n1);
    for (i = 31; i >= 0; i--)
    {
        if ((n1 >> i) & 1)
        {
            printf("%d", 1);
            c = 1;
        }
        else if (c == 1)
        {
            printf("%d", 0);
        }
    }
}
