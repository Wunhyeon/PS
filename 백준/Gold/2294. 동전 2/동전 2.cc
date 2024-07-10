#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, num;
ll a[10004]; // 가치저장
ll dp[10004];
ll inf = 10001;
int main()
{
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    fill(dp, dp + 10004, inf);
    dp[0] = 0;
    for (ll i = 0; i < n; i++) // i번째 인덱스
    {
        for (ll j = a[i]; j <= k; j++) // 가치. 가치가 j일때의 최소 카운트.
        {
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        }
    }

    if (dp[k] == inf)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << dp[k] << "\n";
    }
    return 0;
}

/*
2 5
5
1

ans : 1

2 10
2
3

ans : 4 (2*2 + 3*2)
*/