#include <bits/stdc++.h>
using namespace std;
int n;
int a[204];
int cnt[204];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    fill(cnt, cnt + 204, 1);
    // 초ㅣ장 lis를 구하고 전체길이 - lis 해주면 될듯
    int longgest = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && cnt[j] + 1 > cnt[i])
            {
                cnt[i] = cnt[j] + 1;
            }
        }
        longgest = max(longgest, cnt[i]);
    }

    cout << n - longgest << "\n";

    return 0;
}

/*
5
4 1 2 3 5
*/