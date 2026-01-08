/*
字符】计算子字符串个数
成绩	10	开启时间	2024年12月26日 星期四 00:05
折扣	0.8	折扣时间	2026年01月12日 星期一 23:59
允许迟交	否	关闭时间	2026年01月17日 星期六 23:59
字符串匹配问题：输入一个字符串，计算其中包含的连续给定的子字符串的个数。

例如输入字符串“ EFABCABCABCDABCDD ” , 给定子字符串“ ABC” ，输出是 3 。

函数原型： int countsub( char *str, char *subs ) 。

参数说明： str 保存输入的字符串的首地址， subs 保存需要统计的子字符串的首地址。

返回值：包含的连续子字符串的个数。
*/

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>

int countsub(char *str, char *ss);

int main() {
  char s1[1000] = {0}, s2[100] = {0};
  gets(s1);
  gets(s2);
  printf("%d\n", countsub(s1, s2));
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

int countsub(char *str, char *ss) {
  int str_len = 0;
  int count = 0;
  while (str[str_len++] != '\0')
    ;
  str_len -= 1;
  for (int i = 0; i < str_len; i++) {
    if (str[i] != ss[0]) {
      continue;
    }
    // 在这里开始计算连续字符串个数
    int ss_idx = 0;
    int local_count = 0;
    while (1) {
      if (ss[ss_idx] == '\0' || (str[i] == '\0' && ss[ss_idx] == '\0')) {
        ss_idx = 0;
        local_count++;
        count = local_count > count ? local_count : count;
        continue;
      }
      if (str[i] == '\0') {
        // 防止段错误
        break;
      }
      if (ss[ss_idx++] != str[i++]) {
        break;
      }
    }
  }
  return count;
}
