/*
69. 建立正序链表
成绩	10	开启时间	2025年12月12日 星期五 00:05
折扣	0.8	折扣时间	2025年12月29日 星期一 23:59
允许迟交	否	关闭时间	2026年01月5日 星期一 23:59
请按照输入整数的顺序建立一个带表头节点的链表。已知程序的基本结构如下，
请你编写 ins_list 函数。
*/

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "stdio.h"
#include "stdlib.h"
#include <corecrt_search.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

void outlist(PNODE);
void ins_list(PNODE h, int num);

int main() {
  int num = 1;
  PNODE head;

  head = (PNODE)malloc(sizeof(NODE));
  head->next = NULL;
  head->data = -1;

  while (num != 0) {
    scanf("%d", &num);
    if (num != 0)
      ins_list(head, num);
  }

  outlist(head);
  return 0;
}

void outlist(PNODE head) {
  PNODE p;
  p = head->next;
  while (p != NULL) {
    printf("%d\n", p->data);
    p = p->next;
  }
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void ins_list(PNODE h, int num) {
  PNODE p = h;
  while (p->next != NULL) {
    p = p->next;
  }
  PNODE newNode = (PNODE)malloc(sizeof(NODE));
  newNode->data = num;
  newNode->next = NULL;
  p->next = newNode;
}
