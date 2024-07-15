#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> v;

bool cmp(string a, string b)
{

    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return a[i] < b[i];
        }
    }
    return true;
}

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> s;
        string tmp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (s[i] == '0' && tmp == "0")
                {
                    continue;
                }
                else if (s[i] != '0' && tmp == "0")
                {
                    tmp = s[i];
                    continue;
                }
                tmp += s[i];
            }
            else
            {
                if (tmp.size())
                {
                    v.push_back(tmp);
                    tmp = "";
                }
            }
        }
        if (tmp.size())
        {
            v.push_back(tmp);
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }

    return 0;
}