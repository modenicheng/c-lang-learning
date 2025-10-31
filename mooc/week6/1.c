#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%3d", i * n + j);
            if (j == n)
            {
                printf("\n");
            }
            // else
            // {
            //     printf("  ");
            // }
        }
    }
    return 0;
}
