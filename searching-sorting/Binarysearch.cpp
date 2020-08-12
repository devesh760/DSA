//BINARY SEARCH IMPLEMENTATION IN C++
//To search an element in an array using binary_search ,array must be sorted
//Time:log n
//Space: O(1)
#include <iostream>
using namespace std;
int binary_search(int arr[], int size, int num)
{
    int lower = 0, upper = size - 1, mid;
    while (lower <= upper)
    {
        mid = (lower + upper) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] < num)
            lower = mid + 1;
        else
            upper = mid - 1;
    }
    return -1;
}
int binary_search_using_recursion(int arr[], int size, int num)
{
    static int lower = 0, upper = size - 1, mid;
    if (lower <= upper)
    {
        mid = (lower + upper) / 2;
        if (arr[mid] == num)
            return mid;
        else if (arr[mid] < num)
            lower = mid + 1;
        else
            upper = mid - 1;
        return binary_search_using_recursion(arr, size, num);
    }
    else
        return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    cout << arr[binary_search_using_recursion(arr, 7, 2)];
}