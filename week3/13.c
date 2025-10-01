// 解一元二次方程
#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    double delta, x1, x2, real_part, imag_part;

    scanf("%d %d %d", &a, &b, &c);

    if (a == 0 && b == 0)
    {
        printf("Input error!\n");
        return 0;
    }

    if (a == 0)
    {
        double result = -(double)c / (double)b == 0 ? 0 : -(double)c / (double)b;
        printf("x=%.6lf\n", result);
        return 0;
    }
    delta = b * b - 4 * a * c;
    if (delta > 0)
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("x1=%.6lf\nx2=%.6lf\n", x1 == 0 ? 0 : x1, x2 == 0 ? 0 : x2);
    }
    else if (delta == 0)
    {
        x1 = x2 = -(double)b / (2 * (double)a);
        printf("x1=x2=%.6lf\n", x1 == 0 ? 0 : x1);
    }
    else
    {
        real_part = -(double)b / (2 * (double)a);
        imag_part = sqrt(-delta) / (2 * (double)a);
        if (real_part == 0 && imag_part != 0)
        {
            printf("x1=%.6lfi\nx2=-%.6lfi\n", imag_part, imag_part);
        }
        else if (imag_part == 0 && real_part != 0)
        {
            printf("x1=%.6lf\nx2=%.6lf\n", real_part, -real_part);
        }
        else
        {
            printf("x1=%.6lf+%.6lfi\nx2=%.6lf-%.6lfi\n", real_part, imag_part, real_part, imag_part);
        }
    }

    return 0;
}
