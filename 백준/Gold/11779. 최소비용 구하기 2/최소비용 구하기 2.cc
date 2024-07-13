#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> adj[1004]; // {비용, 정점}
int d[1004];
int INF = 100000004;
int a, b, c;
int s, e;
// vector<int> nxt[1004]; // nxt[3] : 시작점에서 3번정점까지 가는 경로
int pre[1004]; // start에서 n까지 가는 경로
int main()
{
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    cin >> s >> e;

    fill(d, d + 1004, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[s], s});
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
            // cout << "vertex : " << vertex << ", nextVertex : " << nextVertex << "\n";
            pre[nextVertex] = vertex;
        }
    }

    cout << d[e] << "\n";
    // for (int i = 0; i < nxt[e].size(); i++)
    // {
    //     cout << nxt[e][i] << " ";
    // }
    vector<int> path;
    for (int i = e; i != s; i = pre[i])
    {
        path.push_back(i);
    }
    path.push_back(s);

    cout << path.size() << "\n";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << "\n";
    return 0;
}