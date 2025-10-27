/*
H2【图形】铺地板（选作）

背景：
    你是一名室内装潢工程队的配料员。你的伙伴们喜欢采用“之”字型的方式铺大理石地砖，图案如下：

1	2	6	7	15
3	5	8	14	16
4	9	13	17	22
10	12	18	21	23
11	19	20	24	25
学了 C 语言以后，你决定编写一个程序，帮助你的同伴生成这样的图形。

输入：
    方阵N的大小。

输出
    方阵。
*/


#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            int num;

            if (i + j < n)
            {
                int sum = (2 + i + j) * (1 + i + j) / 2;
                if ((i + j) % 2 == 1)
                {
                    num = sum - j;
                }
                else
                {
                    num = sum - i;
                }
            }
            else
            {
                int sum = (2 * n - i - j - 1) * (2 * n - j - i) / 2;
                if ((i + j) % 2 == 1)
                {
                    num = n * n - (sum - (n - j));
                }
                else
                {
                    num = n * n - (sum - (n - i));
                }
                // num = sum;
            }

            printf("%2d", num);
            if (j != n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }

    return 0;
}