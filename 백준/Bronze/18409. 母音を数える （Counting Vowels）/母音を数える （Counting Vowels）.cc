#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    cin >> n;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}