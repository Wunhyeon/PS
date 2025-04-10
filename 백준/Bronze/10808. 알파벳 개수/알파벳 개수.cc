#include <bits/stdc++.h>
using namespace std;
int a[26];
string str;
int main()
{
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        a[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}