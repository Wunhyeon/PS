#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[104][104];
int cnt = 0;
int pre = 0;
int node;
// vector<pair<int, int>> q;
vector<pair<int, int>> v;
int visited[104][104];
const int dirY[4] = {1, -1, 0, 0};
const int dirX[4] = {0, 0, 1, -1};

int main()
{
    // 치즈가 녹을 부분은 바깥 부분에서 bfs나 dfs로 탐색하면서 치즈를 만나는 부분(1인 부분)
    // 반복문을 돈다.
    // 반복문을 돌며 처음 좌표 0,0에서 시작해 1을 만나는 부분의 좌표를 저장한다.
    // pre에 치즈를 녹이기 전 치즈의 크기를 저장한다.
    // 반복문이 끝날 때 저장한 좌표의 부분을 녹인다. (0으로 만든다.)
    // 탐색을 한 전체 넓이가 입력된 가로 * 너비와 같으면 반복문을 멈춘다.
    // 카운트를 ++해준다.
    // 첫째줄에 카운트, 둘째줄에 pre를 출력한다.

    // bfs로 풀어보자.
    // int n,m 을 받는다.
    // 배열 a[104][104];
    // 갔던 곳을 저장할 visited[104][104]
    // bfs로 풀거니깐 큐가 필요함. 갈곳을 저장할 큐
    // int cnt = 0;
    // int pre = 0;
    // 1을 만나는 부분의 좌표를 저장할 벡터 vector<pair<int,in>> v;
    // 이중 반복문 n, m을 돌며 배열을 받는다.
    // while(true)로 반복문을 만든다.
    // 0,0에서부터 bfs시작. (q에 0,0추가)
    // while (q > 0)의 조건으로 반복문 시작.
    // q에서 첫번째 요소 꺼냄. visited에 추가.
    // 1만나는 곳 v에 저장.
    // 탐색이 끝나면, 전체 넓이 - 탐색한 넓이 = 치즈의 넓이가 됨. 이걸 pre에 저장. (치즈의 넓이가 0이 아닐때.)
    // 치즈의 넓이가 0이 아니라면 카운트 ++
    // 치즈의 넓이가 0이라면 break;
    // v에 저장된 곳 녹이기 (0으로 바꾸기)
    // 반복문을 다시 시작할 때, v초기화.visited 초기화

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> node;
            a[i][j] = node;
        }
    }
    // 입력받음.

    while (true)
    {
        // 초기화
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0); // visited초기화
        // v초기화
        for (int i = 0; i < v.size(); i++)
        {
            v.pop_back();
        }
        // v.clear();
        int airSize = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        // bfs시작
        while (q.size())
        {
            int currentY = q.front().first;
            int currentX = q.front().second;
            // visited[currentY][currentX] = 1; // visited check
            airSize++;
            // cout << "currentY : " << currentY << " currentX : " << currentX << "\n";
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nextY = currentY + dirY[i];
                int nextX = currentX + dirX[i];
                if (nextY >= 0 && nextX >= 0 && nextY < n && nextX < m && !visited[nextY][nextX])
                {
                    if (a[nextY][nextX] == 1)
                    {
                        // cout << "nextY : " << nextY << " nextX : " << nextX << "\n";
                        v.push_back({nextY, nextX});
                    }
                    else
                    {
                        visited[nextY][nextX] = 1;
                        q.push({nextY, nextX});
                    }
                }
            }
        }

        // 탐색끝.
        // 전체 넓이 = n*m - airSize
        // int cheeseSize = n * m - airSize;
        // // cout << "else cheeseSize : " << cheeseSize << '\n';
        // if (cheeseSize <= 0)
        // {
        //     break;
        // }
        // else
        // {
        //     pre = cheeseSize;
        //     cnt++;
        //     // 치즈 녹이기
        //     for (int i = 0; i < v.size(); i++)
        //     {
        //         int y = v[i].first;
        //         int x = v[i].second;
        //         a[y][x] = 0;
        //     }
        // }
        int cheeseSize = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                {
                    cheeseSize++;
                }
            }
        }

        if (cheeseSize <= 0)
        {
            break;
        }
        else
        {
            pre = cheeseSize;
            cnt++;
            // 치즈 녹이기
            for (int i = 0; i < v.size(); i++)
            {
                int y = v[i].first;
                int x = v[i].second;
                a[y][x] = 0;
            }
        }

        // cout << "---------------------" << '\n';
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "----------------------- " << '\n';
        // break;
    }

    cout << cnt << '\n';
    cout << pre << '\n';
    return 0;
}

/*
반례
5 5
0 0 0 0 0
0 1 1 0 0
0 1 0 1 0
0 1 1 1 0
0 0 0 0 0
*/