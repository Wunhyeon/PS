#include <bits/stdc++.h>
using namespace std;
int n;
int a[104][104];
int visited[104][104];
int mx = 0;
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};
int mxDiv = 0;

void dfs(int y, int x, int h)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dirY[i];
        int nextX = x + dirX[i];
        if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n && !visited[nextY][nextX] && a[nextY][nextX] > h)
        {
            dfs(nextY, nextX, h);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }

    for (int i = 0; i <= mx; i++) // 물높이
    {
        int tmpCnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (!visited[j][k] && a[j][k] > i)
                {
                    tmpCnt++;
                    dfs(j, k, i);
                }
            }
        }
        mxDiv = max(mxDiv, tmpCnt);
    }

    cout << mxDiv << "\n";

    return 0;
}