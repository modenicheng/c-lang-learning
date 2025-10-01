#include <stdio.h>

int main()
{
    int y, m, d;

    scanf("%d%d%d", &y, &m, &d);

    if (m <= 2)
    {
        y -= 1;
        m += 12;
    }

    // 计算公式来源：https://blog.csdn.net/luoyayun361/article/details/54881835
    // 第四节：基姆拉尔森计算公式（据 blog 作者说这是他命名的）
    int weekday = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7 + 1;
    weekday = weekday == 7 ? 0 : weekday;
    printf("%d\n", weekday);
    return 0;
}
