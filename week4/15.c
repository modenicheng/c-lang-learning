#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        putchar('*');
    }
    putchar('\n');
    return 0;
}
