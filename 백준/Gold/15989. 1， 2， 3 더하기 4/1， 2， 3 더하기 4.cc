#include <bits/stdc++.h>
using namespace std;
int t;
int n;

int dp[10004];

int main()
{
    dp[0] = 1;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = i; j <= 10000; j++)
        {
            dp[j] += dp[j - i];
        }
    }

    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}