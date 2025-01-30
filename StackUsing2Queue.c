#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = 0;
    queue->arr = (int *)malloc(capacity * sizeof(int));
    return queue;
}

int isEmptyQueue(Queue *q)
{
    return (q->front == q->rear);
}

void enqueue(Queue *q, int value)
{
    if (q->rear == q->capacity)
    {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front++];
}

int front(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

typedef struct Stack
{
    Queue *q1;
    Queue *q2;
    int size;
} Stack;

Stack *createStack(int capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->q1 = createQueue(capacity);
    stack->q2 = createQueue(capacity);
    stack->size = 0;
    return stack;
}

int isEmpty(Stack *stack)
{
    return (stack->size == 0);
}

int size(Stack *stack)
{
    return stack->size;
}

void push(Stack *stack, int value)
{
    enqueue(stack->q2, value);

    while (!isEmptyQueue(stack->q1))
    {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    Queue *temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    stack->size++;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }

    int value = dequeue(stack->q1);
    stack->size--;
    return value;
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }

    return front(stack->q1);
}

int main()
{
    Stack *stack = createStack(10);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", peek(stack));
    printf("Stack size: %d\n", size(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Stack size after pop: %d\n", size(stack));

    printf("Top element: %d\n", peek(stack)); 

    pop(stack);
    printf("Is stack empty? %d\n", isEmpty(stack));

    return 0;
}
