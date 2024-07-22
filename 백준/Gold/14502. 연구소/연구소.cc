#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10][10];
int cp[10][10];
int visited[10][10];
vector<pair<int, int>> vv;
vector<vector<int>> combIdx;
vector<pair<int, int>> virus;
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};
int mx;

void makeCombi(int start, int limit, vector<int> v)
{
    if (v.size() == limit)
    {
        combIdx.push_back(v);
    }
    else
    {
        for (int i = start + 1; i < vv.size(); i++)
        {
            v.push_back(i);
            makeCombi(i, limit, v);
            v.pop_back();
        }
    }
}

void virusGo()
{
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    for (int i = 0; i < virus.size(); i++)
    {
        int y = virus[i].first;
        int x = virus[i].second;
        q.push({y, x});
        visited[y][x] = 1;
    }

    while (q.size())
    {
        auto cur = q.front();
        int curY = cur.first;
        int curX = cur.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = curY + dirY[i];
            int nextX = curX + dirX[i];

            if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && !visited[nextY][nextX] && cp[nextY][nextX] != 1)
            {
                q.push({nextY, nextX});
                visited[nextY][nextX] = 1;
                cp[nextY][nextX] = 2;
            }
        }
    }
}

int cntZero()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (cp[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0)
            {
                vv.push_back({i, j});
            }
            else if (a[i][j] == 2)
            {
                virus.push_back({i, j});
            }
        }
    }

    makeCombi(-1, 3, {});

    for (int i = 0; i < combIdx.size(); i++)
    {
        copy(&a[0][0], &a[0][0] + 10 * 10, &cp[0][0]);
        // 벽세우기
        for (int j = 0; j < combIdx[i].size(); j++)
        {
            int idx = combIdx[i][j];
            int y = vv[idx].first;
            int x = vv[idx].second;
            cp[y][x] = 1;
        }
        // 바이러스 확산
        virusGo();
        // 카운트
        int cnt = cntZero();
        mx = max(mx, cnt);
    }

    cout << mx << "\n";

    return 0;
}