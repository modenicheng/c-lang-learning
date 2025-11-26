/*
53【日期】计算天数+
成绩	10	开启时间	2025年11月24日 星期一 00:05
折扣	0.8	折扣时间	2025年12月15日 星期一 23:59
允许迟交	否	关闭时间	2026年01月15日 星期四 23:59
我们经常要计算天数（两个日期之间相差几天），例如要算算春节放假几天，清明节可以休息几天。

输入：
    起始日期的年，月，日
    终止日期的年，月，日   （假设终止日期大于起始日期）

输出：
   终止日期与起始日期之间的天数

测试用例 1

Input:
2013 1 2
2013 1 12

Output:
10 days

测试用例 2
Input:
2013 1 31
2013 2 2

Output:
2 days

测试用例 3
Input:
2013 1 31
2014 2 1

Output:
366 days
*/

#include <stdio.h>

typedef struct {
  int year;
  int month;
  int day;
} Date;

int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int days(int y, int m, int d) {
  int res = 0;
  for (int i = 1; i < y; i++) {
    if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
      res += 1;
    }
    res += 365;
  }
  for (int i = 1; i < m; i++) {
    res += months[i - 1];
  }
  res += d;
  return res;
}
int main() {
  Date day1, day2;
  scanf("%d %d %d", &day1.year, &day1.month, &day1.day);
  scanf("%d %d %d", &day2.year, &day2.month, &day2.day);
  int total_days = days(day2.year, day2.month, day2.day) -
                   days(day1.year, day1.month, day1.day);
  printf("%d %s\n", total_days, total_days == 1 ? "day" : "days");
  return 0;
}