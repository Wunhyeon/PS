#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[50004];
int inf = 1000 * 50004;
int a, b, c;
vector<pair<int, int>> v[50004]; // {비용, 정점}
int main()
{
    fill(d, d + 50004, inf);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[1] = 0;
    pq.push({d[1], 1});

    while (pq.size())
    {
        auto cur = pq.top();
        pq.pop();
        int vertex = cur.second;
        int price = cur.first;

        if (d[vertex] < price)
        {
            continue;
        }

        for (auto next : v[vertex])
        {
            int nextVertex = next.second;
            int toNextPrice = next.first;

            if (d[nextVertex] <= price + toNextPrice)
            {
                continue;
            }
            d[nextVertex] = price + toNextPrice;
            pq.push({d[nextVertex], nextVertex});
        }
    }

    cout << d[n] << "\n";

    return 0;
}