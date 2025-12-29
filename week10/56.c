/*
56【数列】计算分数的SUM
成绩	10	开启时间	2025年11月24日 星期一 00:05
折扣	0.8	折扣时间	2025年12月15日 星期一 23:59
允许迟交	否	关闭时间	2026年01月15日 星期四 23:59
小明上了中学，开始接触数列了。

已知公式：SUM = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n

输入：

    n

输出：

    表达式 sum 的值。结果保留 6 位小数。
*/

#include <stdio.h>

double sum(int n) {
  if (n == 1) {
    return 1.0;
  }
  return 1.0 / n + sum(n - 1);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("sum=%.6f\n", sum(n));
  return 0;
}