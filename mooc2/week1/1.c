/*
1求最大公约数和最小公倍数（15分）
题目内容：

  编写程序，在主函数中输入两个正整数 a,b，调用两个函数 fun1() 和 fun2()，分别求
a 和 b 的最大公约数和最小公倍数，在主函数中输出结果。

输入格式：

  两个正整数

输出格式：

  最大公约数和最小公倍数

输入样例：

12,40[回车]

输出样例：

最大公约数：4[回车]
最小公倍数：120[回车]
*/
#include <stdio.h>

// 函数声明
int fun1(int a, int b);
int fun2(int a, int b);

int main() {
  int a, b;

  // 按照样例格式输入：12,40
  if (scanf("%d,%d", &a, &b) == 2) {
    int gcd = fun1(a, b);
    int lcm = fun2(a, b);

    // 输出结果
    printf("最大公约数：%d\n", gcd);
    printf("最小公倍数：%d\n", lcm);
  }

  return 0;
}

/*
 * 函数：fun1
 * 功能：使用辗转相除法求最大公约数 (GCD)
 */
int fun1(int a, int b) {
  int temp;
  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

/*
 * 函数：fun2
 * 功能：根据公式求最小公倍数 (LCM)
 * 公式：LCM(a, b) = (a * b) / GCD(a, b)
 */
int fun2(int a, int b) {
  // 为了防止 a * b 溢出，建议先除以最大公约数再相乘
  return (a / fun1(a, b)) * b;
}