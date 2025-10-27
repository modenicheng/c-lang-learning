#include <stdio.h>

int main()
{
    int h;
    scanf("%d", &h);
    for (int i = 0; i < h; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < 2 * h - 1; j++)
            {
                putchar('*');
            }
            putchar('\n');
        }
        else if (i == h - 1)
        {
            for (int j = 0; j < h - 1; j++)
            {
                putchar(' ');
            }
            printf("*\n");
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                putchar(' ');
            }
            putchar('*');
            for (int j = 0; j < (2 * h - 1) - ((i + 1) * 2); j++)
            {
                putchar(' ');
            }
            printf("*\n");
        }
    }
    return 0;
}
