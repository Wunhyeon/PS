#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
// string s;
map<string, int> mp;
set<string> s;
char g;
int main()
{
    cin >> n >> g;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

    if (g == 'Y')
    {
        cout << s.size() << "\n";
    }
    else if (g == 'F')
    {
        cout << s.size() / 2 << "\n";
    }
    else if (g == 'O')
    {
        cout << s.size() / 3 << "\n";
    }
    return 0;
}