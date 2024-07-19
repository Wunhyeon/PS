#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> v;
int a, b;
int half;
int dp[50004];
int inf = 100000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 3; i++)
    {
        v.clear();
        cin >> n;
        int total = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> a >> b;
            v.push_back({a, b});
            // mp[a] = b;
            total += a * b;
        }
        if (total % 2 != 0)
        {
            cout << 0 << "\n";
            continue;
        }
        half = total / 2;
        fill(dp, dp + 50004, inf);
        dp[0] = 0;

        for (int i = 0; i < v.size(); i++)
        {
            // int cnt = 0;
            int limit = v[i].second;
            for (int j = half; j >= v[i].first; j--)
            {
                for (int k = 1; k <= limit; k++)
                {
                    if (j - v[i].first * k >= 0 && dp[j] > dp[j - v[i].first * k] + k)
                    {
                        dp[j] = dp[j - v[i].first * k] + k;
                    }
                    if (dp[half] < inf)
                    {
                        break;
                    }
                }
                if (dp[half] < inf)
                {
                    break;
                }
            }
        }
        // cout << dp[half] << "\n";
        if (dp[half] >= inf)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
    }
    return 0;
}