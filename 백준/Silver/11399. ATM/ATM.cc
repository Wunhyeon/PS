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
    sort(v.begin(), v.end());

    int sum = 0;
    int total = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += +v[i];
        total += sum;
    }

    cout << total << "\n";

    return 0;
}