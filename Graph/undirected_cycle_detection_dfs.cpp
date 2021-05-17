#include <bits/stdc++.h>
using namespace std;
vector<bool>visited;
vector<vector<int>>adj;
bool detect_cycle(int src,int par){
    visited[src] = true;
    for(auto it:adj[src]){
        if(it!=par){
            if(visited[it]){
                return true;
            }
            else{
                return detect_cycle(it,src);
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    adj.resize(n+1);
    visited.resize(n+1);
    for(int i=1;i<n;++i){
       int u,v; cin >> u >> v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    bool flag=true;
    for(int i=1;i<n+1;++i){
        if(!visited[i]){
            if(detect_cycle(i,-1)){
                flag=false;
            }
        }
    }
    if(flag){
        cout << "Cycle not detected\n";
    }
    else{
        cout << "Cycle detected\n";
    }
    return 0;
}