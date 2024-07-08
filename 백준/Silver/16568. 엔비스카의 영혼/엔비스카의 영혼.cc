#include <bits/stdc++.h>
using namespace std;
int N, A, B;
int mn = 10000001;
int dp[1000004]; // 위치가 n일때의 최소 초

int main()
{
    cin >> N >> A >> B;
    // go(N, A, B, 0);

    for (int i = 1; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i - A - 1 >= 0)
        {
            dp[i] = min(dp[i - A - 1] + 1, dp[i]);
        }
        if (i - B - 1 >= 0)
        {
            dp[i] = min(dp[i - B - 1] + 1, dp[i]);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}