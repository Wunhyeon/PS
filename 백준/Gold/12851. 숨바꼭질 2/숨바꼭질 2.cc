#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100004];
int visited[100004]; // 초를 저장.
int cnt[100004];     // 방법의 수를 저장
int t = 1e9;         // 동생을 찾는 시간
int m = 0;           // 방법의 수

int main()
{
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    cnt[n] = 1;
    while (q.size())
    {
        int cur = q.front();
        // cnt[cur]++;
        int curTime = visited[cur];
        q.pop();
        // cout << cur << "\n";
        for (int i = 0; i < 3; i++)
        {
            int next = cur;
            if (i == 0)
            {
                next = cur + 1;
            }
            else if (i == 1)
            {
                next = cur - 1;
            }
            else if (i == 2)
            {
                next = cur * 2;
            }

            if (next >= 0 && next <= 100000 && (!visited[next] || visited[next] == curTime + 1))
            {
                q.push(next);
                visited[next] = curTime + 1;
                cnt[next]++;
            }
        }
    }
    cout << visited[k] - 1 << "\n";
    cout << cnt[k] << "\n";
    return 0;
}

/*
input
5 237

ans
10
5

5 17
4
2

1 3
2
2


*/