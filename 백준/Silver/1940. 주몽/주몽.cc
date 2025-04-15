#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
ll a[10000004];
map<ll, bool> mp;
vector<ll> v;
int main()
{
    cin >> n >> m;
    int ans = 0;
    for (ll i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        mp[tmp] = true;
        v.push_back(tmp);
    }
    for (ll i = 0; i < v.size(); i++)
    {
        if (mp[m - v[i]])
        {
            ans++;
        }
    }
    cout << ans / 2 << "\n";

    return 0;
}