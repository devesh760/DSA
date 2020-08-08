#include <bits/stdc++.h>
using namespace std;
vector<int> specialArray(vector<int>v)
{
    vector <int>mv;
    long long product = 1;
    for(auto it:v)
          product*=it;
    for(auto it:v)
         mv.push_back(product/it);
    return mv;
}
int main()
{
    int n;
    cin >>n;
    vector<int>v(n);
    for(int i=0;i<n;++i)
    {
          cin >> v[i];
    }
   v  =  specialArray(v);
     for(auto it:v)
         cout << it << ' ';
     return 0;
}
