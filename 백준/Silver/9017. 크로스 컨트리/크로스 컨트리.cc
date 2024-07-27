#include <bits/stdc++.h>
using namespace std;
int t;
map<int, int> memCnt; // 각 팀마다 선수 몇명있나 카운트
int a[1004];
vector<int> v[204];
int n;
int num;

bool cmp(int ans1, int ans2)
{
    return v[ans1][4] < v[ans2][4];
}

int sum4(int teamNum)
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += v[teamNum][i];
    }
    return sum;
}

int main()
{
    cin >> t;
    while (t--)
    {
        memCnt.clear();
        memset(a, 0, sizeof(a));
        for (int i = 0; i <= 203; i++)
        {
            v[i].clear();
        }

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            memCnt[a[i]]++;
            // v[a[i]].push_back()
        }

        int score = 1;
        for (int i = 1; i <= n; i++)
        {
            if (memCnt[a[i]] >= 6)
            {
                v[a[i]].push_back(score++);
            }
        }

        int mn = 1e9;
        vector<int> ans;
        for (auto item : memCnt)
        {
            int teamNum = item.first;
            int cnt = item.second;
            if (cnt < 6)
            {
                continue;
            }
            int sum = sum4(teamNum);

            if (sum < mn)
            {
                mn = sum;
                ans = {teamNum};
            }
            else if (sum == mn)
            {
                ans.push_back(teamNum);
            }
        }
        // cout << "?? " << "\n";
        if (ans.size() == 1)
        {
            // cout << "1" << "\n";
            cout << ans[0] << "\n";
        }
        else
        {
            // cout << "2" << "\n";
            sort(ans.begin(), ans.end(), cmp);
            cout << ans[0] << "\n";
        }
    }
    return 0;
}