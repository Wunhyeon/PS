#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c;
int mp[104][104];
int main()
{
    cin >> n >> m;
    fill(&mp[0][0], &mp[0][0] + 104 * 104, 10000001);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if (a == b)
        {
            mp[a][b] = 0;
            continue;
        }
        if (mp[a][b] > c)
        {
            mp[a][b] = c;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        mp[i][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 2 => 3으로 갈 때, (2 => 1) + (1 => 3)

            for (int k = 1; k <= n; k++)
            {
                if (mp[j][k] > mp[j][i] + mp[i][k])
                {
                    mp[j][k] = mp[j][i] + mp[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j] >= 10000001)
            {
                cout << 0 << " ";
                continue;
            }
            cout << mp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
5
14
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
3 5 10
3 1 8
1 4 2
5 1 7
3 4 2
5 2 4

ans
0 2 3 1 4
12 0 15 2 5
8 5 0 1 1
10 7 13 0 3
7 4 10 6 0
*/