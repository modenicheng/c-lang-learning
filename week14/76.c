/*
链表处理*
成绩	10	开启时间	2025年12月12日 星期五 00:05
折扣	0.8	折扣时间	2026年01月5日 星期一 23:59
允许迟交	否	关闭时间	2026年01月12日 星期一 23:59
编写一个函数，给定的带有头结点的单向链表 head，给定某结点的数据域值
m，将该结点移到链首。

结构的定义：

typedef struct node
{
  int num;
  struct node *next;
} SNODE;

函数的原型：SNODE *movenode(SNODE *head, int m);

其中：参数 head 是单向链表的头指针；参数 m 是某结点的num成员的值。

例如输入结点数 n=7，则将结点数值域值 m=5
的结点移动到链首。函数运行前后链表的情况如下图所示。
*/

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct sdata {
  int num;
  struct sdata *next;
} SNODE;

void movenode(SNODE *, int);

void setlink(SNODE *head, int n) {
  SNODE *p;

  while (n > 0) {
    p = (SNODE *)malloc(sizeof(SNODE));
    p->num = n;
    p->next = head->next;
    head->next = p;
    n--;
  }
}

void outlink(SNODE *head) {
  while (head->next != NULL) {
    head = head->next;
    printf("%d,", head->num);
  }
  return;
}

int main() {
  int n, m;
  SNODE *head = NULL;

  scanf("%d%d", &n, &m);
  head = (SNODE *)malloc(sizeof(SNODE));
  head->num = -1;
  head->next = NULL;
  setlink(head, n);

  movenode(head, m); /* This is waiting for you. */

  outlink(head);
  printf("\n");
  return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void movenode(SNODE *head, int m) {
  SNODE *prev;
  SNODE *next;
  SNODE *p = head->next;
  if (m <= 1) {
    return;
  }

  for (int i = 1; i < m; i++) {
    if (i == m - 1) {
      prev = p;
    }
    if (p->next == NULL) {
      return;
    }
    p = p->next;
  }

  next = p->next;
  prev->next = next;
  SNODE *first = head->next;
  head->next = p;
  p->next = first;
}
