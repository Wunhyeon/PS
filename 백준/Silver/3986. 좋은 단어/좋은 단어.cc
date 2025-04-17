#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    cin >> n;
    int cnt = 0;
    vector<char> v;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v = {};
        for (int j = 0; j < s.size(); j++)
        {
            if (!v.empty() && v.back() == s[j]) // 여기서 왜 오류가 날까?
            {
                v.pop_back();
            }
            else
            {
                v.push_back(s[j]);
            }
        }
        if (v.size() == 0)
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}