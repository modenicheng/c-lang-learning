#include <stdio.h>
#include <math.h>
int is_armstrong(int number)
{
    int digits[6] = {0, 0, 0, 0, 0, 0};
    int original_number = number;
    for (int i = 0; i < 6; i++)
    {
        digits[i] = number % 10;
        number /= 10;
    }
    int result = 0;
    for (int i = 0; i < 6; i++) {
        result += pow(digits[i], 3);
    }
    return result == original_number;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int range_start = pow(10, n - 1);
    int range_end = pow(10, n);

    int count = 0;
    for (int i = range_start; i < range_end; i++)
    {
        if (is_armstrong(i))
        {
            printf("%d\n", i);
            count += 1;
        }
    }
    if (count == 0)
    {
        printf("No Output.\n");
    }
    return 0;
}
