#include <stdio.h>
void merge(int *arr, int low, int mid, int high)
{
    int temp[high - low + 1];
    int left = low;
    int right = mid + 1;
    int index = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[index++] = arr[left];
            left++;
        }
        else
        {
            temp[index++] = arr[right];
            right++;
        }
    }
    while (left <= mid)
    {
        temp[index++] = arr[left];
        left++;
    }
    while (right <= high)
    {
        temp[index++] = arr[right];
        right++;
    }
    for (int i = 0; i < (high - low + 1); i++)
    {
        arr[low + i] = temp[i];
    }
}
void mergeSort(int *arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
int main()
{
    int arr[5] = {4, 3, 1, 5, 2};
    int n = 5;
    int low = 0;
    int high = n - 1;
    mergeSort(arr, low, high);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}