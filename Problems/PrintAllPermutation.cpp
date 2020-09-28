#include <bits/stdc++.h>
using namespace std;
int printAllPermutation(string str, int i, int n)
{
    static int c;
    if (i == n)
    {
        c++;
        cout << str << ' ';
        // return c;
    }
    else
    {
        for (int j = i; j < n; ++j)
        {
            swap(str[i], str[j]);
            printAllPermutation(str, i + 1, n);
            swap(str[i],str[j]);
        }
    }
    return c;
}
int main()
{
    string str;
    cin >> str;
    cout << printAllPermutation(str, 0, str.length());
}
