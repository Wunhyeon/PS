#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
int main()
{
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 0; j < i; j++)
        {
            v.push_back(i);
        }
        if (v.size() >= 1000)
        {
            break;
        }
    }
    cin >> n >> m;

    int sum = 0;
    for (int i = n - 1; i <= m - 1; i++)
    {
        sum += v[i];
    }

    cout << sum << "\n";

    return 0;
}