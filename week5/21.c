#include <stdio.h>

int is_target_number(int number)
{
    if (number % 2 != 0)
    {
        return 0;
    }

    int digits[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        digits[i] = number % 10;
        number /= 10;
    }
    if (digits[0] == digits[1] ||
        digits[0] == digits[2] ||
        digits[0] == digits[3] ||
        digits[1] == digits[2] ||
        digits[1] == digits[3] ||
        digits[2] == digits[3])
    {
        return 0;
    }
    return 1;
}

int main()
{
    while (1)
    {
        int start, end;
        int counter = 0;

        scanf("%d%d", &start, &end);
        if (start == 0 && end == 0)
        {
            return 0;
        }

        if (start < 1000 || end < 1000){
            printf("Error\n");
            continue;
        }

        for (int number = start; number <= end; number++)
        {
            if (is_target_number(number))
            {
                printf("%d  ", number);
                counter += 1;
            }
        }
        printf("\ncounter=%d\n", counter);
    };
    return 0;
}