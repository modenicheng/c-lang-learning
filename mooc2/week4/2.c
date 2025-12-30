/*
2排序（10分）
题目内容：

    用指针方法，将一维数组int a[10] 中元素按从小到大顺序输出。

输入格式：

    10个整数，空格隔开

输出格式：

    排序后的10个数，逗号隔开

输入样例：

12 34 56 43 7 89 81 11 33 90[回车]

输出样例：

7,11,12,33,34,43,56,81,89,90[回车]
*/
#include <stdio.h>

int main() {
  int arr[10];
  int *ptrs[10];
  for (int i = 0; i < 10; i++) {
    scanf("%d", &arr[i]);
    ptrs[i] = &arr[i];
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10 - i - 1; j++) {
      if (*ptrs[j] > *ptrs[j + 1]) {
        int *temp = ptrs[j];
        ptrs[j] = ptrs[j + 1];
        ptrs[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    printf("%d%c", *ptrs[i], i == 9 ? '\n' : ',');
  }
  return 0;
}