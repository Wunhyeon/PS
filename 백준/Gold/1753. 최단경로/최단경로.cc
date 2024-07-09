#include <bits/stdc++.h>
using namespace std;
int V, E;
int st;
int u, v, w;
vector<pair<int, int>> adj[20004]; // {비용, 정점}
int d[20004];                      // 최소비용 테이블
int INF = 200004;

int main()
{
    cin >> V >> E;
    cin >> st;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    // cout << "input end " << "\n";
    fill(d, d + 20004, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[st] = 0;
    pq.push({d[st], st});

    while (pq.size())
    {
        auto cur = pq.top();
        pq.pop();

        int curVertex = cur.second;
        int curPrice = cur.first; // st에서 현재 여기 정점까지의 비용

        if (d[curVertex] != curPrice)
        {
            continue;
        }

        for (auto next : adj[curVertex])
        {
            int nextVertex = next.second;
            int toNextVertexPrice = next.first;

            if (d[nextVertex] <= d[curVertex] + toNextVertexPrice)
            {
                // st에서 바로 nextVertex 까지 가는 비용과, st에서 현재 정점까지 오고 + nextVertex까지 가는 비용 비교
                continue;
            }
            d[nextVertex] = d[curVertex] + toNextVertexPrice;
            pq.push({d[nextVertex], nextVertex});
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (d[i] == INF)
        {
            cout << "INF" << "\n";
        }
        else
        {
            cout << d[i] << "\n";
        }
    }

    return 0;
}