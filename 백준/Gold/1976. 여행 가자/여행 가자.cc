#include <bits/stdc++.h>
using namespace std;
int n, m;
int mp[204][204];
int d[204][204];
vector<int> plan;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
            // mp[j][i] = mp[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        plan.push_back(p);
    }

    for (int i = 1; i <= n; i++)
    {
        mp[i][i] = 1;
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
                    mp[j][i] = 1;
                }
            }
        }
    }
    bool flag = true;
    for (int i = 1; i < plan.size(); i++)
    {
        int pre = plan[i - 1];
        int cur = plan[i];
        if (!mp[pre][cur])
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "YES" << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }

    return 0;
}

/*
2
2
0 0
0 0
1 1

ans: YES
*/