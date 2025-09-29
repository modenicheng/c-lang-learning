#include <stdio.h>
#include <stdlib.h>
/*
输入：
    整型变量x的值。

输出：
    输出整型变量x对应的十进制、八进制和十六进制形式。
*/
int main()
{
    int x;
    int _ = scanf("%d", &x);
    printf("x=%d,x=%o,x=%x\n", x, x, x);

    return 0;
}