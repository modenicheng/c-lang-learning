/*
为整数编号
成绩	10	开启时间	2025年12月12日 星期五 00:05
折扣	0.8	折扣时间	2026年01月5日 星期一 23:59
允许迟交	否	关闭时间	2026年01月12日 星期一 23:59
使用以下结构
struct nn
{
   int no;
   int num;
};

建立一个结构数组，从键盘输入若干个整数，保存在数组元素的num成员中，并根据输入的数按从小到大进行编号，将编号保存在no成员中。按整数的输入顺序输出整数及其编号。输入的整数不超过100个，每个整数的绝对值不大于1000，输入时以空格分隔整数。
例如输入：4 3 6 8 2 3 9
输出：
      4 4
      3 2
      6 5
      8 6
      2 1
      3 3
      9 7
要求：当两个整数相等时，整数的排列顺序由输入的先后次序决定。例如：输入的第2个整数为3，第6个整数也为3，则将先输入的整数3的编号在前，后输入的整数3的编号在后。编写函数完成为整数编号。

函数原型：int number( char *str, struct nn a[] );
其中：str：保存以字符串方式接收的键盘输入，
          a： 保存整数及编号的结构数组的首地址，
函数返回值：已输入的整数的个数。




        测试输入	期待的输出	时间限制	内存限制	额外进程
测试用例 1	以文本方式显示
4 3 6 8 2 3 9↵
以文本方式显示
4 4↵
3 2↵
6 5↵
8 6↵
2 1↵
3 3↵
9 7↵
1秒	64M	0
测试用例 2	以文本方式显示
1 1 1 1 1↵
以文本方式显示
1 1↵
1 2↵
1 3↵
1 4↵
1 5↵
*/

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */
#include <stdio.h>
#include <stdlib.h>
struct nn {
  int no;
  int num;
};

typedef struct nn DATA;

int number(char *, DATA[]);

int main() {
  DATA b[100];
  char sa[500];
  int i, n;
  gets(sa);
  // fgets(sa, 500, stdin);
  n = number(sa, b);
  for (i = 0; i < n; i++)
    printf("%d %d\n", b[i].num, b[i].no);
  return 0;
}
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

int parse_numbers(char *str, int list[128]) {
  int index = 0;
  int tmp = 0;
  int i = 0;
  int sign = 1;
  int in_number = 0;  // 标记是否正在解析数字

  for (; str[i] != '\n' && str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      if (in_number) {
        list[index++] = tmp * sign;
        tmp = 0;
        sign = 1;
        in_number = 0;
      }
      continue;
    }
    if (str[i] == '-') {
      if (in_number) {
        // 当前数字结束，开始新数字
        list[index++] = tmp * sign;
        tmp = 0;
      }
      sign = -1;
      in_number = 1;
      continue;
    }
    // 数字字符
    int digit = str[i] - '0';
    tmp = tmp * 10 + digit;
    in_number = 1;
  }

  // 处理最后一个数字（如果有）
  if (in_number) {
    list[index++] = tmp * sign;
  }

  return index;  // 返回实际解析的数字个数
}

int number(char *str, DATA res[]) {
  int list[128] = {0};
  int total = parse_numbers(str, list);

  if (total <= 0) return 0;

  // 计数数组：索引0对应-1000，索引2000对应1000
  int count[2001] = {0};

  // 第一步：统计每个数字出现次数
  for (int i = 0; i < total; i++) {
    int num = list[i];
    // 将值映射到0-2000范围
    int index = num + 1000;
    if (index >= 0 && index <= 2000) {
      count[index]++;
    }
  }

  // 第二步：计算前缀和（每个桶的起始位置）
  // prefix[i] 表示小于等于(i-1000)的元素数量
  int prefix[2001] = {0};
  prefix[0] = count[0];
  for (int i = 1; i <= 2000; i++) {
    prefix[i] = prefix[i-1] + count[i];
  }

  // 第三步：从后向前遍历，稳定分配位置
  int position[100] = {0};  // 存储每个元素在排序后的位置

  for (int i = total - 1; i >= 0; i--) {
    int num = list[i];
    int index = num + 1000;

    // 当前元素在排序后数组中的位置（从0开始）
    int sorted_pos = prefix[index] - 1;
    position[i] = sorted_pos;

    // 更新前缀和，为相同值的下一个元素腾出位置
    prefix[index]--;
  }

  // 第四步：分配编号并填充结果数组
  for (int i = 0; i < total; i++) {
    // 编号从1开始
    res[i].no = position[i] + 1;
    res[i].num = list[i];
  }

  return total;
}

