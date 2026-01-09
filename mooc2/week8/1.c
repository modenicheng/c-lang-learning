/**
1字母存储（15分）
题目内容：

    使用单项链表存储一组字母{a, b, c, d, c, b ,
a}，输入序号输出字母，输入字母输出最后一次出现的序号，越界则输出N。

输入格式：

    序号或字母

输出格式：

    字母或序号



输入样例1：

2[回车]

输出样例1：

c[回车]

输入样例2：

c[回车]

输出样例2：

4[回车]

输入样例3：

8[回车]

输出样例3：

N[回车] */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
  int data;  // 存储字符的ASCII码
  struct node *next;
} Node;

// 创建链表
Node* create_list(char chars[], int n) {
  Node *head = NULL;
  Node *tail = NULL;

  for (int i = 0; i < n; i++) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = chars[i];
    new_node->next = NULL;

    if (head == NULL) {
      head = new_node;
      tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
  }

  return head;
}

// 根据索引获取字符，如果越界返回-1
int get_char_at_index(Node *head, int index) {
  Node *current = head;
  int i = 0;

  while (current != NULL) {
    if (i == index) {
      return current->data;
    }
    current = current->next;
    i++;
  }

  return -1;  // 越界
}

// 查找字符最后一次出现的索引，如果没找到返回-1
int find_last_index(Node *head, char ch) {
  Node *current = head;
  int index = -1;
  int i = 0;

  while (current != NULL) {
    if (current->data == ch) {
      index = i;
    }
    current = current->next;
    i++;
  }

  return index;
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
  char char_list[7] = {'a', 'b', 'c', 'd', 'c', 'b', 'a'};
  Node *head = create_list(char_list, 7);

  char input[32];
  if (fgets(input, sizeof(input), stdin) == NULL) {
    free_list(head);
    return 1;
  }

  // 移除换行符
  size_t len = strlen(input);
  if (len > 0 && input[len - 1] == '\n') {
    input[len - 1] = '\0';
    len--;
  }

  // 判断输入是数字还是字母
  if (len == 0) {
    // 空输入
    printf("N\n");
  } else if (isdigit(input[0])) {
    // 输入是数字（索引）
    int index = atoi(input);
    int ch = get_char_at_index(head, index);

    if (ch == -1) {
      // 越界
      printf("N\n");
    } else {
      printf("%c\n", ch);
    }
  } else {
    // 输入是字母（查找最后一次出现的索引）
    if (len != 1) {
      // 输入长度不为1，无效
      printf("N\n");
    } else {
      char ch = input[0];
      int index = find_last_index(head, ch);

      if (index == -1) {
        // 未找到
        printf("N\n");
      } else {
        printf("%d\n", index);
      }
    }
  }

  free_list(head);
  return 0;
}