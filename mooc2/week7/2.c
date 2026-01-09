/**2学生成绩（15分）
题目内容：

    定义结构体，存储学生学号和三门课成绩及平均分，初始化成绩如下{{1,90,80,70}，{2,85,75,95}，{3,88,84,65}}，输入学号，输出平均分，输入max，输出最高分id。

输入格式：

    输入学号或max

输出格式：

    输出平均分或最高分id



输入样例1：

1[回车]

输出样例1：

80[回车]

输入样例2：

max[回车]

输出样例2：

2[回车]

输入样例3：

4[回车]

输出样例3：

0[回车] */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 定义学生结构体
typedef struct {
  int id;
  int scores[3];
  double average;
} Student;

int main() {
  // 初始化学生数据
  Student students[3] = {
      {1, {90, 80, 70}, 0}, {2, {85, 75, 95}, 0}, {3, {88, 84, 65}, 0}};

  // 计算每个学生的平均分
  for (int i = 0; i < 3; i++) {
    double sum = 0;
    for (int j = 0; j < 3; j++) {
      sum += students[i].scores[j];
    }
    students[i].average = sum / 3.0;
  }

  // 读取输入
  char input[32];
  if (fgets(input, sizeof(input), stdin) == NULL) {
    return 1;
  }

  // 移除换行符
  size_t len = strlen(input);
  if (len > 0 && input[len - 1] == '\n') {
    input[len - 1] = '\0';
    len--;
  }

  // 判断输入是否为"max"
  if (strcmp(input, "max") == 0) {
    // 查找最高平均分的学生
    int max_id = 0;
    double max_average = -1.0;

    for (int i = 0; i < 3; i++) {
      if (students[i].average > max_average) {
        max_average = students[i].average;
        max_id = students[i].id;
      }
    }

    printf("%d\n", max_id);
  } else {
    // 尝试解析为学号
    // 检查输入是否都是数字
    int is_number = 1;
    for (size_t i = 0; i < len; i++) {
      if (!isdigit(input[i])) {
        is_number = 0;
        break;
      }
    }

    if (is_number && len > 0) {
      int id = atoi(input);
      int found = 0;

      // 查找对应学号的学生
      for (int i = 0; i < 3; i++) {
        if (students[i].id == id) {
          // 输出平均分（题目要求输出整数，但平均分可能是小数）
          // 根据样例，平均分80应该是整数，直接输出整数部分
          printf("%d\n", (int)students[i].average);
          found = 1;
          break;
        }
      }

      if (!found) {
        // 学号不存在，输出0
        printf("0\n");
      }
    } else {
      // 输入既不是"max"也不是合法数字，输出0
      printf("0\n");
    }
  }

  return 0;
}