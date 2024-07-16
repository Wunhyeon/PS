#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
ll n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll cnt = 0;
        while (n / 5 != 0)
        {
            cnt += n / 5;
            n = n / 5;
        }
        cout << cnt << "\n";
    }
    return 0;
}