#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int placePivot(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low ;
    int j = high;
    while (i <= j)
    {
        while (arr[i] <= pivot && i <= high)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = placePivot(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}
int main()
{
    int arr[6] = {8, 9, 12, 14, 15, 5};
    int n = 6;
    int low = 0;
    int high = n - 1;

    quickSort(arr, low, high);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}