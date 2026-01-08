/**
【测试题2】字符菱形
成绩	10	开启时间	2025年12月26日 星期五 00:05
折扣	0.8	折扣时间	2026年01月12日 星期一 23:59
允许迟交	否	关闭时间	2026年01月17日 星期六 23:59
大写字母空心菱形

输入菱形的边长和起始字母，输出大写字母空心菱形。输出的字母是循环的，即递增到字母
'Z' 以后输出 'A'。

测试用例 1	以文本方式显示
4 D↵
以文本方式显示
   D↵
  E O↵
 F   N↵
G     M↵
 H   L↵
  I K↵
   J↵
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// 获取下一个大写字母，'Z'后回到'A'
char next_char(char c) {
  if (c == 'Z') {
    return 'A';
  }
  return c + 1;
}

int main() {
  int n;
  char start_ch;

  // 读取边长和起始字母
  if (scanf("%d %c", &n, &start_ch) != 2) {
    return 1;
  }

  // 确保起始字母是大写
  start_ch = toupper(start_ch);

  // 处理n=1的特殊情况
  if (n == 1) {
    printf("%c\n", start_ch);
    return 0;
  }

  int rows = 2 * n - 1; // 总行数
  int cols = 2 * n - 1; // 总列数
  int center = n - 1;   // 中心列索引
  char current = start_ch;

  // 分配二维数组
  char **grid = (char **)malloc(rows * sizeof(char *));
  for (int i = 0; i < rows; i++) {
    grid[i] = (char *)malloc(cols * sizeof(char));
    for (int j = 0; j < cols; j++) {
      grid[i][j] = ' '; // 初始化为空格
    }
  }

  // 计算总轮廓点数并生成字母序列
  int total_points = 4 * n - 4; // 2*rows-2
  char *sequence = (char *)malloc(total_points * sizeof(char));
  char seq_char = start_ch;
  for (int i = 0; i < total_points; i++) {
    sequence[i] = seq_char;
    seq_char = next_char(seq_char);
  }

  // 填充菱形轮廓
  for (int i = 0; i < rows; i++) {
    int dist = i;
    if (i >= n) {
      dist = rows - 1 - i;
    }
    int left_col = center - dist;
    int right_col = center + dist;

    if (left_col == right_col) {
      // 顶部或底部：只有一个点
      if (i == 0) {
        // 顶部点
        grid[i][left_col] = sequence[0];
      } else {
        // 底部点
        grid[i][left_col] = sequence[rows - 1];
      }
    } else {
      // 左右两个轮廓点
      // 左轮廓点：从上到下，序列索引1到rows-2
      grid[i][left_col] = sequence[i];  // i从1到rows-2
      // 右轮廓点：从上到下，序列索引total_points-i递减
      grid[i][right_col] = sequence[total_points - i];  // i从1到rows-2
    }
  }

  free(sequence);

  // 输出结果
  for (int i = 0; i < rows; i++) {
    // 去除每行末尾的空格
    int last_non_space = -1;
    for (int j = cols - 1; j >= 0; j--) {
      if (grid[i][j] != ' ') {
        last_non_space = j;
        break;
      }
    }

    if (last_non_space >= 0) {
      for (int j = 0; j <= last_non_space; j++) {
        putchar(grid[i][j]);
      }
    }
    putchar('\n');

    free(grid[i]); // 释放每行内存
  }
  free(grid); // 释放行指针数组

  return 0;
}