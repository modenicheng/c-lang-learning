/*
40【字符】删除重复字符
成绩	10	开启时间	2025年10月27日 星期一 00:05
折扣	0.8	折扣时间	2025年11月24日 星期一 23:59
允许迟交	否	关闭时间	2025年12月1日 星期一 23:59
背景：
输入一个长度不超过 100 的字符串，删除串中的重复字符。

输入：

输入要检查的字符串，长度不超过100个字符。例如：abacaeedabcdcd。

输出：

删除重复字符后的字符串。例如：abced。
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[128] = "";
    scanf("%s", str);

    int str_index = 0;
    char result[128] = "";
    int result_len = 0;

    while (1)
    {
        register char c = str[str_index];
        register int repeat_flag = 0;

        if (c == '\0')
        {
            result[result_len + 1] = '\0';
            break;
        }
        for (int i = 0; i < result_len; i++)
        {
            if (c == result[i])
            {
                repeat_flag = 1;
            }
        }
        if (!repeat_flag)
        {
            result[result_len] = c;
            result_len += 1;
        }
        str_index += 1;
    }
    printf("%s\n", result);
    return 0;
}
