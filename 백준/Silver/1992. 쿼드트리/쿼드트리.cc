#include <bits/stdc++.h>
using namespace std;
int n;
char a[68][68];
string s;
int cnt = 0;

string go(int y1, int x1, int y2, int x2)
{
    if (y1 == y2 && x1 == x2)
    {
        // cout << "in " << "\n";
        return to_string(a[y1][x1] - '0');
    }
    // y2 = 7, x2 = 7
    string s1 = go(y1, x1, (y1 + y2) / 2, (x1 + x2) / 2);
    string s2 = go(y1, ((x1 + x2) / 2) + 1, (y1 + y2) / 2, x2);
    string s3 = go(((y1 + y2) / 2) + 1, x1, y2, (x1 + x2) / 2);
    string s4 = go(((y1 + y2) / 2) + 1, ((x1 + x2) / 2) + 1, y2, x2);

    if (s1.size() == 1 && s1 == s2 && s1 == s3 && s1 == s4)
    {
        return s1;
    }
    else
    {
        return "(" + s1 + s2 + s3 + s4 + ")";
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            a[i][j] = s[j];
        }
    }
    // go(0, 0, n - 1, n - 1);

    cout << go(0, 0, n - 1, n - 1) << "\n";

    return 0;
}

/*
8
11110000
11110000
00011100
00011100
11110000
11110000
11110011
11110011

ans
((110(0101))(0010)1(0001))
*/