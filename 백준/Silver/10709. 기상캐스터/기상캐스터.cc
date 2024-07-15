#include <bits/stdc++.h>
using namespace std;
int h, w;
char a[104][104];
int ans[104][104];
int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(ans, -1, sizeof(ans));

    for (int i = 0; i < h; i++)
    {
        bool flag = false;
        for (int j = 0; j < w; j++)
        {
            if (a[i][j] == 'c')
            {
                ans[i][j] = 0;
                flag = true;
            }
            else if (flag && ans[i][j - 1] != -1)
            {
                ans[i][j] = ans[i][j - 1] + 1;
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}