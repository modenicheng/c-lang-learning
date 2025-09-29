#include <stdio.h>
void main()
{
    int a = 3, b = 2, c = 4, d = 8, x;
    a += b * c; // a = 11
    b -= c / b; // b = 0
    printf("%d,%d,%d,%d\n", a, b, c *= 2 * (a - c), d %= a);
    x=5;
    printf("x=%d\n", x += ++x);
    printf("\\\065a,\n");
}