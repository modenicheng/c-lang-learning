/**
3字符串（15分）
从键盘输入一个字符串，按从左向右顺序分解成连续字符组成的几个子串，并顺序输出这些子串。例如

输入：bxyzacdefgh345x

输出：

xyz

cdefgh

345

时间限制：500ms内存限制：32000kb */
#include <stdio.h>
#include <string.h>

int main() {
  char inp[4096] = "";
  fgets(inp, 4096, stdin);
  int len = strlen(inp);
  if (len > 0 && inp[len-1] == '\n') inp[--len] = '\0';
  int in_str = 0;
  char sub_str[4096] = "";
  int sub_idx = 0;

  for (int i = 0; i < len - 1; i++) {
    if (inp[i] == inp[i + 1] - 1) {
      in_str = 1;
      sub_str[sub_idx++] = inp[i];
    } else if (in_str == 1) {
      in_str = 0;
      sub_str[sub_idx++] = inp[i];
      sub_str[sub_idx] = '\0';
      sub_idx = 0;
      puts(sub_str);
    }
  }
  if (in_str == 1 && len > 0) {
    sub_str[sub_idx++] = inp[len-1];
    sub_str[sub_idx] = '\0';
    puts(sub_str);
  }
  return 0;
}