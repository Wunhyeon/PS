#include <bits/stdc++.h>
using namespace std;
int n, m, x;
vector<pair<int, int>> adj[1004]; // 비용, 정점
int d[1004];                      // 최소거리 테이블
int a, b, c;
int toX[1004];
int xToHome[1004];
int INF = 100004;
int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 1; i <= n; i++)
    {
        fill(d, d + 1004, INF);
        d[i] = 0;
        pq.push({d[i], i});

        while (pq.size())
        {
            auto cur = pq.top();
            pq.pop();
            int vertex = cur.second;
            int price = cur.first;
            if (d[vertex] != price)
            {
                continue;
            }

            for (auto next : adj[vertex])
            {
                int nextVertex = next.second;
                int toNextVertexPrice = next.first;
                if (d[nextVertex] <= d[vertex] + toNextVertexPrice)
                {
                    continue;
                }
                d[nextVertex] = d[vertex] + toNextVertexPrice;
                pq.push({d[nextVertex], nextVertex});
            }
        }
        toX[i] = d[x];
        if (i == x)
        {
            for (int j = 1; j <= n; j++)
            {
                xToHome[j] = d[j];
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        int cal = toX[i] + xToHome[i];
        mx = max(mx, cal);
    }

    cout << mx << "\n";

    return 0;
}

/*
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

ans : 10

4.
4 -> 2 -> 1 -> 4
  3    1    7

4 -> 2 -> 3 -> 4
  3    5    4
*/