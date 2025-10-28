/*
26【日期】计算后续日期

我们经常要计算，从今天往后N天之后是哪一天（哪年哪月哪日）。现在我们就可以编写一个程序，推算指定日期之后的第N天是什么日期。

输入：
  年 月 日
  N

输出：
（年月日+N天后的）年.月.日
*/

#include <stdio.h>

int main()
{
    int y, m, d;
    int delta_d;
    scanf("%d%d%d%d", &y, &m, &d, &delta_d);

    int is_leap_year = (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
    while (delta_d > 0)
    {
        /* code */
        d += 1;
        delta_d -= 1;
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
                d = 1;
                m += 1;
            }
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (d > 30)
            {
                d = 1;
                m += 1;
            }
            break;

        case 2:
            if (is_leap_year)
            {
                if (d > 29)
                {
                    d = 1;
                    m += 1;
                }
            }
            else
            {
                if (d > 28)
                {
                    d = 1;
                    m += 1;
                }
            }
            break;

        default:
            break;
        }
        if (m > 12)
        {
            m = 1;
            y += 1;
            is_leap_year = (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
        }
    }
    printf("%d.%d.%d\n", y, m, d);

    return 0;
}
