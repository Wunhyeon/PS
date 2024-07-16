#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << 666 << "\n";
        return 0;
    }
    int cnt = 1;
    for (int i = 667;; i++)
    {
        string s = to_string(i);
        if (s.find("666") != string::npos)
        {
            cnt++;
        }
        if (cnt == n)
        {
            cout << s << "\n";
            break;
        }
    }
    return 0;
}