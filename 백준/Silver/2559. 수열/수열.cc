#include <bits/stdc++.h>
using namespace std;
int a, b;
int c;
int psum[100009];
int ret = -10000009;
vector<int> v;
int main()
{
    cin >> a;
    cin >> b;
    for (int i = 1; i <= a; i++)
    {
        cin >> c;
        psum[i] = psum[i - 1] + c;
    }

    for (int i = b; i <= a; i++)
    {
        ret = max(ret, psum[i] - psum[i - b]);
    }

    cout << ret << '\n';
    return 0;
}