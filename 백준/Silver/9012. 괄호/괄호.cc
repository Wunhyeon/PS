#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
    cin >> t;
    while (t--)
    {
        stack<char> stk;
        bool flag = true;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stk.push(s[i]);
            }
            else if (s[i] == ')' && stk.size() && stk.top() == '(')
            {
                stk.pop();
            }
            else if (s[i] == ')' && !stk.size())
            {
                flag = false;
                break;
            }
        }

        if (stk.size())
        {
            flag = false;
        }

        if (flag)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    return 0;
}