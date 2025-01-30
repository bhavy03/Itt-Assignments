#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Queue
{
    struct Node *front;
    struct Node *rear;
} Queue;

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

int size(Queue *q)
{
    int count = 0;
    struct Node *temp = q->front;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
struct Node *enqueue(Queue *q, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Queue Overflow (Memory Allocation Failed)\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d\n", value);
    return q->front;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow (Queue is empty)\n");
        return -1;
    }
    struct Node *temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    printf("Dequeued %d\n", dequeuedValue);
    return dequeuedValue;
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

void displayQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = q->front;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;

    while (1)
    {
        printf("\n1. Enqueue the element\n2. Dequeue the element\n3. Retrieve the front element\n4. Check if queue is empty\n5. Size of queue\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int value;
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            q->front = enqueue(q, value);
            displayQueue(q);
            break;
        }
        case 2:
        {
            int dequeuedValue = dequeue(q);
            if (dequeuedValue != -1)
            {
                printf("Dequeued value: %d\n", dequeuedValue);
            }
            displayQueue(q);
            break;
        }
        case 3:
        {
            printf("The front element is: %d\n", peek(q));
            break;
        }
        case 4:
        {
            if (isEmpty(q))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        }
        case 5:
        {
            printf("The size of Queue is: %d", size(q));
            break;
        }
        case 6:
            printf("Exiting the program.\n");
            free(q);
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
}