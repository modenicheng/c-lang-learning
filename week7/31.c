/*
31【字符】合并字符串

输入两个已经按从小到大顺序排列好的字符串，编写一个合并两个字符串的函数，使合并后的字符串，仍然是从小到 大排列。

输入：
            两个已经排好顺序（升序）的两个字符串（字符串长度小于100个字符）

输出：
            一个合并在一起的有序（升序）的字符串

要求：
            设计一个效率尽量高的算法，对每个字符串只扫描一遍就可以了。
            如果采用先进行串连接，然后再进行排序的算法，则效率太低了。

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[1024];
    char str1[1024], str2[1024];
    int read_ptr1 = 0, read_ptr2 = 0, write_ptr = 0;

    char *ptr1 = str1;
    char *ptr2 = str2;
    while (1)
    {
        char c;
        c = getchar();
        if (c == '\n')
        {
            break;
        }
        *ptr1++ = c;
    }
    while (1)
    {
        char c;
        c = getchar();
        if (c == '\n')
        {
            break;
        }
        *ptr2++ = c;
    }
    while (str1[read_ptr1] != '\0' && str2[read_ptr2] != '\0')
    {
        if (str1[read_ptr1] < str2[read_ptr2])
        {
            str[write_ptr++] = str1[read_ptr1++];
        }
        else
        {
            str[write_ptr++] = str2[read_ptr2++];
        }
    }
    while (str1[read_ptr1] != '\0')
    {
        str[write_ptr++] = str1[read_ptr1++];
    }
    while (str2[read_ptr2] != '\0')
    {
        str[write_ptr++] = str2[read_ptr2++];
    }
    str[write_ptr] = '\0';
    printf("%s\n", str);
    return 0;
}
