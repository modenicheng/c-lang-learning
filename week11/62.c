/*
62. 输出图形
成绩	10	开启时间	2025年11月28日 星期五 00:05
折扣	0.8	折扣时间	2025年12月15日 星期一 23:59
允许迟交	否	关闭时间	2025年12月22日 星期一 23:59
输入图形的行数、以及大写英文字母，输出由字母组成的以下图形。

例如输入: 6 W

输出:

W                   W
K X               X K
J   Y           Y   J
I     Z       Z     I
H       A   A       H
G F E D C B C D E F G
*/
#include <stdio.h>

int main() {
  int n;
  char c;
  scanf("%d %c", &n, &c);

  for (int i = 0; i < n; i++) {
    char c1 = (c + i - 'A') % 26 + 'A';
    char c2 = (c + 2 * (n - 1) + (n - 1 - i) - 'A') % 26 + 'A';

    if (i == 0 && n > 1) {
      printf("%c", c1);
      for (int j = 0; j < 4 * n - 5; j++) {
        printf(" ");
      }
      printf("%c\n", c1);
    } else if (i == n - 1) {
      for (int j = 0; j < (n - 1); j++) {
        printf("%c ", (c1 + (n - 1 - j) - 'A') % 26 + 'A');
      }
      for (int j = 0; j < (n - 1); j++) {
        printf("%c ", (c1 + j - 'A') % 26 + 'A');
      }
      printf("%c\n", c2);
    } else {
      printf("%c ", c2);
      for (int j = 0; j < i - 1; j++) {
        printf("  ");
      }
      printf("%c ", c1);
      for (int j = 0; j < 2 * (n - i - 1) - 1; j++) {
        printf("  ");
      }
      printf("%c ", c1);
      for (int j = 0; j < i - 1; j++) {
        printf("  ");
      }
      printf("%c\n", c2);
    }
  }
  return 0;
}