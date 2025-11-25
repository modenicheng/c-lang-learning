/*
41【大学】北理工的恶龙

背景：
最近，北理工出现了一只恶龙，它长着很多
头，而且还会吐火，它将会把北理工烧成废墟，
于是，校长下令召集全校所有勇士杀死这只恶龙。要杀死这只龙，必须把它所有的头都砍掉，
每个勇士只能砍一个龙头，龙的每个头大小都不一样，一个勇士只有在身高不小于龙头的直
径的情况下才能砍下它。而且勇士们要求，砍下一个龙头必须得到和自己身高厘米数一样的学分。
校长想花 最少的学分数杀死恶龙，于是找到你寻求帮助。

输入：
第一行 龙头数 n , 勇士人数 m （ 1<=n, m<=100 ） 接下来 n 行，每行包含一个整数，
表示龙头的直径 接下来 m 行，每行包含一个整数，表示勇士的身高 l

  输出：
  如果勇士们能完成任务，输出校长需要花的最小费用；否则输 出 “bit is doomed! ”
*/
#include <stdio.h>

void sort(int *array, int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        register int tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
}

int main() {
  int heads_num;
  int mans_num;

  int head_radius[100] = {0};
  int man_height[100] = {0};

  scanf("%d %d", &heads_num, &mans_num);

  for (int i = 0; i < heads_num; i++) {
    int tmp;
    scanf("%d", &tmp);
    head_radius[i] = tmp;
  }

  for (int i = 0; i < mans_num; i++) {
    int tmp;
    scanf("%d", &tmp);
    man_height[i] = tmp;
  }

  sort(head_radius, heads_num);
  sort(man_height, mans_num);

  int points_sum = 0;
  int poped_heads = 0;

  int man_index = 0;

  for (int head_index = 0; head_index < heads_num; head_index++) {
    for (; man_index < mans_num; man_index++) {
      if (man_height[man_index] >= head_radius[head_index]) {
        points_sum += man_height[man_index];

        // Equivalent to removing the current man from available warriors to
        // avoid matching the same warrior twice
        poped_heads += 1;
        man_index += 1;
        break;
      }
    }
  }

  if (poped_heads < heads_num) {
    printf("bit is doomed!\n");
    return 0;
  }
  printf("%d\n", points_sum);

  return 0;
}