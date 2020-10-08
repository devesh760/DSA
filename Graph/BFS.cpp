#include <bits/stdc++.h>
using namespace std;
bool visited[4];
void BFS(int[][4]);
int main()
{
    memset(visited,0,4*sizeof(bool));
    int adj[4][4];
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << "Is There Any Path from v" << i + 1 << " to v" << j + 1 << "(1-yes,0-no)";
            cin >> adj[i][j];
        }
    }
    BFS(adj);
}
void BFS(int adj[][4]){
    queue<int>que;
    que.push(2);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        if(!visited[v]){
            cout << v << ' ';
            visited[v] = true;
        }
        for(int i=3;i>=0;--i){
            if(adj[v][i] == 1 && visited[i] == false){
                que.push(i);
            }
        }
    }
}