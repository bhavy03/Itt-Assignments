#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *insertAtEnd(struct Node *head, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    return newNode;
  }

  struct Node *ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = newNode;
  return head;
}

struct Node *insertAtBeginning(struct Node *head, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = head;
  return newNode;
}

struct Node *insertAtPosition(struct Node *head, int data, int pos) {
  if (pos < 1) {
    return head;
  }

  if (pos == 1) {
    return insertAtBeginning(head, data);
  }

  struct Node *ptr = head;
  int index = 1;
  while (ptr != NULL && index < pos - 1) {
    ptr = ptr->next;
    index++;
  }

  if (ptr == NULL) {
    printf("Invalid position\n");
    return head;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = ptr->next;
  ptr->next = newNode;
  return head;
}

void display(struct Node *head) {
  if (head == NULL) {
    printf("\n");
    return;
  }

  struct Node *ptr = head;
  while (ptr != NULL) {
    printf("%d", ptr->data);
    if (ptr->next != NULL) {
      printf(" ");
    }
    ptr = ptr->next;
  }
  printf("\n");
}

struct Node *updateAtPosition(struct Node *head, int pos, int data) {
  if (pos < 1) {
    printf("Invalid position\n");
    return head;
  }

  struct Node *ptr = head;
  int index = 1;
  while (ptr != NULL && index < pos) {
    ptr = ptr->next;
    index++;
  }

  if (ptr == NULL) {
    printf("Invalid position\n");
    return head;
  }

  ptr->data = data;
  return head;
}

struct Node *deleteFirst(struct Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return head;
  }

  struct Node *temp = head;
  head = head->next;
  free(temp);
  return head;
}

struct Node *deleteLast(struct Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return head;
  }

  if (head->next == NULL) {
    free(head);
    return NULL;
  }

  struct Node *ptr = head;
  while (ptr->next != NULL && ptr->next->next != NULL) {
    ptr = ptr->next;
  }

  free(ptr->next);
  ptr->next = NULL;
  return head;
}

struct Node *deleteAtPosition(struct Node *head, int pos) {
  if (pos < 1) {
    printf("Invalid position\n");
    return head;
  }

  if (pos == 1) {
    return deleteFirst(head);
  }

  struct Node *ptr = head;
  int index = 1;
  while (ptr != NULL && index < pos - 1) {
    ptr = ptr->next;
    index++;
  }

  if (ptr == NULL || ptr->next == NULL) {
    printf("Invalid position\n");
    return head;
  }

  struct Node *temp = ptr->next;
  ptr->next = ptr->next->next;
  free(temp);
  return head;
}

int main() {
  int n;
  scanf("%d", &n);

  struct Node *head = NULL;

  while (n--) {
    int operation;
    scanf("%d", &operation);

    switch (operation) {
    case 1: {
      int data;
      scanf("%d", &data);
      head = insertAtEnd(head, data);
      break;
    }
    case 2: {
      int data;
      scanf("%d", &data);
      head = insertAtBeginning(head, data);
      break;
    }
    case 3: {
      int pos, data;
      scanf("%d %d", &pos, &data);
      head = insertAtPosition(head, data, pos);
      break;
    }
    case 4: {
      display(head);
      break;
    }
    case 5: {
      int pos, data;
      scanf("%d %d", &pos, &data);
      head = updateAtPosition(head, pos, data);
      break;
    }
    case 6: {
      head = deleteFirst(head);
      break;
    }
    case 7: {
      head = deleteLast(head);
      break;
    }
    case 8: {
      int pos;
      scanf("%d", &pos);
      head = deleteAtPosition(head, pos);
      break;
    }
    default:
      printf("Invalid operation\n");
      break;
    }
  }

  return 0;
}
