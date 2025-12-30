/*
3查找数（15分）
题目内容：

    用指针方法，在一个一维数组int
a[10]的元素中，查找给定的数，若找到则输出该数，若没找到，输出No。

输入格式：

    第一行：10个整数，空格隔开

    第二行：要查找的数

输出格式：

    找到的数orNo



输入样例1：

11 22 43 56 78 90 76 4 2 10[回车]

43[回车]

输出样例1：

43[回车]


输入样例2：

1 8 3 4 5 6 2 1 7 9[回车]

10[回车]

输出样例2：

No[回车]
*/
#include <stdio.h>

int main() {
  int arr[10];
  int num;
  for (int i = 0; i < 10; i++) {
    scanf("%d", &arr[i]);
  }
  scanf("%d", &num);

  int *res = NULL;
  for (int i = 0; i < 10; i++) {
    if (arr[i] == num) {
      res = &arr[i];
    }
  }
  if (res == NULL) {
    printf("No\n");
  } else {
    printf("%d\n", *res);
  }
  return 0;
}