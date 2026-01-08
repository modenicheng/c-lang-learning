/**
SY4-3 递归
成绩	10	开启时间	2025年12月26日 星期五 00:05
折扣	0.8	折扣时间	2026年01月12日 星期一 23:59
允许迟交	否	关闭时间	2026年01月17日 星期六 23:59
编写一个函数，使用递归算法求满足下述定义的整数序列的第n项。

1

当 n <= 0 时

f( n ) =

n * f(n-1)

当 n > 0 且n为偶数 时


(n+1) - f(n-2)

当 n > 0 且n为奇数 时

函数原型如下：
int findf(int n);
参数说明：n 项数；返回值是第n项值。
例如输入：10，输出：50 */

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>

int findf(int n);

int main() {
  int n, s;
  scanf("%d", &n);
  s = findf(n);
  printf("%d\n", s);
  return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

int findf(int n) {
  // 基本情况：n <= 0 时返回1
  if (n <= 0) {
    return 1;
  }

  // n > 0 的情况
  if (n % 2 == 0) {
    // n为偶数：f(n) = n * f(n-1)
    return n * findf(n - 1);
  } else {
    // n为奇数：f(n) = (n+1) - f(n-2)
    return (n + 1) - findf(n - 2);
  }
}