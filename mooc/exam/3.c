/*
3照相（20分）
题目内容：

总有些字符串中，存在一些重复出现的字符，请将每一个字符串中重复出现的最后一个字符替换成相应的重复数。

例如，在aaa字符串中，a重复了3次，那么就将最后一个a替换为3，即aa3

只出现1次的，当然就不用处理了，因为没有出现重复次数嘛

我们这里的字符串，在变换后长度也不会超过100的

输入格式:

aaa

输出格式：

aa3

输入样例：

abc

输出样例：

abc
*/
#include <stdio.h>
#include <string.h>

int main() {
  char str[128];
  int map[128] = {0};

  scanf("%s", str);

  int len = strlen(str);
  char result[128] = {0};

  for (int i = 0; i < len; i++) {
    int count = 0;
    int index_list[128] = {0};
    int index = 0;

    if (map[i] != 0) {
      continue;
    }

    for (int j = 0; j < len; j++) {
      if (map[j] != 0) {
        continue;
      }
      if (str[i] == str[j] && map[j] == 0) {
        index_list[index++] = j;
        count++;
      }
    }
    for (int j = 0; j < count; j++) {
      map[index_list[j]] = count;
      result[index_list[j]] = str[i];
    }
    if (count > 1) {
      result[index_list[count - 1]] = -count;
    }
  }
  for (int i = 0; i < len; i++) {
    if (result[i] < 0) {
      printf("%d", -result[i]);
    } else {
      putc(result[i], stdout);
    }
  }
  return 0;
}