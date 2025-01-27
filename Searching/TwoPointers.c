#include <stdio.h>

// Check if sum of two numbers with given sum is present or not
int twoSum(int *arr, int n, int sum)
{
    int i = 0;

    int j = n - 1;

    while (i < j)
    {
        if (arr[i] + arr[j] == sum)
        {
            return 1;
        }
        else if (arr[i] + arr[j] < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return 0;
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
    int sum;
    scanf("%d", &sum);

    int result = twoSum(arr, i, sum);
    if (result == 1)
    {
        printf("Two sum is present.\n");
    }
    else
    {
        printf("Two Sum is not present");
    }
    return 0;
}
