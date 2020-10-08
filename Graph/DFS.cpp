#include <bits/stdc++.h>
using namespace std;
bool status[4];
void dfs(int[][4], int);
int main()
{

    int adj[4][4];
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << "IS there a path from v" << i + 1 << "to v" << j + 1 << "(1-yes,0-No)";
            cin >> adj[i][j];
        }
    }
    int src;
    cout << "Enter a source vertex:";
    cin >> src;
    dfs(adj, src);
} 
void dfs(int adj[][4], int v)
{
    stack<int> s;
    s.push(v);
    while (!s.empty())
    {
        v = s.top();
        s.pop();
        if (!status[v])
        {
            cout << v << ' ';
            status[v] = true;
        }
        for (int i = 3; i >= 0; --i)
        {
            if (adj[v][i] && !status[i])
                s.push(i);
        }
    }
}