#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
};

void initializeQueue(struct Queue *q, int capacity)
{
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->arr = (int *)malloc(capacity * sizeof(int));
}

int isEmpty(struct Queue *q)
{
    return q->size == 0;
}

int isFull(struct Queue *q)
{
    return q->size == q->capacity;
}

void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
        return;
    }
    q->rear = (q->rear + 1);
    q->arr[q->rear] = value;
    q->size++;
}

int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->arr[q->front];
    q->front = (q->front + 1);
    q->size--;
    return value;
}

int front(struct Queue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    return q->arr[q->front];
}

struct Stack
{
    struct Queue *q;
};

void initializeStack(struct Stack *stack, int capacity)
{
    stack->q = (struct Queue *)malloc(sizeof(struct Queue));
    initializeQueue(stack->q, capacity);
}

void push(struct Stack *stack, int value)
{
    int currentSize = stack->q->size;
    enqueue(stack->q, value);

    for (int i = 0; i < currentSize; i++)
    {
        int frontValue = dequeue(stack->q);
        enqueue(stack->q, frontValue);
    }
    printf("Pushed %d\n", value);
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack->q))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = dequeue(stack->q);
    printf("Popped %d\n", value);
    return value;
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack->q))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return front(stack->q);
}

int size(struct Stack *stack)
{
    return stack->q->size;
}

int isEmptyStack(struct Stack *stack)
{
    return isEmpty(stack->q);
}

void display(struct Stack *stack)
{
    if (isEmptyStack(stack))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = stack->q->front, count = 0; count < stack->q->size; count++)
    {
        printf("%d ", stack->q->arr[i]);
        i = (i + 1) % stack->q->capacity;
    }
    printf("\n");
}

int main()
{
    int choice, capacity = 5;
    struct Stack stack;
    initializeStack(&stack, capacity);

    while (1)
    {
        printf("\n1. Push the element\n2. Pop the element\n3. Peek the top element\n4. Check if stack is empty\n5. Size of the stack\n6. Display the stack\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int value;
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        }
        case 2:
        {
            int poppedValue = pop(&stack);
            if (poppedValue != -1)
            {
                printf("Popped value: %d\n", poppedValue);
            }
            break;
        }
        case 3:
        {
            printf("Top element: %d\n", peek(&stack));
            break;
        }
        case 4:
        {
            if (isEmptyStack(&stack))
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        }
        case 5:
        {
            printf("Size of stack: %d\n", size(&stack));
            break;
        }
        case 6:
        {
            display(&stack);
            break;
        }
        case 7:
            printf("Exiting the program.\n");
            free(stack.q->arr);
            free(stack.q);
            return 0;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
}
