#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum priority
{
    Critical = 1,
    Serious = 2,
    Stable = 3
};
struct Node
{
    int id;
    enum priority data;
    struct Node *next;
};

struct Node *findMiddle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    struct Node *slowPrev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        slowPrev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == NULL)
    {
        return slowPrev;
    }
    return slow;
}

struct Node *insertAtEnd(struct Node *head, enum priority data, int id)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->id = id;
    newNode->next = NULL;
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
        printf("NULL\n");
        return;
    }
    while (ptr != NULL)
    {
        if (ptr->data == 1)
        {
            printf("%d Critical\n", ptr->id);
        }
        else if (ptr->data == 2)
        {
            printf("%d Serious\n", ptr->id);
        }
        else
        {
            printf("%d Stable\n", ptr->id);
        }
        ptr = ptr->next;
    }
}

struct Node *merge(struct Node *leftHead, struct Node *rightHead)
{
    struct Node *dummyNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = dummyNode;

    while (leftHead != NULL && rightHead != NULL)
    {
        if (leftHead->data <= rightHead->data)
        {
            temp->next = leftHead;
            temp = leftHead;
            leftHead = leftHead->next;
        }
        else
        {
            temp->next = rightHead;
            temp = rightHead;
            rightHead = rightHead->next;
        }
    }

    if (leftHead != NULL)
    {
        temp->next = leftHead;
    }
    if (rightHead != NULL)
    {
        temp->next = rightHead;
    }

    return dummyNode->next;
}

struct Node *mergeSort(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct Node *mid = findMiddle(head);
    struct Node *leftHead = head;
    struct Node *rightHead = mid->next;
    mid->next = NULL;

    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);

    return merge(leftHead, rightHead);
}

int Stringcheck(char *exp)
{
    return ((strcmp(exp, "Critical") == 0) || (strcmp(exp, "Serious") == 0) || (strcmp(exp, "Stable") == 0));
}
int idCheck(struct Node *head, int id)
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        struct Node *ptr = head;
        while (ptr != NULL)
        {
            if (id == ptr->id)
            {
                return 0;
            }
            ptr = ptr->next;
        }
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    struct Node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        int id;
        char exp[30];
        enum priority state;
        scanf("%d %[^\n]%*c", &id, exp);

        if (Stringcheck(exp) && idCheck(head, id))
        {

            if (strcmp(exp, "Critical") == 0)
            {
                state = Critical;
            }
            else if (strcmp(exp, "Serious") == 0)
            {
                state = Serious;
            }
            else if (strcmp(exp, "Stable") == 0)
            {
                state = Stable;
            }

            head = insertAtEnd(head, state, id);
        }
        else
        {
            printf("Enter valid Seriousness or ID\n");
            i--;
        }
    }
    head = mergeSort(head);

    printf("\n\n");
    display(head);

    return 0;
}
