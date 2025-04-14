#include <bits/stdc++.h>
using namespace std;
string s;
int a[30];
int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'A';
        a[idx]++;
    }
    string ans = "";
    string hol = "";
    // bool isHol = false;
    for (int i = 0; i < 30; i++)
    {
        if (!a[i])
        {
            continue;
        }
        if (hol != "" && a[i] % 2 != 0)
        {
            cout << "I'm Sorry Hansoo" << "\n";
            return 0;
        }
        else if (hol == "" && a[i] % 2 != 0)
        {
            hol = i + 'A';
            a[i]--;
        }
        for (int j = 0; j < a[i] / 2; j++)
        {
            ans += i + 'A';
        }
    }
    string realAns = ans;
    realAns += hol;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        realAns += ans[i];
    }
    cout << realAns << "\n";
    return 0;
}