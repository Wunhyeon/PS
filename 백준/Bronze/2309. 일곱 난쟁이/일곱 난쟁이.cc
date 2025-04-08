#include <bits/stdc++.h>
using namespace std;
vector<int> ansV;
vector<int> v;
void cir(int start, vector<int> vv)
{
    if (ansV.size() > 0)
    {
        return;
    }
    int sum = 0;
    for (int i = 0; i < vv.size(); i++)
    {
        sum += vv[i];
    }

    if (sum > 100 || vv.size() > 7)
    {
        return;
    }

    if (vv.size() == 7 && sum == 100)
    {
        for (int i = 0; i < vv.size(); i++)
        {
            ansV.push_back(vv[i]);
        }

        return;
    }

    for (int i = start; i < 9; i++)
    {

        vv.push_back(v[i]);
        cir(i + 1, vv);
        vv.pop_back();
    }
}

int main()
{
    int n;
    for (int i = 0; i < 9; i++)
    {
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    cir(0, {});

    if (ansV.size() > 0)
    {
        for (int i = 0; i < ansV.size(); i++)
        {
            cout << ansV[i] << "\n";
        }
    }
}