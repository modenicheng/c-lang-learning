#include <stdio.h>

int main()
{
    int y, m, d;

    scanf("%d%d%d", &y, &m, &d);

    if (d < 0 || d > 31)
    {
        printf("day is error.\n");
        return 1;
    }

    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (d > 31)
        {
            printf("day is error.\n");
            return 1;
        }
        break;
    case 2:
        if (((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)) && (d > 29))
        {
            printf("day is error.\n");
            return 1;
        }
        else if (!((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)) && (d > 28))
        {
            printf("day is error.\n");
            return 1;
        }
    case 4:
    case 6:
    case 9:
    case 11:
        if (d > 30)
        {
            printf("day is error.\n");
            return 1;
        }
        break;
    default:
        printf("month is error.\n");
        return 1;
    }

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