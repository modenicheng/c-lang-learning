#include<stdio.h>

int main()
{
    double r, h;
    const double pi = 3.1415926;
    scanf("%lf %lf", &r, &h);
    double v = pi * r * r * h;
    double s = 2 * pi * r *  h;
    printf("s=%.2lf,v=%.2lf\n", s, v);
    return 0;
}