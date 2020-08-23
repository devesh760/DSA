//Problem-statement:
#include <bits/stdc++.h>
using namespace std;
float Knapsack(vector<int> p, vector<int> w, float size)
{
    float MaxProfit{};
    float curSize{};
    vector<float> pByw;
    bool visited[pByw.size()];
    for (int i = 0; i < p.size(); ++i)
        pByw.push_back(p[i] / (float)w[i]);
    while (1)
    {
        float max = INT_MIN;
        int j = -1;
        for (int i = 0; i < p.size(); ++i)
        {
            if (max < pByw[i] && !visited[i])
            {
                j = i;
                max = pByw[i];
            }
        }

        if (j == -1)
            break;
        else
        {
            int a = size - curSize;
            if (a <= 0)
                break;
            else if (w[j] >= a)
            {
                curSize += a;
                MaxProfit += pByw[j] * a;
            }
            else
            {
                curSize += w[j];
                MaxProfit += p[j];
            }
        }
        visited[j] = true;
    }
    return MaxProfit;
}
int main()
{
    int n, k;
    float knapsackSize;
    cin >> n >> knapsackSize;
    vector<int> profits;
    vector<int> weights;
    k = n;
    while (n--)
    {
        int a;
        cin >> a;
        profits.push_back(a);
    }
    while (k--)
    {
        int a;
        cin >> a;
        weights.push_back(a);
    }
    float maxProfit = Knapsack(profits, weights, knapsackSize);
    cout << "Maximum Profit: " << maxProfit;
    return 0;
}