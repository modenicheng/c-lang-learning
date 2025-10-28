/*
28【图形】空心字符菱形

输入：

    菱型起始字母和菱形的高度。

输出：

    参看测试用例，打印空心的由字符组成的菱形。

测试用例 1	
输入:
   C 4↵

输出:
   C↵
  D D↵
 E   E↵
F     F↵
 E   E↵
  D D↵
   C↵
*/

#include <stdio.h>

int main()
{
    int n;
    char c;
    scanf("%c %d", &c, &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j == 0 || j == 2 * i)
            {
                printf("%c", c + i);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j == 0 || j == 2 * i)
            {
                printf("%c", c + i);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
