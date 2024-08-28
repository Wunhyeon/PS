#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int a[54][54];
int visited[54][54];
int dirY[4] = {1, -1, 0, 0};
int dirX[4] = {0, 0, 1, -1};
vector<vector<int>> inner;

void dfs(int y, int x)
{
    visited[y][x] = 1;

    inner.push_back({y, x, a[y][x]});
    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dirY[i];
        int nextX = x + dirX[i];
        int subtract = abs(a[y][x] - a[nextY][nextX]);
        if (nextY >= 0 && nextX >= 0 && nextY < n && nextX < n && !visited[nextY][nextX] && (subtract >= l && subtract <= r))
        {
            dfs(nextY, nextX);
        }
    }
}

int main()
{
    // dfs로 푼다.
    // 바깥에 Day를 두고, while문으로 전체를 돌며 마지막에 day를 ++해준다. (조건은 while true)
    // 탐색을 할 때, 좌표를 모두 저장해줘야 한다. 그러니깐 연합인 좌표를 모두 저장해야한다. {{{y좌표,x좌표, 값},{y좌표, x좌표, 값}}, {{y좌표,x좌표, 값},{y좌표, x좌표, 값}},,,} 3중 벡터??
    // 값을 바꿔주는 건 2중 반복문을 모두 다 돌고 난 후 다.
    // 2중 반복문을 돌 때, visited에 들어가 있는 곳은 방문하지 않는다.
    // 2중 반복문을 다 돌아, 위의 3중 벡터가 만들어졌다면 이제 값을 바꿔준다.
    // 3중 벡터의 사이즈가 0이라면 day++을 해주지 않는다.
    // 3중 벡터에 있는 값들을 다 바꿔줬다면 day++을 해준다.
    // while반복문을 빠져나왔다면 day를 출력해준다.
    // while 반복문이 다시 돌아갈 때 visited 초기화, 3중 벡터 초기화

    // int N,L,R
    // int a[54][54];
    // int visited[54][54];

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int node;
            cin >> node;
            a[i][j] = node;
        }
    }

    int day = 0;
    while (true)
    {
        // 초기화
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        // 배열 탐색
        vector<vector<vector<int>>> outer;
        outer.clear();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    inner.clear();
                    dfs(i, j);
                    if (inner.size() > 1)
                        outer.push_back(inner);
                }
            }
        }

        // 좌표 저장됨.
        if (!outer.size())
        {
            break;
        }

        // for (int i = 0; i < outer.size(); i++)
        // {
        //     for (int j = 0; j < outer[i].size(); j++)
        //     {
        //         cout << "y : " << outer[i][j][0] << ", x : " << outer[i][j][1] << " value : " << outer[i][j][2] << "\n";
        //     }
        //     cout << "--------------------- \n";
        // }

        // {{{y좌표,x좌표, 값},{y좌표, x좌표, 값}}, {{y좌표,x좌표, 값},{y좌표, x좌표, 값}},,,}
        // outer의 가장 바깥쪽
        for (int i = 0; i < outer.size(); i++)
        {
            // outer의 한겹 안쪽. 연합들의 배열
            // 합구하기
            int sum = 0;
            for (int j = 0; j < outer[i].size(); j++)
            {
                sum += outer[i][j][2];
            }
            // 구한 합을 연합의 수만큼 나눠준 후, 각 요소에 분배하기
            for (int j = 0; j < outer[i].size(); j++)
            {
                int y = outer[i][j][0];
                int x = outer[i][j][1];
                a[y][x] = sum / outer[i].size();
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        day++;
    }

    cout << day << "\n";
    return 0;
}