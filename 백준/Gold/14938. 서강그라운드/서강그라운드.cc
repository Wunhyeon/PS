#include <bits/stdc++.h>
using namespace std;
int n, m, r;
int t;
int a, b, l;
int mp[104][104];
int item[104];
int inf = 5000;
int nxt[104][104];
int mx;
int main()
{
    fill(&mp[0][0], &mp[0][0] + 104 * 104, inf);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> item[i];
    }
    for (int i = 0; i < r; i++)
    {
        cin >> a >> b >> l;
        if (mp[a][b] > l)
        {
            mp[a][b] = l;
            nxt[a][b] = b;
        }
        if (mp[b][a] > l)
        {
            mp[b][a] = l;
            nxt[b][a] = a;
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
    /*
    cout << "------\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << mp[i][j] << " ";
        }
        cout << "\n";
    }
    */

    for (int i = 1; i <= n; i++)
    {
        int tmp = item[i];
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j] > m)
            {
                continue;
            }
            if (i == j)
            {
                continue;
            }
            tmp += item[j];
            // int start = i;
            // int end = j;
            // vector<int> path;
            // while (start != j)
            // {
            //     if (start != i)
            //     {
            //         path.push_back(start);
            //     }
            //     start = nxt[start][end];
            // }
            // path.push_back(end);

            // cout << "i : " << i << ", j : " << j << "\n";

            // for (int i = 0; i < path.size(); i++)
            // {
            //     cout << "path[i] : " << path[i] << " ";
            //     tmp += item[path[i]];
            // }
            // // cout << "\n";
        }
        mx = max(mx, tmp);
        // cout << "tmp : " << tmp << "\n";
    }

    cout << mx << "\n";

    return 0;
}

/*
5 15 5
2 4 5 20 3
1 2 6
2 3 7
3 4 9
1 3 2
1 5 14

---

정답 : 34
*/