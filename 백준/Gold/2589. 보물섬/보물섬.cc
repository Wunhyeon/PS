#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
char a[54][54];
int mx = 0;
int visited[54][54];
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};
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
}

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y, x});
    while (q.size())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        int curCnt = visited[curY][curX];
        q.pop();

        mx = max(mx, curCnt);
        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dirY[i];
            int nextX = curX + dirX[i];
            if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && (!visited[nextY][nextX] || curCnt + 1 < visited[nextY][nextX]) && a[nextY][nextX] == 'L')
            {
                q.push({nextY, nextX});
                visited[nextY][nextX] = curCnt + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            a[i][j] = s[j];
        }
    }

    // cout << "input end" << "\n";
    // print();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'L')
            {
                memset(visited, 0, sizeof(visited));
                bfs(i, j);
            }
        }
    }

    cout << mx - 1 << "\n";

    return 0;
}