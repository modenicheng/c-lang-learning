/*
68. 学生成绩排序
成绩	10	开启时间	2025年12月12日 星期五 00:05
折扣	0.8	折扣时间	2025年12月29日 星期一 23:59
允许迟交	否	关闭时间	2026年01月5日 星期一 23:59
    大家参加了期末考试，成绩出来后老师要对 n
个学生进行成绩汇总和排序。要求程序按成绩降序进行排序。在排序过程中对于成绩相同的学生，要按照输入数据的顺序进行排列。例如：有5名学生的成绩：
zhang1,90
zhang2,91
zhang3,99
zhang4,91
zhang5,98

则排序结果应该为：
zhang3,99
zhang5,98
zhang2,91
zhang4,91
zhang1,90

请注意例题中“zhang2”和“zhang4”的排列顺序。

输入：
    第一行为将要输入的学生数量n
    从第二行起后面连续 n
行数据，每行为一名学生的姓名（长度不超过20个字符，不包括空格），考试成绩（int）

输出：
    排序后的结果。每行为一名学生的姓名和成绩。
*/

#include <stdio.h>

typedef struct {
  char name[32];
  int score;
} Stu;

void read_stu(Stu *stu) {
  char c;
  int i = 0;
  int read_status = 0; // 0: 姓名, 1: 成绩
  stu->score = 0;

  while ((c = getchar()) != '\n' && c != EOF) {
    if (c == ',') {
      read_status = 1;
      stu->name[i] = '\0';
      continue;
    }

    if (read_status == 1) {
      stu->score = stu->score * 10 + (c - '0');
    } else {
      stu->name[i++] = c;
    }
  }
}

int main() {
  int n = 0;
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {
    n = n * 10 + (c - '0');
  }
  Stu stu[128];
  for (int i = 0; i < n; i++) {
    read_stu(&stu[i]);
  }
  // 排序
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (stu[j].score < stu[j + 1].score) {
        Stu temp = stu[j];
        stu[j] = stu[j + 1];
        stu[j + 1] = temp;
      }
    }
  }
  // 输出
  for (int i = 0; i < n; i++) {
    printf("%s,%d\n", stu[i].name, stu[i].score);
  }
}
