#include <bits/stdc++.h>
using namespace std;
vector<int> v[10004];
int n, m;
int a, b;
int dp[10004];
map<int, int> mp;
int visited[10004];

int dfs(int num)
{
    // cout << "num : " << num << "\n";
    // if (dp[num])
    // {
    //     return dp[num];
    // }
    visited[num] = 1;
    int ret = 1;
    for (int i = 0; i < v[num].size(); i++)
    {
        int next = v[num][i];
        if (visited[next])
        {
            continue;
        }

        // visited[next] = 1;
        ret += dfs(next);
    }
    // dp[num] = ret;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[b].push_back(a);
    }

    int mx = -1;

    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        int tmp = dfs(i);
        // cout << "num : " << i << ", tmp : " << tmp << "\n";
        dp[i] = tmp;
        if (tmp > mx)
        {
            mx = tmp;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << "---------\n";

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == mx)
        {
            cout << i << " ";
        }
    }

    return 0;
}

/*
5 6
3 1
3 2
4 3
5 3
2 1
4 2
답 : 1

6 6
2 1
3 1
4 2
4 3
3 6
6 5
답 1 5
*/