#include <bits/stdc++.h>
using namespace std;
string s, t;
bool flag = false;
map<string, int> mp;
int tACnt;
int tBCnt;
int seqA;
int seqB;
int tmpSeqA;
int tmpSeqB;

int cntA(string str)
{
    int cnt = 0;
    int tmp = 0;
    int tmp2 = 0;
    tmpSeqA = 0;
    tmpSeqB = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'A')
        {
            cnt++;
            tmp++;
            tmpSeqA = max(tmpSeqA, tmp);
            tmp2 = 0;
        }
        else
        {
            tmp = 0;
            tmp2++;
            tmpSeqB = max(tmpSeqB, tmp2);
        }
    }
    return cnt;
}

void go(string str)
{
    // cout << "str : " << str << "\n";
    mp[str] = 1;

    if (str.size() > t.size())
    {
        return;
    }
    if (str == t)
    {
        flag = true;
        // cout << 1 << "\n";
        // exit(0);
        return;
    }
    string r = str;
    reverse(r.begin(), r.end());
    if (t.find(str) == string::npos && t.find(r) == string::npos)
    {
        return;
    }

    int aCnt = cntA(str);
    int bCnt = str.size() - aCnt;

    if (tmpSeqA > seqA || tmpSeqB > seqB)
    {
        // cout << "seqA : " << seqA << ", tmpSeqA : " << tmpSeqA << "\n";
        return;
    }

    if (aCnt + 1 <= tACnt && !mp[str + "A"])
    {
        go(str + "A");
    }

    if (bCnt + 1 > tBCnt)
    {
        return;
    }

    string b = str + "B";
    reverse(b.begin(), b.end());
    if (!mp[b])
    {
        go(b);
    }
}

int main()
{
    cin >> s >> t;
    // go(s);
    int tmp = 0;
    int tmp2 = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == 'A')
        {
            tACnt++;
            tmp++;
            seqA = max(seqA, tmp);
            tmp2 = 0;
        }
        else
        {
            tmp = 0;
            tmp2++;
            seqB = max(seqB, tmp2);
        }
    }

    tBCnt = t.size() - tACnt;
    // bfs(s);
    go(s);

    if (flag)
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }

    return 0;
}