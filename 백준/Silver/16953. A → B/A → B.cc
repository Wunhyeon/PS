#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
ll ans = 1e9 + 1;
void go(ll num, ll cnt)
{
    if (num == b)
    {
        ans = min(ans, cnt);
        return;
    }

    if (num * 2 <= b && cnt + 1 < ans)
    {
        go(num * 2, cnt + 1);
    }
    if ((num * 10) + 1 <= b && cnt + 1 < ans)
    {
        go((num * 10) + 1, cnt + 1);
    }
}

int main()
{
    cin >> a >> b;
    go(a, 0);

    if (ans == 1e9 + 1)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ans + 1 << "\n";
    }
    return 0;
}
/*
430000000 503270511
-1
*/