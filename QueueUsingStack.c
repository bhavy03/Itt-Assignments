#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

typedef struct Queue
{
    int front, rear;
    int arr[MAX];
} Queue;

Queue *initilizeQueue(Queue *q)
{
    q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

int isEmpty(Queue *q)
{
    return q->front == -1 && q->rear == -1;
}

int isFull(Queue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

void enqueue(Queue *q, int x)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
        return;
    }
    else if (isEmpty(q))
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = x;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = x;
    }
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int x = -1;
    if (q->front == q->rear)
    {
        x = q->arr[q->front];
        q->front = q->rear = -1;
    }
    else
    {
        x = q->arr[q->front];
        q->front = (q->front + 1) % MAX;
    }
    return x;
}

int getSize(Queue *q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    if (q->front <= q->rear)
    {
        return q->rear - q->front + 1;
    }
    else
    {
        return MAX - q->front + q->rear + 1;
    }
}

void push(Queue *q, int x)
{
    if (isFull(q))
    {
        printf("Stack Overflow\n");
        return;
    }
    enqueue(q, x);
}

int pop(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Stack is Empty\n");
        return -1;
    }

    int itr = getSize(q) - 1;
    while (itr--)
    {
        int x = dequeue(q);
        enqueue(q, x);
    }

    int x = dequeue(q);
    return x;
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Stack is Empty\n");
        return -1;
    }

    int itr = getSize(q) - 1;
    while (itr--)
    {
        int x = dequeue(q);
        enqueue(q, x);
    }

    int x = dequeue(q);
    enqueue(q, x);
    return x;
}

int main()
{

    Queue *q = NULL;
    q = initilizeQueue(q);

    printf("Enter the number of Operations: ");
    int iterations;
    scanf("%d", &iterations);

    while (iterations--)
    {
        printf("1. Push\n2. Pop\n3. Peek\n4. Size\n5. isEmpty\n");
        int choice;
        printf("Enter the choice: ");
        scanf("%d", &choice);
        int x;

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &x);
            push(q, x);
            break;
        case 2:
            x = pop(q);
            if (x != -1)
            {
                printf("Popped Element: %d\n", x);
            }
            break;
        case 3:
            x = peek(q);
            if (x != -1)
            {
                printf("Top Element: %d\n", x);
            }
            break;
        case 4:
            printf("Size of Stack: %d\n", getSize(q));
            break;
        case 5:
            if (isEmpty(q))
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Stack is not Empty\n");
            }
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
    return 0;
}