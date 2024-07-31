#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int k;

int cnt[30]; // 알파벳 몇개나왔나 카운트
// int strt[30];   // 알파벳 시작 언제하나
int main()
{
    cin >> t;
    while (t--)
    {
        int mn = 10001;
        int mx = 0;
        vector<int> loc[30];

        fill(cnt, cnt + 30, 0);
        cin >> s;
        cin >> k;
        for (int i = 0; i < s.size(); i++)
        {
            // cout << "i : " << i << "\n";
            int charNum = s[i] - 'a';
            // cout << "charNum : " << charNum << "\n";
            loc[charNum].push_back(i);
            cnt[charNum]++;

            if (cnt[charNum] >= k)
            {
                // int len = i - (loc[charNum].size()-k)
                int preIdx = loc[charNum].size() - k;
                int pre = loc[charNum][preIdx];
                int len = i - pre + 1;
                mn = min(mn, len);
                mx = max(mx, len);
            }
        }

        if (mn == 10001 && mx == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << mn << " " << mx << "\n";
        }
    }
    return 0;
}