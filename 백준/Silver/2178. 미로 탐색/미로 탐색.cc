#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int a[104][104];
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};
int visited[104][104];
int ans;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            a[i][j] = s[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (q.size())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        int visitCnt = visited[curY][curX];
        q.pop();

        if (curY == n - 1 && curX == m - 1)
        {
            ans = visitCnt;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dirY[i];
            int nextX = curX + dirX[i];

            if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && !visited[nextY][nextX] && a[nextY][nextX] != 0)
            {
                q.push({nextY, nextX});
                visited[nextY][nextX] = visitCnt + 1;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}