/**
H25. 求循环节（选作）
成绩	10	开启时间	2025年12月12日 星期五 00:05
折扣	0.8	折扣时间	2026年01月17日 星期六 23:59
允许迟交	是的	关闭时间	2026年01月17日 星期六 23:59
对于任意的真分数 N/M （ 0 < N < M
），均可以求出对应的小数。如果采用链表存储各位小数，对于循环节采用循环链表表示，则所有分数均可以表示为如下链表形式。



输入： N M

输出： 整个循环节

要求：
 编写一个尽可能高效的查找循环节起始点的函数： NODE * find( NODE * head, int * n
) 。函数的返回值为循环节的起点（即图中的指针p），n为循环节的长度。

说明：提交程序时请同时提交将分数转换为小数的函数 change( int n, int m, NODE *
head ) 。
*/

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} NODE;

NODE *find(NODE *, int *);
void outputring(NODE *);
void change(int, int, NODE *);

void outputring(NODE *pring) {
  NODE *p;
  p = pring;
  if (p == NULL)
    printf("NULL");
  else
    do {
      printf("%d", p->data);
      p = p->next;
    } while (p != pring);
  printf("\n");
  return;
}

int main() {
  int n, m;
  NODE *head, *pring;

  scanf("%d%d", &n, &m);
  head = (NODE *)malloc(sizeof(NODE));
  head->next = NULL;
  head->data = -1;

  change(n, m, head);
  pring = find(head, &n);
  printf("ring=%d\n", n);
  outputring(pring);

  return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

// int calc_power_of_2_and_5(int num) {
//   int count = 0;
//   while (num % 2 == 0) {
//     num /= 2;
//     count++;
//   }
//   while (num % 5 == 0) {
//     num /= 5;
//     count++;
//   }
//   return count;
// }

// NODE *push(int data, NODE *tail) {
//   NODE *new = (NODE *)malloc(sizeof(NODE));
//   new->data = data;
//   new->next = NULL;
//   tail->next = new;
//   return new;
// }

// void change(int n, int m, NODE *head) {
//   // n/m，这个分式化成小数循环节长度不超过 m - 1;
//   // 根据 m 的质因数分解中 2 和 5 的幂次，可以推断出有多少位是不循环的
//   // 加上一个整数位，m + calc_power_of_2_and_5(m) 是最长需要的链表节点数量
//   // 为了能够找到循环节，需要至少两个循环，所以 m * 2
//   int digits = m * 2 - 1 + calc_power_of_2_and_5(m);
//   NODE *tail = head;
//   for (int i = 0; i < digits; i++) {
//     int remaining = n % m;
//     int division = n / m;
//     tail = push(division, tail);
//     putc('0' + division, stdout);
//     n = 10 * remaining;
//   }
// }

// NODE *find(NODE *head, int *n) {
//   // 滑动窗口
// }

/**
 * find 函数：在带环链表中找到环的起点并计算长度。
 * 采用 Floyd 判圈算法（快慢指针）。
 */
NODE *find(NODE *head, int *n) {
  if (head == NULL || head->next == NULL)
    return NULL;

  NODE *slow = head->next;
  NODE *fast = head->next;

  // 1. 确定是否有环（本题 change 逻辑保证必有环）并找到相遇点
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      break;
  }

  // 2. 寻找环的起点 (指针 p)
  // 将 slow 重新指向链表首个有效节点，fast 保持在相遇点
  // 两者同步移动，相遇处即为环起点
  slow = head->next;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  NODE *start_node = slow;

  // 3. 计算环的长度
  int length = 1;
  NODE *curr = start_node->next;
  while (curr != start_node) {
    curr = curr->next;
    length++;
  }

  *n = length;       // 通过指针返回长度
  return start_node; // 返回环起点指针
}