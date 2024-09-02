#include <bits/stdc++.h>
using namespace std;
int n;
int num;
// map<int,vector<int>> idxMap;
vector<int> v;
vector<int> v2;
map<int, int> mp;
map<int, bool> visited;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
        if (!visited[num])
        {
            v2.push_back(num);
            visited[num] = 1;
        }
    }

    sort(v2.begin(), v2.end());
    for (int i = 0; i < v2.size(); i++)
    {
        mp[v2[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << mp[v[i]] << " ";
    }

    return 0;
}