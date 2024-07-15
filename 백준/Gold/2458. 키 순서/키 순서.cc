#include <bits/stdc++.h>
using namespace std;
int n, m;
int mp[504][504]; // n이 m보다 작다.
int a, b;
int INF = 2500000;
int main()
{
    // fill(&mp[0][0], &mp[0][0] + 504 * 504, INF);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        mp[a][b] = 1;
        // mp[b][a] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mp[i][k] && mp[k][j])
                {
                    mp[i][j] = 1;
                }
            }
        }
    }

    map<int, int> cntMap;
    for (int i = 1; i <= n; i++)
    {
        cntMap[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cntMap[j] += mp[i][j];
            cntMap[i] += mp[i][j];
        }
    }

    int cnt = 0;
    for (auto item : cntMap)
    {
        if (item.second == n - 1)
        {
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}