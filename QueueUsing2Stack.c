#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *arr;
    int top;
    int capacity;
} Stack;

void initializeStack(Stack *stack, int capacity)
{
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(capacity * sizeof(int));
}

int isEmptyStack(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, int value)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmptyStack(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack)
{
    if (isEmptyStack(stack))
    {
        return -1;
    }
    return stack->arr[stack->top];
}

typedef struct Queue
{
    Stack *stack1;
    Stack *stack2;
} Queue;

void initializeQueue(Queue *queue, int capacity)
{
    queue->stack1 = (Stack *)malloc(sizeof(Stack));
    queue->stack2 = (Stack *)malloc(sizeof(Stack));
    initializeStack(queue->stack1, capacity);
    initializeStack(queue->stack2, capacity);
}

void enqueue(Queue *queue, int value)
{
    while (!isEmptyStack(queue->stack1))
    {
        push(queue->stack2, pop(queue->stack1));
    }

    push(queue->stack1, value);

    while (!isEmptyStack(queue->stack2))
    {
        push(queue->stack1, pop(queue->stack2));
    }
}

int dequeue(Queue *queue)
{
    if (isEmptyStack(queue->stack1))
    {
        printf("Queue Underflow\n");
        return -1;
    }

    return pop(queue->stack1);
}

int front(Queue *queue)
{
    if (isEmptyStack(queue->stack1))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return peek(queue->stack1);
}

int isEmptyQueue(Queue *queue)
{
    return isEmptyStack(queue->stack1) && isEmptyStack(queue->stack2);
}

int size(Queue *queue)
{
    return queue->stack1->top + 1;
}

void display(Queue *queue)
{
    printf("Queue elements: ");

    int queueSize = size(queue);

    for (int i = 0; i < queueSize; i++)
    {
        printf("%d ", queue->stack1->arr[i]);
    }
    printf("\n");
}

int main()
{
    int choice, capacity = 5;

    Queue *queue = (Queue *)malloc(sizeof(Queue));
    initializeQueue(queue, capacity);

    while (1)
    {
        printf("\n1. Enqueue the element\n2. Dequeue the element\n3. Peek the front element\n4. Check if queue is empty\n5. Size of the queue\n6. Display the queue\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int value;
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(queue, value);
            display(queue);
            break;
        }
        case 2:
        {
            int dequeuedValue = dequeue(queue);
            if (dequeuedValue != -1)
            {
                printf("Dequeued value: %d\n", dequeuedValue);
            }
            display(queue);
            break;
        }
        case 3:
        {
            printf("Front element: %d\n", front(queue));
            break;
        }
        case 4:
        {
            if (isEmptyQueue(queue))
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
            printf("Size of queue: %d\n", size(queue));
            break;
        }
        case 6:
        {
            display(queue);
            break;
        }
        case 7:
            printf("Exiting the program.\n");
            free(queue->stack1->arr);
            free(queue->stack2->arr);
            free(queue->stack1);
            free(queue->stack2);
            free(queue);
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
}
