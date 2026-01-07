/*
H24：水王争霸（选作）
成绩	10	开启时间	2025年12月12日 星期五 00:05
折扣	0.8	折扣时间	2026年01月17日 星期六 23:59
允许迟交	是的	关闭时间	2026年01月17日 星期六 23:59
Description
众所周知，联盟有很多水王，他们的发贴数是如此之多，以至于必须要用高精度数才能保存。

为了迎接国庆，联盟决定举行一次水王争霸赛，比赛的规则是将这些水王截止到2030年9月30日23时59分59秒
这一刻所发的总贴数从大到小进行排序。每个水王当然都想取得尽量靠前的名次，所以他们竭尽全力，不择手段地进行灌水。

终于，激动人心的一刻到来了，2030年10月1日0时0分0秒，你作为裁判得到了每个水王的发贴数，现在，
你的任务是公正地把这些水王按照发贴数从大到小进行排序。

Input
输入的第一行是一个1到1000的整数N，表示总共有N位水王参加了争霸赛。

以下依次给出每位水王的描述，一位水王的描述占据两行，第一行为一个仅由字母和数字组成的长度不超过20
的字符串，代表这个水王的ID，第二行一个高精度的整数(非负数)，代表这个水王的发贴数。注意，这个整数
的首位没有不必要的0。

所有水王发贴数数字的总长度（注意，是总长度而不是总和）不会超过10000。除了子母、数字和必要的换行，
输入中不会出现空格等字符。

Output
依次输出按照发贴数从大到小排好序的各位水王的ID，每个ID占据单独的一行。不能有任何多余的字符。若几
个ID的发贴数相同，则按照ID的字典顺序先后排列。

        测试输入	期待的输出	时间限制	内存限制	额外进程
测试用例 1	以文本方式显示
6↵
lowai↵
1534534124561243453↵
zhouyuan↵
23453265344↵
Maolaoda↵
23442353452342↵
BuTaoCaiGuai↵
7568784573464↵
ArthurKing↵
97534892734723947↵
hyyylr↵
623893451↵

以文本方式显示
lowai↵
ArthurKing↵
Maolaoda↵
BuTaoCaiGuai↵
zhouyuan↵
hyyylr↵
1秒	320KB	0
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Data {
  char id[21];
  int num_len;
  char *num;
} Data;

// 比较函数：如果 a 的优先级低于 b（即 a 应该排在 b 后面），返回 1，触发交换
int should_swap(Data a, Data b) {
  // 1. 比较发帖数长度（长者在前）
  if (a.num_len < b.num_len)
    return 1;
  if (a.num_len > b.num_len)
    return 0;

  // 2. 长度相同时，比较发帖数内容（字典序大者在前）
  int num_cmp = strcmp(a.num, b.num);
  if (num_cmp < 0)
    return 1;
  if (num_cmp > 0)
    return 0;

  // 3. 发帖数完全相同时，比较 ID（字典序小者在前）
  // 注意：题目要求 ID 升序，所以 a.id > b.id 时需要交换
  if (strcmp(a.id, b.id) > 0)
    return 1;

  return 0;
}

int main() {
  int n;
  if (scanf("%d", &n) != 1)
    return 0;

  // 分配结构体数组
  Data *list = (Data *)malloc(sizeof(Data) * n);

  for (int i = 0; i < n; i++) {
    char temp_id[21];
    char temp_num[10001];
    scanf("%s%s", temp_id, temp_num);

    strcpy(list[i].id, temp_id);
    list[i].num_len = strlen(temp_num);
    list[i].num = (char *)malloc(list[i].num_len + 1);
    strcpy(list[i].num, temp_num);
  }

  // 冒泡排序
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (should_swap(list[j], list[j + 1])) {
        Data temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
      }
    }
  }

  // 输出结果
  for (int i = 0; i < n; i++) {
    printf("%s\n", list[i].id);
    free(list[i].num); // 释放每个字符串的内存
  }
  free(list); // 释放结构体数组内存

  return 0;
}