#include <bits/stdc++.h>
using namespace std;
char a[54][54];
char ans1[8][8];
char ans2[8][8];
string s;
int n, m;
int mn = 1e9;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            a[i][j] = s[j];
        }
    }

    char pan1[8] = {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'};
    char pan2[8] = {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'};

    for (int i = 0; i < 8; i += 2)
    {
        for (int j = 0; j < 8; j++)
        {
            ans1[i][j] = pan1[j];
            ans2[i][j] = pan2[j];
        }
    }

    for (int i = 1; i < 8; i += 2)
    {
        for (int j = 0; j < 8; j++)
        {
            ans1[i][j] = pan2[j];
            ans2[i][j] = pan1[j];
        }
    }

    for (int i = 0; i <= n - 8; i++)
    {
        for (int j = 0; j <= m - 8; j++)
        {
            int dif1 = 0;
            int dif2 = 0;
            for (int k = i; k < i + 8; k++)
            {
                for (int l = j; l < j + 8; l++)
                {
                    if (a[k][l] != ans1[k - i][l - j])
                    {
                        dif1++;
                    }
                    if (a[k][l] != ans2[k - i][l - j])
                    {
                        dif2++;
                    }
                    // cout << "i :" << i << ", j :" << j << ",k:" << k << ", l :" << l << "\n";
                }
            }
            // cout << "i : " << i << ", j : " << j << ", dif1 : " << dif1 << ", dif2 : " << dif2 << "\n";
            mn = min({mn, dif1, dif2});
        }
    }
    cout << mn << "\n";
    return 0;
}