#include <bits/stdc++.h>
using namespace std;
// int a[1000000004];
map<int, int> a;
vector<int> v;
int n;
int num;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a[num]++;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int st = v[i];

        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            if (left == i)
            {
                left++;
            }
            if (right == i)
            {
                right--;
            }
            if (left >= right)
            {
                break;
            }
            int sum = v[left] + v[right];
            if (sum == st)
            {
                cnt++;
                break;
            }
            else if (sum < st)
            {
                left++;
            }
            else if (sum > st)
            {
                right--;
            }
        }
        // cout << "st : " << st << ", cnt : " << cnt << "\n";
    }

    cout << cnt << "\n";
    return 0;
}
/*
3
1 1 2
ans : 1

2
1 2
ans : 0

3
0 0 0
ans : 3

3
-1 -1 -2
ans : 1

3
0 0 1
ans : 0
*/