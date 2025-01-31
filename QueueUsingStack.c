#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

typedef struct Stack
{
    int top;
    int arr[MAX];
} Stack;

Stack *initializeStack(Stack *s)
{
    s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int x)
{
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = x;
}

int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

void enqueue(Stack *s, int x)
{
    push(s, x);
}

int dequeue(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int x = pop(s);
    if (isEmpty(s))
    {
        return x;
    }
    int temp = dequeue(s);
    push(s, x);
    return temp;
}

int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int x = pop(s);
    if (isEmpty(s))
    {
        push(s, x);
        return x;
    }
    int temp = peek(s);
    push(s, x);
    return temp;
}

int getSize(Stack *s)
{
    return s->top + 1;
}

int main()
{

    Stack *s = NULL;
    s = initializeStack(s);

    printf("Enter the number of Operations: ");
    int iterations;
    scanf("%d", &iterations);

    while (iterations--)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Size\n5. isEmpty\n");

        int choice;
        printf("Enter the choice: ");
        scanf("%d", &choice);
        int x;
        switch (choice)
        {
        case 1:
            printf("Enter the element to Enqueue: ");
            scanf("%d", &x);
            enqueue(s, x);
            break;
        case 2:
            x = dequeue(s);
            if (x != -1)
            {
                printf("Dequeued Element: %d\n", x);
            }
            break;
        case 3:
            x = peek(s);
            if (x != -1)
            {
                printf("Front Element: %d\n", x);
            }
            break;
        case 4:
            printf("Size of Queue: %d\n", getSize(s));
            break;

        case 5:
            if (isEmpty(s))
            {
                printf("Queue is Empty\n");
            }
            else
            {
                printf("Queue is not Empty\n");
            }
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }

    return 0;
}
