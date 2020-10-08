#include <bits/stdc++.h>
using namespace std;
#define inf 10000
void dijshtra(int[][6], int[], int);
int min(int[], bool[]);
int main()
{

    int path[6];
    int adj[6][6] = {
        inf,2,4,inf,inf,inf,
        inf,inf,1,7,inf,inf,
        inf,inf,inf,inf,3,inf,
        inf,inf,inf,inf,2,1,
        inf,inf,inf,2,inf,5,
        inf,inf,inf,inf,inf,inf,
    };
    int src;
    cout << "Enter source and destination";
    cin >> src;
    dijshtra(adj, path, src);
    for (int i = 0; i < 6; i++)
    {
        if (path[i] == inf)
            cout << "Inf" << ' ';
        else
            cout << path[i] << ' ';
    }
    return 0;
}
void dijshtra(int adj[][6], int path[], int src)
{
    for (int i = 0; i < 6; ++i)
    {
        path[i] = adj[src][i];
    }
    bool visited[6];
    memset(visited, 0, sizeof(bool) * 6);
    while (1)
    {
        int minV = min(path, visited);
        if (minV == 0)
            break;
        visited[minV] = true;
        for (int i = 0; i < 6; ++i)
        {
            if (adj[minV][i] != inf && !visited[i])
            {
                if (adj[minV][i] + path[minV] < path[i])
                {
                    path[i] = adj[minV][i] + path[minV];
                }
            }
        }
    }
}

int min(int path[], bool visited[])
{
    int minI = 0;
    for (int i = 0; i < 6; ++i)
    {
        if (!visited[i] && path[minI] > path[i])
        {
            minI = i;
        }
    }
    return minI;
}
