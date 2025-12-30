/*
3输出各位数字之和（10分）
题目内容：

  编程调用递归函数，求输入一个数，输出这个数的各位数字之和。

输入格式：

  输入一个数

输出格式：

  输出这个数的各位数字之和



输入样例：

2354[回车]

输出样例：

14[回车]
*/
#include <stdio.h>

int digit_sum(int n) {
  if (n == 0) {
    return 0;
  }
  return n % 10 + digit_sum(n / 10);
}

int main() {
  int num;
  scanf("%d", &num);
  printf("%d\n", digit_sum(num));
  return 0;
}