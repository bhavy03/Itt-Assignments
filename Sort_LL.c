// Problem Statement:-
// Given the head of a linked list, return the list after sorting it in ascending order.
// The number of nodes in the list is in the range [0, 5 * 104].
// -105 <= Node.val <= 105

// Time Complexity analysis:-
// As merge sort works on divide and conquer and
// merging step is performed at each level of recursion
// and there are log(N) levels, the time complexity is:
// O(nlogn)

// Space Complexity analysis:-
// Since this is linked list and we are not using extra space
// therefore the space complexity is
// O(1)

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *findMiddle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    // struct Node *fast = head->next;
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
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
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
    newNode->next = NULL;
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
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *merge(struct Node *leftHead, struct Node *rightHead)
{
    struct Node *dummyNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = dummyNode;
    while (leftHead != NULL && rightHead != NULL)
    {
        if (leftHead->data < rightHead->data)
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
int main()
{
    int num = 0;
    struct Node *head = NULL;
    while ((scanf("%d", &num)) == 1)
    {
        head = insertAtEnd(head, num);
        if (getchar() == '\n')
        {
            break;
        }
    }
    struct Node *ptr = head;
    head = mergeSort(head);
    display(head);
    return 0;
}