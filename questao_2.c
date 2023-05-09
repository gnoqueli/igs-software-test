#include <stdio.h>
#include <string.h>

int digit(char);

// another function which wheels will not be invented. some of these tasks are about things people did long time ago.
// honestly, even if the idea itself is to see how one would develop it, i'd say knowing where to look makes for a great task as well.
int main()
{
    char roman_number[1000];
    int i = 0;
    long int number = 0;

    printf("Enter any roman number (Valid digits are I, V, X, L, C, D, M):  \n");
    scanf("%s", roman_number);

    while (roman_number[i])
    {

        if (digit(roman_number[i]) < 0)
        {
            printf("Invalid roman digit : %c", roman_number[i]);
            return 0;
        }

        if ((strlen(roman_number) - i) > 2)
        {
            if (digit(roman_number[i]) < digit(roman_number[i + 2]))
            {
                printf("Invalid roman number");
                return 0;
            }
        }

        if (digit(roman_number[i]) >= digit(roman_number[i + 1]))
            number = number + digit(roman_number[i]);
        else
        {
            number = number + (digit(roman_number[i + 1]) - digit(roman_number[i]));
            i++;
        }
        i++;
    }

    printf("Its decimal value is : %ld\n", number);

    return 0;
}

int digit(char c)
{

    int value = 0;

    switch (c)
    {
    case 'I':
        value = 1;
        break;
    case 'V':
        value = 5;
        break;
    case 'X':
        value = 10;
        break;
    case 'L':
        value = 50;
        break;
    case 'C':
        value = 100;
        break;
    case 'D':
        value = 500;
        break;
    case 'M':
        value = 1000;
        break;
    case '\0':
        value = 0;
        break;
    default:
        value = -1;
    }

    return value;
}