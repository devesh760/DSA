#include <bits/stdc++.h>
using namespace std;
#define I 10000;
void Prim(int[][8], int[][6]);
int main()
{
    int cost[8][8], t[2][6];
    for (int i = 1; i < 8; ++i)
    {
        for (int j = 1; j < 8; ++j)
        {
            cout << "Enter cost of v" << i << "to v" << j << " or enter 0";
            cin >> cost[i][j];
            if (!cost[i][j])
                cost[i][j] = I;
        }
    }
}
void Prim(int cost[][8], int t[][6])
{
    int near[8];
    for (int i = 0; i < 8; ++i)
        near[i] = I;
    int u, v;
    int min = INT_MAX;
    for (int i = 1; i < 8; ++i)
    {
        for (int j = 1; j < 8; ++j)
        {
            if (cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;
    for (int i = 1; i < 7; ++i)
    {
        if (near[i])
        {
            if (cost[i][u] < cost[i][v])
                near[i] = v;
            else
                near[i] = u;
        }
    }
    for (int i = 0; i < 6; ++i)
    {
        min = INT_MAX;
        int k;
        for (int j = 1; j < 7; j++)
        {
            if (near[j])
            {
                if (cost[j][near[j]] < min)
                {
                    min = cost[j][near[j]];
                    k = j;
                }
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;
        for (int j = 1; j < 8; ++j)
        {
            if (near[j])
            {
                if (cost[j][k] < cost[j][near[j]])
                    near[j] = k;
            }
        }
    }
}