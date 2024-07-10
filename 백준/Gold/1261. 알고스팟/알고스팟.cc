#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int mp[104][104];
vector<pair<int, pair<int, int>>> adj[104][104]; // {비용, 정점(y,x)} // 정점 n,m 에서 정점 y,x까지 비용
int d[104][104];                                 // 최소거리(비용) 테이블
int inf = 10004;
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            mp[i][j] = s[j] - '0';
        }
    }
    // cout << "input end" << "\n";
    fill(&d[0][0], &d[0][0] + 104 * 104, inf);
    d[0][0] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({d[0][0], {0, 0}});

    while (pq.size())
    {
        auto cur = pq.top();
        pq.pop();

        int vertexY = cur.second.first;
        int vertexX = cur.second.second;
        int price = cur.first;

        // cout << "vertexY : " << vertexY << ", vertexX : " << vertexX << ", price : " << price << "\n";

        if (d[vertexY][vertexX] != price)
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextVertexY = vertexY + dirY[i];
            int nextVertexX = vertexX + dirX[i];

            if (nextVertexY < 0 || nextVertexY >= n || nextVertexX < 0 || nextVertexX >= m)
            {
                continue;
            }

            int nextPrice = mp[nextVertexY][nextVertexX];

            if (d[nextVertexY][nextVertexX] <= d[vertexY][vertexX] + nextPrice)
            {
                continue;
            }
            d[nextVertexY][nextVertexX] = d[vertexY][vertexX] + nextPrice;
            pq.push({d[nextVertexY][nextVertexX], {nextVertexY, nextVertexX}});
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << d[n - 1][m - 1] << "\n";

    return 0;
}