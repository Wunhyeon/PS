#include <bits/stdc++.h>
using namespace std;
int y, x, k, xOne, yOne, xTwo, yTwo;
int a[100][100];
int visited[100][100];
vector<int> v;
const int dirY[4] = {1, -1, 0, 0};
const int dirX[4] = {0, 0, 1, -1};
int cnt = 0;
void dfs(int curY, int curX)
{
    cnt++;
    visited[curY][curX] = 1;
    // cout << "curY : " << curY << " curX : " << curX << " cnt : " << cnt << '\n';
    for (int i = 0; i < 4; i++)
    {
        int nextY = curY + dirY[i];
        int nextX = curX + dirX[i];

        if (nextY >= 0 && nextX >= 0 && nextY < y && nextX < x && a[nextY][nextX] == 0 && !visited[nextY][nextX])
        {
            // visited[nextY][nextX] = 1; <= visited를 체크할 때, 여기다 두는 게 아니라 반복문 밖으로 빼야 main에서 처음에 들어갈 때 들어갔던 곳을 한번 더 체크하지 않는다.
            // 여기다 두면 main에서 처음 들어간 부분이 visited 체크가 되지 않기 때문에, 한번 더 방문하게 된다.
            dfs(nextY, nextX);
        }
    }
}

int main()
{
    cin >> y >> x >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> xOne >> yOne >> xTwo >> yTwo;
        for (int j = yOne; j < yTwo; j++)
        {
            for (int l = xOne; l < xTwo; l++)
            {
                a[j][l] = 1;
            }
        }
    }

    for (int i = 0; i < y; i++)
    {

        for (int j = 0; j < x; j++)
        {
            if (a[i][j] == 0 && !visited[i][j])
            {
                dfs(i, j);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}

// input
/*
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
*/
// output
/*
3
1 7 13
*/