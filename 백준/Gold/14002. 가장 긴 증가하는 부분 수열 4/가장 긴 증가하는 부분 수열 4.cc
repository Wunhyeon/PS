#include <bits/stdc++.h>
using namespace std;
int a[1004];
int n;
int cnt[1004];
int pre[1004];
int idx;
int ret=1;
vector<int> v;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    fill(cnt, cnt + 1004, 1);
    fill(pre, pre + 1004, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && cnt[i] < cnt[j] + 1)
            {
                cnt[i] = cnt[j] + 1;
                pre[i] = j;
                if (ret < cnt[i])
                {
                    ret = cnt[i];
                    idx = i;
                }
            }
        }
    }

    for (int i = idx; i != -1; i = pre[i])
    {
        v.push_back(a[i]);
    }

    cout << ret << "\n";
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    return 0;
}