/**
 * @ Author: Lakshya Singh
 * @ Create Time: 2020-06-15 20:50:55
 * @ Modified by: Target_X
 * @ Modified time: 2020-06-16 22:40:39
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
// #define int long long
#define pii pair<int, int>
#define minq priority_queue<int, vector<int>, greater<int>>
#define mem(a, val) memset(a, val, sizeof(a))

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    map<int, int> m1;

    int x;
    rep(i, n)
    {
        cin >> x;
        m1[x]++;
    }

    int count = 0, money = m;
    ostringstream s1;
    repA(i, 1, m)
    {
        if (m1.count(i) == 0)
        {
            if (money >= (i))
            {
                count++;
                s1 << i << " ";
                money -= (i);
            }
            else
                break;
        }
    }
    cout << count << endl;
    cout << s1.str();
}