/*
46【日期】再算天数
成绩	10	开启时间	2025年11月10日 星期一 00:05
折扣	0.8	折扣时间	2025年12月1日 星期一 23:59
允许迟交	否	关闭时间	2025年12月8日 星期一 23:59
我们再来计算天数（两个日期之间相差几天）。

本次编程与过去的程序不一样，我们已经给出了一些子函数，请你将这些函数拿下来，然后编写主函数来完成所需要的功能。

输入：
    起始日期的年，月，日
    终止日期的年，月，日   （假设终止日期大于起始日期）

输出：
    终止日期与起始日期之间的天数

注意：不用提交完整程序，只需要提交你自己编写的主函数即可。
*/

#include <stdio.h>

// 声明函数原型
int leap_year(int);
int year_days(int);
int days(int, int, int);

int leap_year(int year) // 判断闰年或平年
{
  return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;
}

int year_days(int year) // 计算一整年的天数
{
  return leap_year(year) ? 366 : 365;
}

int days(int year, int month, int day) // 计算该天month,day 是本年year的第几天
{
  int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, i;

  if (leap_year(year) && month > 2)
    day++;

  for (i = 1; i < month; i++)
    day += months[i];

  return day;
}

// Solve is below. DO NOT CHANGE / SUBMIT THE CODE ABOVE.

int total_days(int year, int month, int day) {
  int total = 0;
  for (int y = 1900; y < year; y++) {
    total += year_days(y);
  }
  total += days(year, month, day);
  return total;
}

int main() {
  int start_year, start_month, start_day, end_year, end_month, end_day;
  scanf("%d %d %d %d %d %d", &start_year, &start_month, &start_day, &end_year,
        &end_month, &end_day);

  int start_days = total_days(start_year, start_month, start_day);
  int end_days = total_days(end_year, end_month, end_day);

  int days_diff = end_days - start_days;

  if (days_diff == 1) {
    printf("1 day\n");
  } else {
    printf("%d days\n", days_diff);
  }

  return 0;
}