/**
2链表合并（15分）
题目内容：

    实现两个由单项链表存储的有序字母数据的合并，如有重复的则只保留一个。

    例如：给定{a, c ,f}, { b, e, g}合并后结果为{a, b, c , e , f , g}。

输入格式：

    两个有序字母数据

输出格式：

    合并后的字母数据



输入样例1：

a b c[回车]

d e f[回车]

输出样例1：

a b c d e f[回车]


输入样例2：

e f g[回车]

e g m[回车]

输出样例2：

e f g m[回车]

时间限制：500ms内存限制：32000kb */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 链表节点结构
typedef struct Node {
  char data;
  struct Node *next;
} Node;

// 创建新节点
Node *create_node(char ch) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = ch;
  new_node->next = NULL;
  return new_node;
}

// 向有序链表中插入字符（按字母顺序，不重复）
void insert_sorted(Node **head, char ch) {
  Node *new_node = create_node(ch);

  // 如果链表为空或新节点应插入在头部
  if (*head == NULL || ch < (*head)->data) {
    new_node->next = *head;
    *head = new_node;
    return;
  }

  // 查找插入位置
  Node *current = *head;

  // 跳过重复字符
  if (current->data == ch) {
    free(new_node); // 重复，不插入
    return;
  }

  while (current->next != NULL && current->next->data < ch) {
    current = current->next;
  }

  // 检查重复
  if (current->next != NULL && current->next->data == ch) {
    free(new_node); // 重复，不插入
    return;
  }

  // 插入节点
  new_node->next = current->next;
  current->next = new_node;
}

// 从空格分隔的字符串构建有序链表
Node *build_sorted_list(const char *str) {
  Node *head = NULL;

  // 创建字符串拷贝以避免修改原字符串
  char *str_copy = strdup(str);
  if (str_copy == NULL) {
    return NULL;
  }

  char *token = strtok(str_copy, " ");

  while (token != NULL) {
    if (strlen(token) == 1 && isalpha(token[0])) {
      insert_sorted(&head, token[0]);
    }
    token = strtok(NULL, " ");
  }

  free(str_copy);
  return head;
}

// 合并两个有序链表，去重
Node *merge_sorted_lists(Node *list1, Node *list2) {
  Node dummy; // 虚拟头节点
  Node *tail = &dummy;
  dummy.next = NULL;

  while (list1 != NULL && list2 != NULL) {
    if (list1->data < list2->data) {
      tail->next = list1;
      list1 = list1->next;
    } else if (list1->data > list2->data) {
      tail->next = list2;
      list2 = list2->next;
    } else {
      // 相等的情况，只保留一个，跳过另一个
      tail->next = list1;
      list1 = list1->next;
      Node *temp = list2;
      list2 = list2->next;
      free(temp); // 释放重复节点
    }
    tail = tail->next;
    tail->next = NULL; // 断开连接
  }

  // 连接剩余部分
  if (list1 != NULL) {
    tail->next = list1;
  } else {
    tail->next = list2;
  }

  return dummy.next;
}

// 打印链表
void print_list(Node *head) {
  Node *current = head;
  int first = 1;

  while (current != NULL) {
    if (!first) {
      printf(" ");
    }
    printf("%c", current->data);
    first = 0;
    current = current->next;
  }
  printf("\n");
}

// 释放链表内存
void free_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    Node *temp = current;
    current = current->next;
    free(temp);
  }
}

int main() {
  char line1[1024];
  char line2[1024];

  // 读取第一行
  if (fgets(line1, sizeof(line1), stdin) == NULL) {
    return 1;
  }

  // 读取第二行
  if (fgets(line2, sizeof(line2), stdin) == NULL) {
    return 1;
  }

  // 移除换行符
  line1[strcspn(line1, "\n")] = '\0';
  line2[strcspn(line2, "\n")] = '\0';

  // 构建两个有序链表
  Node *list1 = build_sorted_list(line1);
  Node *list2 = build_sorted_list(line2);

  // 合并链表
  Node *merged_list = merge_sorted_lists(list1, list2);

  // 输出结果
  print_list(merged_list);

  // 释放内存
  free_list(merged_list);

  return 0;
}