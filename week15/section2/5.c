/**
查找元素
成绩	10	开启时间	2025年12月19日 星期五 00:05
折扣	0.8	折扣时间	2026年01月10日 星期六 23:59
允许迟交	否	关闭时间	2026年01月20日 星期二 23:59
题目描述：


在本题中，给出单链表的结构定义如下：

typedef struct node {

    int data;

    struct node *next;

} NODE;

请你实现一段代码，完成查找链表的倒数第二个元素的过程。程序所需要的其他代码已经写好。


输入：

第一行有一个正整数N，表示接下来有N个正整数元素要依次插入链表。

第二行有N个正整数，分别表示数据。


输出：

如果链表长度大于等于2，输出倒数第二个元素中的data数值。

否则，输出“No such element.”


样例输入：

6

1 2 3 4 5 6


样例输出:

5

*/

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} NODE;

NODE *findelement(NODE *head);
//****************HERE IS THE CODE FOR YOU TO FINISH****************************
//**函数签名为：NODE*
// findelement(NODE*)***这个函数的含义是找到倒数第二个元素***************
//******************************************************************************
NODE *findelement(NODE *head) {
    // 检查链表是否至少有两个数据节点
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return NULL;
    }

    // 使用双指针技巧
    NODE *slow = head->next;  // 第一个数据节点
    NODE *fast = head->next->next;  // 第二个数据节点

    // 移动fast直到末尾
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
//****************ABOVE IS THE CODE FOR YOU TO FINISH***************************
//******************************************************************************

int main() {
  NODE *head = (NODE *)malloc(sizeof(NODE));
  head->data = 0;
  head->next = NULL;
  int n, x;

  scanf("%d", &n);
  NODE *pre = head;
  while (n--) {
    scanf("%d", &x);
    NODE *cnt = (NODE *)malloc(sizeof(NODE));
    cnt->data = x;
    cnt->next = NULL;
    pre->next = cnt;
    pre = cnt;
  }

  NODE *pos = findelement(head);
  if (pos == NULL)
    puts("No such element.");
  else
    printf("%d\n", pos->data);

  return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */