#include <bits/stdc++.h>
using namespace std;
int a;
string s;
int arr[29];
int main()
{
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> s;
        arr[s[0] - 'a']++;
    }
    string ans;
    for (int i = 0; i < 27; i++)
    {
        if (arr[i] >= 5)
        {
            ans += 'a' + i;
        }
    }
    if (ans.size())
    {
        cout << ans << "\n";
    }
    else
    {
        cout << "PREDAJA" << "\n";
    }
    return 0;
}