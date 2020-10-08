// Warshalls algo for transitive closure

#include <bits/stdc++.h>
using namespace std;
void warshall(int[][4], int[][4]);
int main()
{
    int adj[4][4], path[4][4];
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << "Is There Path From v[" << i + 1 << ']' << "to v[" << j + 1 << "](y/n)";
            char ch;
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
                adj[i][j] = 1;
            else
                adj[i][j] = 0;
        }
    }
    warshall(adj, path);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
void warshall(int adj[][4], int path[][4])
{
    for (int k = 1; k <= 4; ++k)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                int a = adj[i][j] || adj[i][k] && adj[k][j];
                path[i][j] = a;
                adj[i][j] = a;
            }
        }
    }
}

