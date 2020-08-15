#include <iostream>
using namespace std;
void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
int main()
{
    int arr[] = {2, 1, 6, 2, 8, 5, 10};
    selection_sort(arr, 7);
    for (int i = 0; i < 7; ++i)
        cout << arr[i] << ' ';
}