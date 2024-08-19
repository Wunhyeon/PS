#include <bits/stdc++.h>
using namespace std;
int a[1004][1004];
int n, m;
int tCnt;
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "---------\n";
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
            {
                tCnt++;
            }
            if (a[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }
    // cout << "tCnt-1 : " << tCnt << "\n";
    if (tCnt == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    int t = 0;
    while (q.size())
    {
        int qSize = q.size();
        bool flag = false;
        for (int j = 0; j < qSize; j++)
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nextY = y + dirY[i];
                int nextX = x + dirX[i];
                if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && a[nextY][nextX] == 0)
                {
                    a[nextY][nextX] = 1;
                    q.push({nextY, nextX});
                    tCnt--;
                }
            }
            if (tCnt == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            break;
        }

        t++;
        // print();
    }

    // cout << "tCnt : " << tCnt << "\n";
    if (tCnt)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << t + 1 << "\n";
    }

    return 0;
}