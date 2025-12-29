/*
58. 【大学】寻找矩阵的鞍点
成绩	10	开启时间	2025年11月28日 星期五 00:05
折扣	0.8	折扣时间	2025年12月15日 星期一 23:59
允许迟交	否	关闭时间	2025年12月22日 星期一 23:59
二维数组中的鞍点，即该位置上的元素是所在行上的最大值，是所在列上的最小值。

二维数组也可能没有鞍点。

输入一个二维数组的行数n，列数m，二维数组的诸元素值；输出数组的鞍点，以及鞍点所在的行列号。

输入：第一行为矩阵的行数和列数，从第二行开始，为矩阵本身（假设输入的矩阵只有0和1个鞍点）
    3 4
    1 3 5 3
    2 3 4 1
    3 2 6 7

输出：
     Point: a[1][2] == 4   (下标从0开始)

测试用例 1
3 4↵
1 3 5 3↵
2 3 4 1↵
3 2 6 7↵

Point:a[1][2]==4↵

测试用例 2
3 4↵
1 2 3 4↵
8 4 3 6↵
9 4 5 1↵

No Point↵
*/

#include <stdio.h>

int main() {
  int m, n;
  scanf("%d%d", &m, &n);

  int matrix[128][128];
  int row_max_marks[128][128];
  // Here `r` stands for `row_index`, and `c` stands for `column_index`.
  for (int r = 0; r < m; r++) {
    int row_max = -2147483648;
    for (int c = 0; c < n; c++) {
      int tmp;
      scanf("%d", &tmp);
      matrix[r][c] = tmp;

      if (tmp > row_max) {

        // clear the current minimum value marks.
        for (int i = 0; i < n; i++) {
          row_max_marks[r][i] = 0;
        }
        row_max = tmp;
      }

      // here add all possible minimum value marks
      if (tmp >= row_max) {
        row_max_marks[r][c] = 1;
      }
    }
  }

  for (int r = 0; r < m; r++) {
    for (int c = 0; c < n; c++) {
      int min_row_index = 0;
      if (row_max_marks[r][c] == 1) {
        int min_col_value = 2147483647;

        // scan for column minimum value
        for (int i = 0; i < m; i++) {
          if (matrix[i][c] < min_col_value) {
            min_col_value = matrix[i][c];
            min_row_index = i;
          }
        }
        if (min_row_index == r) {
          printf("Point:a[%d][%d]==%d\n", r, c, matrix[r][c]);
          return 0;
        }
      }
    }
  }
  printf("No Point\n");
  return 0;
}