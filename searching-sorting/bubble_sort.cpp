//BUBBLE SORT ALGORITHM TO SORT AN ARRAY OF ELEMENTS
//AVG-TIME:O(N^2)
//SPACE: O(1)
#include <iostream>
using namespace std;
void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        bool issorted = false;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                issorted = 1;
            }
        }
        if (!issorted)
            break;
    }
}
int main()
{
    int arr[] = {1, 23, 32, 2, 1, 20, 49};
    bubble_sort(arr, 8);
    for (int it = 0; it < 8; ++it)
        cout << arr[it] << ' ';
    return 0;
}