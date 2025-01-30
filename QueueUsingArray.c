#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int size;
    int *arr;
    int top;
    int bottom;
} queue;
int isEmpty(queue *s)
{
    return s->bottom == -1 || s->bottom > s->top;
}
int isFull(queue *s, int size)
{
    return s->top == size - 1;
}
int size(queue *s)
{
    return s->top + 1;
}
void enqueue(queue *s, int value)
{
    if (isFull(s, s->size))
    {
        printf("queue Overflow: Cannot push %d, queue is full!\n", value);
        return;
    }
    else
    {
        if (s->bottom == -1)
        {
            s->bottom = 0;
        }
        (s->top)++;
        s->arr[s->top] = value;
    }
}
void dequeue(queue *s)
{
    if (isEmpty(s))
    {
        printf("queue Underflow: queue is empty!\n");
        return;
    }
    s->bottom++;
}
int peek(queue *s)
{
    if (isEmpty(s))
    {
        printf("queue is empty!\n");
        return -1;
    }
    return s->arr[s->bottom];
}
void display(queue *s)
{
    if (isEmpty(s))
    {
        printf("queue is empty!\n");
        return;
    }
    printf("queue elements are: ");
    for (int i = s->bottom; i <= s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
int main()
{
    queue *s = (queue *)malloc(sizeof(queue));
    if (s == NULL)
    {
        printf("Memory allocation failed!\n");
        return -1;
    }

    printf("Enter the size of queue\n");
    scanf("%d", &(s->size));
    s->top = -1;
    s->bottom = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    if (s->arr == NULL)
    {
        printf("Memory allocation for queue array failed!\n");
        free(s);
        return -1;
    }

    int choice;
    while (1)
    {
        printf("1. Enqueue the element\n2. Dequeue the element\n3. Retrive the bottom element\n4. Check if queue is empty\n5. Size of queue\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int value;
            scanf("%d", &value);
            enqueue(s, value);
            display(s);
            break;
        }
        case 2:
        {
            dequeue(s);
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
                printf("queue is empty\n");
            }
            else
            {
                printf("queue is not empty\n");
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