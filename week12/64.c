/*
64. 【大学】恭喜发财 利是窦来
成绩	10	开启时间	2025年12月5日 星期五 00:05
折扣	0.8	折扣时间	2025年12月22日 星期一 23:59
允许迟交	否	关闭时间	2025年12月29日 星期一 23:59
    在中国，过春节时人们有给孩子压岁钱（粤语称为利是）的习俗。

最早的压岁钱出现于汉代，又叫压胜钱，并不在市面上流通，而是铸成钱币形式的玩赏物，有避邪的功能。
钱币正面一般铸有“万岁千秋”、“去殃除凶”等吉祥话和龙凤、龟蛇、双鱼等吉祥图案。

据说嘉兴府有一户姓管的人家，夫妻老年得子，十分珍爱。在年三十晚上，为防止“祟”来侵扰一直逗孩子玩，
小孩用红纸包了八枚铜钱，包了又拆，拆了又包，睡下以后，包着的八枚铜钱就放在枕边。半夜里，一阵阴风吹过，
黑矮的小人正要用他的白手摸孩子的头，突然孩子枕边迸出一道金光，祟尖叫着逃跑了。

于是这件事传扬开来，大家纷纷效仿，在大年夜用红纸包上钱给孩子，祟就不敢再来侵扰了。因而人们把这种钱叫“压祟钱”，
“祟”与“岁”发音相同，日久天长，就被称为
“压岁钱”了。

现在有 N
个人，他们都有小孩，春节来了，他们要发压岁钱给朋友的小孩，而他们自己的小孩也会收到压岁钱。
为了简单，他们在发压岁钱的时候，使用以下的计算方法，譬如某甲有 100
块，它要给另外三个人的小孩发压岁钱， 则每个小孩会分到 100/3 = 33 块，剩余的 1
块就不发了。

给你这 N 个人的信息，以及他们把压岁钱发给了谁的小孩，
请你计算他们每个人的小孩收到的压岁钱和他们发出去的压岁钱的差额是多少。

输入
第 1 行:	一个整数 N（2 <= N <= 10)
第 2..N+1 行:	每行是一个人名，每个名字不超过 14 个字符
第 N+2..结束:	N 组按照以下规则组织的数据：
组中的第一行为送出压岁钱的人名。
第二行包括两个数字，第一个是该人有多少钱（0~2000），第二个是它要把钱发给几个人的小孩，用
NGi 表示(0 ≤ NGi ≤ N-1). 如果 NGi 为非零，则下面的 NGi
行会列出接受压岁钱的人的名字。 输入样例
5
dave
laura
owen
vick
amr
dave
200 3
laura
owen
vick
owen
500 1
dave
amr
150 2
vick
owen
laura
0 2
amr
vick
vick
0 0
输出格式
输出为 N
行，每行上是一个人名与它收到和送出的压岁钱之差额，这两项之间有一个空格。这 N
行的顺序应该和输入中第 2~N+1 行的顺序相同。

输出样例
dave 302
laura 66
owen -359
vick 141
amr -150
*/
#include <stdio.h>
#include <string.h>

int main() {
  // 输入总共有N个人类
  int N;
  scanf("%d", &N);
  char s[N][15];
  // N个人的名字
  for (int i = 0; i < N; i++) {
    scanf("%s", s[i]);
  }
  // 创建一个int数组来记录最终净利润
  int end_money[N];
  for (int i = 0; i < N; i++) {
    end_money[i] = 0;
  }
  // 对每一个分钱的人做的同样操作进行循环
  for (int i = 0; i < N; i++) {
    // 定位是哪个富翁在分钱
    char scan[15];
    scanf("%s", scan);
    int j;
    for (j = 0; j < N; j++) {
      if (!strcmp(scan, s[j])) {
        break;
      } else {
        continue;
      }
    }
    int give_money, give_number;
    scanf("%d %d", &give_money, &give_number); // 输入分了多少钱，分给多少人
    // 平均到每个人头上是多少
    // 有剩下的记作自己的收入
    int every = 0;
    if (give_number != 0) {
      every = give_money / give_number;
      end_money[j] += give_money % give_number;
      end_money[j] -= give_money;
    } else {
      end_money[j] += give_money;
    }
    // 输入收红包的小可莉
    for (int k = 0; k < give_number; k++) {
      char receive[15];
      scanf("%s", receive);
      // 核对对应的是哪一个小可莉
      int m;
      for (m = 0; m < N; m++) {
        if (!strcmp(receive, s[m])) {
          break;
        } else {
          continue;
        }
      }
      end_money[m] += every;
    }
  }
  // 输出
  for (int i = 0; i < N; i++) {
    printf("%s %d\n", s[i], end_money[i]);
  }
  return 0;
}