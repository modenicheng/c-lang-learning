/*
30【中学】求最后3位数值

小明在中学会求一个数的 n 次方了，但计算机还不会，请你来编写一个程序吧。由于计算机比较“笨”，所以我们编写程序的功能不用太强，只要能算出 a 的 n 次方的最后 3 位数就可以了。

输入：

    a 和 n 的值。假设 a<=150 。

输出：

    求 a 的 n 次方的最后 3 位数。

提示：再想一想，你的方法对吗？你用的是什么数据类型？
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int base, exponent;
    scanf("%d %d", &base, &exponent);
    int result = 1;

    for (int i = 0; i < exponent; i++)
    {
        result *= base;
        result %= 1000;
    }
    if (pow(base, exponent) > 99){
        printf("The last 3 numbers is %.3d.\n", result);
    } else if (pow(base, exponent) > 99)
    {
        printf("The last 3 numbers is %.2d.\n", result);
    } else
    {
        printf("The last 3 numbers is %d.\n", result);
    }
    return 0;
}
