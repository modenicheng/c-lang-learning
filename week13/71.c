/*
71（BOSS）Poker time! （使用结构）
成绩	10	开启时间	2025年12月12日 星期五 00:05
折扣	0.9	折扣时间	2025年12月29日 星期一 23:59
允许迟交	否	关闭时间	2026年01月5日 星期一 23:59
背景：两个人每人发3张牌（各从一副牌中），每张牌包括花色（红桃(Heart)>黑桃(Spade)>方块(Diamond)>梅花(Club））和大小（从小到大依次是：2-10、J、Q、K、A），谁手上有最大的一张或多张（如果有相同的牌）牌谁获胜。

输入：A的3张牌（未排序）和B的3张牌（未排序）。（参见用例）

输出：A的3张牌的排序后的输出和B的3张牌的排序后的输出，以及A和B谁获胜。（参见用例）
*/

#include <stdio.h>
#include <stdlib.h>

char rank[15] = {'2', '3', '4', '5', '6', '7', '8',
                 '9', '1', 'J', 'Q', 'K', 'A'};
char suit[4] = {'C', 'D', 'S', 'H'};

typedef struct {
  int rank; // 2-10, J = 11, Q = 12, K = 13, A = 14
  int suit; // Heart = 45, Spade = 30, Diamond = 15, Club = 0
  // 类似进位制，保证 rank + suit 不会重复。（如果 suit 从 1-4, 会出现 CA = DK
  // 的情况，无法排序）
} Card;

typedef struct Node {
  Card* card;
  struct Node* next;
} Node;

typedef Node* NodeP;

// 链表操作函数声明
NodeP create_head();
void ins_list(NodeP h, Card card);
void free_list(NodeP h);
void sort_list(NodeP h);
int has_duplicate(NodeP h);
void print_list(NodeP h, const char* label);
Card get_card_at(NodeP h, int index);

int weight(Card card) { return card.rank + card.suit; }

void print_card(Card card) {
  if (card.rank == 10) {
    printf("%c10", suit[(card.suit / 15)]);
    return;
  }
  printf("%c%c", suit[(card.suit / 15)], rank[card.rank - 2]);
}

void sort_cards(Card cards[3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3 - i - 1; j++) {
      if (weight(cards[j]) < weight(cards[j + 1])) {
        Card tmp = cards[j];
        cards[j] = cards[j + 1];
        cards[j + 1] = tmp;
      }
    }
  }
}

Card get_card() {
  Card card;

  int rank = 0;
  int suit;
  while (1) {
    char c = getchar();
    if (c == ' ' || c == '\n') {
      card = (Card){rank, suit};
      return card;
    } else if (c >= '0' && c <= '9') {
      rank *= 10;
      rank += c - 48;
    } else if (c >= 'A' && c <= 'Z') {
      switch (c) {
      case 'A':
        rank = 14;
        break;
      case 'K':
        rank = 13;
        break;
      case 'Q':
        rank = 12;
        break;
      case 'J':
        rank = 11;
        break;
      case 'H':
        suit = 45;
        break;
      case 'S':
        suit = 30;
        break;
      case 'D':
        suit = 15;
        break;
      case 'C':
        suit = 0;
        break;
      default:
        printf("Input Error!\n");
        exit(1);
      }
    }
  }
}

// 创建链表头节点（哨兵节点）
NodeP create_head() {
    NodeP head = (NodeP)malloc(sizeof(Node));
    if (head == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    head->card = NULL;
    head->next = NULL;
    return head;
}

// 插入节点到链表尾部
void ins_list(NodeP h, Card card) {
    // 遍历到链表尾部
    NodeP current = h;
    while (current->next != NULL) {
        current = current->next;
    }

    // 创建新节点
    NodeP newNode = (NodeP)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // 分配Card内存并复制数据
    Card* newCard = (Card*)malloc(sizeof(Card));
    if (newCard == NULL) {
        printf("Memory allocation failed!\n");
        free(newNode);
        exit(1);
    }
    *newCard = card;  // 深拷贝

    // 连接节点
    newNode->card = newCard;
    newNode->next = NULL;

    // 连接到链表尾部
    current->next = newNode;
}

// 释放链表内存
void free_list(NodeP h) {
    NodeP current = h->next;
    NodeP next;

    while (current != NULL) {
        next = current->next;
        free(current->card);  // 先释放Card内存
        free(current);        // 再释放Node内存
        current = next;
    }

    free(h);  // 释放头节点
}

// 对链表进行降序排序（冒泡排序）
void sort_list(NodeP h) {
    // 空链表或只有一个节点，无需排序
    if (h->next == NULL || h->next->next == NULL) {
        return;
    }

    int swapped;
    NodeP ptr1;
    NodeP lptr = NULL;

    do {
        swapped = 0;
        ptr1 = h->next;

        while (ptr1->next != lptr) {
            // 比较当前节点和下一节点的权重
            if (weight(*(ptr1->card)) < weight(*(ptr1->next->card))) {
                // 交换card指针（不交换节点本身）
                Card* temp = ptr1->card;
                ptr1->card = ptr1->next->card;
                ptr1->next->card = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// 检查链表中是否有重复的牌
int has_duplicate(NodeP h) {
    NodeP current = h->next;

    while (current != NULL) {
        NodeP runner = current->next;
        while (runner != NULL) {
            if (weight(*(current->card)) == weight(*(runner->card))) {
                return 1;  // 发现重复
            }
            runner = runner->next;
        }
        current = current->next;
    }
    return 0;  // 无重复
}

// 打印链表内容
void print_list(NodeP h, const char* label) {
    printf("%s: ", label);
    NodeP current = h->next;

    while (current != NULL) {
        print_card(*(current->card));
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

// 获取链表第i个节点的Card（0-indexed）
Card get_card_at(NodeP h, int index) {
    NodeP current = h->next;
    int i = 0;

    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        // 错误处理：返回一个默认Card
        Card defaultCard = {0, 0};
        return defaultCard;
    }

    return *(current->card);
}

int main(int argc, char const *argv[]) {
  // 创建链表A和B
  NodeP listA = create_head();
  NodeP listB = create_head();

  // 读取A的3张牌并插入链表
  for (int i = 0; i < 3; i++) {
    Card card = get_card();
    ins_list(listA, card);
  }

  // 读取B的3张牌并插入链表
  for (int i = 0; i < 3; i++) {
    Card card = get_card();
    ins_list(listB, card);
  }

  // 检查每手牌内是否有重复牌
  if (has_duplicate(listA) || has_duplicate(listB)) {
    printf("Input Error!\n");
    free_list(listA);
    free_list(listB);
    exit(1);
  }

  // 对链表进行降序排序
  sort_list(listA);
  sort_list(listB);

  // 确定赢家：比较排序后的牌
  char winner = 'X';
  NodeP currA = listA->next;
  NodeP currB = listB->next;

  while (currA != NULL && currB != NULL) {
    if (weight(*(currA->card)) > weight(*(currB->card))) {
      winner = 'A';
      break;
    } else if (weight(*(currA->card)) < weight(*(currB->card))) {
      winner = 'B';
      break;
    }
    currA = currA->next;
    currB = currB->next;
  }

  printf("Winner is %c!\n", winner);

  // 打印结果
  print_list(listA, "A");
  print_list(listB, "B");

  // 释放内存
  free_list(listA);
  free_list(listB);

  return 0;
}
