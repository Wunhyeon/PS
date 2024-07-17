#include <bits/stdc++.h>
using namespace std;
int N, r, c;
int cnt = 0;

void go(int y1, int x1, int y2, int x2)
{
    // cout << "y1 : " << y1 << ", x1 : " << x1 << ", y2 : " << y2 << ", x2 : " << x2 << "\n";
    if (y1 + 1 == y2 && x1 + 1 == x2)
    {
        // cout << y1 << x1 << "\n";
        if (y1 == r && x1 == c)
        {
            cout << cnt << "\n";
            return;
        }
        cnt++;

        // cout << y1 << x2 << "\n";
        if (y1 == r && x2 == c)
        {
            cout << cnt << "\n";
            return;
        }
        cnt++;
        // cout << y2 << x1 << "\n";
        if (y2 == r && x1 == c)
        {
            cout << cnt << "\n";
            return;
        }
        cnt++;
        // cout << y2 << x2 << "\n";
        if (y2 == r && x2 == c)
        {
            cout << cnt << "\n";
            return;
        }
        cnt++;
        return;
    }

    int yHalf = (y1 + y2) / 2;
    int xHalf = (x1 + x2) / 2;

    if (r <= yHalf && c <= xHalf)
    {
        go(y1, x1, yHalf, xHalf);
    }
    else if (r <= yHalf && c > xHalf)
    {
        cnt += (yHalf - y1 + 1) * (xHalf - x1 + 1);
        go(y1, xHalf + 1, yHalf, x2);
    }

    else if (r > yHalf && c <= xHalf)
    {
        cnt += (yHalf - y1 + 1) * (xHalf - x1 + 1);
        cnt += (yHalf - y1 + 1) * (x2 - xHalf + 1 - 1);
        go(yHalf + 1, x1, y2, xHalf);
    }

    else if (r > yHalf && c > xHalf)
    {
        cnt += (yHalf - y1 + 1) * (xHalf - x1 + 1);
        cnt += (yHalf - y1 + 1) * (x2 - xHalf + 1 - 1);
        cnt += (y2 - yHalf + 1 - 1) * (xHalf - x1 + 1);
        go(yHalf + 1, xHalf + 1, y2, x2);
    }
}

int main()
{
    cin >> N >> r >> c;
    int p = pow(2, N);

    go(0, 0, p - 1, p - 1);

    return 0;
}