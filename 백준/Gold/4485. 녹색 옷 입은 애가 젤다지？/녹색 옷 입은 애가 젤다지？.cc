#include <bits/stdc++.h>
using namespace std;
int n;
int a[130][130];
int num;
int inf = 1e9;
int d[130][130];
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};
int main()
{
    int p = 1;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> num;
                a[i][j] = num;
            }
        }

        fill(&d[0][0], &d[0][0] + 130 * 130, inf);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // {비용, 정점}

        d[0][0] = a[0][0];
        pq.push({d[0][0], {0, 0}});
        while (pq.size())
        {
            auto cur = pq.top();
            pq.pop();
            int price = cur.first;
            int curY = cur.second.first;
            int curX = cur.second.second;

            if (d[curY][curX] < price)
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

                int nextPrice = a[nextY][nextX];
                if (d[nextY][nextX] <= price + nextPrice)
                {
                    continue;
                }
                d[nextY][nextX] = price + nextPrice;
                pq.push({d[nextY][nextX], {nextY, nextX}});
            }
        }
        cout << "Problem " << p << ": " << d[n - 1][n - 1] << "\n";
        p++;
    }
    return 0;
}