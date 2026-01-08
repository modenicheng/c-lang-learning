/*
链表
成绩	10	开启时间	2025年12月19日 星期五 00:05
折扣	0.8	折扣时间	2026年01月10日 星期六 23:59
允许迟交	否	关闭时间	2026年01月20日 星期二 23:59
建立一个链表，每个结点存储一个学生的姓名和成绩，将a,b,c三个结点按照分数由高到低链接起来，然后输出，编写链表结点连接函数connect。

链表的结构定义方式如下：

struct Node {

    char *name;

    int  score;

    struct Node *next;

};

请你完成以下函数代码

struct Node * connect(struct Node *x, struct Node *y, struct Node *z)
{

}
*/

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

struct Node {
  char *name;
  int score;
  struct Node *next;
};

struct Node *connect(struct Node *x, struct Node *y, struct Node *z);

int main(int argc, char *argv[]) {
  struct Node a, b, c, *p;

  a.name = "LiPing";
  b.name = "LiuHai";
  c.name = "FengYun";
  scanf("%d,%d,%d", &a.score, &b.score, &c.score);
  p = connect(&a, &b, &c);
  printf("%s-%d\n", p->name, p->score);
  p = p->next;
  printf("%s-%d\n", p->name, p->score);
  p = p->next;
  printf("%s-%d\n", p->name, p->score);
  return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

struct Node *connect(struct Node *x, struct Node *y, struct Node *z) {
    // 确定最高、中间、最低分数的节点
    struct Node *highest = NULL;
    struct Node *middle = NULL;
    struct Node *lowest = NULL;

    // 比较三个节点的分数，确定顺序
    if (x->score >= y->score && x->score >= z->score) {
        highest = x;
        if (y->score >= z->score) {
            middle = y;
            lowest = z;
        } else {
            middle = z;
            lowest = y;
        }
    } else if (y->score >= x->score && y->score >= z->score) {
        highest = y;
        if (x->score >= z->score) {
            middle = x;
            lowest = z;
        } else {
            middle = z;
            lowest = x;
        }
    } else {
        highest = z;
        if (x->score >= y->score) {
            middle = x;
            lowest = y;
        } else {
            middle = y;
            lowest = x;
        }
    }

    // 按照从高到低的顺序链接节点
    highest->next = middle;
    middle->next = lowest;
    lowest->next = NULL;

    return highest;
}