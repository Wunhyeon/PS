#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int num;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    int sum = 0;
    int level = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            level++;
            sum += level;
        }
        else
        {
            level = 0;
        }
    }

    cout << sum << "\n";

    return 0;
}