#include <stdio.h>
#include <stdlib.h>

typedef struct numLink {
  int no;
  struct numLink *next;
} NODE;

NODE *monenode(NODE *head, int m, int n);
void SetLink(NODE *h, int n);

void SetLink(NODE *h, int n) {
  NODE *p = NULL, *q = h;
  for (int i = 0; i < n; i++) {
    p = (NODE *)malloc(sizeof(NODE));
    p->no = i + 1;
    p->next = NULL;
    q->next = p;
    q = p;
  }
}

int main() {
  int n, m;
  NODE *head = NULL, *q = NULL;

  if (scanf("%d%d", &n, &m) != 2 || n <= 0) {
    return 0;
  }

  head = (NODE *)malloc(sizeof(NODE));
  head->no = -1;
  head->next = NULL;

  SetLink(head, n);

  // Pass n to handle cases where m >= n
  q = monenode(head, m, n);

  // Printing the modified list
  NODE *curr = q->next;
  while (curr != NULL) {
    printf("%d ", curr->no);
    curr = curr->next;
  }
  printf("\n");

  return 0;
}

NODE *monenode(NODE *head, int m, int n) {
  if (head == NULL || head->next == NULL || m % n == 0) {
    return head; // No rotation needed
  }

  m = m % n; // Handle cases where m > n

  NODE *first_node = head->next;
  NODE *end_node = first_node;

  // 1. Find the current last node
  while (end_node->next != NULL) {
    end_node = end_node->next;
  }

  // 2. Find the new tail (the node at index m-1)
  NODE *new_tail = first_node;
  for (int i = 0; i < m - 1; i++) {
    new_tail = new_tail->next;
  }

  // 3. Find the new head (the node after the new tail)
  NODE *new_head = new_tail->next;

  // 4. Rearrange pointers
  end_node->next =
      first_node; // Connect old end to old start (make circular temporarily)
  head->next = new_head; // Update dummy head to point to new start
  new_tail->next = NULL; // Break the circle at the new tail

  return head;
}