#include <bits/stdc++.h>
using namespace std;
int a[14][14];
int visited[14];
int m[14][14];
int n;
int k;
int inf = 1e9;
int mn = inf;

void go(int v, int cnt, int sum)
{
    // cout << "v : " << v << ", cnt : " << cnt << ", sum : " << sum << "\n";
    if (sum >= mn)
    {
        return;
    }
    if (cnt == n)
    {
        mn = min(mn, sum);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }

        visited[i] = 1;
        go(i, cnt + 1, sum + m[v][i]);
        visited[i] = 0;
    }
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    fill(&m[0][0], &m[0][0] + 14 * 14, inf);
    for (int i = 0; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[i][j] > a[i][k] + a[k][j])
                {
                    m[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    visited[k] = 1;
    go(k, 1, 0);
    cout << mn << "\n";

    return 0;
}