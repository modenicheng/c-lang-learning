/**
SY4-4 链表
成绩	10	开启时间	2024年12月26日 星期四 00:05
折扣	0.8	折扣时间	2026年01月12日 星期一 23:59
允许迟交	否	关闭时间	2026年01月17日 星期六 23:59
预设代码中建立了一个带有头结点的单向链表。
编写一个函数，将链表中数值域的数值为偶数的节点移到链表尾部。
如果偶数节点多于一个,则连接到链表尾部节点的先后顺序按原来的顺序。
结构的定义：
struct node
{
int num;
struct node *next;
}
typedef struct node NODE;
函数的原型：NODE *MoveNode( NODE *head )。
其中：参数 head 是单向链表的头指针。函数的返回值是单向链表的头指针。
运行时输入有一行，输入各个节点的数值域的值，输入-1时结束。
例如链表节点数值成员值为：15 6 7 21 2 13 24 -1 //-1 是节点输入结束标志
输出：15 7 21 13 6 2 24 */
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>
typedef struct numLink {
  int no;
  struct numLink *next;
} NODE;

NODE *MoveNode(NODE *);

void SetLink(NODE *h) {
  NODE *p = NULL, *q = NULL;
  int m;
  while (1) {
    scanf("%d", &m);
    if (m == -1)
      return;
    p = (NODE *)malloc(sizeof(NODE));
    p->no = m;
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
  NODE *head = NULL, *q = NULL;
  head = (NODE *)malloc(sizeof(NODE));
  head->no = -1;
  head->next = NULL;

  SetLink(head);
  q = MoveNode(head);
  do {
    printf("%d ", q->next->no);
    q = q->next;
  } while (q->next != NULL);
  printf("\n");
  return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */


NODE *MoveNode(NODE *head) {
    // 如果链表为空或只有一个节点，直接返回
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // 创建偶数链表的虚拟头节点
    NODE evenHead;
    evenHead.next = NULL;
    NODE *evenTail = &evenHead;

    NODE *prev = head;
    NODE *curr = head->next;

    // 遍历原链表
    while (curr != NULL) {
        if (curr->no % 2 == 0) {
            // 偶数节点：从原链表移除，添加到偶数链表
            prev->next = curr->next;
            evenTail->next = curr;
            evenTail = curr;
            curr->next = NULL;  // 断开连接
            curr = prev->next;   // 移动到下一个节点
        } else {
            // 奇数节点：保留在原链表
            prev = curr;
            curr = curr->next;
        }
    }

    // 将偶数链表附加到奇数链表尾部
    prev->next = evenHead.next;

    return head;
}
