/*
求解递归问题, 已知f(x,y)=f(x*3,y)*f(x,y/2)


x

当 x ≥ y 且 y ≠ 0 时

 f(x,y) =


y

当 y = 0 时

输入：x,y

输出：f(x,y)的值

例如输入：
2,4↙
输出
12↙
*/
#include <stdio.h>

int f(int x, int y) {
  if (x >= y && y != 0)
    return f(x * 3, y) * f(x, y / 2);
  else if (y == 0)
    return 1;
  else
    return x;  // When x < y and y != 0
}

int main() {
  int x, y;
  scanf_s("%d,%d", &x, &y);
  printf("%d\n", f(x, y));
  return 0;
}
