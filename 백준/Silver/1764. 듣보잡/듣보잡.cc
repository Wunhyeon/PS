#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int m;
map<string, int> mp;
string s;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        cin >> s;
        mp[s]++;
    }

    int sum = 0;
    vector<string> ans;
    for (auto item : mp)
    {
        if (item.second >= 2)
        {
            sum++;
            ans.push_back(item.first);
        }
    }
    sort(ans.begin(), ans.end());
    cout << sum << "\n";
    for (int i = 0; i < sum; i++)
    {
        cout << ans[i] << '\n';
    }

    return 0;
}