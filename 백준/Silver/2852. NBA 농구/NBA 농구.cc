#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int team;
int scoreA, scoreB;
int preTime;
int winTimeA, winTimeB;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> team >> s;
        if (team == 1)
        {
            scoreA++;
        }
        else
        {
            scoreB++;
        }

        int min = 0;
        int sec = 0;
        string tmp = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ':')
            {
                min = stoi(tmp);
                tmp = "";
                continue;
            }
            tmp += s[i];
        }
        sec = stoi(tmp);

        int curTime = min * 60 + sec;

        int timeGap = curTime - preTime;

        int preScoreA = scoreA;
        int preScoreB = scoreB;

        if (team == 1)
        {
            preScoreA--;
        }
        else
        {
            preScoreB--;
        }

        if (preScoreA > preScoreB)
        {
            winTimeA += timeGap;
        }
        else if (preScoreB > preScoreA)
        {
            winTimeB += timeGap;
        }

        preTime = curTime;
    }

    int timeGap = 48 * 60 - preTime;
    if (scoreA > scoreB)
    {
        winTimeA += timeGap;
    }
    else if (scoreB > scoreA)
    {
        winTimeB += timeGap;
    }

    int minuteA = winTimeA / 60;
    int secA = winTimeA % 60;

    int minuteB = winTimeB / 60;
    int secB = winTimeB % 60;

    string stringMA = minuteA >= 10 ? to_string(minuteA) : '0' + to_string(minuteA);
    string stringSA = secA >= 10 ? to_string(secA) : '0' + to_string(secA);

    string stringMB = minuteB >= 10 ? to_string(minuteB) : '0' + to_string(minuteB);
    string stringSB = secB >= 10 ? to_string(secB) : '0' + to_string(secB);

    cout << stringMA << ":" << stringSA << "\n";
    cout << stringMB << ":" << stringSB << "\n";

    return 0;
}
