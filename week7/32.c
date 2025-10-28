/*
32【字符】组成最大数

任意输入一个自然数，输出该自然数的各位数字组成的最大数。例如，输入 1593 ，则输出为 9531 。

输入：自然数 n

输出：各位数字组成的最大数

测试用例 1
In:

1593↵


Out:

9531↵
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n[64];
    int read_index = 0;
    while (1)
    {
        char c = getchar();
        if (c == '\n')
        {
            break;
        }
        n[read_index] = c - 48;
        read_index++;
    }
    for (int i = 0; i < read_index; i++)
    {
        for (int j = i + 1; j < read_index; j++)
        {
            if (n[i] < n[j])
            {
                int temp = n[i];
                n[i] = n[j];
                n[j] = temp;
            }
        }
    }
    for (int i = 0; i < read_index; i++)
    {
        printf("%d", n[i]);
    }
    printf("\n");
    return 0;
}
