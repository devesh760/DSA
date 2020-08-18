#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j > 0; --j)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
                break;
        }
    }
}
int main()
{
    int arr[] = {2, 6, 4, 8, 1, 6, 9};
    insertionSort(arr, 7);
    for (int i = 0; i < 7; ++i)
        cout << arr[i] << ' ';
    return 0;
}