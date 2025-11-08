/*
组成最大数（10分）
题目内容：

任意输入一个自然数，输出该自然数的各位数字组成的最大数。

输入格式：

自然数 n

输出格式：

各位数字组成的最大数

输入样例：

1593

输出样例：

9531[回车]
*/

#include<stdio.h>

int main(int argc, char const *argv[])
{
    int number;
    int digits[100] = {0};
    scanf("%d", &number);
    int count = 0;

    for (int i = 0; i < 100; i++)
    {
        digits[i] = number % 10;
        number /= 10;
        count++;
        if (number == 0)
        {
            break;
        }
    }
    // Bubble sort to arrange digits in descending order
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (digits[j] < digits[j + 1])
            {
                int tmp = digits[j];
                digits[j] = digits[j + 1];
                digits[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d", digits[i]);
    }
    printf("\n");
    return 0;
}
