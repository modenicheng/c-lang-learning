/**
1解析字符串（15分）
题目内容：

    输入一个字符串，要求将其中的字母‘n’理解为回车符号’\n’，模拟文件缓冲区读取的数据，并按替换后的数据流解析出其中包括的字符串。（即通过'n'分割两个字符串）

输入格式：

    一个字符串

输出格式：

    其中包括的字符串

输入样例：

abcnde[回车]

输出样例：

abc[回车]

de[回车]

时间限制：500ms内存限制：32000kb */
#include <stdio.h>
#include <string.h>

int main() {
  char input[10001];
  fgets(input, sizeof(input), stdin);
  // 移除换行符
  size_t len = strlen(input);
  if (len > 0 && input[len - 1] == '\n') {
    input[len - 1] = '\0';
    len--;
  }

  char buffer[1001];
  int buf_index = 0;

  for (int i = 0; i < len; i++) {
    char c = input[i];
    if (c == 'n') {
      // 遇到'n'，输出当前缓冲区内容（可能为空）
      buffer[buf_index] = '\0';
      if (buf_index != 0) {
        printf("%s\n", buffer);
      }
      // 重置缓冲区
      buf_index = 0;
    } else {
      buffer[buf_index++] = c;
    }
  }
  // 输出最后一部分（如果有）
  buffer[buf_index] = '\0';
  if (buf_index != 0) {
    printf("%s\n", buffer);
  }

  return 0;
}