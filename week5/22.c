#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int max = 0, min = 0;
    char operator;
    c = getchar();
    max = min = c - 48;
    while (1)
    {
        c = getchar();
        if (c == '=')
        {
            break;
        }
        if (c == '+' ||
            c == '-' ||
            c == '*' ||
            c == '/' ||
            c == '%')
        {
            operator = c;
        }
        else if (c >= '0' && c <= '9')
        {
            int num = c - 48;
            if (num < min)
            {
                min = num;
            }
            else if (num > max)
            {
                max = num;
            }
        }
    }
    int result;
    switch (operator)
    {
    case '+':
        result = max + min;
        break;

    case '-':
        result = max - min;
        break;

    case '*':
        result = max * min;
        break;

    case '/':
        if (min == 0)
        {
            printf("Error!\n");
            return 1;
        }
        result = max / min;
        break;

    case '%':
        result = max % min;
        break;

    default:
        break;
    }
    printf("%d%c%d=%d\n", max, operator, min, result);
    return 0;
}