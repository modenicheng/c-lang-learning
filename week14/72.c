/*
买东西*
成绩	10	开启时间	2025年12月12日 星期五 00:05
折扣	0.8	折扣时间	2026年01月5日 星期一 23:59
允许迟交	否	关闭时间	2026年01月12日 星期一 23:59
有 3 种商品在 N
个商店出售，同样商品在不同商店的售价各不相同，假定商店名称用数字1、2、3、4、......来表示，商品的名称用A、B、C来表示。

如果按照最先购买商品A、再购买商品B、最后购买商品C的顺序购买商品，且在一个商店只能购买一种商品。请编程设计一个购物方案，用最少的钱购得
3 种商品。

编写求购物方案的函数：int findm( int n, int price[][3], BUY scheme[] );

其中：n 是商店数量，gp[][] 是保存商品价格表的数组名，schm[ ]
是保存求得购物方案的数组名；函数的返回值是购得 3 种商品的总钱数。

保存求得购物方案的是一个结构类型为 BUY 的结构数组，结构 BUY 的定义如下：

typedef struct buy
{
char gname; // 商品名称
int sname; // 商店名称
int gprice; // 商品价格
} BUY;

例如：有 3 种商品，在 5 个商店出售，商品在各商店的售价如下表所示：

A	B	C
1	12	29	9
2	10	30	8
3	11	35	12
4	10	28	11
5	12	31	8
程序运行后输出是：

Total Money are: 46
Goods-Name Shop-Name Goods-Price
A: 2 10
B: 4 28
C: 5 8

其中第一行是购物的总钱数，第二行是购物方案的表头，从第三行起每行为一种商品名和商店名、该种商品在该店的价格。商品名用大写英文字母表示,从
A 开始，商店名用数字表示，从 1
开始。购物方案的输出顺序按商品名英文字母升序排列。

注意：只提交自编的函数
findm，不要提交主函数。给定的程序已经控制好了输出的格式，你只要你的方案按要求放入数组即可

预设代码

```c
#include <stdio.h>

typedef struct buy
{  char  gname;
   int   sname;
   int   gprice;
} BUY;
int main( )
{  int i, j, n;
   int min, price[10][3];
   int findm( int n, int price[][3], BUY scheme[] );

   static BUY scheme[3]={ {'A', 0, 0}, {'B', 0, 0}, {'C', 0, 0} };

   scanf( "%d", &n );
   for( i = 0; i < n; i++ )
    for( j = 0; j < 3; j++ )
       scanf( "%d", &price[i][j] );

   min = findm( n, price, scheme );

   printf("Total Money are : %d\nGoods-Name  Shop-Name  Goods-Price\n", min );
   for ( i=0; i < 3; i++ )
       printf("         %c:%10d%13d\n", scheme[i].gname, scheme[i].sname,
scheme[i].gprice ); return 0;
}
```

测试用例 1
5↵
12  29  9↵
10  30  8↵
11  35  12↵
10  28  11↵
12  31  8↵
↵
以文本方式显示
Total Money are : 46↵
Goods-Name  Shop-Name  Goods-Price↵
         A:         2           10↵
         B:         4           28↵
         C:         5            8↵
1秒	64M	0
测试用例 2
3↵
1 2 3↵
1 2 3↵
1 2 3↵
以文本方式显示
Total Money are : 6↵
Goods-Name  Shop-Name  Goods-Price↵
         A:         1            1↵
         B:         2            2↵
         C:         3
*/

#include <stdio.h>

typedef struct buy {
  char gname;
  int sname;
  int gprice;
} BUY;
int main() {
  int i, j, n;
  int min, price[10][3];
  int findm(int n, int price[][3], BUY scheme[]);

  static BUY scheme[3] = {{'A', 0, 0}, {'B', 0, 0}, {'C', 0, 0}};

  scanf("%d", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j < 3; j++)
      scanf("%d", &price[i][j]);

  min = findm(n, price, scheme);

  printf("Total Money are : %d\nGoods-Name  Shop-Name  Goods-Price\n", min);
  for (i = 0; i < 3; i++)
    printf("         %c:%10d%13d\n", scheme[i].gname, scheme[i].sname,
           scheme[i].gprice);
  return 0;
}

int findm(int n, int price[][3], BUY scheme[]) {
  int min_total = 1e9; // 初始化为一个很大的数
  int bestA = 0, bestB = 0, bestC = 0;

  // i, j, k 分别代表购买商品 A, B, C 的商店索引（从0开始）
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i)
        continue; // 同一个商店只能买一种商品
      for (int k = 0; k < n; k++) {
        if (k == i || k == j)
          continue; // 同一个商店只能买一种商品

        int current_sum = price[i][0] + price[j][1] + price[k][2];

        // 如果当前组合更省钱，则记录下来
        if (current_sum < min_total) {
          min_total = current_sum;
          bestA = i;
          bestB = j;
          bestC = k;
        }
      }
    }
  }

  // 将最优方案填入 scheme 数组
  // 注意：商店名称是从 1 开始的，所以要索引 + 1
  scheme[0].gname = 'A';
  scheme[0].sname = bestA + 1;
  scheme[0].gprice = price[bestA][0];

  scheme[1].gname = 'B';
  scheme[1].sname = bestB + 1;
  scheme[1].gprice = price[bestB][1];

  scheme[2].gname = 'C';
  scheme[2].sname = bestC + 1;
  scheme[2].gprice = price[bestC][2];

  return min_total;
}