/*
38【字符】串的减法
成绩	10	开启时间	2025年10月27日 星期一 00:05
折扣	0.8	折扣时间	2025年11月24日 星期一 23:59
允许迟交	否	关闭时间	2025年12月1日 星期一 23:59
输入字符串s和t（串长不超过80个字符），将在字符串s中出现，但未在字符串t中出现的字符组成一个新的字符串放在u中，u中字符按原字符串中字符顺序排列，不去掉重复字符，输出u。

例如：当s="112345"，t="2467"时，u="1135"。

输入：
　　第一行为串s
　　第二行为串t

输出：
      串u

In

112345↵
2467↵

Out

1135↵
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[128] = "", str2[128] = "";
    fgets(str1, 128, stdin);
    fgets(str2, 128, stdin);

    char result[128] = "";
    int result_index = 0;

    int len1 = strlen(str1), len2 = strlen(str2);
    for (int i = 0; i < len1; i++)
    {
        char current_char = str1[i];
        int is_unique = 1;
        for (int j = 0; j < len2; j++)
        {
            if (current_char == str2[j])
            {
                is_unique = 0;
                break;
            }
        }
        if (is_unique == 1)
        {
            result[result_index] = current_char;
            result_index += 1;
        }
    }
    printf("%s\n", result);
    return 0;
}
