#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (a + b <= c || a + c <= b || b + c <= a)
    {
        printf("non-triangle.\n");
        return 0;
    }

    if (a == b && b == c && a == c)
    {
        printf("equilateral triangle.\n");
        return 0;
    }
    else if (a == b || b == c || a == c)
    {
        printf("isoceles triangle.\n");
        return 0;
    }
    printf("triangle.\n");
    return 0;
}