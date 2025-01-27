#include <stdio.h>

int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[100];
    int i = 0;
    int num = 0;
    while ((scanf("%d", &num)) == 1)
    {
        arr[i++] = num;
        if (getchar() == '\n')
        {
            break;
        }
    }
    int target;
    scanf("%d", &target);

    int result = linearSearch(arr, i, target);

    if (result == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index: %d\n", result);
    }

    return 0;
}