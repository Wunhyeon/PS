#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll mx = 1e6;
ll dp[1000004];

void trace(ll num)
{
    if (num == 0)
    {
        return;
    }
    cout << num << " ";
    if (num % 3 == 0 && dp[num] == dp[num / 3] + 1)
    {
        trace(num / 3);
    }
    else if (num % 2 == 0 && dp[num] == dp[num / 2] + 1)
    {
        trace(num / 2);
    }
    else if (num - 1 >= 0 && dp[num] == dp[num - 1] + 1)
    {
        trace(num - 1);
    }
}

ll go(ll num)
{
    if (num == 1)
    {
        dp[1] = 1;
        return 1;
    }

    if (dp[num])
    {
        return dp[num];
    }

    ll n1 = mx;
    ll n2 = mx;
    ll n3 = mx;
    ll cnt = 0;

    if (num % 3 == 0)
    {
        n1 = go(num / 3) + 1;
    }
    if (num % 2 == 0)
    {
        n2 = go(num / 2) + 1;
    }
    n3 = go(num - 1) + 1;

    cnt = min({n1, n2, n3});
    dp[num] = cnt;

    return cnt;
}

int main()
{
    cin >> n;
    cout << go(n) - 1 << "\n";
    trace(n);
    return 0;
}