#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeNumInWindow(vector<int> &array, int k)
{
    vector<int> ans(array.size() - k + 1, 0);
    int negNumIdx = 0, i = 0;
    k--;
    int ansIdx = 0;
    while (k < array.size())
    {
        while (negNumIdx <= k)
        {
            if (array[negNumIdx] < 0)
            {
                if (negNumIdx >= i && negNumIdx <= k)
                {
                    ans[ansIdx] = array[negNumIdx];
                    break;
                }
            }
            negNumIdx++;
        }
        ansIdx++;
        i++;
        k++;
    }
    return ans;
}
int main()
{
    vector<int> v = {1, 2, 1, -2, 3, -4, 5, 6, 7};
    v = firstNegativeNumInWindow(v, 1);
    for (auto it : v)
    {
        cout << it << ' ';
    }
}
