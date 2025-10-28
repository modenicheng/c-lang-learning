#include <stdio.h>

int main(int argc, char const *argv[])
{
    long long n;
    int count = 0;
    scanf("%lld", &n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int k = j; k <= n; k++)
                if (i * i + j * j == k * k)
                {
                    count++;
                }
        }
    }

    printf("%d\n", count);

    return 0;
}
