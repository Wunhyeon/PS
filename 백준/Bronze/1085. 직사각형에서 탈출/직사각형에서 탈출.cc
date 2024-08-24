#include <bits/stdc++.h>
using namespace std;
int x, y, w, h;
int main()
{
    cin >> x >> y >> w >> h;
    int a = w - x;
    int b = h - y;
    int c = x - 0;
    int d = y - 0;
    cout << min({a, b, c, d}) << "\n";
    return 0;
}