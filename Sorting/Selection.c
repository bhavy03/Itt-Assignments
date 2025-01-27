#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int arr[6] = {2, 45, 32, 12, 1, 6};
    int n = 6;

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}