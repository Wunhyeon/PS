#include <bits/stdc++.h>
using namespace std;
string s;
map<char, int> mp;
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        mp[toupper(s[i])]++;
    }

    vector<pair<int, char>> v;
    for (auto item : mp)
    {
        v.push_back({item.second, item.first});
    }

    sort(v.begin(), v.end());

    if (v.size() >= 2 && v[v.size() - 1].first == v[v.size() - 2].first)
    {
        cout << "?" << "\n";
    }
    else
    {
        cout << v[v.size() - 1].second << "\n";
    }

    return 0;
}