/*
42【日期】黑色星期五
成绩	10	开启时间	2025年10月27日 星期一 00:05
折扣	0.8	折扣时间	2025年11月24日 星期一 23:59
允许迟交	否	关闭时间	2025年12月1日 星期一 23:59
在西方，星期五和数字13都代表着坏运气，两个不幸的个体最后结合成超级不幸的一天。所以，不管哪个月的十三日又恰逢星期五就叫"黑色星期五”。

输入：

    年份

输出：

    判断该年是否包含黑色星期五，如包含，给出具体日期
*/

#include <stdio.h>

int days_map[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int week(int year, int month, int day) {
  int days = 0;
  for (int y = 1; y < year; y++) {
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
      days += 366;
    } else {
      days += 365;
    }
  }
  for (int m = 1; m < month; m++) {
    days += days_map[m - 1];
  }
  if (month > 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
    days += 1;
  }
  days += day;

  return days % 7;
}

typedef struct {
  int year;
  int month;
  int day;
} Date;

int main() {
  int year;
  scanf("%d", &year);

  int count = 0;
  Date dates[16] = {};

  for (int m = 1; m <= 12; m++) {
    if (week(year, m, 13) == 5) {
      Date date = {year, m, 13};
      dates[count++] = date;
    }
  }
  switch (count) {
  case 0:
    printf("There is no black friday in %d.\n", year);
    break;
  case 1:
    printf("There is 1 black friday in %d.\n", year);
    printf("It is:\n");
    break;
  default:
    printf("There are %d black fridays in %d.\n", count, year);
    printf("They are:\n");
    break;
  }
  for (int i = 0; i < count; i++) {
    printf("%d/%d/%d\n", dates[i].year, dates[i].month, dates[i].day);
  }
}
