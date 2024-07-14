#include <bits/stdc++.h>
using namespace std;
int n, e;
int a, b, c;
vector<pair<int, int>> adj[804]; // {비용, 정점}
int d[804];                      // 최단거리 비용
int pre[804];
int inf = 80000004;
int v1, v2;

void dajik(int start)
{
    fill(d, d + 804, inf);
    memset(pre, 0, sizeof(pre));
    d[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[start], start});
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
            pre[nextVertex] = vertex;
        }
    }
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> v1 >> v2;
    // cout << "input end " << "\n";
    dajik(1);
    int toV1 = d[v1];
    int toV2 = d[v2];
    dajik(v1);
    int v1ToV2 = d[v2];
    int v1ToN = d[n];
    dajik(v2);
    int v2ToV1 = d[v1];
    int v2ToN = d[n];

    int distance1 = toV1 + v1ToV2 + v2ToN;
    int distance2 = toV2 + v2ToV1 + v1ToN;

    int ret = min(distance1, distance2);
    if (ret >= inf)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ret << "\n";
    }

    return 0;
}
