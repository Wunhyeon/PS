#include <bits/stdc++.h>
using namespace std;
int a[54][54];
int cp[54][54];
int n, m;
vector<pair<int, int>> v;
vector<vector<int>> combi;
int mn = 1e9;
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};
int visited[54][54];
int floorCnt = 0;

void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << cp[i][j] << " ";
        }
        cout << "\n";
    }
}

void makeCombi(int start, int limit, vector<int> tmp)
{
    if (tmp.size() == limit)
    {
        combi.push_back(tmp);
        return;
    }
    for (int i = start + 1; i < v.size(); i++)
    {
        tmp.push_back(i);
        makeCombi(i, limit, tmp);
        tmp.pop_back();
    }
}

bool check()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cp[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
            {
                v.push_back({i, j});
            }
            if (a[i][j] == 0)
            {
                floorCnt++;
            }
        }
    }
    if (floorCnt == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    makeCombi(-1, m, {});

    for (int i = 0; i < combi.size(); i++)
    {
        copy(&a[0][0], &a[0][0] + 54 * 54, &cp[0][0]);
        memset(visited, 0, sizeof(visited));
        int fCnt = floorCnt;
        // 바이러스 활성화 (3)
        int t = 1;
        queue<pair<int, int>> q;
        for (int j = 0; j < combi[i].size(); j++)
        {
            int idx = combi[i][j];
            int y = v[idx].first;
            int x = v[idx].second;
            cp[y][x] = 3;
            q.push({y, x});
        }
        bool flag = false;
        while (q.size())
        {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++)
            {
                int curY = q.front().first;
                int curX = q.front().second;
                // cout << "curY : " << curY << ", curX : " << curX << "\n";
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    int nextY = curY + dirY[j];
                    int nextX = curX + dirX[j];
                    if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n && !visited[nextY][nextX] && (a[nextY][nextX] == 0 || a[nextY][nextX] == 2))
                    {
                        cp[nextY][nextX] = 3;
                        visited[nextY][nextX] = 1;
                        if (a[nextY][nextX] == 0)
                        {
                            fCnt--;
                        }
                        q.push({nextY, nextX});
                    }
                }
            }
            if (fCnt == 0)
            {
                flag = true;
                break;
            }
            t++;
        }
        // cout << "t : " << t << "\n";
        // print();
        // cout << "----------\n";
        if (flag)
        {
            mn = min(mn, t);
        }
    }

    if (mn == 1e9)
    {
        cout << -1 << "\n";
    }
    else
    {

        cout << mn << "\n";
    }
    return 0;
}