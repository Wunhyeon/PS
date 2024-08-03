#include <bits/stdc++.h>
using namespace std;
int h, w, n, m;
int main()
{
    cin >> h >> w >> n >> m;

    int hCnt = h / (n + 1);
    if (h % (n + 1) != 0)
    {
        hCnt++;
    }
    int wCnt = w / (m + 1);
    if (w % (m + 1) != 0)
    {
        wCnt++;
    }
    cout << hCnt * wCnt << "\n";

    return 0;
}