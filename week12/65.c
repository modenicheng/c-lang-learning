/*
65. 回文字符串——递归
成绩	10	开启时间	2025年12月5日 星期五 00:05
折扣	0.8	折扣时间	2025年12月22日 星期一 23:59
允许迟交	否	关闭时间	2025年12月29日 星期一 23:59
    有一种特殊形式的字符串，其正反序相同，被称为“回文字符串”。例如LeveL就是一个回文字符串。

输入：
          字符串

输出：
          Yes或者No

说明：
          如输出Yes，说明输入的字符串是一个回文字符串
          输出No，说明输入的字符串不是一个回文字符串
          请使用递归算法实现。

In 1:
LeveL↵

Out 1:
Yes↵

In 2:
↵

Out 2:
Yes↵
*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_palindrome(char str[], int l1, int l2) {
  if (l1 >= l2) {
    return true;
  }
  if (str[l1] != str[l2]) {
    return false;
  }
  return is_palindrome(str, l1 + 1, l2 - 1);
}

int main() {
  char str[1000];
  fgets(str, sizeof(str), stdin);
  if (is_palindrome(str, 0, strlen(str) - 1)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}