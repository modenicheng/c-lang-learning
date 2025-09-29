#include<stdio.h>
#include<math.h>

int main()
{
    double a, x;
    // a = 3;
    // x = 3.5;
    // result: -7.473194
    a = 351;
    x = 35.12579;
    // result: 206.713731
    
    double result = (0.65l * a - sqrt(x) + 4l / 15l - 7.83l) * 0.96418l;
    printf("%lf\n", result);
    return 0;
}