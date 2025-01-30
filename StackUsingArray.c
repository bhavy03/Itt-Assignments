#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int size;
    int *arr;
    int top;
} stack;

int isEmpty(stack *s)
{
    return s->top == -1;
}
int isFull(stack *s, int size)
{
    return s->top == size - 1;
}
int size(stack *s)
{
    return s->top + 1;
}
void push(stack *s, int value)
{
    if (isFull(s, s->size))
    {
        printf("Stack Overflow: \n");
        return;
    }
    (s->top)++;
    s->arr[s->top] = value;
}
void pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow: Stack is empty!\n");
        return;
    }
    s->top--;
}
int peek(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}
void display(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }
    printf("Enter the size of stack\n");
    scanf("%d", &(s->size));
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    if (s->arr == NULL)
    {
        printf("Memory allocation for stack array failed!\n");
        free(s);
        return -1;
    }
    int choice;
    while (1)
    {
        printf("1. Push the element\n2. Pop the element\n3. Retrive the top element\n4. check if stack is empty\n5. Size of stack\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int value;
            scanf("%d", &value);
            push(s, value);
            display(s);
            break;
        }
        case 2:
        {
            pop(s);
            display(s);
            break;
        }
        case 3:
        {
            printf("The peek is :%d\n", peek(s));
            break;
        }
        case 4:
        {
            if (isEmpty(s))
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
            printf("The size is:%d\n", size(s));
            break;
        }
        case 6:
            free(s->arr);
            free(s);
            return 0;
        default:
            printf("Enter a valid choice\n");
            break;
        }
    }
}