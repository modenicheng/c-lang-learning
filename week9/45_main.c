/*
45【递归】子串反向

这个文件是用于运行测试的文件，将题目给的代码封装到此处，
并调用 reverse 函数进行测试。

*/
#include "./45.c"
#include <stdio.h>

void reverse(char[], int, int);
int main() {
  char str[100];
  int start, end;

  scanf_s("%s", str);
  scanf_s("%d%d", &start, &end);
  reverse(str, start, end);
  printf("%s\n", str);
  return 0;
}
