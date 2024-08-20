#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a;
ll n;
ll num;
ll mn = 1e11;
pair<ll, ll> ans;
int main()
{
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> num;
        a.push_back(num);
    }

    ll l = 0;
    ll r = a.size() - 1;
    while (l < r)
    {
        ll sum = a[l] + a[r];

        if (abs(sum) < mn)
        {
            mn = abs(sum);
            ans = {a[l], a[r]};
        }

        if (sum < 0)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}

/*
4
-10 0 100 200

ans : -10 0
*/