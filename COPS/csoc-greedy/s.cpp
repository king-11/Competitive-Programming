/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-06-15 20:50:55
 * @ Modified by: Target_X
 * @ Modified time: 2020-06-16 22:13:41
 * @ Description:
 */

#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = a; i <= (n); ++i)
#define repD(i, a, n) for (int i = a; i >= (n); --i)
#define tr(a, x) for (auto &a : x)
#define all(c) c.begin(), c.end()

#define lld long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define f first
#define s second
#define sz(a) int((a).size())
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

#define vi vector<lld>
#define si set<lld>
#define endl "\n"
#define int long long
#define pii pair<int, int>
#define minq priority_queue<int, vector<int>, greater<int>>
#define mem(a, val) memset(a, val, sizeof(a))

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;
    int a = abs(s[0] - t[0]);
    int b = abs(s[1] - t[1]);
    cout << max(a, b) << "\n";
    int diff = min(a, b);
    a = abs(a - diff);
    b = abs(b - diff);
    if (s[1] > t[1])
    {
        if (s[0] > t[0])
            while (diff--)
                cout << "LD\n";
        else
            while (diff--)
                cout << "RD\n";
    }
    else
    {
        if (s[0] > t[0])
            while (diff--)
                cout << "LU\n";
        else
            while (diff--)
                cout << "RU\n";
    }
    if (a != 0 && b == 0)
    {
        if (s[0] < t[0])
            while (a--)
                cout << "R\n";
        else
            while (a--)
                cout << "L\n";
    }
    else if (a == 0 && b != 0)
    {
        if (s[1] < t[1])
            while (b--)
                cout << "U\n";
        else
            while (b--)
                cout << "D\n";
    }
}