int String_scan(char *str)
{
    int i = 0;
    scanf("%c", &str[0]);
    for (; str[i] != '\n';)
    {
        i++;
        scanf("%c", &str[i]);
    }
    str[i] = '\0';
    return i;
}

void String_Print(char *str)
{
    for (int i = 0; str[i] != 0; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}
void String_swap(char *p1, char *p2)
{
    char temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int String_len(char *str)
{
    int i;
    for (i = 0; str[i] != 0; i++)
        ;
    return i;
}

void String_reverseprint(char *str)
{
    int i = (String_len(str) - 1);
    for (i; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}

int String_compare(char *str1, char *str2)
{
    int i;
    for (i = 0; str1[i] || str2[i]; i++)
    {
        if (str1[i] != str2[i])
        {
            return 0;
        }
    }
    return 1;
}

int String_compare2(char *str1, char *str2)
{
    int i;
    for (i = 0; str1[i] || str2[i]; i++)
    {
        if (str1[i] != str2[i] && (str1[i] - 'a') != (str2[i] - 'A') && (str1[i] - 'A') != (str2[i] - 'a'))
        {
            return 0;
        }
    }
    return 1;
}

int String_MostRepeatedChar(char *str, char *character)
{
    char index, counter = 0, max = 0;
    for (int i = 0; str[i]; i++)
    {
        counter = 0;
        for (int j = i; str[j]; j++)
        {
            if ((str[i] == str[j]) || (str[i] - 'a') == (str[j] - 'A') || (str[i] - 'A') == (str[j] - 'a'))
            {
                counter++;
            }
            if (max <= counter)
            {
                max = counter;
                index = i;
            }
        }
    }
    if ((str[index] - 'a') >= 0)
    {
        *character = (str[index] - 'a' + 'A');
    }
    else
    {
        *character = str[index];
    }
    return max;
}

int String_LongestWord(char *str, char *word)
{
    int i, j = 0, c = 0, max = 0, index = 0, flag = 0;
    for (i = 0; str[i]; i++)
    {
        if (str[i] != ' ')
        {
            c++;
            if (max < c)
            {
                max = c;
                index = i;
            }
        }
        else
        {
            c = 0;
        }
    }
    i = (index - max + 1);
    for (i; i <= index; i++)
    {
        word[j] = str[i];
        j++;
    }
    word[j] = '\0';
    return max;
}

int String_Search(char *str)
{
    int i, j = 0, flag = 0, index, count;
    char word[100];
    printf("Enter the word you want to search for\n");

    count = (String_scan(word));

    for (i = 0; str[i] && j != count; i++)
    {
        if ((str[i]) == (word[j]) || (str[i] - 'a') == (word[j] - 'A') || (str[i] - 'A') == (word[j] - 'a'))
        {
            j++;
            if (flag == 0)
            {
                flag = 1;
                index = i;
            }
        }
        else
        {
            j = 0;
            flag = 0;
        }
    }
    if (j == count)
    {
        return index;
    }
    else
    {
        return -1;
    }
}

void String_Mirror(char *str)
{
    int i = 0, l = 0, j = 0, k = 0;

    for (; str[i] != '\0';)
    {

        for (l; str[l] != '\0' && str[l] != ' '; l++)
            ;

        j = (l - 1);
        for (j; j > k; j--)
        {
            String_swap(&str[k], &str[j]);
            k++;
        }
        i = l;
        k = ++l;
    }
}

void string_copy(char *S_str, char *C_str)
{
    for (int i = 0; S_str[i]; i++)
    {
        C_str[i] = S_str[i];
    }
}

void IntToString(char *str, int num)
{

    int i = 0, j = 0, k = 0;
    if (num == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    if (num < 0)
    {
        num = num * -1;
        str[0] = '-';
        j = 1;
        i = 1;
    }
    while (num != 0)
    {
        str[i] = num % 10 + '0';
        num = num / 10;
        i++;
    }
    str[i] = '\0';
    k = (i - 1);

    for (j; j < k; j++)
    {
        String_swap(&str[k], &str[j]);
        k--;
    }
}

int StringToInt(char *str)
{
    int i = 0, num = 0;

    if (str[0] == '-')
    {
        i = 1;
    }

    while (str[i] != '\0')
    {
        num = (num * 10) + (str[i] - '0');
        i++;
    }
    if (str[0] == '-')
    {
        num = num * -1;
    }
    return num;
}

int String_CheckPalindrome(char *str)
{
    char C_str[100];
    string_copy(str, C_str);
    String_Mirror(C_str);
    for (int i = 0; str[i]; i++)
    {
        if (str[i] != C_str[i])
        {
            return 0;
        }
    }
    return 1;
}

void String_reverseSentence(char *str)
{
    int i, j = 0;
    for (i = 0; str[i]; i++)
        ;
    i = i - 1;
    for (j; j < i; j++)
    {
        String_swap(&str[i], &str[j]);
        i--;
    }
    String_Mirror(str);
}

char *String_checkTriangle(char *str)
{
    int i, num1 = 0, num2 = 0, num3 = 0, flag = 0;
    for (i = 0; str[i]; i++)
    {
        if (num2 == 0 && num3 == 0 && str[i] != ' ' && flag == 0)
        {
            num1 = num1 * 10 + (str[i] - '0');
        }
        else if (num3 == 0 && str[i] != ' ' && flag == 1)
        {
            num2 = num2 * 10 + (str[i] - '0');
        }
        else if (str[i] != ' ' && flag == 2)
        {
            num3 = num3 * 10 + (str[i] - '0');
        }
        else if (str[i] == ' ')
        {
            flag++;
        }
    }

    if (num1 + num2 > num3 && num1 + num3 > num2 && num3 + num2 > num1)
    {
        if (num1 == num2 && num1 == num3 && num2 == num3)
        {
            static char triangle[25] = "Equilateral triangle";
            return triangle;
        }
        else if (((num1 == num2) && (num1 != num3)) || ((num3 == num2) && (num3 != num1)) || ((num3 == num1) && (num3 != num2)))
        {
            static char triangle[25] = "Isosceles triangle";
            return triangle;
        }
        else if (num1 != num2 && num1 != num3 && num2 != num3)
        {
            static char triangle[25] = "Scalene triangle";
            return triangle;
        }
    }
    else
    {
        static char triangle[20] = "Not a triangle";
        return triangle;
    }
}

void FloatToString(double num, char *str)
{
    int num1 = 0, i = 0, j = 0, k = 0, c = 0;

    if (num == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    if (num < 0)
    {
        num = num * -1;
        str[0] = '-';
        j = 1;
        i = 1;
        c = 1;
    }
    double num2 = num;

    while (num1 != num2)
    {
        num2 = num2 * 10;
        num1 = num2;
        c++;
    }

    while (num1 != 0)
    {
        if (i == c)
        {
            str[i] = '.';
        }
        else
        {
            str[i] = num1 % 10 + '0';
            num1 = num1 / 10;
        }
        i++;
    }
    str[i] = '\0';
    k = (i - 1);

    for (j; j < k; j++)
    {
        String_swap(&str[k], &str[j]);
        k--;
    }
}