/**
1字母加密对照表（15分）
题目内容：

    先定义一张字母加密对照表。将需要加密的一行文字输入加密程序，程序根据加密表中的对应关系，可以很简单地将输入的文字加密输出，对于表中未出现的字符则不加密。

字母加密对照表


输入 a b c d e i k ; w

输出 d w k ; i a b c e

输入格式：

  字母

输出格式：

  字母

输入样例1：

abc[回车]

输出样例1：

dwk[回车]


输入样例2：

de[回车]

输出样例2：

;i[回车] */

#include <stdio.h>
#include <string.h>

// 加密函数：根据对照表加密字符
char encrypt_char(char c) {
  switch (c) {
  case 'a':
    return 'd';
  case 'b':
    return 'w';
  case 'c':
    return 'k';
  case 'd':
    return ';';
  case 'e':
    return 'i';
  case 'i':
    return 'a';
  case 'k':
    return 'b';
  case ';':
    return 'c';
  case 'w':
    return 'e';
  default:
    return c; // 表中未出现的字符不加密
  }
}

int main() {
  char input[1024];

  // 读取一行输入
  if (fgets(input, sizeof(input), stdin) == NULL) {
    return 1;
  }

  // 移除可能的换行符
  size_t len = strlen(input);
  if (len > 0 && input[len - 1] == '\n') {
    input[len - 1] = '\0';
    len--;
  }

  // 加密并输出每个字符
  for (size_t i = 0; i < len; i++) {
    putchar(encrypt_char(input[i]));
  }
  putchar('\n');

  return 0;
}