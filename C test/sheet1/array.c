#include "stdio.h"
#include "stdlib.h"
#include "math.c"

void Array_print(int *arr, int size)
{
    int i = 0;
    for (i; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void Array_scan(int *arr, int M_size)
{
    int i = 0, size;
    printf("please enter the size not more that %d\n", M_size);
    scanf("%d", &size);
    if (size > M_size)
    {
        size = M_size;
    }
    for (i = 0; i < size; i++)
    {
        scanf("%d", arr + i);
    }
    printf("\n");
}
int Array_removePrime(int *arr, int size)
{
    int i, c;
    for (i = 0; i < size; i++)
    {
        if (IsPrime(arr[i]) == 1)
        {
            arr[i] = 0;
            c++;
        }
    }
    return c;
}
int Array_search(int *arr, int size, int num)
{
    int i, c;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int Array_copy(int *S_arr, int S_size, int *C_arr, int C_size)
{
    int i, size;
    size = S_size >= C_size ? C_size : S_size;
    for (i = 0; i < size; i++)
    {
        C_arr[i] = S_arr[i];
    }
    return size;
}

int Array_most_repeated_number(int *arr, int size, int *num)
{
    int i, j, c, max = 0;

    for (i = 0; i < size; i++)
    {
        c = 0;
        for (j = i; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                c++;
            }
        }
        if (c > max)
        {
            max = c;
            *num = arr[i];
        }
    }
    return max;
}

int find_most_repeated(int arr[], int n) {
    int i, max_count = 0, max_element = arr[0];
    int count[100] = {0}; // assuming maximum element value in the array is 99

    for (i = 0; i < n; i++) {
        count[arr[i]]++;
        if (count[arr[i]] > max_count) {
            max_count = count[arr[i]];
            max_element = arr[i];
        }
    }

    return max_element;
}

int *compareTriplets(int a_count, int *a, int b_count, int *b, int *result_count)
{
    char i;
    result_count[0] = 0;
    result_count[1] = 0;

    for (i = 0; i < b_count; i++)
    {
        if (a[i] > b[i])
        {
            *result_count = *result_count + 1;
        }
        if (a[i] < b[i])
        {
            *(result_count + 1) = *(result_count + 1) + 1;
        }
    }
    return result_count;
}

int Array_Occurrence_index(int *arr, int size, int num)
{
    int i, flag, occur;
    for (i = 0; i < size; i++)
    {
        if (num == arr[i])
        {
            flag = 1;
            occur = i;
        }
    }
    if (flag == 1)
    {
        return occur;
    }
    else
    {
        return -1;
    }
}

void Array_get_Max_Min(int *arr, int size, int *ar)
{
    signed int imax, imin, i = 0, min = 0x7FFFFFFF, max = 0, index = 0;

    for (i; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            imax = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            imin = i;
        }
    }
    ar[0] = max;
    ar[1] = imax;
    ar[2] = min;
    ar[3] = imin;
}

void Array_Fill_BetweentwoNumbers(int num1, int num2, int *arr)
{
    int c = 0, i;
    for (i = num1; i < (num2 - 1); i++)
    {
        arr[c] = num1 + c + 1;
        c++;
    }
}

void Array_reverseNumbers(int *arr, int size)
{
    int i, j = (size - 1);
    int ar[100];
    Array_copy(arr, size, ar, size);
    for (i = 0; i < size; i++)
    {
        arr[i] = ar[j];
        j--;
    }
}

void Array_Swap(int *arr1, int size1, int *arr2, int size2)
{
    int i, size;
    int C_ar1[100];
    int C_ar2[100];

    Array_copy(arr1, size1, C_ar1, 100);
    Array_copy(arr2, size2, C_ar2, 100);

    size = size1 >= size2 ? size2 : size1;
    for (i = 0; i < size; i++)
    {
        arr1[i] = C_ar2[i];
        arr2[i] = C_ar1[i];
    }
}

int Array_Occurrence_Number(int *arr, int size, int num)
{
    int i, flag, c = 0, max = 0;
    for (i = 0; i < size; i++)
    {
        if (num == arr[i])
        {
            flag = 1;
            c++;
            if (c > max)
            {
                max = c;
            }
        }
        else
        {
            c = 0;
        }
    }
    if (flag == 1)
    {
        return max;
    }
    else
    {
        return -1;
    }
}

int Array_Concecitive_Occurrence(int *arr, int size)
{
    int i, flag, c = 1, max = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            flag = 1;
            c++;

            if (c > max)
            {
                max = c;
            }
        }
        else
        {
            c = 1;
        }
    }
    if (flag == 1)
    {
        return max;
    }
    else
    {
        return -1;
    }
}

int Array_merge(int *arr1, int size1, int *arr2, int size2, int *arr3)
{
    int i, size, s, j = 0;
    size = size1 + size2;
    s = size1 >= size2 ? size2 : size1;
    for (i = 0; i < (s * 2); i = i + 2)
    {
        arr3[i] = arr1[j];
        arr3[i + 1] = arr2[j];
        j++;
    }
    if (s == size1)
    {
        for (; i < size; i = i + 1)
        {
            arr3[i] = arr2[j];
            j++;
        }
    }
    else if (s == size2)
    {
        for (; i < size; i++)
        {
            arr3[i] = arr1[j];
            j++;
        }
    }
    return size;
}

int Array_RemoveRepeated(int *arr, int size, int *N_arr)
{
    int i = 0, j = 0, k = 0, flag = 0;
    for (i; i < size; i++)
    {
        flag = 0;
        for (j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            N_arr[k] = arr[i];
            k++;
        }
    }
    return k;
}


void Array_removeRepeatedNumber(int *arr, int size, int *N_arr)
{
    int i, num;
   /* for (i = 0; i < size; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            N_arr[i] = 0;
            N_arr[i + 1] = arr[i];
        }
        else
        {
            N_arr[i] = arr[i];
        }
    }*/
       
        for (i = size; i >= 0; i--)
    {
        if (arr[i] == arr[i + 1])
        {
            N_arr[i] = arr[i];
            N_arr[i + 1] = 0;
        }
        else
        {
            N_arr[i] = arr[i];
        }
    }
}

void Array_SwapThreeNumbers(int *arr)
{
    int i = 0, i1 = 0, i2 = 0, flag = 0;
    while (flag != 2)
    {
        if (arr[i] == 0 && flag == 0)
        {
            i1 = i;
            flag++;
        }
        else if (arr[i] == 0 && flag == 1)
        {
            i2 = i;
            flag++;
        }
        i++;
    }
    
    Swap(arr + i1 + 1, arr + i2 + 1);
    Swap(arr + i1 + 2, arr + i2 + 2);
    Swap(arr + i1 + 3, arr + i2 + 3);
}

 int Array_BiggestDifference(int *ar, int size)
{
     int imax = 0, imin_o = 0, imin_n = 0, i = 0, min = 0x7FFFFFFF, max = 0, difference = 0;

    for (i; i < size; i++)
    {

        if (ar[i] < min)
        {
            min = ar[i];
            imin_n = i;
        }
        if (imin_o != imin_n)
        {
            max = 0;
        }
        if (ar[i] > max)
        {
            max = ar[i];
            imax = i;
        }
        imin_o = imin_n;
    }
    printf("%d       %d\n", max, min);

    difference = max - min;

    return difference;
}