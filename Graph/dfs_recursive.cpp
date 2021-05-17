#include<bits/stdc++.h>
using namespace std;
vector<bool>isVisited={false};
void dfs(vector<vector<int>>adj,int src){
    isVisited[src] = true;
    cout << src << ' ' ;
    for(auto i:adj[src]){
        if(isVisited[i]==false)
            dfs(adj,i);
    }
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;++i){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    isVisited.resize(n+1,false);
    dfs(adj,1);
    return 0;
}