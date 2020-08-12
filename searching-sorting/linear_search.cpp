// LINEAR SEARCH (ITERATIVE AND RECURSIVE) IMPLEMENTATION IN C++
//TIME:O(n)
//SPACE:O(1)

#include <iostream>
using namespace std;
int linear_search(int arr[], int size, int num)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == num)
            return i;
    }
    return -1;
}
int linear_search_by_recursion(int arr[], int size, int num)
{
    if (size == -1)
        return -1;
    else if (arr[size - 1] == num)
        return size - 1;
    else
        return linear_search_by_recursion(arr, size - 1, num);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    cout << arr[linear_search(arr, 6, 6)];
    cout << arr[linear_search_by_recursion(arr, 6, 6)];
}