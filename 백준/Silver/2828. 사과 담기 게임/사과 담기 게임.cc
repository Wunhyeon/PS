#include <bits/stdc++.h>
using namespace std;
int n, m, j;
int a[24];
int main()
{
    cin >> n >> m;
    cin >> j;
    for (int i = 0; i < j; i++)
    {
        cin >> a[i];
    }

    int first = 1;
    int last = m;
    int ans = 0;

    for (int i = 0; i < j; i++)
    {
        if (a[i] >= first && a[i] <= last)
        {
            continue;
        }
        else if (a[i] > last)
        {
            int gap = a[i] - last;
            ans += gap;
            last += gap;
            first += gap;
        }
        else if (a[i] < first)
        {
            int gap = first - a[i];
            ans += gap;
            last -= gap;
            first -= gap;
        }
    }

    cout << ans << "\n";

    return 0;
}

/*
입력값
5 2
2
5
1


기대값
6

5 1
1
3

Ans : 2

9 1
4
5
6
1
7

정답: 16

10 2
7
5
6
9
4
5
9
9

정답: 15

7 4
7
1
7
5
1
3
5
2

정답: 7
*/