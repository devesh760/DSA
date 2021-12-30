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

int binary_search_recursive(int arr[],int low,int high,int num){
    if(low>high)
      return -1;
    int mid = low + (high-low)/2;
    if(arr[mid]==num)
      return mid;
    else if(arr[mid]>num)
      return binary_search_recursive(arr,low,mid-1,num);
    else
      return binary_search_recursive(arr,mid+1,high,num);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    cout << arr[binary_search_using_recursion(arr, 7, 2)];
}
