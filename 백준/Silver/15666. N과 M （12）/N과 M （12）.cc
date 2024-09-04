#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v;
int num;
vector<vector<int>> vv;
map<string, bool> mp;

void makeCombi(int start, int limit, vector<int> tmp)
{
    if (tmp.size() == limit)
    {
        string s = "";
        for (int i = 0; i < tmp.size(); i++)
        {
            s += v[tmp[i]] + '0';
        }
        // cout << "s : " << s << "\n";
        if (mp[s])
        {
            return;
        }

        vv.push_back(tmp);
        mp[s] = 1;
        return;
    }
    for (int i = start; i < n; i++)
    {
        tmp.push_back(i);
        makeCombi(i, limit, tmp);
        tmp.pop_back();
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
    sort(v.begin(), v.end());
    makeCombi(0, m, {});

    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {
            int idx = vv[i][j];
            cout << v[idx] << " ";
        }
        cout << "\n";
    }
    return 0;
}