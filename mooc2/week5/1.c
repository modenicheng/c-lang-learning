/*
1输出指定学生成绩（15分）
题目内容：

    从键盘输入3个同学4门课的成绩，输出指定同学的成绩和平均分。

输入格式：

    输入3个同学4门课的成绩

输出格式：

    输出指定同学的成绩和平均分

输入样例：

89 78 80 76 88 78 75 90 99 92 100 89[回车]

1[回车]

输出样例：

89 78 80 76[回车]

80.75[回车]
*/
#include <stdio.h>

int main() {
  int table[3][4];
  for (int i  = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &table[i][j]);
    }
  }
  int index;
  scanf("%d", &index);

  // 检查索引是否在有效范围（1-3）
  if (index < 1 || index > 3) {
    // 索引无效，可以返回或处理错误
    return 1;
  }

  // 索引从1开始，转换为从0开始
  int *p = table[index - 1];
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    printf("%d", p[i]);
    sum += p[i];
    if (i < 3) printf(" ");
  }
  printf("\n");

  // 计算平均分，如果是整数则输出整数，否则保留两位小数
  double average = sum / 4.0;
  if (average == (int)average) {
    printf("%d\n", (int)average);
  } else {
    printf("%.2f\n", average);
  }
}