#include <bits/stdc++.h>
using namespace std;
int t, k;
int che[1299713];
vector<int> v;
int mxNum = 1299709;

void era(int num)
{
    for (int i = 2; i <= num; i++)
    {
        if (che[i])
        {
            continue;
        }
        for (int j = 2 * i; j <= num; j += i)
        {
            che[j] = 1;
        }
    }

    for (int i = 2; i <= num; i++)
    {
        if (che[i] == 0)
        {
            v.push_back(i);
        }
    }
}

int main()
{
    era(mxNum);

    cin >> t;
    while (t--)
    {
        cin >> k;
        if (!che[k])
        {
            cout << 0 << "\n";
            continue;
        }
        while (che[k])
        {
            k--;
        }
        int mn = k;
        k++;
        while (che[k])
        {
            k++;
        }
        int mx = k;
        cout << mx - mn << "\n";
    }
    return 0;
}