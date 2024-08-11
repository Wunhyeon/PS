#include <bits/stdc++.h>
using namespace std;
int a, b;
vector<vector<int>> vv;
void go(int start, int limit, vector<int> tmp)
{

    if (tmp.size() == limit)
    {
        vv.push_back(tmp);
        return;
    }
    for (int i = start; i <= a; i++)
    {
        tmp.push_back(i);
        go(i, limit, tmp);
        tmp.pop_back();
    }
}

int main()
{
    cin >> a >> b;

    go(1, b, {});

    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}