#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    while (1)
    {
        cin >> s;
        if (s == "end")
        {
            break;
        }
        bool flag = true;
        bool mo = false;
        int jaCnt = 0;
        int moCnt = 0;
        char pre = '\0';
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                mo = true;
                moCnt++;
                jaCnt = 0;
            }
            else
            {
                jaCnt++;
                moCnt = 0;
            }

            if (moCnt >= 3 || jaCnt >= 3)
            {
                flag = false;
                break;
            }

            if (pre == s[i])
            {
                if (pre != 'e' && pre != 'o')
                {
                    flag = false;
                    break;
                }
            }

            pre = s[i];
        }

        if (mo && flag)
        {
            cout << "<" << s << "> is acceptable." << "\n";
        }
        else
        {
            cout << "<" << s << "> is not acceptable." << "\n";
        }
    }
    return 0;
}