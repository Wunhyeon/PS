#include <bits/stdc++.h>
using namespace std;
int n, c;
map<int, int> mp;
vector<int> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{

    // 숫자를 받는다.
    // 맵에 빈도수를 저장한다.
    // 벡터에 순서대로 저장한다.
    // 그러니깐 앞에서부터 돌면서 맵에 없으면 1로 넣고, 있으면 ++을 해준다.
    // 맵에 없으면 1로 넣으면서 벡터에도 추가, 맵에 없으면 벡터에 추가 X
    // 2중 벡터를 만든다. 형식은 {{숫자, 빈도수}, {숫자, 빈도수}} 이런식.
    // (1중)벡터를 반복문을 돌며 맵을 참조해 위에서 만든 2중벡터를 채운다.
    // 2중 벡터를 정렬한다. 빈도수로
    // sort(v.begin()[1], v.end()[1])이런식으로 하면 되지 않을까? => 안됌. 커스텀 정렬함수 cmp를 만들어줬다.
    // 2중 벡터를 반복문을 돌며 출력한다.
    // 출력할 때, 빈도수만큼 돌고, 다음으로 넘어간다.

    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        if (!mp[j])
            v.push_back(j);
        mp[j]++;
    }

    vector<pair<int, int>> v2;

    for (int i = 0; i < v.size(); i++)
    {
        v2.push_back({v[i], mp[v[i]]});
    }

    stable_sort(v2.begin(), v2.end(), cmp);

    for (int i = 0; i < v2.size(); i++)
    {
        int j = v2[i].second;
        for (int k = 0; k < j; k++)
        {
            cout << v2[i].first << " ";
        }
    }

    return 0;
}