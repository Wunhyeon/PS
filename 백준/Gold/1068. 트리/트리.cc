#include <bits/stdc++.h>
using namespace std;
int n;
int a[54]; // n에 부모를 저장
int visited[54];
int r;

void dfs(int num)
{
    visited[num] = 1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && a[i] == num)
        {
            dfs(i);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> r;

    dfs(r);

    // dfs에서 1차로 부모가 r인 애들 전부 visited처리 했고, 2차로 리프구하기에서 부모인 애들을 visited처리 해준다.

    // 리프 구하기
    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            continue;
        }
        if (visited[i] == 1)
        {
            continue; // dfs에서 이미 체크된 애의 부모는 남겨둔다.
        }
        visited[a[i]] = 2; // 부모를 체크.
    }

    // dfs에서 체크된것들(r을 부모로 둔 애들) 제외, 부모인 것들을 제외한 수 세주기.
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}

/*
3
-1 -1 -1
0
ans : 2

3
-1 0 1
2
ans : 1

// 0의 부모가 뒤에 나오는 수인 경우
3
1 2 -1
1
ans : 1

4
-1 0 0 0
2

ans : 2

2
-1 0
1 (루트노드 단 하나만 남음)

정답 : 1

9
-1 0 0 5 2 4 4 6 6
4

정답 : 2 (루트 노드에 연결된 1 and 2 가 리프 노드가 됨)

4
-1 0 1 2
2

답 : 1
*/