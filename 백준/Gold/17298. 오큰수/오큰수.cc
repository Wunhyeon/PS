#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000004];
int ans[10000004];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    memset(ans, -1, sizeof(ans));
    stack<int> stk;
    stack<int> idxStk;
    for (int i = 0; i < n; i++)
    {
        if (stk.empty())
        {
            stk.push(a[i]);
            idxStk.push(i);
            continue;
        }
        if (stk.size() && stk.top() >= a[i])
        {
            stk.push(a[i]);
            idxStk.push(i);
        }
        else if (stk.size() && stk.top() < a[i])
        {
            while (stk.size() && stk.top() < a[i])
            {
                stk.pop();
                int idx = idxStk.top();
                idxStk.pop();
                ans[idx] = a[i];
                // cout << "idx : " << idx << ", a[i] : " << a[i] << ", ans[idx] : " << ans[idx] << "\n";
            }
            stk.push(a[i]);
            idxStk.push(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

/*
7
4 3 2 1 2 3 4
-1 4 3 2 3 4 -1
*/