#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll t = a * b * c;
    ll arr[11];
    memset(arr, 0, sizeof(arr));
    ll p = 10;
    // cout << "t : " << t << "\n";
    while (t)
    {
        ll tmp = t % p;
        arr[tmp + 1]++;
        t /= p;
        // cout << "tmp : " << tmp << ", arr[tmp+1] : " << arr[tmp + 1] << "\n";
    }
    for (int i = 1; i < 11; i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}