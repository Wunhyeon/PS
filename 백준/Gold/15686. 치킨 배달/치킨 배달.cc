#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[54][54];
vector<pair<int, int>> chickenAddress; // 좌표 치킨집
vector<pair<int, int>> houseAddress;   // 집 좌표
vector<vector<int>> comb;              // 조합

void makeCombi(vector<int> v, int limit, int start)
{
    if (v.size() == limit)
    {
        comb.push_back(v);
    }
    else
    {
        for (int i = start; i < chickenAddress.size(); i++)
        {
            v.push_back(i);
            makeCombi(v, limit, i + 1);
            v.pop_back();
        }
    }
}

int main()
{
    // int n과 m을 받는다.
    // n * n만큼 이중배열로 입력을 받는다.
    // 치킨집 (2)의 좌표를 저장한다. {{1,2},{3,4},,,}이런식으로
    // 치킨집 m개를 고르는 조합을 만든다. (인덱스로) {{0,1,2}, {1,1,3},,,} 이런식으로
    // 맵을 만들어보고 거리를 계산한다.
    // y = 좌표[인덱스[0][0]][1] 이런식으로. 이러려면 조합을 도는 배열을 구한다음 (2중 포문이 될거다). 거기서 인덱스를 꺼내고, 그 인덱스에 맞는 좌표를 설정해주면 된다.
    /*
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int idx = combi[i][j]
                int y = 좌표[idx][0];
                int x = 좌표[idx][1];
            }
        }
        이렇게 하면 될듯.

        이렇게 해서 골라진 치킨집의 주소를 저장하고, 복사된 배열을 이중포문을 돌면서 위 주소에 저장되어 있지 않다면 0으로 없앤다.
        다시 위의 저장된 치킨집을 반복문을 돌리며 가장 가까운 집을 찾는다. 이때도 min으로 찾는다. 아마 3중 반복문이 될 것 같다.
        반복문을 다 돌고 나면 answer에 위에서 구한 가장 가까운 거리를 더해준다.
        저장된 치킨집 3중 반복문을 다 돌고 나면 answer를 cout 해준다.


        집주소도 저장을 하자. 그러면 위에서 y,x를 구하면 더 쉽게 최소 거리를 구할 수 있다.
    */

    // min으로 가장 작은 사이즈를 얻어내서 출력한다.
    int answer = 100000;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int node;
            cin >> node;
            a[i][j] = node;
            if (node == 2)
            {
                chickenAddress.push_back({i, j});
            }
            else if (node == 1)
            {
                houseAddress.push_back({i, j});
            }
        }
    }

    vector<int> v;
    makeCombi(v, m, 0);

    // comb는 {{1,2,3}, {2,3,4},,,} 이런식으로 되어있을 것
    for (int i = 0; i < comb.size(); i++)
    {

        // comb[i] = {1,2,3},,,
        vector<pair<int, int>> newChickenAddress;
        for (int j = 0; j < comb[i].size(); j++)
        {
            int idx = comb[i][j];
            int y = chickenAddress[idx].first;
            int x = chickenAddress[idx].second;
            newChickenAddress.push_back({y, x});
        }

        // 치킨집 주소 새로고침 완료. newChickenAddress에 넣음. newChickenAddress 는 {{1,2},{5,8},,,}이런식.
        int distance = 0;
        // 가장 작은 거리 구하기. 집주소를 반복문을 돌리고, 그 안에서 newChickenAddress 를 반복문을 돌림.
        for (int j = 0; j < houseAddress.size(); j++)
        {
            int each = 100000;
            int houseY = houseAddress[j].first;
            int houseX = houseAddress[j].second;

            for (int k = 0; k < newChickenAddress.size(); k++)
            { // 이 반복문을 돌고나면 가장 각 집에서 가장 작은 치킨로드가 구해짐.
                int newChickenY = newChickenAddress[k].first;
                int newChickenX = newChickenAddress[k].second;
                each = min(each, abs(houseY - newChickenY) + abs(houseX - newChickenX));
            }

            distance += each;
        } // 반복문이 다 돌고 나면, 각 집에서 가장 작은 치킨로드 들의 합이 구해짐.
        answer = min(answer, distance);
    }

    cout << answer << '\n';

    return 0;
}