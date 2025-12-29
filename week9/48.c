/*
48.【图形】字母X *
成绩	5	开启时间	2025年11月10日 星期一 00:05
折扣	0.8	折扣时间	2025年12月1日 星期一 23:59
允许迟交	否	关闭时间	2025年12月8日 星期一 23:59
输入整数n值和首字母，输出以首字母为中心，边长为n的X形。其中，上两条边上字母递增，下两条边上字母递减。且认为字母是循环的，即Z与A相邻。

若输入的不是大写字母，则输出”input error"提示。

输入：4 A
输出：
D　　　　　D
　C　　　C
　　B　B
　　　A
　　Z　Z
　Y　　　Y
X　　　　　X
*/

#include <stdio.h>

char start;
char yield_count = 0;

char yield() {
  char res = (char)(start + yield_count--);
  if (res > 'Z') {
    res -= 26;
  }
  if (res < 'A') {
    res += 26;
  }
  return res;
}

int main() {
  int n;
  scanf("%d %c", &n, &start);
  start += n - 1;
  if (start > 'Z') {
    start -= 26;
  }
  if (start < 'A' || start > 'Z') {
    printf("input error.\n");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    register char c = yield();
    for (int j = 0; j < i; j++) {
      printf(" ");
    }
    printf("%c", c);
    for (int j = 0; j < 2 * (n - i) - 3; j++) {
      printf(" ");
    }
    if (i != n - 1) {
      printf("%c", c);
    }
    printf("\n");
  }
  for (int i = n - 2; i >= 0; i--) {
    register char c = yield();
    for (int j = 0; j < i; j++) {
      printf(" ");
    }
    printf("%c", c);
    for (int j = 0; j < 2 * (n - i) - 3; j++) {
      printf(" ");
    }
    if (i != n - 1) {
      printf("%c", c);
    }
    printf("\n");
  }
}