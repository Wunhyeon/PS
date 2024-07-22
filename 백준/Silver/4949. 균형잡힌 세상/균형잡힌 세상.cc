#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    while (1)
    {
        // cin >> s;
        getline(cin, s);
        if (s == ".")
        {
            break;
        }

        stack<char> stk;
        bool flag = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[')
            {
                stk.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (stk.size() && stk.top() == '(')
                {
                    stk.pop();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (stk.size() && stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (stk.size())
        {
            flag = false;
        }

        if (flag)
        {
            cout << "yes" << "\n";
        }
        else
        {
            cout << "no" << "\n";
        }
    }
    return 0;
}