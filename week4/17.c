#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num, iter, sum;
    scanf("%d", &num);
    iter = 0;
    sum = 0;
    while (sum < num)
    {
        iter += 1;
        sum += iter;
    }
    printf("%d\n", iter);
    return 0;
}
