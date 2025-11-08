/*
2回文数（10分）
题目内容：

    输出所有不超过ｎ(取n<256)的、其平方具有对称性质的正整数（也称为回文数）。

如：  1*1=1； 2*2=4；3*3=9；11*11=121；1,2,3,11是回文数。

输入格式：

    输入n（n<256）

输出格式：

    输出所有不超过n的回文数

输入样例：

3

输出样例：

1[回车]

2[回车]
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int digits[5] = {0};
        int count = 0;
        int num = i * i;
        while (1)
        {
            digits[count] = num % 10;
            num /= 10;
            count++;
            if (num == 0)
            {
                break;
            }
        }
        // printf("%d, %d\n", i, i * i);
        for (int j = 0; j < count / 2 + 1; j++)
        {
            if (digits[j] != digits[count - 1 - j])
            {
                break;
            }
            if (j == count / 2)
            {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
