#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// int t;
vector<vector<int>> vv;
int n;

int main()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        sum += pow(n, 2);
    }
    cout << sum % 10 << "\n";

    return 0;
}