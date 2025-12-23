/*
61.【数列】等值数列段
成绩	10	开启时间	2025年11月28日 星期五 00:05
折扣	0.8	折扣时间	2025年12月15日 星期一 23:59
允许迟交	否	关闭时间	2025年12月22日 星期一 23:59
如果一个数列中的某一段（至少有两个元素）的各元素值均相同，则称之为等值数列段。等值数列段中元素的个数叫做等值数列段的长度。

输入：
        由N个元素组成的整数数列A（其中N<=50)

输出：
        A中长度最大的所有等值数列段的始末位置，如果没有等值数列段，则输出No
equal number list.

说明：
        始末位置是指数组下标，即0表示第一个元素。
        如果有多个同等长度的等值数列，只输出第一个等值数列的起始位置。即：当在一个LIST中出现两个等长的连续串时，答案应该是第一个等长串。

        测试输入	期待的输出	时间限制	内存限制	额外进程
测试用例 1	以文本方式显示
5↵
1 2 3 4 5↵
以文本方式显示
No equal number list.↵
1秒	64M	0
测试用例 2	以文本方式显示
6↵
1 0 1 1 1 0↵
以文本方式显示
The longest equal number list is from 2 to 4.↵
1秒	64M	0
测试用例 3	以文本方式显示
10↵
1 1 1 0 1 1 1 1 1 1↵
以文本方式显示
The longest equal number list is from 4 to 9.↵
1秒	64M	0
测试用例 4	以文本方式显示
10↵
1 4 4 4 5 6 6 6 5 6↵
以文本方式显示
The longest equal number list is from 1 to 3.↵
*/
#include <stdio.h>

int main() {
  int n;
  int arr[64];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int start = 0;
  int len = 1;

  int local_len = 1;

  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      local_len++;
    } else {
      if (local_len > len) {
        len = local_len;
        start = i - local_len + 1;
      }
      local_len = 1;
    }
  }
  if (local_len > len) {
    len = local_len;
    start = n - local_len;
  }
  if (len <= 1) {
    printf("No equal number list.\n");
  } else {
    printf("The longest equal number list is from %d to %d.\n", start,
           start + len - 1);
  }
  return 0;
}