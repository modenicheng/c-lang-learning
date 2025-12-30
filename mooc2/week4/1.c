/*
1对称字符串（15分）
题目内容：

    从键盘输入一个字符串，判断是否为对称字符串，若是输出“YES”，若不是输出“NO”

输入格式：

    一个字符串

输出格式：

    YES or NO



输入样例1：

abcdedcba[回车]

输出样例1：

YES[回车]


输入样例2：

1234432[回车]

输出样例2：

NO[回车]
*/
#include <stdio.h>
#include <string.h>

int main() {
  char str[128];
  scanf("%s", str);
  int len = strlen(str);

  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}