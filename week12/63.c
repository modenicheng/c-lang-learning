/*
63.【日期】车辆限行
成绩	10	开启时间	2025年12月5日 星期五 00:05
折扣	0.8	折扣时间	2025年12月22日 星期一 23:59
允许迟交	否	关闭时间	2025年12月29日 星期一 23:59
    2012年4月1日，北京是人民政府根据《中华人民共和国道路交通安全法》和《北京市实施〈中华人民共和国大气污染防
治法〉办法》有关规定，自2012年4月11日起，继续对机动车实施按车牌尾号工作日高峰时段
区域限行交通管理措施。
　　根据规定，按车牌尾号限行的机动车车牌尾号分为五组，每13周轮换一次限行日，分别为：
　　(1)
自2012年4月9日至2012年7月7日，星期一至星期五限行机动车车牌尾号分别为：3和8、4和9、5和0、1和6、2和7(含临时号牌，机动车车牌尾号为英文字母的按0号管理，下同)；
　　(2)
自2012年7月8日至2012年10月6日，星期一至星期五限行机动车车牌尾号分别为：2和7、3和8、4和9、5和0、1和6；
　　(3)
自2012年10月7日至2013年1月5日，星期一至星期五限行机动车车牌尾号分别为：1和6、2和7、3和8、4和9、5和0；
　　(4)
自2013年1月6日至2013年4月10日，星期一至星期五限行机动车车牌尾号分别为：5和0、1和6、2和7、3和8、4和9。

现给出 2012 年 4 月 9
日之后的任意日期，如果不考虑国家统一的公假，只考虑日期一个因素，请计算指定日期要限行的车牌尾号。

（政府的公告确实有点意思，在时间衔接上和限号安排上公告（http://unn.people.com.cn/GB/14748/17574443.html）与公告（http://www.gov.cn/gzdt/2013-04/02/content_2367908.htm）之间有重叠，显然，后面的公告是覆盖前面的公告的，我们计算的时候，只能是“理论”上的事情，咱严格按照从
2012年4月9日 星期一 开始，每 13 周进行一次轮换计算就可以了。）

测试用例	     测试输入	       期待的输出
测试用例 1	   2012 7 9	      2 and 7.
测试用例 2	   2012 7 12	    5 and 0.
测试用例 3	   2012 7 14	    Free.
测试用例 5	   2013 4 11	    2 and 7.

*/

#include <stdio.h>

typedef struct {
  int year;
  int month;
  int day;
  int days;    // 总计天数（自1年1月1日起）
  int weekday; // 0-6，0表示星期日
} Date;

int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int restrict_days[5][14] = {{3, 8, 4, 9, 5, 0, 1, 6, 2, 7, -1, -1, -1, -1},
                            {2, 7, 3, 8, 4, 9, 5, 0, 1, 6, -1, -1, -1, -1},
                            {1, 6, 2, 7, 3, 8, 4, 9, 5, 0, -1, -1, -1, -1},
                            {5, 0, 1, 6, 2, 7, 3, 8, 4, 9, -1, -1, -1, -1},
                            {4, 9, 5, 0, 1, 6, 2, 7, 3, 8, -1, -1, -1, -1}};

void init_date(Date *date) {
  register int count = 0;
  for (int i = 1; i < date->year; i++) {
    count += 365;
    if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
      count++;
    }
  }
  for (int i = 0; i < date->month - 1; i++) {
    count += month_days[i];
    if (i == 1 && ((date->year % 4 == 0 && date->year % 100 != 0) ||
                   (date->year % 400 == 0))) {
      count++;
    }
  }
  date->days = count + date->day;
  date->weekday = date->days % 7;
}

int main() {
  Date date;
  scanf("%d %d %d", &date.year, &date.month, &date.day);
  init_date(&date);

  // compute days for base date 2012-04-09
  Date base = {2012, 4, 9, 0, 0};
  init_date(&base);
  int days_diff = date.days - base.days;
  // weeks since base
  int weeks = days_diff / 7;
  int index = (weeks / 13) % 5;

  // handle weekend
  if (date.weekday == 0 || date.weekday == 6) {
    printf("Free.\n");
    return 0;
  }

  int day_index = (date.weekday - 1) * 2;
  if (restrict_days[index][day_index] == -1) {
    printf("Free.\n");
  } else {
    printf("%d and %d.\n", restrict_days[index][day_index],
           restrict_days[index][day_index + 1]);
  }
  return 0;
}