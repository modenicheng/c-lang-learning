#include <stdio.h>

int main()
{
    char c;
    scanf("%c", &c);
    if (c >= 'A' && c <= 'Z') {
        printf("%c", c += 32);
    } else if (c >= 'a' && c <= 'z') {
        printf("%c", c -= 32);
    } else {
        printf("%c", c);
    }
    return 0;
}