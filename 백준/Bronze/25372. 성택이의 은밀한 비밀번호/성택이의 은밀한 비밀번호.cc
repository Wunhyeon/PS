#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s.size() >= 6 && s.size() <= 9)
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