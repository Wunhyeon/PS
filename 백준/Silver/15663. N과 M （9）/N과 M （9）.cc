#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
int a[10];
int num;
vector<vector<int>> vv;
map<string, bool> mp;
void makePermu(int n, int r, int depth)
{
    if (r == depth)
    {
        vector<int> tmp;
        string s;
        for (int i = 0; i < r; i++)
        {
            tmp.push_back(v[i]);
            s += v[i];
        }
        if (!mp[s])
        {
            vv.push_back(tmp);
            mp[s] = 1;
        }
        return;
    }
    for (int i = depth; i < n; i++)
    {
        swap(v[i], v[depth]);
        makePermu(n, r, depth + 1);
        swap(v[i], v[depth]);
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

    makePermu(n, m, 0);
    sort(vv.begin(), vv.end());
    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}