#include <bits/stdc++.h>
using namespace std;
int h, w;
int a[504];
int f;
int strt;
int main()
{
    cin >> h >> w;
    for (int i = 0; i < w; i++)
    {
        cin >> a[i];
        if (f == 0 && a[i] != 0)
        {
            f = a[i];
            strt = i;
        }
    }
    int total = 0;
    // for (int i = f; i >= 0; i--)
    // {
    //     // i = 물높이
    //     int tmp = 0;
    //     for (int j = strt; j < w; j++)
    //     {
    //         if (a[j] < i)
    //         {
    //             tmp++;
    //         }
    //         else if (a[j] >= i)
    //         {
    //             cout << "i : " << i << ", j : " << j << "\n";
    //             cout << "tmp : " << tmp << "\n";
    //             total += tmp;
    //             tmp = 0;
    //         }
    //     }
    // }

    for (int i = h; i >= 0; i--)
    {
        int tmp = 0;
        bool flag = false;
        for (int j = 0; j < w; j++)
        {
            if (flag == false && a[j] >= i)
            {
                flag = true;
            }
            else if (flag && a[j] < i)
            {
                tmp++;
            }
            else if (flag && a[j] >= i)
            {
                // flag = false;
                total += tmp;
                tmp = 0;
            }
        }
    }
    cout << total << "\n";
    return 0;
}