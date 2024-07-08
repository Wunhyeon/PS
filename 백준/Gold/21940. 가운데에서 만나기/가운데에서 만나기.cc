#include <bits/stdc++.h>
using namespace std;
int n, m;
int a, b, t;
int k;
vector<int> p;
int mp[204][204];
int inf = 200004;
int main()
{
    fill(&mp[0][0], &mp[0][0] + 204 * 204, inf);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> t;
        if (mp[a][b] > t)
        {
            mp[a][b] = t;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        p.push_back(num);
    }

    // cout << "input end" << "\n";
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
                }
            }
        }
    }

    int mn = inf;
    vector<int> ans;
    // 왕복시간 구하기
    for (int i = 1; i <= n; i++)
    {
        // 기준도시 city = i
        int tmpMx = 0;
        for (int j = 0; j < p.size(); j++)
        {
            // 사람 한명이 사는 도시
            int per = p[j];
            // 왕복시간
            tmpMx = max(tmpMx, mp[per][i] + mp[i][per]);
        }
        if (tmpMx < mn)
        {
            mn = tmpMx;
            ans.clear();
            ans.push_back(i);
        }
        else if (tmpMx == mn)
        {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}