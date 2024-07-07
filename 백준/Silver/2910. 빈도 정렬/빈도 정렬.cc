#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<int> v;
map<int, int> cnt;
map<int, int> order;
int num;

bool cmp(int a, int b)
{
    if (cnt[a] == cnt[b])
    {
        return order[a] < order[b];
    }
    return cnt[a] > cnt[b];
}

int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        v.push_back(num);
        cnt[num]++;
        if (!order[num])
        {
            order[num] = i;
        }
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}