#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v;
int num;
vector<vector<int>> vv;

void makePermu(int n, int r, int depth)
{
    if (depth == r)
    {
        vector<int> tmp;
        for (int i = 0; i < r; i++)
        {
            tmp.push_back(v[i]);
        }
        vv.push_back(tmp);
        return;
    }

    for (int i = depth; i < n; i++)
    {
        swap(v[i], v[depth]);
        makePermu(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    makePermu(N, M, 0);

    sort(vv.begin(), vv.end());

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