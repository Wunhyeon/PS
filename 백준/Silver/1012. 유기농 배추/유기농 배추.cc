#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
int a[54][54];
int visited[54][54];
vector<int> dirY = {1, -1, 0, 0};
vector<int> dirX = {0, 0, 1, -1};

void dfs(int curY, int curX)
{
    // cout << "curY : " << curY << ", curX : " << curX << "\n";
    visited[curY][curX] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nextY = curY + dirY[i];
        int nextX = curX + dirX[i];
        if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && a[nextY][nextX] && !visited[nextY][nextX])
        {
            dfs(nextY, nextX);
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 54; i++)
        {
            for (int j = 0; j < 54; j++)
            {
                a[i][j] = 0;
                visited[i][j] = 0;
            }
        }
        cin >> m >> n >> k;
        // cout << "m : " << m << ", n : " << n << ", k : " << k << "\n";
        for (int i = 0; i < k; i++)
        {
            int i1, i2;

            cin >> i2 >> i1;
            a[i1][i2] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1 && !visited[i][j])
                {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}