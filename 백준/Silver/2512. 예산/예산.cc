#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> v;
ll num;
ll m;
ll ans = m;
ll mx;
bool go(ll mid)
{
    // cout << "mid : " << mid << "\n";
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll num = v[i];
        if (num > mid)
        {
            sum += mid;
        }
        else
        {
            sum += num;
        }
    }
    if (sum > m)
    {
        return false;
    }
    else if (sum <= m)
    {
        return true;
    }
    return true;
}

int main()
{
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
        mx = max(mx, num);
    }
    cin >> m;
    ll left = 0;
    ll right = m;
    while (right >= left)
    {
        ll mid = (left + right) / 2;
        bool res = go(mid);
        if (res)
        {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    ans = min(mx, ans);
    cout << ans << "\n";
    return 0;
}