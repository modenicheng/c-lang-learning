/*
2成绩排序（10分）
题目内容：

    从键盘输入3个同学4门课的成绩，将其按平均分从高到低排序输出。

输入格式：

    输入3个同学4门课的成绩

输出格式：

    按平均分从高到低排序输出

输入样例：

89 78 80 76 88 78 75 90 99 92 100 89[回车]

输出样例：

99,92,100,89[回车]

88,78,75,90[回车]

89,78,80,76[回车]
*/
#include <stdio.h>

int main() {
  int table[3][4];
  // 读入12个成绩
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &table[i][j]);
    }
  }

  double avg[3];
  for (int i = 0; i < 3; i++) {
    int sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += table[i][j];
    }
    avg[i] = sum / 4.0;
  }

  // 排序索引
  int idx[3] = {0, 1, 2};
  // 简单冒泡排序，按平均分降序
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2 - i; j++) {
      if (avg[idx[j]] < avg[idx[j+1]]) {
        int temp = idx[j];
        idx[j] = idx[j+1];
        idx[j+1] = temp;
      }
    }
  }

  // 输出排序后的成绩
  for (int i = 0; i < 3; i++) {
    int row = idx[i];
    printf("%d,%d,%d,%d\n", table[row][0], table[row][1], table[row][2], table[row][3]);
  }

  return 0;
}