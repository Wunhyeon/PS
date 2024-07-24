#include <bits/stdc++.h>
using namespace std;
int n, m;
typedef long long ll;
ll a[250004];
ll p[250004];
int main()
{
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += a[i];
        p[i + 1] = sum;
    }

    ll mx = 0;
    ll cnt = 0;
    for (ll i = m; i <= n; i++)
    {
        if (p[i] - p[i - m] > mx)
        {
            mx = p[i] - p[i - m];
            cnt = 1;
        }
        else if (p[i] - p[i - m] == mx)
        {
            cnt++;
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     cout << p[i] << " ";
    // }
    // cout << "\n";

    if (mx == 0)
    {
        cout << "SAD" << "\n";
    }
    else
    {
        cout << mx << "\n";
        cout << cnt << "\n";
    }
    return 0;
}