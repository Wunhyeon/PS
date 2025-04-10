#include <bits/stdc++.h>
using namespace std;
string str;
int main()
{
    cin >> str;

    int s = 0;
    int e = str.size() - 1;
    while (s < e)
    {
        if (str[s] != str[e])
        {
            cout << 0;
            return 0;
        }
        s++;
        e--;
    }
    cout << 1;
    return 0;
}