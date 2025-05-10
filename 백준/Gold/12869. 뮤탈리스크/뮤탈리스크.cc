#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> dir = {-9, -3, -1};
vector<vector<int>> dirP;
vector<int> v;
bool visited[64][64][64];

void makeP(int n, int r, int depth)
{
    if (r == depth)
    {
        dirP.push_back(dir);
        return;
    }
    for (int i = depth; i < n; i++)
    {
        swap(dir[i], dir[depth]);
        makeP(n, r, depth + 1);
        swap(dir[i], dir[depth]);
    }
}

int main()
{
    int ans = 180000;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    while (v.size() < 4)
    {
        v.push_back(0);
    }

    makeP(n, n, 0);

    // for (int i = 0; i < dirP.size(); i++)
    // {
    //     for (int j = 0; j < dirP[i].size(); j++)
    //     {
    //         cout << dirP[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    queue<vector<int>> q;
    q.push(v);
    while (q.size())
    {
        int f = q.front()[0];
        int s = q.front()[1];
        int t = q.front()[2];
        int depth = q.front()[3];
        q.pop();

        if (f <= 0 && s <= 0 && t <= 0)
        {
            ans = min(ans, depth);
            continue;
        }
        for (int i = 0; i < dirP.size(); i++)
        {
            int nextF = max(0, f + dirP[i][0]);
            int nextS = max(0, s + dirP[i][1]);
            int nextT = max(0, t + dirP[i][2]);
            int nextDepth = depth + 1;
            if (nextDepth < ans && nextF >= -60 && nextS >= -60 && nextT >= -60 && !visited[nextF][nextS][nextT])
            {
                visited[nextF][nextS][nextT] = true;
                q.push({nextF, nextS, nextT, nextDepth});
            }
        }
    }

    cout << ans << "\n";

    return 0;
}