/*
2离高考还有几天（20分）
题目内容：

一般情况下，凡是遇到重大的活动，都会竖起一个倒计时牌子，提醒人们，离某个重要的日子，还有几天。
例如：高考前，每个学校都会有一块动态显示屏：“离高考还有xx天”。我们假定每年的高考日期都是6月6日。
我们输入一个日期，请你判断，离下次高考还有多少天？

提示：如果相差日期小于1天，就显示下一次高考的相差天数。



输入格式:

高考日期的年月日



输出格式：

相差天数



输入样例：

2016.6.1[回车]



输出样例：

5 days.[回车]
*/
#include <stdio.h>

typedef struct {
  int year;
  int month;
  int day;
} Date;

int days_map[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  Date date, target_date;
  scanf("%d.%d.%d", &date.year, &date.month, &date.day);

  target_date.year = date.year;
  target_date.month = 6;
  target_date.day = 6;

  if (date.month > 6 || (date.month == 6 && date.day >= 6)) {
    target_date.year++;
  }

  int days = 0;

  for (int i = date.month; 1; i++) {
    if (i == 13) {
      i = 1;
      date.year++;
    }
    if (i == target_date.month && target_date.year == date.year) {
      break;
    }
    days += days_map[i - 1];
    if (i == 2 &&
        (date.year % 400 == 0 || (date.year % 4 == 0 && date.year % 100 != 0))) {
      days++;
    }
  }
  days += target_date.day - date.day;

  printf("%d %s.\n", days, days == 1 ? "day" : "days");

  return 0;
}