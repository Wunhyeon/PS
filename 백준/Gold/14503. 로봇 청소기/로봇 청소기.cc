#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[54][54];
int r, c, d;
int dirY[4] = {-1, 0, 1, 0};
int dirX[4] = {0, 1, 0, -1};
int visited[54][54];
int main()
{
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    // cout << "--------- \n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = 1;
    int cnt = 1;

    while (q.size())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        // cout << "curY : " << curY << ", curX : " << curX << ", d : " << d << "\n";
        q.pop();

        bool flag = true;

        for (int i = 0; i < 4; i++)
        {
            d = d - 1;
            if (d == -1)
            {
                d = 3;
            }
            int nextY = curY + dirY[d];
            int nextX = curX + dirX[d];
            if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && a[nextY][nextX] != 1 && !visited[nextY][nextX])
            {
                q.push({nextY, nextX});
                visited[nextY][nextX] = 1;
                flag = false;
                cnt++;
                break;
            }
        }
        if (flag)
        {
            int tmpD = d - 2;
            if (tmpD < 0)
            {
                tmpD = 4 + tmpD;
            }
            int nextY = curY + dirY[tmpD];
            int nextX = curX + dirX[tmpD];
            // cout << "d : " << d << ", tmpD : " << tmpD << "\n";
            // cout << "nextY : " << nextY << ", nextX : " << nextX << "\n";
            if (a[nextY][nextX] != 1)
            {
                // cout << "flag" << "a[nextY][nextX] : " << a[nextY][nextX] << "\n";
                q.push({nextY, nextX});
            }
        }
    }

    // int cnt2 = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (visited[i][j])
    //         {
    //             cnt2++;
    //         }
    //     }
    // }

    cout << cnt << "\n";
    // cout << cnt2 << "\n";

    return 0;
}

/*
1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우, 반시계 방향으로 90도 회전한다.
3-1. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
3-2. 1번으로 돌아간다.

북 -> 서 -> 남 -> 동
d가
0인 경우 북쪽,
1인 경우 동쪽,
2인 경우 남쪽,
3인 경우 서쪽을 바라보고 있는 것이다.
*/