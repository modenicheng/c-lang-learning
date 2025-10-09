#include <stdio.h>

int main()
{
    int y;
    int m = 5;

    scanf("%d", &y);

    // 只计算五月份所以不需要下面的判断

    // if (m <= 2)
    // {
    //     y -= 1;
    //     m += 12;
    // }

    // 计算公式来源：https://blog.csdn.net/luoyayun361/article/details/54881835
    // 第四节：基姆拉尔森计算公式（据 blog 作者说这是他命名的）
    int counter = 0;
    for (int d = 1; d < 31; d++)
    {
        int weekday = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
        if (weekday == 6)
        {
            counter += 1;
            if (counter == 2)
            {
                printf("%d\n", d);
                break;
            }
        }
    }

    return 0;
}
