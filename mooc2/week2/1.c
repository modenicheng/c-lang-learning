/*
1最大公约数（15分）
题目内容：

  输入两个整数m,n，用递归算法实现计算两个数的最大公约数。

输入格式:

  输入两个整数m,n

输出格式：

  最大公约数

输入样例：

12,40[回车]

输出样例：

4[回车]
*/
#include <stdio.h>

int fun1(int m, int n);

int main() {
  int m, n;
  scanf("%d,%d", &m, &n);
  printf("%d\n", fun1(m, n));
}

int fun1(int m, int n) {
  if (n == 0) {
    return m;
  } else {
    return fun1(n, m % n);
  }
}