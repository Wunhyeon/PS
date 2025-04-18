#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B, C;

ll go(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a % C;
    }

    ll ret = go(a, b / 2);
    ret = (ret * ret) % C;
    if (b % 2 != 0)
    {
        ret = (ret * a) % C;
    }

    return ret;
}

int main()
{
    cin >> A >> B >> C;
    cout << go(A, B) << "\n";
    return 0;
}