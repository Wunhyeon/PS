#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int num;

int main()
{
    while (1)
    {
        cin >> num;
        if (num == 0)
        {
            break;
        }
        int sum = 2;
        while (num)
        {
            int lst = num % 10;
            if (lst == 0)
            {
                sum += 4;
            }
            else if (lst == 1)
            {
                sum += 2;
            }
            else
            {
                sum += 3;
            }
            sum += 1;
            num = num / 10;
        }

        cout << sum - 1 << "\n";
    }

    return 0;
}