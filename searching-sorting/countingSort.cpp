#include <iostream>
void countingSort(int arr[],int,int);
using namespace std;
int main(){
    int arr[] = {23,5,33,82,3,24,5,83,6,3};
    countingSort(arr,10,83);
    for(auto it:arr){
        cout << it << ' ';
    }
    return 0;
}
void countingSort(int arr[],int size,int range){
    range++;
    int count[range] = {0};
    for(int i=0;i<size;++i)
        count[arr[i]]++;
    for(int i=1;i<range;++i)
        count[i]+=count[i-1];
    int sorted[size];
    for(int i=0;i<size;++i){
        sorted[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<size;i++){
        arr[i] = sorted[i];
    }
}