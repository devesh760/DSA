//QuickSort Algorithm with the help of templates for any type of value except
//defined
#include <bits/stdc++.h>
using namespace std;
template<typename T>
int partition(T arr[], int l, int h)
{
    T pivot = arr[l];
    int i = l, j = h;
    do
    {
        do{ i++;} while (arr[i] <= pivot);
        do{j--;} while (arr[j] > pivot);
        if (i < j) swap(arr[i], arr[j]);
    } while (i < j);
    swap(arr[j], arr[l]);
    return j;
}
template<typename T>
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int j = partition(arr, l, h);
        quickSort(arr, l, j);
        quickSort(arr, j + 1, h);
    }
}
int main()
{
    int arr[] = {6, 2, 4, 8, 9, 12, 54, 9999};
    quickSort(arr, 0, 8);
    for (auto it : arr)
        cout << it << ' ';
    return 0;
}
