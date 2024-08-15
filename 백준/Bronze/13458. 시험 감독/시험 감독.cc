#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<ll> v;
ll b, c;
ll num;
int main()
{
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    cin >> b >> c;
    ll sum = n;

    for (ll i = 0; i < v.size(); i++)
    {
        ll p = v[i] - b;
        if (p <= 0)
        {
            continue;
        }
        sum += p / c;
        if (p % c != 0)
        {
            sum++;
        }
    }

    cout << sum << "\n";

    return 0;
}