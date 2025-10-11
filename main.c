#include <stdio.h>
int main()
{
    int year, month, day;
    int run = year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
    scanf("%d%d%d", &year, &month, &day);
    int sum1 = (year - 1901) / 4 + (year - 1901) * 365;
    int sum2 = 0;
    if (month > 12 || month < 1)
        printf("month is error.\n");
    else
    {
        if (day > 31 || day < 1)
        {
            printf("day is error.\n");
            return 0;
        }
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
        {
            printf("day is error.\n");
            return 0;
        }
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        {
            printf("day is error.\n");
            return 0;
        }
        if (month == 2)
        {
            if (run && (day > 29))
            {
                printf("day is error.\n");
                return 0;
            }
            else if (!run && (day > 28))
            {
                printf("day is error.\n");
                return 0;
            }

        }

        switch (month)
        {
        case 12:
            sum2 += 30;
        case 11:
            sum2 += 31;
        case 10:
            sum2 += 30;
        case 9:
            sum2 += 31;
        case 8:
            sum2 += 31;
        case 7:
            sum2 += 30;
        case 6:
            sum2 += 31;
        case 5:
            sum2 += 30;
        case 4:
            sum2 += 31;
        case 3:
            sum2 += (28 + run);
        case 2:
            sum2 += 31;
        case 1:
            sum2 += 0;
        }
        int sum3 = day;
        int sum = sum1 + sum2 + sum3;
        int yu = sum % 7;
        int date = 1 + yu;
        if (date == 7)
            date = 0;
        printf("%d\n", date);
    }
    return 0;
}