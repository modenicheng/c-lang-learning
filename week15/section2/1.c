/*
输出图形
成绩	10	开启时间	2025年12月19日 星期五 00:05
折扣	0.8	折扣时间	2026年01月10日 星期六 23:59
允许迟交	否	关闭时间	2026年01月20日 星期二 23:59
输入奇数 n
、图形左上角的字母，在屏幕上输出如图所示的由大写英文字母围起的图形。无论输入的字母是大写或小写，输出的字母均是大写，且字母输出是循环的，即输出
‘Z’ 后接着输出 ‘A’
。（↙表示回车）如输入的左上角字符不是字母或输入的数字不是奇数，输出“input error!
↙”



样例输入:

5 m↙



样例输出：

M N O P Q↙

N     P     R↙

O     Q    S↙

P     R     T↙

Q R S T U↙




        测试输入	期待的输出	时间限制	内存限制	额外进程
测试用例 1	以文本方式显示
5 m↵
以文本方式显示
MNOPQ↵
N P R↵
O Q S↵
P R T↵
QRSTU↵
*/
#include <stdio.h>

int main() {
  int n;
  char c;
  scanf("%d %c", &n, &c);
  if (n % 2 == 0) {
    puts("input error!");
    return 1;
  }
  if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
    puts("input error!");
    return 1;
  }
  if (c >= 'a' && c <= 'z') {
    c = c - 'a' + 'A';
  }

  // 输出图形
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || i == n - 1 || j == 0 || j == n - 1 || j == n / 2) {
        int offset = i + j;
        char ch = (c - 'A' + offset) % 26 + 'A';
        printf("%c", ch);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}