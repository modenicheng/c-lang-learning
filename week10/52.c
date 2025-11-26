/*
52 三角形是一个永不过时的话题
成绩	10	开启时间	2025年11月24日 星期一 00:05
折扣	0.8	折扣时间	2025年12月15日 星期一 23:59
允许迟交	否	关闭时间	2026年01月15日 星期四 23:59
题目描述

欢迎参加程序设计竞赛~

程序设计竞赛中有着很多有意思的问题，其中，与三角形有关的问题就经常出现。今天你要解决的，就是其中最简单的一个问题：

给定平面直角坐标系上的N个点，保证这N个点中任意三点都不共线。求任意三点能够构成的三角形中，面积最大的三角形的面积。

输入

输入的第一行是一个整数T（1 <= T <= 10），表示一共有T组用例。

每组用例的第一行为一个整数N（3 <= n <=
100），表示平面上点的个数。接下来的N行，每行包含两个用空格隔开的整数Xi和Yi（-1000
<= Xi, Yi <= 1000），表示第i个点的坐标（Xi, Yi）。

输出

每组用例输出一个数，表示最大的三角形的面积，结果保留一位小数。

输入样例

2

4

-1 1

1 1

1 -1

-1 -1

3

-1 -1

3 0

0 0

输出样例

2.0

1.5
*/

#include <math.h>
#include <stdio.h>

typedef struct {
  int x, y;
} Point;

int main() {
  int t, n, i;
  double max_area, area;
  Point points[100];
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d %d", &points[i].x, &points[i].y);
    }
    max_area = 0.0;
    for (i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          area =
              0.5 * fabs(points[i].x * points[j].y + points[j].x * points[k].y +
                         points[k].x * points[i].y - points[i].y * points[j].x -
                         points[j].y * points[k].x - points[k].y * points[i].x);
          if (area > max_area) {
            max_area = area;
          }
        }
      }
    }
    printf("%.1lf\n", max_area);
  }
  return 0;
}
