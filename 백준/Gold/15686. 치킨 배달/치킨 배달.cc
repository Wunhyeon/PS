#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[54][54];
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;
vector<vector<int>> vvv;

void comb(int limit, vector<int> vv, int start)
{
    if (vv.size() >= limit)
    {
        vvv.push_back(vv);
        return;
    }

    for (int i = start; i < v2.size(); i++)
    {
        vv.push_back(i);
        comb(limit, vv, i + 1);
        vv.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            a[i][j] = tmp;
            if (tmp == 1)
            {
                v1.push_back({i, j});
            }
            else if (tmp == 2)
            {
                v2.push_back({i, j});
            }
        }
    }

    comb(m, {}, 0);
    int ans = 25040;
    for (int i = 0; i < vvv.size(); i++)
    {
        int tmpAns = 0;
        for (int j = 0; j < v1.size(); j++)
        {
            int homeY = v1[j].first;
            int homeX = v1[j].second;
            int subbest = 2504;
            for (int k = 0; k < vvv[i].size(); k++)
            {
                int idx = vvv[i][k];
                int chiY = v2[idx].first;
                int chiX = v2[idx].second;
                int minus = abs(homeY - chiY) + abs(homeX - chiX);
                subbest = min(minus, subbest);
            }
            tmpAns += subbest;
        }

        ans = min(ans, tmpAns);
    }

    cout << ans << "\n";
    return 0;
}