#include <bits/stdc++.h>
using namespace std;
char c[54][54];
string s;
int y, x;

vector<int> dirY = {1, -1, 0, 0};
vector<int> dirX = {0, 0, 1, -1};

int visited[54][54];

int bfs(pair<int, int> d)
{

    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;
    q.push(d);
    visited[d.first][d.second] = 1;

    int mm = 0;
    while (q.size())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        int curDepth = visited[curY][curX];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dirY[i];
            int nextX = curX + dirX[i];
            int nextDepth = curDepth + 1;
            if (nextY >= 0 && nextY < y && nextX >= 0 && nextX < x && (!visited[nextY][nextX] || visited[nextY][nextX] > nextDepth) && c[nextY][nextX] == 'L')
            {
                visited[nextY][nextX] = nextDepth;
                q.push({nextY, nextX});
            }
            else
            {
                mm = curDepth;
            }
        }
    }
    return mm - 1;
}

int main()
{
    cin >> y >> x;
    for (int i = 0; i < y; i++)
    {
        cin >> s;
        for (int j = 0; j < x; j++)
        {
            c[i][j] = s[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (c[i][j] == 'L')
            {
                int tmp = bfs({i, j});
                ans = max(tmp, ans);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}