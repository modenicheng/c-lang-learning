/*
英文单词输出
成绩	10	开启时间	2025年12月19日 星期五 00:05
折扣	0.8	折扣时间	2026年01月10日 星期六 23:59
允许迟交	否	关闭时间	2026年01月20日 星期二 23:59
输入一个英文句子（20单词以内，不含标点符号或者数字特殊字符等），将其中各个单词按照字典顺序排序输出，各单词之间以空格分隔。


        测试输入	期待的输出	时间限制	内存限制	额外进程
测试用例 1	以文本方式显示
How are you↵
以文本方式显示
How are you↵
1秒	64M	0
测试用例 2	以文本方式显示
You should go home↵
以文本方式显示
You go home should↵
*/

#include <stdio.h>
#include <string.h>

int main() {
  char sentence[20][32] = {};
  int word_idx = 0;
  int char_idx = 0;
  while (1) {
    char c = getchar();
    if (c == '\n' || c == EOF) {
      sentence[word_idx++][char_idx + 1] = '\0';
      char_idx = 0;
      break;
    }
    if (c == ' ') {
      sentence[word_idx++][char_idx + 1] = '\0';
      char_idx = 0;
      continue;
    }
    sentence[word_idx][char_idx++] = c;
  }
  for (int i = 0; i < word_idx; i++) {
    for (int j = 0; j < word_idx - i - 1; j++) {
      if (strcmp(sentence[j], sentence[j + 1]) > 0) {
        char tmp[32] = "";
        strcpy(tmp, sentence[j]);
        strcpy(sentence[j], sentence[j + 1]);
        strcpy(sentence[j + 1], tmp);
      }
    }
  }
  for (int i = 0; i < word_idx - 1; i++) {
    printf("%s ", sentence[i]);
  }
  printf("%s\n", sentence[word_idx - 1]);
  return 0;
}