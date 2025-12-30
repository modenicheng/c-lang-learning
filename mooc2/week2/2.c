/*
2奇数求和（15分）
题目内容：

  用递归算法实现，输入整数n（n>0）, 求1+3+5+7….+(2*n-1) 的和

输入格式:

  输入整数n

输出格式：

  输出和

输入样例：

5[回车]

输出样例：

25[回车]
*/
#include <stdio.h>

int calculate(int n);

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", calculate(n));
}

int calculate(int n) {
  if (n == 1) {
    return 1;
  } else {
    return calculate(n - 1) + 2 * n - 1;
  }
}