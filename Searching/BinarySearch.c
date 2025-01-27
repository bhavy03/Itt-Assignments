#include <stdio.h>

int binarySearch(int *arr, int n, int target)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (target < arr[mid])
        {
            end = mid - 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            // ans found
            return mid;
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

    int result = binarySearch(arr, i, target);

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