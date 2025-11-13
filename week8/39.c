/*
39【字符】单词排序
    输入 5 个单词，将它们按从大到小的顺序排列后输出。

输入：

    5个单词

输出：

    排序后的顺序
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    
    char words[5][64] = {""};
    for (int i = 0; i < 5; i++)
    {
        fgets(words[i], sizeof(words[i]), stdin);
        words[i][strcspn(words[i], "\n")] = '\0';
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i - 1; j++)
        {
            if (strcmp(words[j], words[j + 1]) < 0)
            {
                char tmp[64];
                strcpy(tmp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], tmp);
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", words[i]);
    }
    return 0;
}
