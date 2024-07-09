#include <bits/stdc++.h>
using namespace std;
int n, m;
int mp[104][104];
int a, b, c;
int inf = 10000004;
int nxt[104][104];
int main()
{
    fill(&mp[0][0], &mp[0][0] + 104 * 104, inf);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (mp[a][b] > c)
        {
            mp[a][b] = c;
            nxt[a][b] = b;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        mp[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mp[i][j] > mp[i][k] + mp[k][j])
                {
                    mp[i][j] = mp[i][k] + mp[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j] == inf)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << mp[i][j] << " ";
            }
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || mp[i][j] == inf || mp[i][j] == 0)
            {
                cout << 0 << "\n";
                continue;
            }
            int start = i;
            int end = j;

            vector<int> path;
            while (start != end)
            {
                path.push_back(start);
                start = nxt[start][end];
            }
            path.push_back(end);

            cout << path.size() << " ";
            for (int k = 0; k < path.size(); k++)
            {
                cout << path[k] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}