/*
34【图形】打印三角形

 打印如下数字三角形
输入：起始数字，行数
输出：对应数字三角形
（数字递增，若超过9，则从0开始）

例如，输入3 6，则输出：

345678
7     9
6   0
5 1
42
3
*/
#include <stdio.h>

int num;

int yield()
{
    return num++ % 10;
}

int main(int argc, char const *argv[])
{
    int start_num, h;
    scanf("%d%d", &start_num, &h);
    num = start_num;

    // first line
    for (int i = 0; i < h; i++)
    {
        printf("%d", yield());
    }
    printf("\n");
    // other lines
    for (int i = 1; i < h; i++)
    {
        int line_main_num = yield();
        if (i != h - 1)
        {
            printf("%d", (line_main_num + (h - i - 1) * 2) % 10);
        };
        for (int j = 0; j < h - i - 2; j++)
        {
            printf(" ");
        }
        printf("%d\n", line_main_num);
    }
    return 0;
}
