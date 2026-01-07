/*
猜猜我是谁
成绩	10	开启时间	2025年12月12日 星期五 00:05
折扣	0.8	折扣时间	2026年01月5日 星期一 23:59
允许迟交	否	关闭时间	2026年01月12日 星期一 23:59
在指定的文本文件中包含了我需要的信息，请从指定文件中读取指定的行。如果文件中没有指定的行，则显示“Line No Error.”。如果文件不存在，则显示“File Name Error.”。

输入：
第一行为要以只读方式打开的文本文件名
第二行要读取的行号（从1开始）

输出：
文件中指定行号的内容（完整一行的内容）

数据文件
data1.txt
 	测试输入	期待的输出	时间限制	内存限制	额外进程
测试用例 1	以文本方式显示
data1.txt↵
2↵
以文本方式显示
This is Line 2.↵
1秒	64M	0
测试用例 2	以文本方式显示
data1.txt↵
1↵
以文本方式显示
This is Line 1.↵
1秒	64M	0
测试用例 3	以文本方式显示
data1.txt↵
10↵
以文本方式显示
Line No Error.↵
1秒	64M	0
测试用例 4	以文本方式显示
data.txt↵
2↵
以文本方式显示
File Name Error.↵
*/
#include <stdio.h>

int main() {
  FILE *file_ptr;
  char buffer[1024] = "";
  char file_name[128] = "";
  int line_number;
  char *status;
  scanf("%s%d", file_name, &line_number);
  file_ptr = fopen(file_name, "r");
  if (file_ptr == NULL) {
    puts("File Name Error.");
    return 1;
  }
  for (int i = 0; i < line_number; i++) {
    status = fgets(buffer, 1024, file_ptr);
  }
  if (status == NULL) {
    puts("Line No Error.");
    return 1;
  }
  printf("%s", buffer);
  fclose(file_ptr);
  return 0;
}
