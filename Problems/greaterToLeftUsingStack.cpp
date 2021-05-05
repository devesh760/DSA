#include <bits/stdc++.h>
using namespace std;
vector<int> greaterToLeft(vector<int>v){
        stack<int>s;
        vector<int>ans;
        for(int i=0;i<v.size();++i){
            while(!s.empty() && s.top()<v[i])
                s.pop();
            if(s.empty()){
                 ans.push_back(-1);
            }
            else{
                ans.push_back(s.top());
            }
            s.push(v[i]);
        }
        return ans;
}
int main(){
    vector<int>v = {31,41,51,61};
    v = greaterToLeft(v);
    for(auto it: v){
        cout << it << ' ';
    }
}
