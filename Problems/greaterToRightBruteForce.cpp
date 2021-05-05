#include <iostream>
#include <vector>
using namespace std;
void greaterToNext(vector<int>arr){
    int n = arr.size();
    for(int i=0;i<n;++i){
        bool flag = false;
        for(int j=i+1;j<n;++j){
            if(arr[i]<arr[j]){
                cout << arr[j] << ' ' ;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << -1 << ' ';
        }
    }
}
int main(){
    vector<int>arr = {1,3,0,0,1,2,4};
    greaterToNext(arr);
}