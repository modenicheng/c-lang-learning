/*
51 【大学】函数递归*
成绩	10	开启时间	2025年11月24日 星期一 00:05
折扣	0.8	折扣时间	2025年12月15日 星期一 23:59
允许迟交	否	关闭时间	2026年01月15日 星期四 23:59
编写一个函数，使用递归算法求满足下述定义的整数序列的第n项。


1	当 n >= 0 且 n <= 4 时
f( n ) =	f(n-1) + f(n-3)	当 n > 4 且n为偶数 时
f(n-2) + f(n-4)	当 n > 4 且n为奇数 时
-1	其他

函数原型如下：

int findf(int n);

参数说明：n 项数；返回值是第n项值。
例如输入：10，输出：8

预设代码
前置代码

#include <stdio.h>

int main()
{  int n,s, findf( int );
    scanf("%d", &n);
    s = findf(n);
    printf("%d\n", s);
    return 0;
}

*/

#include <stdio.h>

int main() {
  int n, s, findf(int);
  scanf("%d", &n);
  s = findf(n);
  printf("%d\n", s);
  return 0;
}

int findf(int n) {
  if (n >= 0 && n <= 4) {
    return 1;
  }
  if (n % 2 == 0 && n > 4) {
    return findf(n - 1) + findf(n - 3);
  }
  if (n % 2 == 1 && n > 4) {
    return findf(n - 2) + findf(n - 4);
  }
  return -1;
}