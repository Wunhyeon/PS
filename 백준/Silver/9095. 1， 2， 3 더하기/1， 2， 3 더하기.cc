#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int dp[15];

int go(int num)
{
    if (dp[num])
    {
        return dp[num];
    }
    if (num == 0)
    {
        return 1;
    }
    if (num < 0)
    {
        return 0;
    }

    int n1 = go(num - 1);
    int n2 = go(num - 2);
    int n3 = go(num - 3);
    dp[num] = n1 + n2 + n3;
    return n1 + n2 + n3;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << go(n) << "\n";
    }
    return 0;
}