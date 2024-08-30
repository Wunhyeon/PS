#include <bits/stdc++.h>
using namespace std;
int main()
{
    while (1)
    {
        string num;
        cin >> num;
        if (num == "0")
        {
            break;
        }
        bool flag = true;
        int l = 0;
        int r = num.size() - 1;

        while (l < r)
        {
            if (num[l] != num[r])
            {
                flag = false;
                break;
            }
            l++;
            r--;
        }
        if (flag)
        {
            cout << "yes" << "\n";
        }
        else
        {
            cout << "no" << "\n";
        }
    }
    return 0;
}