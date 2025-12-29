/*
57大家一起做游戏
成绩	10	开启时间	2025年11月24日 星期一 00:05
折扣	0.8	折扣时间	2025年12月15日 星期一 23:59
允许迟交	否	关闭时间	2026年01月15日 星期四 23:59
幼儿园的小朋友们刚学习了如何数数，阿姨在下课时组织大家一起玩游戏。规则如下：所有的小朋友绕成一圈，顺序排号，从第一个小朋友开始报数，凡是报到固定数字（例如5）的，都退出该游戏，直到只剩下一位小朋友游戏才中止。

每个小朋友都希望自己能有更多的练习数数的机会，所以都希望成为最终被留下的那位。

现在，请大家帮小朋友们计算一下，在第一次排号的时候排到第几位才能成为最终被留下的小朋友。

输入：
        小朋友的个数（<=50）   要被练习的数字

输出：
        最终被留下的小朋友的序号

说明：
        如“要被练习的数字”是5，则每次数到5的同学要退出该游戏

In:
4 3↵

Out:
The left child is NO 1.↵
*/

#include <stdio.h>
#include <stdlib.h>

int josephus(int n, int m) {
  // 创建一个数组表示孩子们的编号
  int *children = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    children[i] = i + 1;
  }

  int len = n; // 当前剩余的孩子数量
  int idx = 0; // 当前起始位置

  // 当剩余孩子数大于1时继续
  while (len > 1) {
    // 计算要移除的孩子的位置
    idx = (idx + m - 1) % len;

    // 移除该位置的孩子（将后面的所有元素向前移动一位）
    for (int i = idx; i < len - 1; i++) {
      children[i] = children[i + 1];
    }

    // 减少剩余孩子数量
    len--;
  }

  int result = children[0];
  free(children); // 释放内存
  return result;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int result = josephus(n, m);
  printf("The left child is NO %d.\n", result);

  return 0;
}