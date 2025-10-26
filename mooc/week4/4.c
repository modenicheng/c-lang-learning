/*
题目内容：

小明在中学会求一个数的 n 次方了，但计算机还不会，请你来编写一个程序吧。由于计算机比较“笨”，所以我们编写程序的功能不用太强，只要能算出 a 的 n 次方的最后 3 位数就可以了。



输入格式:

a 和 n 的值。假设 a<=150 。



输出格式：

求 a 的 n 次方的最后 3 位数。

提示：再想一想，你的方法对吗？你用的是什么数据类型？



输入样例：

10 0


输出样例：

The last 3 numbers is 1.

*/

#include <stdio.h>
#include <math.h>

unsigned long long int power(long long base, long long n);

int main()
{
    long long a, n;
    scanf("%lld%lld", &a, &n);
    if (a == 0)
    {
        printf("The last 3 numbers is 0.\n");
        return 0;
    }
    unsigned long long int result;

    result = pow(a, n);

    // unsigned long long tmp = ((unsigned long long)0 - 1);

    // if (result >= ((unsigned long long)0 - 1))
    // {
    //     for (long long i = 0; i < n; i++)
    //     {
    //         result *= a;
    //         result %= 1000;
    //     }
    //     printf("The last 3 numbers is %.3lld.\n", result % 1000);
    // }

    // else if (result >= 100)
    // {
    //     printf("The last 3 numbers is %.3lld.\n", result % 1000);
    // }
    // else if (result >= 10)
    // {
    //     printf("The last 3 numbers is %lld.\n", (long long)pow(a, n) % 1000);
    // }
    // else
    // {
    //     printf("The last 3 numbers is %lld.\n", result % 1000);
    // }

    // printf("The last 3 numbers is %.3d.\n", 0);
    if (a % 10 == 0 && a * n >= 30)
    {
        printf("The last 3 numbers is 000.\n", 0);
    }
    else if (a % 10 == 0 && n == 0)
    {

        printf("The last 3 numbers is 1.\n");
    }
    else
    {
        printf("The last 3 numbers is %d.\n", result % 1000);
    }
    return 0;
}

unsigned long long int power(long long base, long long n)
{
    unsigned long long result = 1;

    for (long long i = 0; i < n; i++)
    {
        result *= base;
    }
    return result;
}
