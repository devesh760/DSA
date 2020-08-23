#include <iostream>
using namespace std;
void printAllSubArrays(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            cout << "[ ";
            for (int k = i; k <= j; ++k)
            {
                cout << arr[k] << ' ';
            }
            cout << "]\n";
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    printAllSubArrays(arr, 5);
}