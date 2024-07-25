#include <bits/stdc++.h>
using namespace std;
int n, k;
deque<int> belt;
deque<int> robot;
int num;

void printBelt()
{
    for (int i = 0; i < 2 * n; i++)
    {
        cout << belt[i] << " ";
    }
    cout << "\n";
}

void printRobot()
{
    for (int i = 0; i < robot.size(); i++)
    {
        cout << robot[i] << " ";
    }
    cout << "\n";
}

int check()
{
    int cnt = 0;
    for (int i = 0; i < belt.size(); i++)
    {
        if (belt[i] == 0)
        {
            cnt++;
        }
    }
    return cnt;
}

void moveBelt()
{
    // belt
    int back = belt.back();
    belt.pop_back();
    belt.push_front(back);
    // robot
    robot.pop_back();
    robot.push_front(0);
}

void moveRobot()
{
    if (robot[n - 1])
    {
        robot[n - 1] = 0;
    }
    for (int i = robot.size() - 2; i >= 0; i--)
    { // robot.size()-1이면 로봇 하치위치임.
        if (robot[i] == 0)
        {
            continue;
        }
        if (belt[i + 1] && !robot[i + 1])
        {
            robot[i + 1] = 1;
            belt[i + 1]--;
            robot[i] = 0;

            if (i + 1 == n - 1)
            {
                // 내리는 자리에 도착한 로봇은 내림
                robot[i + 1] = 0;
            }
        }
    }
}

void pushRobot()
{
    if (belt[0])
    {
        robot[0] = 1;
        belt[0]--;
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> num;
        belt.push_back(num);
        robot.push_back(0);
    }
    // check();
    int stage = 1;
    while (check() != 2 * n)
    {
        // cout << "@@@@@ stage : " << stage << "\n";
        // cout << "belt move" << "\n";
        moveBelt();
        // printRobot();
        // printBelt();

        // cout << "-------\n";
        // cout << "robot move" << "\n";
        moveRobot();
        // printRobot();
        // printBelt();
        // cout << "------\n";

        // cout << "push robot" << "\n";
        pushRobot();
        // printRobot();
        // printBelt();

        // cout << "-----\n";
        int cnt = check();
        // cout << "cnt : " << cnt << "\n";
        // cout << "\n";
        if (cnt >= k)
        {
            break;
        }
        stage++;
    }

    cout << stage << "\n";

    return 0;
}