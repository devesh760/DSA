#include <iostream>
using namespace std;
void merge(int arr[], int first, int mid, int last)
{
    int n = last - first + 1;
    int temp[n];
    int i = first;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= last)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            ++i;
        }
        else
        {
            temp[k] = arr[j];
            ++j;
        }
        ++k;
    }
    for (; i <= mid; ++i)
    {
        temp[k++] = arr[i];
    }
    for (; j <= last; ++j)
    {
        temp[k++] = arr[j];
    }
    k = first;
    for (i = 0; i < n; ++i)
    {
        arr[k] = temp[i];
        ++k;
    }
}
void mergeSort(int arr[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}
int main()
{
    int arr[] = {1, 4, 3, 7, 8, 4, 5, 6, 9, 1, 4, 6, 8, 9};
    mergeSort(arr, 0, 13);
    for (int i = 0; i < 14; ++i)
        cout << arr[i] << ' ';
}