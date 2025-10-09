#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, d, x;
    int r = scanf("(%lf,%lf) (%lf,%lf)", &a, &b, &c, &d);
    printf("r = %d\n", r);
    x = sqrt((a - c) * (a - c) + (b - d) * (b - d));
    printf("%.2lf\n", x);
    return 0;
}