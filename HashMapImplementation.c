#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    int value;
    struct Node *next;
} Node;

Node *insert_at_end(Node *head, unsigned int key, unsigned int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->key = key;
    node->value = value;

    if (head == NULL)
    {
        return node;
    }

    Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->key == key)
        {
            ptr->value = value;
            free(node);
            return head;
        }
        if (ptr->next == NULL)
        {
            break;
        }
        ptr = ptr->next;
    }

    ptr->next = node;
    return head;
}
Node *hash_map[10] = {NULL};

int hash_function(unsigned int key)
{
    return key % 10;
}

void insertHashmap(unsigned int key, unsigned int value)
{
    unsigned int idx = hash_function(key);
    hash_map[idx] = insert_at_end(hash_map[idx], key, value);
    return;
}

int searchHashmap(unsigned int key)
{
    unsigned int idx = hash_function(key);

    Node *ptr = hash_map[idx];
    while (ptr != NULL)
    {
        if (ptr->key == key)
        {
            return ptr->value;
        }
        ptr = ptr->next;
    }

    return -1;
}

void display()
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d : ", i);
        Node *ptr = hash_map[i];
        while (ptr)
        {
            printf("(%u, %u) --> ", ptr->key, ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }
    return;
}

void delete_from_hash_map(unsigned int key)
{
    unsigned int idx = hash_function(key);

    if (!hash_map[idx])
        return;

    Node *ptr = hash_map[idx];
    if (hash_map[idx]->key == key)
    {
        if (hash_map[idx]->next)
            hash_map[idx] = hash_map[idx]->next;
        else
            hash_map[idx] = NULL;
        return;
    }

    ptr = hash_map[idx];
    while (ptr && ptr->next)
    {
        if (ptr->next->key == key)
        {
            ptr->next = ptr->next->next;
            return;
        }
        ptr = ptr->next;
    }
    return;
}

int main()
{

    int count;
    printf("Enter number of operations to perform : ");
    scanf("%d", &count);

    while (count--)
    {
        printf("1. Add a value.\n2. Search a value.\n3. Delete a value.\n4. Display Hashmap\n5. Exit..\n");
        int oper;
        scanf("%d", &oper);
        if (oper == 1)
        {
            unsigned int key;
            unsigned int value;
            printf("Enter key and value to take add in hash map : ");
            scanf("%u%u", &key, &value);
            insertHashmap(key, value);
        }
        else if (oper == 2)
        {
            int key;
            printf("Enter key to search : ");
            scanf("%u", &key);
            int value = searchHashmap(key);
            printf("value is : %u\n", value);
        }
        else if (oper == 3)
        {
            int key;
            printf("Enter key to delete : ");
            scanf("%u", &key);
            delete_from_hash_map(key);
        }
        else if (oper == 4)
        {
            display();
        }
        else
        {
            break;
        }
    }
}