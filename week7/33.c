/*
33【中学】贪吃的猴子

有一只猴子，第一天摘了若干个桃子 ，当即吃了一半，但还觉得不过瘾 ，就又多吃了一个。第2天早上又将剩下的桃子吃掉一半，
还是觉得不过瘾，就又多吃了两个。以后每天早上都吃了前一天剩下的一半加天数个（例如，第5天吃了前一天剩下的一般加5个）。
到第n天早上再想吃的时候，就只剩下一个桃子了。

输入：

    天数n

输出：

    第一天的桃子个数

提述：要先建立递推公式。

测试用例 1
In:
3↵

Out:
The monkey got 14 peaches in first day.↵

*/
#include <stdio.h>

int peaches(int n, int day)
{
    if (day == n)
    {
        return 1;
    }
    return (peaches(n, day + 1) + day) * 2;
}


int main(int argc, char const *argv[])
{
    int n;
    int day = 1;
    scanf("%d", &n);
    printf("The monkey got %d peaches in first day.\n", peaches(n, day));
    return 0;
}
