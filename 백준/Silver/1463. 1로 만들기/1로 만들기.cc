#include <bits/stdc++.h>
using namespace std;
int n;
int visited[1000004]; // x번째 숫자에 오는 최소 카운트
int main()
{
    // bfs
    cin >> n;
    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while (q.size())
    {
        int cur = q.front();
        int curCount = visited[cur];
        q.pop();
        if (cur == 1)
        {
            break;
        }

        for (int i = 0; i < 3; i++)
        {
            if (i == 0 && cur % 3 != 0)
                continue;
            if (i == 1 && cur % 2 != 0)
                continue;

            int next = cur;
            if (i == 0)
            {
                next = cur / 3;
            }
            else if (i == 1)
            {
                next = cur / 2;
            }
            else if (i == 2)
            {
                next = cur - 1;
            }

            if (next >= 0 && next < 3000004 && !visited[next])
            {
                q.push(next);
                visited[next] = curCount + 1;
            }
        }
    }

    cout << visited[1] - 1 << "\n";

    return 0;
}