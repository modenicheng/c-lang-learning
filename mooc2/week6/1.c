/**
1统计字符串出现次数（10分）
题目内容：

    从键盘输入两个字符串，输出第二个串在第一个串中出现的次数。如果没有，输出“No”。

输入格式：

    输入两个字符串

输出格式：

    输出第二个串在第一个串中出现的次数。

    如果没有，输出 No

输入样例1：

This is his book[回车]

is[回车]
输出样例1：

3[回车]

输入样例2：

This is my book[回车]

at[回车]

输出样例2：

No[回车]

时间限制：500ms内存限制：32000kb */
#include <stdio.h>
#include <string.h>

int main() {
  char str[1024];
  char substr[1024];
  fgets(str, 1024, stdin);
  fgets(substr, 1024, stdin);

  // 移除fgets读取的换行符
  str[strcspn(str, "\n")] = '\0';
  substr[strcspn(substr, "\n")] = '\0';

  int len_str = strlen(str);
  int len_sub = strlen(substr);
  int count = 0;

  // 如果子串为空，直接输出No
  if (len_sub == 0) {
    printf("No\n");
    return 0;
  }

  // 遍历主字符串
  for (int i = 0; i <= len_str - len_sub; i++) {
    int match = 1;
    // 检查子串是否匹配
    for (int j = 0; j < len_sub; j++) {
      if (str[i + j] != substr[j]) {
        match = 0;
        break;
      }
    }
    if (match) {
      count++;
    }
  }

  // 输出结果
  if (count > 0) {
    printf("%d\n", count);
  } else {
    printf("No\n");
  }

  return 0;
}