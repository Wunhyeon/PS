#include <bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int n, m;
int visited[10001];
int dp[10001];
int mx = -1;
int dfs(int n)
{
    visited[n] = 1;
    int ret = 1;

    for (int i = 0; i < v[n].size(); i++)
    {
        if (!visited[v[n][i]])
        {
            ret += dfs(v[n][i]);
        }
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    vector<pair<int, int>> answer;

    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        dp[i] = dfs(i);
        mx = max(dp[i], mx);
    }
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