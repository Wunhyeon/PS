#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int> v;
int num;
vector<vector<int>> vv;
int mx;

void makeCombi(int start, int limit, vector<int> tmp)
{
    if (tmp.size() == limit)
    {
        vv.push_back(tmp);
    }
    else
    {
        for (int i = start + 1; i < v.size(); i++)
        {
            tmp.push_back(v[i]);
            makeCombi(i, limit, tmp);
            tmp.pop_back();
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    makeCombi(-1, 3, {});

    for (int i = 0; i < vv.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < vv[i].size(); j++)
        {
            sum += vv[i][j];
        }
        if (sum > m)
        {
            continue;
        }
        mx = max(mx, sum);
    }
    cout << mx << "\n";

    return 0;
}