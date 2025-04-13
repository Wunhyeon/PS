#include <bits/stdc++.h>
using namespace std;

int n, m;
string a[100004];
map<string, int> mp;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        a[i] = s;
        mp[s] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9')
        {
            cout << a[stoi(s)] << "\n";
        }
        else
        {
            cout << mp[s] << "\n";
        }
    }

    return 0;
}