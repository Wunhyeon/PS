#include <bits/stdc++.h>
using namespace std;
int a[24][24];
int n;
int level = 2;
int eat = 0;
int t;
pair<int, int> loc;
vector<pair<int, int>> v[14];
int d[24][24];
int inf = 1e9;
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};
int eatten[24][24];

void printA()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void printD()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] == inf)
            {
                cout << "inf" << " ";
            }
            else
            {
                cout << d[i][j] << " ";
            }
        }
        cout << "\n";
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
            if (a[i][j] == 9)
            {
                loc = {i, j};
            }

            if (a[i][j] >= 1 && a[i][j] <= 8)
            {
                v[a[i][j]].push_back({i, j});
            }
        }
    }

    // cout << "input end" << "\n";

    bool flag = false;

    for (int i = 1; i <= 8; i++)
    {
        // cout << "i : " << i << ", v[i].size : " << v[i].size() << "\n";
        if (v[i].size())
        {
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        cout << 0 << "\n";
        return 0;
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, loc});

    while (flag)
    {
        fill(&d[0][0], &d[0][0] + 24 * 24, inf);
        d[loc.first][loc.second] = 0;

        while (pq.size())
        {
            int price = pq.top().first;
            int curY = pq.top().second.first;
            int curX = pq.top().second.second;
            pq.pop();
            if (price > d[curY][curX])
            {

                continue;
            }

            for (int i = 0; i < 4; i++)
            {
                int nextY = curY + dirY[i];
                int nextX = curX + dirX[i];

                if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)
                {
                    continue;
                }
                if (price + 1 >= d[nextY][nextX] || a[nextY][nextX] > level)
                {
                    continue;
                }
                d[nextY][nextX] = price + 1;
                pq.push({price + 1, {nextY, nextX}});
            }
        }
        // printD();
        // cout << "-------------------\n";
        // 먹을 수 있는 물고기들
        pair<int, int> can = {-1, -1};
        int mn = 1e9;
        for (int i = 1; i < level; i++)
        {
            if (i >= 8)
            {
                break;
            }
            for (int j = 0; j < v[i].size(); j++)
            {
                int y = v[i][j].first;
                int x = v[i][j].second;

                if (y == loc.first && x == loc.second)
                {
                    continue;
                }

                if (!eatten[y][x])
                {
                    if (d[y][x] == inf)
                    {
                        continue;
                    }
                    if (d[y][x] < mn)
                    {
                        mn = d[y][x];
                        can = {y, x};
                    }
                    else if (d[y][x] == mn)
                    {
                        if (y < can.first)
                        {
                            can = {y, x};
                        }
                        else if (y == can.first && x < can.second)
                        {
                            can = {y, x};
                        }
                    }
                }
            }
        }

        // cout << "mn : " << mn << "\n";
        // cout << "can.first : " << can.first << ", can.second : " << can.second << "\n";

        if (can.first == -1 || can.second == -1)
        {
            flag = false;
            break;
        }

        t += d[can.first][can.second];
        a[loc.first][loc.second] = 0;
        a[can.first][can.second] = 9;
        eatten[can.first][can.second] = 1;
        loc = {can.first, can.second};
        eat++;
        pq.push({0, loc});

        if (level == eat)
        {
            level++;
            eat = 0;
        }

        // printA();
        // cout << "t : " << t << ",level : " << level << ", eat : " << eat << "\n";
        // cout << "---------------------- \n";
    }

    cout << t << "\n";

    return 0;
}
