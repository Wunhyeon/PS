#include <bits/stdc++.h>
using namespace std;
int n, k;
int visited[100004];
int main()
{
    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    int mn = 100004;

    while (q.size())
    {
        int cur = q.front();
        q.pop();
        int curD = visited[cur];
        if (cur == k)
        {
            if (curD < mn)
            {
                mn = curD;
            }
            else
            {
                continue;
            }
        }

        for (int next : {cur - 1, cur + 1, 2 * cur})
        {
            if (next >= 0 && next <= 100000 && (!visited[next] || curD + 1 < visited[next]))
            {
                visited[next] = curD + 1;
                q.push(next);
            }
        }
    }

    cout << mn - 1 << "\n";

    return 0;
}