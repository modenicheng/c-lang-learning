/*
36【串】Hi, there!

Input your English name, and the computer will say Hi to you.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char name[1024];
    char *ptr = name;
    while (1)
    {
        char c = getchar();
        if (c == '\n')
        {
            *ptr = '\0';
            break;
        };
        *ptr = c;
        ptr++;
    }
    printf("Hi,there,%s!\n", name);
    return 0;
}
