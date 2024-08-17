#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[104][104];
int cheeseCnt;
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int visited[104][104];

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

void dfs(int y, int x)
{
    // 외부공기표시
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dirY[i];
        int nextX = x + dirX[i];
        if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && !visited[nextY][nextX] && a[nextY][nextX] == 0)
        {
            dfs(nextY, nextX);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                cheeseCnt++;
            }
        }
    }

    int t = 0;
    // cout << "------\n";

    while (cheeseCnt)
    {
        memset(visited, 0, sizeof(visited));
        // print();
        // cout << "------\n";
        dfs(0, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int tmpCnt = 0;
                int y = i;
                int x = j;
                for (int k = 0; k < 4; k++)
                {
                    int nextY = y + dirY[k];
                    int nextX = x + dirX[k];
                    if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || a[y][x] != 1)
                    {
                        break;
                    }
                    if (visited[nextY][nextX] == 1)
                    {
                        tmpCnt++;
                    }
                    if (tmpCnt >= 2)
                    {
                        q.push({y, x});
                        break;
                    }
                }
            }
        }

        while (q.size())
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            a[y][x] = 0;
            cheeseCnt--;
        }
        t++;
    }
    cout << t << "\n";
    return 0;
}

/*
8 9
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 1 1 0
0 1 0 1 1 1 0 1 0
0 1 0 0 1 0 0 1 0
0 1 0 1 1 1 0 1 0
0 1 1 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0
*/