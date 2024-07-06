#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1004][1004];
int visited[1004][1004][2];
string s;
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};
struct str
{
    int y;
    int x;
    int b;
};
int inf = 987654321;
int mn = inf;

void bfs()
{
    queue<str> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;

    while (q.size())
    {
        int curY = q.front().y;
        int curX = q.front().x;
        int curB = q.front().b;
        int curD = visited[curY][curX][curB];
        q.pop();

        if (curY == n - 1 && curX == m - 1)
        {
            mn = min(mn, curD);
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dirY[i];
            int nextX = curX + dirX[i];
            if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && (!visited[nextY][nextX][curB] || curD + 1 < visited[nextY][nextX][curB]))
            {
                if (a[nextY][nextX] == 1)
                {
                    if (curB < 1)
                    {
                        visited[nextY][nextX][curB + 1] = curD + 1;
                        q.push({nextY, nextX, curB + 1});
                    }
                }
                else if (a[nextY][nextX] == 0)
                {
                    visited[nextY][nextX][curB] = curD + 1;
                    q.push({nextY, nextX, curB});
                }
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
        for (int j = 0; j < m; j++)
        {
            a[i][j] = s[j] - '0';
        }
    }

    bfs();

    if (mn >= inf)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << mn << "\n";
    }
    return 0;
}

/*
5 5
00000
11110
00000
01111
00000

9

6 5
00000
11110
00000
01111
01111
00010


*/