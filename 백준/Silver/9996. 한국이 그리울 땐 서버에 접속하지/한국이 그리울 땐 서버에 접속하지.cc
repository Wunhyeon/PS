#include <bits/stdc++.h>
using namespace std;
int n;
string str;
string s1 = "";
string s2 = "";
string tmp;
int main()
{
    cin >> n;
    cin >> str;
    bool flag = true;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '*')
        {
            flag = false;
            continue;
        }
        if (flag)
        {
            s1 += str[i];
        }
        else
        {
            s2 += str[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        string tmpS1 = "";
        string tmpS2 = "";
        if (tmp.size() < s1.size() + s2.size())
        {
            cout << "NE" << "\n";
            continue;
        }
        for (int j = 0; j < s1.size(); j++)
        {
            tmpS1 += tmp[j];
        }
        for (int j = tmp.size() - s2.size(); j < tmp.size(); j++)
        {
            tmpS2 += tmp[j];
        }
        if (s1 == tmpS1 && s2 == tmpS2)
        {
            cout << "DA" << "\n";
        }
        else
        {
            cout << "NE" << "\n";
        }
    }
    return 0;
}