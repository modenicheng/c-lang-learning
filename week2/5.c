#include <stdio.h>

/*
小明上了小学一年级，老师开始教他认识两个数哪个大，哪个小。计算机要学会这个可以使用 if 语句，也可以使用三目运算 ? 。

输入：两个整型数

输出：两个整型值中的最小值
*/

// implementation 1
// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);
//     if (a < b)
//     {
//         printf("min=%d\n", a);
//         return 0;
//     }
//     printf("min=%d\n", b);
//     return 0;
// }

// implementation 2
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("min=%d\n", a < b ? a : b);
    return 0;
}


// implementation 3
// int main()
// {
//     int a, b;
//     scanf("%d%d", &a, &b);
//     if (a < b) {
//         printf("min=%d", a);
//     } else {
//         printf("min=%d", b);
//     }
//     return 0;
// }