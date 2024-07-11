#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1004]; //  dp[n]은 돌이 n개일때 선공이 이기나, 후공이 이기나. 선공 : 0, 후공 : 1
int main()
{
    cin >> n;
    // int cnt = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 1;
    dp[5] = 0;

    for (int i = 6; i <= n; i++)
    {
        dp[i] = !(dp[i - 1] && dp[i - 3]);
    }
    // cout << dp[n] << "\n";

    if (!dp[n])
    {
        cout << "SK" << "\n";
    }
    else
    {
        cout << "CY" << "\n";
    }

    return 0;
}