#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = data;
    if (head == NULL)
    {
        return newNode;
    }
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return head;
}
void display(struct Node *head)
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("NULL");
    }
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *removeDuplicate(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *prev = NULL;
    while (ptr != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
        while (ptr != NULL && prev->data == ptr->data)
        {
            struct Node *temp = ptr;
            ptr = ptr->next;
            prev->next = ptr;
            free(temp);
        }
    }
    return head;
}
int main()
{
    struct Node *head = NULL;
    int n;
    scanf("%d", &n);
    int data = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    // display(head);
    head = removeDuplicate(head);
    // printf("\n");
    display(head);

    return 0;
}
