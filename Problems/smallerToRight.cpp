#include <bits/stdc++.h>
using namespace std;
vector<int> smallerToRight(vector<int>v){
    stack<int>s;
    vector<int>ans;
    for(int i=v.size()-1;i>=0;--i){
        while(!s.empty() && s.top()>v[i])
            s.pop();
        if(s.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(s.top());
        }
        s.push(v[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int> v = {31,41,51,61};
    v = smallerToRight(v);
    for(auto it: v){
        cout << it << ' ' ;
    }
    return 0;
}
