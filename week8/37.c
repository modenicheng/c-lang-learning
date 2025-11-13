/*
37【图形】画一个字母组成的菱形

输入顶行字符(大写)和图形的高，输出如图所示图形。

例如顶行字符为 ' A ' ，图形的高为 5。且认为字母是循环的，即Z与A相邻。

              A
            B   B
          C     C
        D         D
       E            E
        D         D
          C    C
            B B
             A

输入:
A,3↵

输出:
  A↵
 B B↵
C   C↵
 B B↵
  A↵
*/

#include <stdio.h>

char ch(int n)
{
    if (n >= 'A' && n <= 'Z')
    {
        return n;
    }
    else if (n > 'Z')
    {
        return ch(n - 26);
    } else if (n < 'A')
    {
        return ch(n + 26);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    char c;
    scanf("%c,%d", &c, &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        printf("%c", ch(c + i));
        for (int j = 0; j < i * 2 - 1; j++)
        {
            printf(" ");
        }
        if (i != 0)
        {
            printf("%c", ch(c + i));
        }
        printf("\n");
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        printf("%c", ch(c + i));
        for (int j = 0; j < i * 2 - 1; j++)
        {
            printf(" ");
        }
        if (i != 0)
        {
            printf("%c", ch(c + i));
        }
        printf("\n");
    }
    return 0;
}
