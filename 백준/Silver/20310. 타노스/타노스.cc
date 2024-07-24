#include <bits/stdc++.h>
using namespace std;
string s;
int a[2];
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        int code = s[i] - '0';
        a[code]++;
    }
    string tmp;
    for (int i = 0; i < a[0] / 2; i++)
    {
        tmp += '0';
    }
    for (int i = 0; i < a[1] / 2; i++)
    {
        tmp += '1';
    }

    cout << tmp << "\n";
    return 0;
}