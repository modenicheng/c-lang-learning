#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    char operator;

    scanf("%d%c%d", &a, &operator, &b);

    switch (operator)
    {
    case '+':
        printf("%d\n", a + b);
        break;
    case '-':
        printf("%d\n", a - b);
        break;
    case '*':
        printf("%d\n", a * b);
        break;
    case '/':
        printf("%d\n", a / b);
        break;
    case '%':
        printf("%d\n", a % b);
        break;
    default:
        break;
    }

    return 0;
}
