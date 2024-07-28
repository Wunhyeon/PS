#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000][3];
int dp[3];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    dp[0] = a[0][0];
    dp[1] = a[0][1];
    dp[2] = a[0][2];

    for (int i = 1; i < n; i++)
    {
        vector<int> tmpV;
        for (int j = 0; j < 3; j++)
        {
            int tmp = 0;
            if (j == 0)
            {
                tmp = max(dp[j], dp[j + 1]) + a[i][j];
            }
            else if (j == 1)
            {
                tmp = max({dp[j - 1], dp[j], dp[j + 1]}) + a[i][j];
            }
            else if (j == 2)
            {
                tmp = max(dp[j], dp[j - 1]) + a[i][j];
            }
            tmpV.push_back(tmp);
        }
        for (int j = 0; j < 3; j++)
        {
            dp[j] = tmpV[j];
        }
    }

    int mx = max({dp[0], dp[1], dp[2]});

    dp[0] = a[0][0];
    dp[1] = a[0][1];
    dp[2] = a[0][2];

    for (int i = 1; i < n; i++)
    {
        vector<int> tmpV;
        for (int j = 0; j < 3; j++)
        {
            int tmp = 0;
            if (j == 0)
            {
                tmp = min(dp[j], dp[j + 1]) + a[i][j];
            }
            else if (j == 1)
            {
                tmp = min({dp[j - 1], dp[j], dp[j + 1]}) + a[i][j];
            }
            else if (j == 2)
            {
                tmp = min(dp[j], dp[j - 1]) + a[i][j];
            }
            tmpV.push_back(tmp);
        }
        for (int j = 0; j < 3; j++)
        {
            dp[j] = tmpV[j];
        }
    }

    int mn = min({dp[0], dp[1], dp[2]});

    cout << mx << " " << mn << "\n";

    return 0;
}

/*
int = 32bit
8bit = 1byte
1024byte = 1kb;
1024kb = 1mb
4mb = 4 * 1024 * 1024 * 8
*/