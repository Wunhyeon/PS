#include <bits/stdc++.h>
using namespace std;
int N, A, B;
int mn = 10000001;
int visited[1000004];
struct str
{
    int a;
    int b;
};
void go(int n, int a, int b, int cnt)
{
    if (n < 0)
    {
        return;
    }
    if (n == 0)
    {
        mn = min(mn, cnt);
        return;
    }

    go(n - 1 - b, a, b, cnt + 1);
    go(n - 1 - a, a, b, cnt + 1);
    go(n - 1, a, b, cnt + 1);
}

void bfs(int a, int b)
{
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (q.size())
    {
        int cur = q.front();
        int curD = visited[cur];
        q.pop();
        if (cur == N)
        {
            mn = min(mn, curD);
            continue;
        }
        for (int next : {cur + 1, cur + a + 1, cur + b + 1})
        {
            if (next <= N && (!visited[next] || visited[next] > curD + 1))
            {
                q.push(next);
                visited[next] = curD + 1;
            }
        }
    }
}

int main()
{
    cin >> N >> A >> B;
    // go(N, A, B, 0);
    // dp[N] = 0;
    bfs(A, B);

    cout << mn - 1 << "\n";

    return 0;
}