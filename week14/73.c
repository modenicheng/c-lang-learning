/*
链表移动
成绩	10	开启时间	2025年12月12日 星期五 00:05
折扣	0.8	折扣时间	2026年01月5日 星期一 23:59
允许迟交	否	关闭时间	2026年01月12日 星期一 23:59
编写一个函数，将给定的带有头结点的单向链表的前m个节点移到链尾。
    结构的定义：
struct node
{  int num;
             struct node *next;
}
函数的原型：struct node *monenode( struct node *head,int m )， 其中：参数head
是单向链表的头指针；参数m 是要移动的节点数。函数的返回值是单向链表的头指针。
例如当m=4时：


测试用例 1	以文本方式显示
7 4↵
以文本方式显示
5 6 7 1 2 3 4 ↵
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct numLink {
  int no;
  struct numLink *next;
} NODE;

NODE *monenode(NODE *head, int m);

void SetLink(NODE *h, int n) {
  NODE *p = NULL, *q = NULL;
  int i;
  for (i = 0; i < n; i++) {
    p = (NODE *)malloc(sizeof(NODE));
    p->no = i + 1;
    p->next = NULL;
    if (h->next == NULL) {
      h->next = p;
      q = p;
    } else {
      q->next = p;
      q = q->next;
    }
  }
  return;
}

int main() {
  int n, m;
  NODE *head = NULL, *q = NULL;
  scanf("%d%d", &n, &m);
  head = (NODE *)malloc(sizeof(NODE));
  head->no = -1;
  head->next = NULL;

  SetLink(head, n);

  q = monenode(head, m);

  do {
    printf("%d ", q->next->no);
    q = q->next;
  } while (q->next != NULL);
  printf("\n");
  return 0;
}

NODE *monenode(NODE *head, int m) {
  NODE *first_node = head->next;
  NODE *target_node = first_node;
  for (int i = 0; i < m; i++) {
    target_node = target_node->next;
  }
  head->next = target_node;
  NODE *end_node = target_node;
  while (end_node->next != NULL) {
    end_node = end_node->next;
  }
  end_node->next = first_node;

  NODE *new_end_node = first_node;
  for (int i = 0; i < m-1; i++) {
    new_end_node = new_end_node->next;
  }
  new_end_node->next=NULL;
  return head;
}
